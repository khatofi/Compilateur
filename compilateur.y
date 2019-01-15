
%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	/*#define yylnum type_y.num
	#define yylflt type_y.flt
	#define yylstr type_y.string*/

	extern FILE* yyin;
	extern FILE* yyout;

	char* precision;
	char* rounding;

	typedef struct var
	{
		char * name;
		int ind;
		char * type;
	} var;

	var array_var[256];
	
	int compteur;
	int size_array_var;

	
	void clear_tmp(void){
		for(int k=0; k<compteur; k++){
			fprintf(yyout, "mpc_clear(T%i);\n", k);
		}
		compteur = 0;
	}
	
	void declaration(char* type)
	{
		if(strcmp(type,"entier") == 0 || strcmp(type,"int") == 0)
			fprintf(yyout, "mpc_set_si");
		else if(strcmp(type,"flottant") == 0 || strcmp(type,"float") || strcmp(type,"double") || strcmp(type,"variable"))
			fprintf(yyout, "mpc_set_d");
	}

	void add_var(char * name, int ind_temp, char * type)
	{
		array_var[size_array_var].name = strdup(name);	
		array_var[size_array_var].ind = ind_temp;
  		array_var[size_array_var].type = strdup(type);	
		size_array_var++;
	}

	int var_exist(char * name)
	{
		for(int i=0; i<size_array_var; i++)
		{
			if(strcmp(name,array_var[i].name)==0)
				return array_var[i].ind;
		}
		return -1;
	}
 	
	int indice_T_exist(int indice)
	{
		for(int i=0; i<size_array_var; i++)
		{
			if(array_var[i].ind==indice)
				return 0;
		}
		return -1;
	}

	char* get_type(int indice)
	{
		for(int i=0; i<size_array_var; i++)
		{
			if(array_var[i].ind==indice)
				return array_var[i].type;
		}
		return "erreur";
	}

	void print_array(void)
	{
		for(int i=0; i<size_array_var; i++)
		{
			printf("%s ", array_var[i].name); 
		}
		printf("\n");
	}

%}

%union {
	struct {
		int num;
		float flt;
		char * yylstr;
		char* yylstr2;
	} type_y;
}

%token Pragma
%token MPC
%token Pourcent
%token Precision
%token Esp_Tab
%token <int> entier
%token <float> flottant
%token Rounding
%token <string> Arg_Rounding
%token variable
%token type

%token if_token
%token elseif_token
%token else_token
%token while_token
%token for_token

%token comparateur

%token all

%left "+" "-"
%left "*" "/"

%type <type_y> AFFECTATION OPERATION TMP


%%

F : S
;

S : Pragma Esp_Tab MPC Esp_Tab Precision '(' RL PRECISION RL ')' Esp_Tab Rounding '(' RL ROUNDING RL ')' RL '{' RL INIT CODE RL MPRAGMA '}' HorsPrag 
  | HorsPrag S//TODO libérer array_var entre 2 pragma?
  | /*empty*/
;

INIT: /*empty*/ {fprintf(yyout, "mpc_t T0;mpc_init2(T0, 128);\nmpc_set_si(T0,0,MPC_RNDZZ);\n");//Valeur initialisée au début du pragma qui stocke la constante 0.
				compteur++;
				}

MPRAGMA : /*empty*/ { clear_tmp();}
;

HorsPrag :
 | MPC {fprintf(yyout, "MPC");}
 | Precision {fprintf(yyout, "precision");}
 | Esp_Tab {fprintf(yyout, " ");}
 | entier {fprintf(yyout, yylval.type_y.yylstr);}
 | type {fprintf(yyout, yylval.type_y.yylstr2);}
 | flottant {fprintf(yyout, yylval.type_y.yylstr);}
 | Rounding {fprintf(yyout, "rounding");}
 | Arg_Rounding {fprintf(yyout, yylval.type_y.yylstr);}
 | variable {fprintf(yyout, yylval.type_y.yylstr);}
 | if_token {fprintf(yyout, "if");}
 | elseif_token {fprintf(yyout, "else if");}
 | else_token {fprintf(yyout, "else");}
 | while_token {fprintf(yyout, "while");}
 | for_token {fprintf(yyout, "for");}
 | all {fprintf(yyout, yylval.type_y.yylstr);}
 | comparateur {fprintf(yyout, yylval.type_y.yylstr);}
 | '(' {fprintf(yyout, "(");}
 | ')' {fprintf(yyout, ")");}
 | '+' {fprintf(yyout, "+");}
 | '*' {fprintf(yyout, "*");}
 | '-' {fprintf(yyout, "-");}
 | '\n' {fprintf(yyout, "\n");}
 | '{' {fprintf(yyout, "{");}
 | '}' {fprintf(yyout, "}");}
 | ';' {fprintf(yyout, ";");}
 | '%' {fprintf(yyout, "%s", "%");}//% est un caractère spécial dans fprintf()
 | '=' {fprintf(yyout, "=");}
 | '/' {fprintf(yyout, "/");}
 | S
;

PRECISION : entier {precision = strdup(yylval.type_y.yylstr);}
;

ROUNDING : Arg_Rounding {rounding = strdup(yylval.type_y.yylstr);};
;

CODE : /* empty */
	| DECLARATION RL CODE
	| FOR RL CODE 
;

DECLARATION : type Esp_Tab variable RL ';' 
{fprintf(yyout, "%s %s ;\n", yylval.type_y.yylstr2, yylval.type_y.yylstr);}
	| type Esp_Tab variable TMP '=' RL OPERATION RL ';'
{int exist = indice_T_exist($7.num);
 if(exist == 0)
 {
 fprintf(yyout, "mpc_t T%i;", compteur); 
 fprintf(yyout, "mpc_init2(T%i, %s);\n", compteur, precision);
 declaration(yylval.type_y.yylstr2);
 fprintf(yyout, "(T%i,0,%s);\n", compteur, rounding);
 fprintf(yyout, "mpc_add(T%i,T%i,T%i,%s);\n", compteur, compteur, $7.num, rounding);
 fprintf(yyout, "%s %s = mpc_get_ldc(T%i, %s);\n", yylval.type_y.yylstr2, $4.yylstr, compteur, precision);
 add_var($4.yylstr, compteur, yylval.type_y.yylstr2);
 compteur++;
 }
 else
 {
 fprintf(yyout, "%s %s = mpc_get_ldc(T%i, %s);\n", yylval.type_y.yylstr2, $4.yylstr, $7.num, precision);
 add_var($4.yylstr, $7.num, yylval.type_y.yylstr2);
 }
 print_array();
}
	| variable TMP '=' RL OPERATION RL ';'
{int ind = var_exist($2.yylstr);
 if(ind > 0)
 {
	fprintf(yyout, "mpc_add(T%i,T0,T%i,%s);\n", ind, $5.num, rounding);
    fprintf(yyout, "%s = mpc_get_ldc(T%i, %s);\n", $2.yylstr, ind, precision);
 }
 else
 {
	int exist = indice_T_exist($5.num);
	 if(exist == 0)
	 {
		 fprintf(yyout, "mpc_t T%i;", compteur); 
		 fprintf(yyout, "mpc_init2(T%i, %s);\n", compteur, precision);
		 declaration($5.yylstr2);
		 fprintf(yyout, "(T%i,0,%s);\n", compteur, rounding);
		 fprintf(yyout, "mpc_add(T%i,T%i,T%i,%s);\n", compteur, compteur, $5.num, rounding);
		 fprintf(yyout, "%s = mpc_get_ldc(T%i, %s);\n", $2.yylstr, compteur, precision);
		 add_var($2.yylstr, compteur, $5.yylstr2);
		 compteur++;
	 }
	 else
	 {
		 fprintf(yyout, "%s = mpc_get_ldc(T%i, %s);\n", $2.yylstr, $5.num, precision);
		 add_var($2.yylstr, $5.num, $5.yylstr2);
	 }
 }
 print_array();
}
	| ';'
;

OPERATION : OPERATION RL '+' RL OPERATION
{$$.yylstr2 = strdup($1.yylstr2);
 //Cette série de if évite que l'on modifie la valeur Tn d'une variable existante
 int exist1 = indice_T_exist($1.num);
 int exist3 = indice_T_exist($5.num);
 if(exist1 == 0 && exist3 == 0){
	 $$.num = compteur; 
	 fprintf(yyout, "mpc_t T%i;", compteur); 
	 fprintf(yyout, "mpc_init2(T%i, %s);\n", compteur, precision);
	 char *type_exist1 = strdup(get_type($1.num));
	 declaration(type_exist1);//TODO vérifier si on met le type de 1 ou 3
	 fprintf(yyout, "(T%i,%i,%s);\n", compteur, 0, rounding);
	 fprintf(yyout, "mpc_add(T%i,T%i,T%i,%s);\n", compteur, $1.num, $5.num, rounding);
	 compteur++;
 }
 else if(exist1 == 0){
 	fprintf(yyout, "mpc_add(T%i,T%i,T%i,%s);\n", $5.num, $1.num, $5.num, rounding);
	$$.num = $5.num;
 }
 else if(exist3 == 0){
  	fprintf(yyout, "mpc_add(T%i,T%i,T%i,%s);\n", $1.num, $1.num, $5.num, rounding);
	$$.num = $1.num;
 }
 else{
	fprintf(yyout, "mpc_add(T%i,T%i,T%i,%s);\n", $1.num, $1.num, $5.num, rounding);
	$$.num = $1.num;
 }
}
	|OPERATION RL '*' RL OPERATION
{$$.yylstr2 = strdup($1.yylstr2);
 //Cette série de if évite que l'on modifie la valeur Tn d'une variable existante
 int exist1 = indice_T_exist($1.num);
 int exist3 = indice_T_exist($5.num);
 if(exist1 == 0 && exist3 == 0){
	 $$.num = compteur; 
	 fprintf(yyout, "mpc_t T%i;", compteur); 
	 fprintf(yyout, "mpc_init2(T%i, %s);\n", compteur, precision);
	 char *type_exist1 = strdup(get_type($1.num));
	 declaration(type_exist1);//TODO vérifier si on met le type de 1 ou 3
	 fprintf(yyout, "(T%i,%i,%s);\n", compteur, 0, rounding);
	 fprintf(yyout, "mpc_mul(T%i,T%i,T%i,%s);\n", compteur, $1.num, $5.num, rounding);
	 compteur++;
 }
 else if(exist1 == 0){
 	fprintf(yyout, "mpc_mul(T%i,T%i,T%i,%s);\n", $5.num, $1.num, $5.num, rounding);
	$$.num = $5.num;
 }
 else if(exist3 == 0){
  	fprintf(yyout, "mpc_mul(T%i,T%i,T%i,%s);\n", $1.num, $1.num, $5.num, rounding);
	$$.num = $1.num;
 }
 else{
	fprintf(yyout, "mpc_mul(T%i,T%i,T%i,%s);\n", $1.num, $1.num, $5.num, rounding);
	$$.num = $1.num;
 }
}
	|OPERATION RL '/' RL OPERATION
{$$.yylstr2 = strdup($1.yylstr2);
 //Cette série de if évite que l'on modifie la valeur Tn d'une variable existante
 int exist1 = indice_T_exist($1.num);
 int exist3 = indice_T_exist($5.num);
 if(exist1 == 0 && exist3 == 0){
	 $$.num = compteur; 
	 fprintf(yyout, "mpc_t T%i;", compteur); 
	 fprintf(yyout, "mpc_init2(T%i, %s);\n", compteur, precision);
	 char *type_exist1 = strdup(get_type($1.num));
	 declaration(type_exist1);//TODO vérifier si on met le type de 1 ou 3
	 fprintf(yyout, "(T%i,%i,%s);\n", compteur, 0, rounding);
	 fprintf(yyout, "mpc_div(T%i,T%i,T%i,%s);\n", compteur, $1.num, $5.num, rounding);
	 compteur++;
 }
 else if(exist1 == 0){
 	fprintf(yyout, "mpc_div(T%i,T%i,T%i,%s);\n", $5.num, $1.num, $5.num, rounding);
	$$.num = $5.num;
 }
 else if(exist3 == 0){
  	fprintf(yyout, "mpc_div(T%i,T%i,T%i,%s);\n", $1.num, $1.num, $5.num, rounding);
	$$.num = $1.num;
 }
 else{
	fprintf(yyout, "mpc_div(T%i,T%i,T%i,%s);\n", $1.num, $1.num, $5.num, rounding);
	$$.num = $1.num;
 }
}
	|OPERATION RL '-' RL OPERATION
{$$.yylstr2 = strdup($1.yylstr2);
 //Cette série de if évite que l'on modifie la valeur Tn d'une variable existante
 int exist1 = indice_T_exist($1.num);
 int exist3 = indice_T_exist($5.num);
 if(exist1 == 0 && exist3 == 0){
	 $$.num = compteur; 
	 fprintf(yyout, "mpc_t T%i;", compteur); 
	 fprintf(yyout, "mpc_init2(T%i, %s);\n", compteur, precision);
	 char *type_exist1 = strdup(get_type($1.num));
	 declaration(type_exist1);//TODO vérifier si on met le type de 1 ou 3
	 fprintf(yyout, "(T%i,%i,%s);\n", compteur, 0, rounding);
	 fprintf(yyout, "mpc_sub(T%i,T%i,T%i,%s);\n", compteur, $1.num, $5.num, rounding);
	 compteur++;
 }
 else if(exist1 == 0){
 	fprintf(yyout, "mpc_sub(T%i,T%i,T%i,%s);\n", $5.num, $1.num, $5.num, rounding);
	$$.num = $5.num;
 }
 else if(exist3 == 0){
  	fprintf(yyout, "mpc_sub(T%i,T%i,T%i,%s);\n", $1.num, $1.num, $5.num, rounding);
	$$.num = $1.num;
 }
 else{
	fprintf(yyout, "mpc_sub(T%i,T%i,T%i,%s);\n", $1.num, $1.num, $5.num, rounding);
	$$.num = $1.num;
 }
}

	|'(' RL OPERATION RL ')'
{
	$$.num = $3.num;
	$$.yylstr2 = strdup($3.yylstr2); 
}

	| AFFECTATION
{
 int ind;
 $$.yylstr2 = strdup($1.yylstr2);
 if((ind = var_exist($1.yylstr)) < 0)
 {
	 $$.num = compteur; 
	 fprintf(yyout, "mpc_t T%i;", compteur); 
	 fprintf(yyout, "mpc_init2(T%i, %s);\n", compteur, precision);
	 declaration($1.yylstr2);
	 fprintf(yyout, "(T%i,%s,%s);\n", compteur, $1.yylstr, rounding); 
	 compteur++;
 }
 else
	$$.num = ind;
}
;


//yylstr contient la valeur de l'affectation et yylstr2 son type
AFFECTATION : variable {$$.yylstr = strdup(yylval.type_y.yylstr); $$.yylstr2 = strdup("variable");}
	| entier {$$.yylstr = strdup(yylval.type_y.yylstr); $$.yylstr2 = strdup("entier");}
	| flottant {$$.yylstr = strdup(yylval.type_y.yylstr); $$.yylstr2 = strdup("flottant");}
;


FOR : for_token RL '('  RL DECLARATION RL ')' RL '{' RL '}' //PLUS TARD
;

TMP : RL 
{$$.yylstr = strdup(yylval.type_y.yylstr);}
;


RL : /* empty */
	|'\n' RL
	| Esp_Tab RL
;

%%

int yyerror(char *s)
{
	printf("ERROR %s\n",s);
	return 1;
}

int main(int argc, char * argv[])
{
	if(argc != 2){
		fprintf(stderr, "Le nombre d'argument doit être 2.\n");
		exit(EXIT_FAILURE);
	}
	compteur = 0;
  size_array_var = 0;
	if((yyin = fopen(argv[1], "r")) == NULL){
		fprintf(stderr, "L'ouverture du fichier d'entrée à échoué.\n");
		exit(EXIT_FAILURE);
	}
	if((yyout = fopen("sortie", "w")) == NULL){
		fprintf(stderr, "L'ouverture du fichier de sortie à échoué.\n");
		exit(EXIT_FAILURE);
	}

	fprintf(yyout, "#include <complex.h>\n"
			"#include <mpfr.h>\n"
			"#include <mpc.h>\n"
			);

	yyparse();
	fclose(yyin);
	fclose(yyout);
}
