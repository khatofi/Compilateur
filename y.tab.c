/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "compilateur.y" /* yacc.c:339  */

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


#line 158 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    Pragma = 258,
    MPC = 259,
    Pourcent = 260,
    Precision = 261,
    Esp_Tab = 262,
    entier = 263,
    flottant = 264,
    Rounding = 265,
    Arg_Rounding = 266,
    variable = 267,
    type = 268,
    if_token = 269,
    elseif_token = 270,
    else_token = 271,
    while_token = 272,
    for_token = 273,
    comparateur = 274,
    all = 275
  };
#endif
/* Tokens.  */
#define Pragma 258
#define MPC 259
#define Pourcent 260
#define Precision 261
#define Esp_Tab 262
#define entier 263
#define flottant 264
#define Rounding 265
#define Arg_Rounding 266
#define variable 267
#define type 268
#define if_token 269
#define elseif_token 270
#define else_token 271
#define while_token 272
#define for_token 273
#define comparateur 274
#define all 275

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 94 "compilateur.y" /* yacc.c:355  */

	struct {
		int num;
		float flt;
		char * yylstr;
		char* yylstr2;
	} type_y;

#line 247 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 264 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  34
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   135

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  126

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   279

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      32,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    34,     2,     2,
      25,    26,    30,    29,     2,    31,     2,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    33,
       2,    35,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    27,     2,    28,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   133,   133,   136,   137,   138,   141,   145,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   180,   183,
     186,   187,   188,   191,   193,   213,   242,   245,   273,   301,
     329,   358,   364,   384,   385,   386,   390,   393,   398,   399,
     400
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "Pragma", "MPC", "Pourcent", "Precision",
  "Esp_Tab", "entier", "flottant", "Rounding", "Arg_Rounding", "variable",
  "type", "if_token", "elseif_token", "else_token", "while_token",
  "for_token", "comparateur", "all", "\"+\"", "\"-\"", "\"*\"", "\"/\"",
  "'('", "')'", "'{'", "'}'", "'+'", "'*'", "'-'", "'\\n'", "';'", "'%'",
  "'='", "'/'", "$accept", "F", "S", "INIT", "MPRAGMA", "HorsPrag",
  "PRECISION", "ROUNDING", "CODE", "DECLARATION", "OPERATION",
  "AFFECTATION", "FOR", "TMP", "RL", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,    40,    41,   123,   125,    43,
      42,    45,    10,    59,    37,    61,    47
};
# endif

#define YYPACT_NINF -68

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-68)))

#define YYTABLE_NINF -3

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      83,    -3,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
       9,    10,    83,    15,   -68,   -68,    14,    16,     1,    -2,
      -2,    -2,    23,   -68,   -68,   -68,    -2,     7,    17,    33,
      20,    -2,    35,   -68,    -2,    27,    -2,    28,    -2,   -68,
      -1,    -2,    51,    -2,   -68,    -2,    -2,    -2,    24,   -68,
      30,    47,   -68,    -1,    -1,    -2,    -2,    -2,    49,   -68,
     -68,    32,    38,    46,     2,    83,   -68,   -68,   -68,    -2,
      -2,   -68,    -2,   -68,    -2,   -68,    83,    32,    91,    32,
      52,    -2,    -2,    -2,    -2,   -68,    -2,    -2,    -2,    45,
      32,    32,    32,    32,    99,    53,   -68,    -2,    -2,    -2,
      -2,   -68,    -2,    31,    54,   -68
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     9,    10,    11,    12,    14,    15,    16,    17,
      13,    18,    19,    20,    21,    22,    24,    23,    25,    26,
      31,    32,    27,    28,    29,    30,    33,    34,    35,    36,
       0,    37,     5,     0,     1,     4,     0,     0,     0,    58,
      58,    58,     0,    60,    59,    38,    58,     0,     0,     0,
       0,    58,     0,    39,    58,     0,    58,     0,    58,     6,
      40,    58,     0,    58,    46,    58,    58,    58,     0,    57,
       0,     0,     7,    40,    40,    58,    58,    58,     0,    41,
      42,     0,     0,    57,     0,     5,    54,    55,    53,    58,
      58,    52,    58,    43,    58,    37,     3,     0,     0,     0,
       0,    58,    58,    58,    58,    45,    58,    58,    58,     0,
       0,     0,     0,     0,     0,     0,    51,    47,    48,    50,
      49,    44,    58,     0,     0,    56
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -68,   -68,     0,   -68,   -68,     3,   -68,   -68,   -67,    21,
     -63,   -68,   -68,    50,   -38
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    30,    35,    60,    78,    32,    46,    54,    65,    66,
      90,    91,    67,    68,   123
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      31,    42,    43,    44,    33,    40,    79,    80,    47,    34,
      -2,    61,    62,    52,    61,    62,    55,    63,    57,    36,
      59,    37,    38,    69,    49,    71,    39,    72,    73,    74,
      41,    45,    64,    48,   101,    64,   107,    81,    83,    84,
      86,    87,    76,    50,    88,    51,    53,   117,   118,   119,
     120,    97,    98,    56,    99,    58,   100,    89,    70,    75,
     102,   103,   104,   109,   110,   111,   112,   106,   113,   114,
     115,   116,    77,    92,   102,   103,   104,    85,   108,    93,
     122,   106,   125,     0,   124,    95,     1,     2,    96,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,     0,    94,     0,     0,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
     102,   103,   104,     0,   105,     0,    82,   106,   102,   103,
     104,     0,   121,     0,     0,   106
};

static const yytype_int8 yycheck[] =
{
       0,    39,    40,    41,     7,     7,    73,    74,    46,     0,
       0,    12,    13,    51,    12,    13,    54,    18,    56,     4,
      58,     7,     6,    61,     7,    63,    25,    65,    66,    67,
      32,     8,    33,    26,    97,    33,    99,    75,    76,    77,
       8,     9,    12,    10,    12,    25,    11,   110,   111,   112,
     113,    89,    90,    26,    92,    27,    94,    25,     7,    35,
      29,    30,    31,   101,   102,   103,   104,    36,   106,   107,
     108,    26,    25,    35,    29,    30,    31,    28,    26,    33,
      27,    36,    28,    -1,   122,    85,     3,     4,    85,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    -1,    84,    -1,    -1,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      29,    30,    31,    -1,    33,    -1,    76,    36,    29,    30,
      31,    -1,    33,    -1,    -1,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      38,    39,    42,     7,     0,    39,     4,     7,     6,    25,
       7,    32,    51,    51,    51,     8,    43,    51,    26,     7,
      10,    25,    51,    11,    44,    51,    26,    51,    27,    51,
      40,    12,    13,    18,    33,    45,    46,    49,    50,    51,
       7,    51,    51,    51,    51,    35,    12,    25,    41,    45,
      45,    51,    50,    51,    51,    28,     8,     9,    12,    25,
      47,    48,    35,    33,    46,    39,    42,    51,    51,    51,
      51,    47,    29,    30,    31,    33,    36,    47,    26,    51,
      51,    51,    51,    51,    51,    51,    26,    47,    47,    47,
      47,    33,    27,    51,    51,    28
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    39,    39,    39,    40,    41,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    42,    43,    44,
      45,    45,    45,    46,    46,    46,    46,    47,    47,    47,
      47,    47,    47,    48,    48,    48,    49,    50,    51,    51,
      51
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,    26,     2,     0,     0,     0,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     3,     3,     5,     9,     7,     1,     5,     5,     5,
       5,     5,     1,     1,     1,     1,    11,     1,     0,     2,
       2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 6:
#line 141 "compilateur.y" /* yacc.c:1646  */
    {fprintf(yyout, "mpc_t T0;mpc_init2(T0, 128);\nmpc_set_si(T0,0,MPC_RNDZZ);\n");//Valeur initialisée au début du pragma qui stocke la constante 0.
				compteur++;
				}
#line 1424 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 145 "compilateur.y" /* yacc.c:1646  */
    { clear_tmp();}
#line 1430 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 149 "compilateur.y" /* yacc.c:1646  */
    {fprintf(yyout, "MPC");}
#line 1436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 150 "compilateur.y" /* yacc.c:1646  */
    {fprintf(yyout, "precision");}
#line 1442 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 151 "compilateur.y" /* yacc.c:1646  */
    {fprintf(yyout, " ");}
#line 1448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 152 "compilateur.y" /* yacc.c:1646  */
    {fprintf(yyout, yylval.type_y.yylstr);}
#line 1454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 153 "compilateur.y" /* yacc.c:1646  */
    {fprintf(yyout, yylval.type_y.yylstr2);}
#line 1460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 154 "compilateur.y" /* yacc.c:1646  */
    {fprintf(yyout, yylval.type_y.yylstr);}
#line 1466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 155 "compilateur.y" /* yacc.c:1646  */
    {fprintf(yyout, "rounding");}
#line 1472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 156 "compilateur.y" /* yacc.c:1646  */
    {fprintf(yyout, yylval.type_y.yylstr);}
#line 1478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 157 "compilateur.y" /* yacc.c:1646  */
    {fprintf(yyout, yylval.type_y.yylstr);}
#line 1484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 158 "compilateur.y" /* yacc.c:1646  */
    {fprintf(yyout, "if");}
#line 1490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 159 "compilateur.y" /* yacc.c:1646  */
    {fprintf(yyout, "else if");}
#line 1496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 160 "compilateur.y" /* yacc.c:1646  */
    {fprintf(yyout, "else");}
#line 1502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 161 "compilateur.y" /* yacc.c:1646  */
    {fprintf(yyout, "while");}
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 162 "compilateur.y" /* yacc.c:1646  */
    {fprintf(yyout, "for");}
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 163 "compilateur.y" /* yacc.c:1646  */
    {fprintf(yyout, yylval.type_y.yylstr);}
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 164 "compilateur.y" /* yacc.c:1646  */
    {fprintf(yyout, yylval.type_y.yylstr);}
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 165 "compilateur.y" /* yacc.c:1646  */
    {fprintf(yyout, "(");}
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 166 "compilateur.y" /* yacc.c:1646  */
    {fprintf(yyout, ")");}
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 167 "compilateur.y" /* yacc.c:1646  */
    {fprintf(yyout, "+");}
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 168 "compilateur.y" /* yacc.c:1646  */
    {fprintf(yyout, "*");}
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 169 "compilateur.y" /* yacc.c:1646  */
    {fprintf(yyout, "-");}
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 170 "compilateur.y" /* yacc.c:1646  */
    {fprintf(yyout, "\n");}
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 171 "compilateur.y" /* yacc.c:1646  */
    {fprintf(yyout, "{");}
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 172 "compilateur.y" /* yacc.c:1646  */
    {fprintf(yyout, "}");}
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 173 "compilateur.y" /* yacc.c:1646  */
    {fprintf(yyout, ";");}
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 174 "compilateur.y" /* yacc.c:1646  */
    {fprintf(yyout, "%s", "%");}
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 175 "compilateur.y" /* yacc.c:1646  */
    {fprintf(yyout, "=");}
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 176 "compilateur.y" /* yacc.c:1646  */
    {fprintf(yyout, "/");}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 180 "compilateur.y" /* yacc.c:1646  */
    {precision = strdup(yylval.type_y.yylstr);}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 183 "compilateur.y" /* yacc.c:1646  */
    {rounding = strdup(yylval.type_y.yylstr);}
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 192 "compilateur.y" /* yacc.c:1646  */
    {fprintf(yyout, "%s %s ;\n", yylval.type_y.yylstr2, yylval.type_y.yylstr);}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 194 "compilateur.y" /* yacc.c:1646  */
    {int exist = indice_T_exist((yyvsp[-2].type_y).num);
 if(exist == 0)
 {
 fprintf(yyout, "mpc_t T%i;", compteur); 
 fprintf(yyout, "mpc_init2(T%i, %s);\n", compteur, precision);
 declaration(yylval.type_y.yylstr2);
 fprintf(yyout, "(T%i,0,%s);\n", compteur, rounding);
 fprintf(yyout, "mpc_add(T%i,T%i,T%i,%s);\n", compteur, compteur, (yyvsp[-2].type_y).num, rounding);
 fprintf(yyout, "%s %s = mpc_get_ldc(T%i, %s);\n", yylval.type_y.yylstr2, (yyvsp[-5].type_y).yylstr, compteur, precision);
 add_var((yyvsp[-5].type_y).yylstr, compteur, yylval.type_y.yylstr2);
 compteur++;
 }
 else
 {
 fprintf(yyout, "%s %s = mpc_get_ldc(T%i, %s);\n", yylval.type_y.yylstr2, (yyvsp[-5].type_y).yylstr, (yyvsp[-2].type_y).num, precision);
 add_var((yyvsp[-5].type_y).yylstr, (yyvsp[-2].type_y).num, yylval.type_y.yylstr2);
 }
 print_array();
}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 214 "compilateur.y" /* yacc.c:1646  */
    {int ind = var_exist((yyvsp[-5].type_y).yylstr);
 if(ind > 0)
 {
	fprintf(yyout, "mpc_add(T%i,T0,T%i,%s);\n", ind, (yyvsp[-2].type_y).num, rounding);
    fprintf(yyout, "%s = mpc_get_ldc(T%i, %s);\n", (yyvsp[-5].type_y).yylstr, ind, precision);
 }
 else
 {
	int exist = indice_T_exist((yyvsp[-2].type_y).num);
	 if(exist == 0)
	 {
		 fprintf(yyout, "mpc_t T%i;", compteur); 
		 fprintf(yyout, "mpc_init2(T%i, %s);\n", compteur, precision);
		 declaration((yyvsp[-2].type_y).yylstr2);
		 fprintf(yyout, "(T%i,0,%s);\n", compteur, rounding);
		 fprintf(yyout, "mpc_add(T%i,T%i,T%i,%s);\n", compteur, compteur, (yyvsp[-2].type_y).num, rounding);
		 fprintf(yyout, "%s = mpc_get_ldc(T%i, %s);\n", (yyvsp[-5].type_y).yylstr, compteur, precision);
		 add_var((yyvsp[-5].type_y).yylstr, compteur, (yyvsp[-2].type_y).yylstr2);
		 compteur++;
	 }
	 else
	 {
		 fprintf(yyout, "%s = mpc_get_ldc(T%i, %s);\n", (yyvsp[-5].type_y).yylstr, (yyvsp[-2].type_y).num, precision);
		 add_var((yyvsp[-5].type_y).yylstr, (yyvsp[-2].type_y).num, (yyvsp[-2].type_y).yylstr2);
	 }
 }
 print_array();
}
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 246 "compilateur.y" /* yacc.c:1646  */
    {(yyval.type_y).yylstr2 = strdup((yyvsp[-4].type_y).yylstr2);
 //Cette série de if évite que l'on modifie la valeur Tn d'une variable existante
 int exist1 = indice_T_exist((yyvsp[-4].type_y).num);
 int exist3 = indice_T_exist((yyvsp[0].type_y).num);
 if(exist1 == 0 && exist3 == 0){
	 (yyval.type_y).num = compteur; 
	 fprintf(yyout, "mpc_t T%i;", compteur); 
	 fprintf(yyout, "mpc_init2(T%i, %s);\n", compteur, precision);
	 char *type_exist1 = strdup(get_type((yyvsp[-4].type_y).num));
	 declaration(type_exist1);//TODO vérifier si on met le type de 1 ou 3
	 fprintf(yyout, "(T%i,%i,%s);\n", compteur, 0, rounding);
	 fprintf(yyout, "mpc_add(T%i,T%i,T%i,%s);\n", compteur, (yyvsp[-4].type_y).num, (yyvsp[0].type_y).num, rounding);
	 compteur++;
 }
 else if(exist1 == 0){
 	fprintf(yyout, "mpc_add(T%i,T%i,T%i,%s);\n", (yyvsp[0].type_y).num, (yyvsp[-4].type_y).num, (yyvsp[0].type_y).num, rounding);
	(yyval.type_y).num = (yyvsp[0].type_y).num;
 }
 else if(exist3 == 0){
  	fprintf(yyout, "mpc_add(T%i,T%i,T%i,%s);\n", (yyvsp[-4].type_y).num, (yyvsp[-4].type_y).num, (yyvsp[0].type_y).num, rounding);
	(yyval.type_y).num = (yyvsp[-4].type_y).num;
 }
 else{
	fprintf(yyout, "mpc_add(T%i,T%i,T%i,%s);\n", (yyvsp[-4].type_y).num, (yyvsp[-4].type_y).num, (yyvsp[0].type_y).num, rounding);
	(yyval.type_y).num = (yyvsp[-4].type_y).num;
 }
}
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 274 "compilateur.y" /* yacc.c:1646  */
    {(yyval.type_y).yylstr2 = strdup((yyvsp[-4].type_y).yylstr2);
 //Cette série de if évite que l'on modifie la valeur Tn d'une variable existante
 int exist1 = indice_T_exist((yyvsp[-4].type_y).num);
 int exist3 = indice_T_exist((yyvsp[0].type_y).num);
 if(exist1 == 0 && exist3 == 0){
	 (yyval.type_y).num = compteur; 
	 fprintf(yyout, "mpc_t T%i;", compteur); 
	 fprintf(yyout, "mpc_init2(T%i, %s);\n", compteur, precision);
	 char *type_exist1 = strdup(get_type((yyvsp[-4].type_y).num));
	 declaration(type_exist1);//TODO vérifier si on met le type de 1 ou 3
	 fprintf(yyout, "(T%i,%i,%s);\n", compteur, 0, rounding);
	 fprintf(yyout, "mpc_mul(T%i,T%i,T%i,%s);\n", compteur, (yyvsp[-4].type_y).num, (yyvsp[0].type_y).num, rounding);
	 compteur++;
 }
 else if(exist1 == 0){
 	fprintf(yyout, "mpc_mul(T%i,T%i,T%i,%s);\n", (yyvsp[0].type_y).num, (yyvsp[-4].type_y).num, (yyvsp[0].type_y).num, rounding);
	(yyval.type_y).num = (yyvsp[0].type_y).num;
 }
 else if(exist3 == 0){
  	fprintf(yyout, "mpc_mul(T%i,T%i,T%i,%s);\n", (yyvsp[-4].type_y).num, (yyvsp[-4].type_y).num, (yyvsp[0].type_y).num, rounding);
	(yyval.type_y).num = (yyvsp[-4].type_y).num;
 }
 else{
	fprintf(yyout, "mpc_mul(T%i,T%i,T%i,%s);\n", (yyvsp[-4].type_y).num, (yyvsp[-4].type_y).num, (yyvsp[0].type_y).num, rounding);
	(yyval.type_y).num = (yyvsp[-4].type_y).num;
 }
}
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 302 "compilateur.y" /* yacc.c:1646  */
    {(yyval.type_y).yylstr2 = strdup((yyvsp[-4].type_y).yylstr2);
 //Cette série de if évite que l'on modifie la valeur Tn d'une variable existante
 int exist1 = indice_T_exist((yyvsp[-4].type_y).num);
 int exist3 = indice_T_exist((yyvsp[0].type_y).num);
 if(exist1 == 0 && exist3 == 0){
	 (yyval.type_y).num = compteur; 
	 fprintf(yyout, "mpc_t T%i;", compteur); 
	 fprintf(yyout, "mpc_init2(T%i, %s);\n", compteur, precision);
	 char *type_exist1 = strdup(get_type((yyvsp[-4].type_y).num));
	 declaration(type_exist1);//TODO vérifier si on met le type de 1 ou 3
	 fprintf(yyout, "(T%i,%i,%s);\n", compteur, 0, rounding);
	 fprintf(yyout, "mpc_div(T%i,T%i,T%i,%s);\n", compteur, (yyvsp[-4].type_y).num, (yyvsp[0].type_y).num, rounding);
	 compteur++;
 }
 else if(exist1 == 0){
 	fprintf(yyout, "mpc_div(T%i,T%i,T%i,%s);\n", (yyvsp[0].type_y).num, (yyvsp[-4].type_y).num, (yyvsp[0].type_y).num, rounding);
	(yyval.type_y).num = (yyvsp[0].type_y).num;
 }
 else if(exist3 == 0){
  	fprintf(yyout, "mpc_div(T%i,T%i,T%i,%s);\n", (yyvsp[-4].type_y).num, (yyvsp[-4].type_y).num, (yyvsp[0].type_y).num, rounding);
	(yyval.type_y).num = (yyvsp[-4].type_y).num;
 }
 else{
	fprintf(yyout, "mpc_div(T%i,T%i,T%i,%s);\n", (yyvsp[-4].type_y).num, (yyvsp[-4].type_y).num, (yyvsp[0].type_y).num, rounding);
	(yyval.type_y).num = (yyvsp[-4].type_y).num;
 }
}
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 330 "compilateur.y" /* yacc.c:1646  */
    {(yyval.type_y).yylstr2 = strdup((yyvsp[-4].type_y).yylstr2);
 //Cette série de if évite que l'on modifie la valeur Tn d'une variable existante
 int exist1 = indice_T_exist((yyvsp[-4].type_y).num);
 int exist3 = indice_T_exist((yyvsp[0].type_y).num);
 if(exist1 == 0 && exist3 == 0){
	 (yyval.type_y).num = compteur; 
	 fprintf(yyout, "mpc_t T%i;", compteur); 
	 fprintf(yyout, "mpc_init2(T%i, %s);\n", compteur, precision);
	 char *type_exist1 = strdup(get_type((yyvsp[-4].type_y).num));
	 declaration(type_exist1);//TODO vérifier si on met le type de 1 ou 3
	 fprintf(yyout, "(T%i,%i,%s);\n", compteur, 0, rounding);
	 fprintf(yyout, "mpc_sub(T%i,T%i,T%i,%s);\n", compteur, (yyvsp[-4].type_y).num, (yyvsp[0].type_y).num, rounding);
	 compteur++;
 }
 else if(exist1 == 0){
 	fprintf(yyout, "mpc_sub(T%i,T%i,T%i,%s);\n", (yyvsp[0].type_y).num, (yyvsp[-4].type_y).num, (yyvsp[0].type_y).num, rounding);
	(yyval.type_y).num = (yyvsp[0].type_y).num;
 }
 else if(exist3 == 0){
  	fprintf(yyout, "mpc_sub(T%i,T%i,T%i,%s);\n", (yyvsp[-4].type_y).num, (yyvsp[-4].type_y).num, (yyvsp[0].type_y).num, rounding);
	(yyval.type_y).num = (yyvsp[-4].type_y).num;
 }
 else{
	fprintf(yyout, "mpc_sub(T%i,T%i,T%i,%s);\n", (yyvsp[-4].type_y).num, (yyvsp[-4].type_y).num, (yyvsp[0].type_y).num, rounding);
	(yyval.type_y).num = (yyvsp[-4].type_y).num;
 }
}
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 359 "compilateur.y" /* yacc.c:1646  */
    {
	(yyval.type_y).num = (yyvsp[-2].type_y).num;
	(yyval.type_y).yylstr2 = strdup((yyvsp[-2].type_y).yylstr2); 
}
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 365 "compilateur.y" /* yacc.c:1646  */
    {
 int ind;
 (yyval.type_y).yylstr2 = strdup((yyvsp[0].type_y).yylstr2);
 if((ind = var_exist((yyvsp[0].type_y).yylstr)) < 0)
 {
	 (yyval.type_y).num = compteur; 
	 fprintf(yyout, "mpc_t T%i;", compteur); 
	 fprintf(yyout, "mpc_init2(T%i, %s);\n", compteur, precision);
	 declaration((yyvsp[0].type_y).yylstr2);
	 fprintf(yyout, "(T%i,%s,%s);\n", compteur, (yyvsp[0].type_y).yylstr, rounding); 
	 compteur++;
 }
 else
	(yyval.type_y).num = ind;
}
#line 1830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 384 "compilateur.y" /* yacc.c:1646  */
    {(yyval.type_y).yylstr = strdup(yylval.type_y.yylstr); (yyval.type_y).yylstr2 = strdup("variable");}
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 385 "compilateur.y" /* yacc.c:1646  */
    {(yyval.type_y).yylstr = strdup(yylval.type_y.yylstr); (yyval.type_y).yylstr2 = strdup("entier");}
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 386 "compilateur.y" /* yacc.c:1646  */
    {(yyval.type_y).yylstr = strdup(yylval.type_y.yylstr); (yyval.type_y).yylstr2 = strdup("flottant");}
#line 1848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 394 "compilateur.y" /* yacc.c:1646  */
    {(yyval.type_y).yylstr = strdup(yylval.type_y.yylstr);}
#line 1854 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1858 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 403 "compilateur.y" /* yacc.c:1906  */


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