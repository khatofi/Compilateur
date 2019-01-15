%option noyywrap
%option nounput

%{
	#include <stdio.h>
	#include "y.tab.h"

	/*#define yylnum type_y.num
	#define yylflt type_y.flt
	#define yylstr type_y.string*/

%}

ESPTAB [ \t]
ARGROUNDING "MPC_RNDZZ"
TYPE "int"|"float"|"double"
VARIABLE [a-zA-Z][a-zA-Z0-9]*
FLOTTANT -?[0-9]+\.[0-9]*|[0-9]*\.[0-9]+
ENTIER -?[0-9]+
ELSEIF "else"[\n ]*"if"
COMPARATEUR [>|<|>=|<=|==]
ALL .


%%
[+] {return '+';};
{ESPTAB}+ {return Esp_Tab;};
[-] {return '-';};
[*] {return '*';};
[/] {return '/';};
[(] {return '(';};
[)] {return ')';};	
[\n] {return '\n';};
[{] {return '{';};
[}] {return '}';};
[;] {return ';';};
[=] {return '=';};
[%] {return '%';};

#pragma {return Pragma;};
MPC {return MPC;};
precision {return Precision;};
rounding {return Rounding;};

for {return for_token;};
while {return while_token;};
if {return if_token;};
{ELSEIF} {yylval.type_y.yylstr = strdup(yytext); return elseif_token;};
else {return else_token;};

{COMPARATEUR} {yylval.type_y.yylstr = strdup(yytext); return comparateur;};

{ENTIER} {yylval.type_y.yylstr = strdup(yytext); return entier;};
{FLOTTANT} {yylval.type_y.yylstr = strdup(yytext); return flottant;};


{ARGROUNDING} {yylval.type_y.yylstr = strdup(yytext); return Arg_Rounding;};
{TYPE} {yylval.type_y.yylstr2 = strdup(yytext); return type;};
{VARIABLE} {yylval.type_y.yylstr = strdup(yytext); return variable;};

{ALL} {yylval.type_y.yylstr = strdup(yytext); return all;};




