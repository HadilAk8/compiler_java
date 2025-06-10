
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "syn.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include<stdbool.h>
    #include <math.h>
    #include"ts.h"
    #include"quad.h" 
    int nb_ligne = 1;
    int Col = 1;
    char save_type[50]; 
     char nom_fonction[50]; 
    char typeAffTable[50];
    float taille, i, j, n; // Variables pour la gestion des tableaux et matrices
    char nom_variable[50]; 
    char type_retour_methode[50]; // Stocke le type de retour de la méthode courante
    char loop_var[100]; // Variable globale pour stocker le nom de la variable de boucle for
    char tmp_name[100] = "";         // Pour les noms de la var dans la condition while
    char tmp_compare_value[100] = "";  // Pour stocker la valeur de comparaison while
    char tmp_name_dowhile[100] = "";         // Pour les noms de la var dans la condition dowhile
    char tmp_compare_value_dowhile[100] = "";  // Pour stocker la valeur de comparaison dowhile
    char tmp [20] , tm[20];
    char tmp1 [20] , tmp2[20] , tmpb [20];
    int fin_if = 0 ,fin_ifelse = 0 , deb_else = 0 , deb_dowhile = 0 , deb_for = 0 , qnt = 0 , jump = 0;
    extern int qc;
    char* factor_names[100];
    int factor_index = 0;
    int boolc = -1 , t = 0; // 0 false 1 true 
    int qc_save[100];
    int qc_index = 0;
    int jump_save[100];
    int jump_index = 0;
    // Déclaration des tables de symboles
    SymbolTable* idfTable;
    SymbolTable* separatorTable;
    SymbolTable* keywordTable;
    int yylex();  
    void yyerror(const char *msg) {
        fprintf(stderr, "Erreur syntaxique à la ligne %d, colonne %d: %s\n", nb_ligne, Col, msg);
    }


/* Line 189 of yacc.c  */
#line 116 "syn.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     mc_int = 258,
     mc_float = 259,
     mc_boolean = 260,
     mc_double = 261,
     mc_return = 262,
     mc_out = 263,
     idf = 264,
     real = 265,
     integer = 266,
     chaine = 267,
     mc_char = 268,
     mc_class = 269,
     mc_print = 270,
     mc_system = 271,
     mc_void = 272,
     mc_do = 273,
     mc_while = 274,
     mc_for = 275,
     mc_if = 276,
     mc_else = 277,
     mc_switch = 278,
     mc_break = 279,
     mc_case = 280,
     mc_default = 281,
     mc_try = 282,
     mc_catch = 283,
     mc_finally = 284,
     mc_final = 285,
     mc_elseif = 286,
     mc_extends = 287,
     mc_public = 288,
     mc_private = 289,
     mc_protected = 290,
     mc_static = 291,
     logic = 292,
     mc_new = 293,
     mc_this = 294,
     mc_throws = 295,
     mc_exception = 296,
     mc_string = 297,
     mc_args = 298,
     mc_and = 299,
     mc_or = 300,
     mc_neq = 301,
     mc_eq = 302,
     mc_le = 303,
     mc_ge = 304,
     mc_arithmetic_exception = 305,
     mc_throw = 306,
     mc_println = 307
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 43 "syn.y"

    int entier;
    char *str;
    float reel;



/* Line 214 of yacc.c  */
#line 212 "syn.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 224 "syn.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   637

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  72
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  73
/* YYNRULES -- Number of rules.  */
#define YYNRULES  221
/* YYNRULES -- Number of states.  */
#define YYNSTATES  512

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,     2,     2,    61,     2,     2,
      65,    66,    59,    57,    70,    58,    67,    60,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    71,    64,
      55,    56,    54,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    68,     2,    69,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    62,     2,    63,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    11,    19,    20,    30,
      32,    33,    36,    38,    41,    43,    45,    47,    49,    56,
      63,    70,    71,    84,    85,    96,    97,   111,   112,   124,
     125,   134,   138,   141,   145,   149,   153,   158,   163,   168,
     174,   180,   186,   189,   191,   193,   196,   198,   200,   203,
     205,   207,   209,   215,   223,   230,   240,   252,   262,   274,
     278,   282,   289,   296,   303,   305,   307,   313,   317,   321,
     323,   327,   329,   337,   344,   354,   364,   368,   372,   376,
     380,   384,   388,   390,   392,   394,   396,   398,   400,   401,
     405,   409,   418,   423,   428,   432,   436,   440,   444,   448,
     452,   454,   458,   460,   461,   463,   465,   467,   469,   471,
     473,   475,   485,   487,   492,   498,   504,   508,   510,   511,
     515,   519,   523,   527,   531,   535,   539,   543,   547,   551,
     556,   561,   563,   569,   575,   580,   586,   591,   596,   604,
     607,   611,   616,   623,   631,   639,   647,   657,   666,   680,
     685,   690,   691,   693,   695,   697,   699,   701,   703,   708,
     712,   716,   722,   728,   732,   734,   738,   744,   748,   751,
     756,   761,   762,   764,   766,   768,   770,   774,   776,   780,
     782,   786,   790,   794,   798,   802,   806,   808,   812,   816,
     818,   822,   826,   830,   832,   834,   836,   838,   842,   845,
     848,   851,   854,   856,   858,   860,   862,   865,   868,   870,
     872,   875,   877,   878,   885,   889,   894,   897,   901,   905,
     912,   919
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      73,     0,    -1,    74,    -1,    75,    74,    -1,    75,    -1,
      -1,    78,    14,     9,    62,    76,    79,    63,    -1,    -1,
      78,    14,     9,    32,     9,    62,    77,    79,    63,    -1,
      33,    -1,    -1,    80,    79,    -1,    80,    -1,    87,    79,
      -1,    87,    -1,   127,    -1,    82,    -1,    81,    -1,    30,
     126,     9,    56,   140,    64,    -1,    30,   126,     9,    56,
      12,    64,    -1,    30,   126,     9,    56,    37,    64,    -1,
      -1,   126,     9,    65,    83,   129,    66,   141,    62,    91,
     139,    64,    63,    -1,    -1,    17,     9,    65,    84,   129,
      66,   141,    62,    91,    63,    -1,    -1,   138,   126,     9,
      65,    85,   129,    66,   141,    62,    91,   139,    64,    63,
      -1,    -1,   138,    17,     9,    65,    86,   129,    66,   141,
      62,    91,    63,    -1,    -1,     9,    65,   129,    66,    62,
      88,    89,    63,    -1,    90,    64,    89,    -1,    90,    64,
      -1,     9,    56,     9,    -1,     9,    56,   140,    -1,     9,
      56,    12,    -1,   126,     9,    56,     9,    -1,   126,     9,
      56,    12,    -1,   126,     9,    56,   140,    -1,    39,    67,
       9,    56,     9,    -1,    39,    67,     9,    56,    12,    -1,
      39,    67,     9,    56,   140,    -1,    92,    91,    -1,    92,
      -1,    99,    -1,   101,    64,    -1,   127,    -1,   103,    -1,
     142,    64,    -1,    98,    -1,    93,    -1,    81,    -1,   126,
      68,    69,     9,    64,    -1,   126,    68,    69,    68,    69,
       9,    64,    -1,     9,    56,    38,   126,    94,    64,    -1,
     126,    68,    69,     9,    56,    38,   126,    94,    64,    -1,
     126,    68,    69,    68,    69,     9,    56,    38,   126,    94,
      64,    -1,   126,    68,    69,     9,    56,    62,    95,    63,
      64,    -1,   126,    68,    69,    68,    69,     9,    56,    62,
      95,    63,    64,    -1,    68,    11,    69,    -1,    68,     9,
      69,    -1,    68,    11,    69,    68,    11,    69,    -1,    68,
       9,    69,    68,    11,    69,    -1,    68,     9,    69,    68,
       9,    69,    -1,    96,    -1,    97,    -1,    62,    97,    63,
      70,    96,    -1,    62,    97,    63,    -1,   140,    70,    97,
      -1,   140,    -1,    12,    70,    97,    -1,    12,    -1,    51,
      38,    50,    65,    12,    66,    64,    -1,    51,    38,    50,
      65,    66,    64,    -1,    16,    67,     8,    67,    15,    65,
     100,    66,    64,    -1,    16,    67,     8,    67,    52,    65,
     100,    66,    64,    -1,    12,    57,   100,    -1,     9,    57,
     100,    -1,    11,    57,   100,    -1,    10,    57,   100,    -1,
     142,    57,   100,    -1,   143,    57,   100,    -1,    12,    -1,
       9,    -1,    11,    -1,    10,    -1,   142,    -1,   143,    -1,
      -1,     9,    56,    12,    -1,     9,    56,   131,    -1,     9,
       9,    56,    38,     9,    65,   102,    66,    -1,     9,     9,
      56,   142,    -1,     9,    56,     9,   144,    -1,   143,    56,
     140,    -1,   143,    56,    12,    -1,     9,    57,    57,    -1,
     143,    56,     9,    -1,     9,    58,    58,    -1,   140,    70,
     102,    -1,   140,    -1,    12,    70,   102,    -1,    12,    -1,
      -1,   104,    -1,   116,    -1,   121,    -1,   124,    -1,   105,
      -1,   107,    -1,   114,    -1,   106,    62,    91,    63,    19,
      65,   130,    66,    64,    -1,    18,    -1,   108,    62,    91,
      63,    -1,   109,   112,    64,   113,    66,    -1,    20,    65,
     111,   110,    64,    -1,     9,    56,    11,    -1,   126,    -1,
      -1,     9,    55,     9,    -1,     9,    54,     9,    -1,     9,
      48,     9,    -1,     9,    49,     9,    -1,     9,    55,   140,
      -1,     9,    54,   140,    -1,     9,    48,   140,    -1,     9,
      49,   140,    -1,     9,    57,    57,    -1,     9,    58,    58,
      -1,   115,    62,    91,    63,    -1,    19,    65,   130,    66,
      -1,   119,    -1,   119,    22,    62,    91,    63,    -1,   117,
      22,    62,    91,    63,    -1,   118,    62,    91,    63,    -1,
     119,    31,    65,   130,    66,    -1,   120,    62,    91,    63,
      -1,    21,    65,   130,    66,    -1,    23,    65,     9,    66,
      62,   122,    63,    -1,   123,   122,    -1,    26,    71,    92,
      -1,    26,    62,    91,    63,    -1,    25,   140,    71,    92,
      24,    64,    -1,    25,   140,    62,    91,    63,    24,    64,
      -1,    25,    12,    71,    92,    24,    64,   122,    -1,    25,
      12,    62,    91,    63,    24,    64,    -1,    27,    62,    91,
      63,    28,   125,    62,    91,    63,    -1,    27,    62,    91,
      63,    29,    62,    91,    63,    -1,    27,    62,    91,    63,
      28,   125,    62,    91,    63,    29,    62,    91,    63,    -1,
      65,    41,     9,    66,    -1,    65,    50,     9,    66,    -1,
      -1,     3,    -1,     4,    -1,     5,    -1,     6,    -1,    13,
      -1,    42,    -1,   138,   126,   128,    64,    -1,   126,   128,
      64,    -1,     9,    70,   128,    -1,     9,    56,   140,    70,
     128,    -1,     9,    56,    12,    70,   128,    -1,     9,    56,
      12,    -1,     9,    -1,     9,    56,   131,    -1,     9,    56,
      37,    70,   128,    -1,     9,    56,    37,    -1,   126,     9,
      -1,    42,    68,    69,    43,    -1,   126,     9,    70,   129,
      -1,    -1,   131,    -1,   142,    -1,   132,    -1,   133,    -1,
     132,    45,   133,    -1,   134,    -1,   133,    44,   134,    -1,
     135,    -1,   135,    54,   135,    -1,   135,    55,   135,    -1,
     135,    49,   135,    -1,   135,    48,   135,    -1,   135,    46,
     135,    -1,   135,    47,   135,    -1,   136,    -1,   135,    57,
     136,    -1,   135,    58,   136,    -1,   137,    -1,   136,    59,
     137,    -1,   136,    60,   137,    -1,   136,    61,   137,    -1,
       9,    -1,   140,    -1,   142,    -1,    37,    -1,    65,   131,
      66,    -1,    53,   137,    -1,    34,    36,    -1,    35,    36,
      -1,    33,    36,    -1,    34,    -1,    35,    -1,    33,    -1,
      36,    -1,     7,    12,    -1,     7,   131,    -1,    10,    -1,
      11,    -1,    40,    41,    -1,    40,    -1,    -1,     9,    67,
       9,    65,   102,    66,    -1,     9,    67,     9,    -1,     9,
     144,    67,     9,    -1,     9,   144,    -1,    68,    11,    69,
      -1,    68,     9,    69,    -1,    68,    11,    69,    68,    11,
      69,    -1,    68,     9,    69,    68,    11,    69,    -1,    68,
       9,    69,    68,     9,    69,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    82,    82,    87,    87,    89,    89,   100,   100,   114,
     114,   116,   116,   116,   116,   118,   118,   118,   120,   137,
     151,   169,   169,   185,   185,   201,   201,   215,   215,   229,
     229,   240,   240,   242,   265,   287,   306,   335,   346,   358,
     384,   404,   427,   427,   429,   430,   431,   432,   433,   434,
     435,   436,   438,   447,   455,   469,   481,   493,   502,   511,
     516,   534,   542,   562,   584,   584,   586,   587,   589,   590,
     613,   614,   616,   617,   619,   620,   622,   623,   628,   629,
     630,   631,   632,   633,   638,   639,   640,   641,   642,   645,
     668,   693,   707,   717,   737,   749,   758,   773,   787,   803,
     804,   805,   806,   807,   809,   809,   809,   809,   811,   811,
     811,   813,   820,   822,   832,   833,   836,   850,   850,   852,
     862,   872,   882,   893,   904,   915,   926,   941,   955,   970,
     977,   988,   992,   996,  1001,  1007,  1012,  1018,  1023,  1032,
    1033,  1034,  1035,  1040,  1045,  1050,  1056,  1057,  1058,  1060,
    1060,  1060,  1062,  1062,  1062,  1062,  1062,  1062,  1064,  1065,
    1067,  1074,  1085,  1096,  1106,  1113,  1135,  1148,  1163,  1167,
    1168,  1172,  1173,  1173,  1175,  1177,  1178,  1188,  1189,  1199,
    1200,  1211,  1221,  1231,  1241,  1251,  1262,  1263,  1272,  1286,
    1287,  1298,  1314,  1331,  1354,  1360,  1361,  1362,  1363,  1365,
    1365,  1365,  1366,  1366,  1366,  1366,  1368,  1376,  1392,  1393,
    1395,  1395,  1395,  1397,  1408,  1416,  1425,  1433,  1440,  1461,
    1469,  1491
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "mc_int", "mc_float", "mc_boolean",
  "mc_double", "mc_return", "mc_out", "idf", "real", "integer", "chaine",
  "mc_char", "mc_class", "mc_print", "mc_system", "mc_void", "mc_do",
  "mc_while", "mc_for", "mc_if", "mc_else", "mc_switch", "mc_break",
  "mc_case", "mc_default", "mc_try", "mc_catch", "mc_finally", "mc_final",
  "mc_elseif", "mc_extends", "mc_public", "mc_private", "mc_protected",
  "mc_static", "logic", "mc_new", "mc_this", "mc_throws", "mc_exception",
  "mc_string", "mc_args", "mc_and", "mc_or", "mc_neq", "mc_eq", "mc_le",
  "mc_ge", "mc_arithmetic_exception", "mc_throw", "mc_println", "'!'",
  "'>'", "'<'", "'='", "'+'", "'-'", "'*'", "'/'", "'%'", "'{'", "'}'",
  "';'", "'('", "')'", "'.'", "'['", "']'", "','", "':'", "$accept", "S",
  "CLASSES", "CLASS", "$@1", "$@2", "PUBLIC", "MULTIBLOCKS", "BLOCKS",
  "CSTDEC", "METHODE", "$@3", "$@4", "$@5", "$@6", "CONSTRUCTOR", "$@7",
  "MULTISPDEC", "SPDEC", "MULTIINST", "INST", "TABLES", "INTMATRIX",
  "VALUES", "MULTIVALUE", "VALUE", "NEWTHROW", "OUTPUT", "MESSEGE", "AFF",
  "ARG", "FUN", "BOUCLE", "DOWHILE", "ADOWHILE", "FOR", "AFOR", "BFOR",
  "A", "FORTYPE", "CONDFOR", "INCDEC", "WHILE", "AWHILE", "CONDIF", "CiF",
  "DiF", "BiF", "AiF", "SWITCH", "CASE", "ACASE", "TRY", "EXPS", "TYPE",
  "DEC", "DECLARATION", "ARGUMENT", "EXPRESSIONS", "EXPRESSION",
  "LOGICAL_OR", "LOGICAL_AND", "RELATIONAL", "ADDITIVE", "TERM", "FACTOR",
  "MODIFIERS", "RETURN", "NUMB", "THROWS", "OBJFUN", "AFFTABLE",
  "DINTMATRIX", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,    33,    62,    60,    61,    43,    45,    42,
      47,    37,   123,   125,    59,    40,    41,    46,    91,    93,
      44,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    72,    73,    74,    74,    76,    75,    77,    75,    78,
      78,    79,    79,    79,    79,    80,    80,    80,    81,    81,
      81,    83,    82,    84,    82,    85,    82,    86,    82,    88,
      87,    89,    89,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    91,    91,    92,    92,    92,    92,    92,    92,
      92,    92,    93,    93,    93,    93,    93,    93,    93,    94,
      94,    94,    94,    94,    95,    95,    96,    96,    97,    97,
      97,    97,    98,    98,    99,    99,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   102,
     102,   102,   102,   102,   103,   103,   103,   103,   104,   104,
     104,   105,   106,   107,   108,   109,   110,   111,   111,   112,
     112,   112,   112,   112,   112,   112,   112,   113,   113,   114,
     115,   116,   116,   116,   117,   118,   119,   120,   121,   122,
     122,   122,   123,   123,   123,   123,   124,   124,   124,   125,
     125,   125,   126,   126,   126,   126,   126,   126,   127,   127,
     128,   128,   128,   128,   128,   128,   128,   128,   129,   129,
     129,   129,   130,   130,   131,   132,   132,   133,   133,   134,
     134,   134,   134,   134,   134,   134,   135,   135,   135,   136,
     136,   136,   136,   137,   137,   137,   137,   137,   137,   138,
     138,   138,   138,   138,   138,   138,   139,   139,   140,   140,
     141,   141,   141,   142,   142,   142,   143,   144,   144,   144,
     144,   144
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     0,     7,     0,     9,     1,
       0,     2,     1,     2,     1,     1,     1,     1,     6,     6,
       6,     0,    12,     0,    10,     0,    13,     0,    11,     0,
       8,     3,     2,     3,     3,     3,     4,     4,     4,     5,
       5,     5,     2,     1,     1,     2,     1,     1,     2,     1,
       1,     1,     5,     7,     6,     9,    11,     9,    11,     3,
       3,     6,     6,     6,     1,     1,     5,     3,     3,     1,
       3,     1,     7,     6,     9,     9,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     0,     3,
       3,     8,     4,     4,     3,     3,     3,     3,     3,     3,
       1,     3,     1,     0,     1,     1,     1,     1,     1,     1,
       1,     9,     1,     4,     5,     5,     3,     1,     0,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     4,
       4,     1,     5,     5,     4,     5,     4,     4,     7,     2,
       3,     4,     6,     7,     7,     7,     9,     8,    13,     4,
       4,     0,     1,     1,     1,     1,     1,     1,     4,     3,
       3,     5,     5,     3,     1,     3,     5,     3,     2,     4,
       4,     0,     1,     1,     1,     1,     3,     1,     3,     1,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     1,     1,     1,     3,     2,     2,
       2,     2,     1,     1,     1,     1,     2,     2,     1,     1,
       2,     1,     0,     6,     3,     4,     2,     3,     3,     6,
       6,     6
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      10,     9,     0,     2,     4,     0,     1,     3,     0,     0,
       0,     5,     0,     0,     7,   152,   153,   154,   155,     0,
     156,     0,     0,   204,   202,   203,   205,   157,     0,    12,
      17,    16,    14,     0,    15,     0,     0,   171,     0,     0,
     201,   199,   200,     6,    11,    13,   164,     0,     0,     0,
       0,   157,     0,     0,    23,     0,     0,    21,     0,   159,
       0,   164,     0,     8,     0,   168,     0,   171,     0,   193,
     208,   209,   163,   196,     0,     0,   165,   174,   175,   177,
     179,   186,   189,   194,   195,   171,   164,   160,    27,    25,
     158,     0,   171,    29,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   196,   198,   194,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   171,   171,   169,   170,     0,   212,    19,    20,
      18,   214,     0,     0,     0,   162,   166,   197,   176,   178,
     184,   185,   183,   182,   180,   181,   187,   188,   190,   191,
     192,   161,   212,     0,     0,     0,     0,     0,     0,     0,
     211,     0,   103,   218,   217,   215,     0,   212,   212,     0,
       0,    30,    32,     0,   210,     0,   102,     0,   100,     0,
       0,     0,     0,     0,    33,    35,    34,     0,    31,     0,
       0,     0,   112,     0,     0,     0,     0,     0,     0,    51,
       0,    43,    50,    49,    44,     0,    47,   104,   108,     0,
     109,     0,     0,   110,     0,   105,     0,     0,   131,     0,
     106,   107,     0,    46,     0,     0,     0,   103,   213,   103,
       0,     0,     0,     0,     0,     0,     0,    36,    37,    38,
       0,     0,     0,     0,   216,     0,     0,   118,     0,     0,
       0,     0,    24,    42,    45,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,     0,   101,
      99,   221,   220,   219,     0,     0,     0,     0,    39,    40,
      41,     0,   193,    89,     0,    90,    96,    98,     0,     0,
     172,   195,     0,   117,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    97,    95,    94,   206,   207,     0,    28,     0,
       0,     0,    92,    93,     0,     0,   130,     0,     0,   137,
       0,     0,     0,     0,   113,   121,   125,   122,   126,   120,
     124,   119,   123,     0,     0,   129,     0,   134,     0,     0,
     136,     0,     0,    22,     0,     0,     0,     0,     0,     0,
       0,   115,     0,   151,     0,     0,     0,     0,     0,     0,
     114,   133,   132,   135,     0,    52,     0,    26,   103,     0,
       0,    54,    88,    88,   116,     0,     0,     0,     0,     0,
       0,     0,     0,    73,     0,   127,   128,     0,     0,     0,
       0,    60,    59,    83,    85,    84,    82,     0,    86,    87,
       0,     0,     0,     0,     0,   138,   139,     0,     0,     0,
       0,    72,     0,     0,    71,     0,     0,    64,    65,    69,
       0,    53,    91,     0,     0,    88,    88,    88,    88,     0,
      88,    88,     0,     0,     0,     0,     0,     0,   140,     0,
       0,     0,   147,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    77,    79,    78,    76,    74,    80,
      81,    75,     0,     0,     0,     0,   141,   149,   150,   146,
     111,    55,    70,    67,    57,    68,     0,     0,    63,    62,
      61,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   142,     0,    66,    56,    58,   145,   144,   143,
       0,   148
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    13,    36,     5,    28,    29,   199,
      31,    85,    67,   123,   122,    32,   126,   157,   158,   200,
     201,   202,   357,   426,   427,   428,   203,   204,   407,   205,
     177,   206,   207,   208,   209,   210,   211,   212,   328,   292,
     258,   344,   213,   214,   215,   216,   217,   218,   219,   220,
     387,   388,   221,   390,   222,   223,    47,    53,   289,   290,
      77,    78,    79,    80,    81,    82,   224,   275,   105,   161,
     225,   226,   100
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -412
static const yytype_int16 yypact[] =
{
      24,  -412,    29,  -412,    66,    87,  -412,  -412,   142,   -17,
     148,  -412,    50,   322,  -412,  -412,  -412,  -412,  -412,   108,
    -412,   173,   311,   154,   183,   193,  -412,  -412,   123,   322,
    -412,  -412,   322,   195,  -412,   295,   322,   356,   191,   250,
    -412,  -412,  -412,  -412,  -412,  -412,    46,   198,   258,   268,
     209,   229,   298,   247,  -412,   266,   115,  -412,   320,  -412,
     267,    73,   272,  -412,   271,   274,   276,   356,   204,   102,
    -412,  -412,   280,    27,   168,   168,  -412,   296,   307,  -412,
     319,   163,  -412,   284,  -412,   356,   -29,  -412,  -412,  -412,
    -412,   328,   356,  -412,   297,   308,   321,   326,   366,   106,
     330,   320,   320,  -412,  -412,  -412,   333,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     320,   335,   356,   356,  -412,  -412,   197,   362,  -412,  -412,
    -412,   339,   363,   364,   422,  -412,  -412,  -412,   307,  -412,
     150,   150,   150,   150,   150,   150,   163,   163,  -412,  -412,
    -412,  -412,   362,   368,   369,   380,   370,   375,   376,   430,
     401,   379,   400,   377,   381,  -412,   382,   362,   362,   294,
     434,  -412,   197,   391,  -412,   260,   378,   385,   383,   240,
     439,   260,   390,   392,  -412,  -412,  -412,   399,  -412,   309,
      25,   389,  -412,   393,   394,   395,   396,   402,   419,  -412,
     403,   260,  -412,  -412,  -412,   398,  -412,  -412,  -412,   405,
    -412,   406,   454,  -412,   408,  -412,   443,   409,    97,   411,
    -412,  -412,     8,  -412,   311,   412,   416,   400,  -412,   400,
     414,   417,   420,   462,   260,   260,   337,  -412,  -412,  -412,
     421,   111,   423,   424,   330,   466,   168,   311,   168,   469,
     260,   425,  -412,  -412,  -412,   260,   260,   237,   426,   260,
     429,   260,   431,   427,   260,   428,   320,  -412,   384,  -412,
    -412,  -412,  -412,  -412,   130,   432,   435,   462,  -412,  -412,
    -412,     9,   102,  -412,   311,  -412,  -412,  -412,   433,   436,
    -412,   437,   470,  -412,   438,   440,   442,   444,   445,   447,
     404,   407,   410,   413,   472,   448,   260,   449,   260,   168,
     450,    19,  -412,  -412,  -412,  -412,  -412,   451,  -412,   452,
     102,   475,  -412,   330,   453,    -4,  -412,   459,   455,  -412,
     456,   214,    18,   468,  -412,  -412,  -412,  -412,  -412,  -412,
    -412,  -412,  -412,   217,   441,  -412,   457,  -412,   460,   458,
    -412,   -21,   461,  -412,   463,   464,   244,   467,   471,   473,
     474,  -412,   263,   476,   465,   477,   478,   479,   480,   481,
    -412,  -412,  -412,  -412,    -7,  -412,   485,  -412,   400,   482,
     483,  -412,   397,   397,  -412,   415,    75,   484,   263,   103,
     486,   260,   489,  -412,   168,  -412,  -412,   311,    26,    94,
     488,   487,   490,   -18,   492,   493,   499,   491,   502,   503,
     495,   122,   147,   260,   260,  -412,  -412,   508,   513,   260,
     500,  -412,   496,   453,   494,   418,   504,  -412,  -412,   498,
      -6,  -412,  -412,   259,   514,   397,   397,   397,   397,   501,
     397,   397,   505,   260,   260,   260,   260,   507,  -412,   506,
     509,   510,  -412,   512,   515,   418,   511,   516,   418,   311,
      26,   497,   517,   518,  -412,  -412,  -412,  -412,  -412,  -412,
    -412,  -412,   519,   521,   520,   522,  -412,  -412,  -412,   542,
    -412,  -412,  -412,   523,  -412,  -412,   453,   525,  -412,  -412,
    -412,   553,   526,   554,   527,   530,   532,   531,   533,   534,
     263,   535,  -412,   260,  -412,  -412,  -412,  -412,  -412,  -412,
     537,  -412
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -412,  -412,   524,  -412,  -412,  -412,  -412,   208,  -412,   162,
    -412,  -412,  -412,  -412,  -412,  -412,  -412,   316,  -412,  -161,
    -400,  -412,  -411,    35,     3,  -270,  -412,  -412,  -275,  -412,
    -224,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,
    -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,
    -382,  -412,  -412,  -412,   -13,   199,   -16,   104,  -238,   -54,
    -412,   528,   529,   269,   194,   -66,   225,   224,   -55,   -62,
     -49,  -305,  -186
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -174
static const yytype_int16 yytable[] =
{
      33,    83,    76,   269,   244,   270,   416,    84,   104,    39,
     294,   358,   454,    97,   448,    10,    33,    86,   320,    33,
     233,   106,    49,    33,    52,    84,    84,    56,   351,     6,
     365,   397,   459,    62,   240,   374,    70,    71,   424,   435,
     253,    58,    87,   375,   473,    11,   475,   321,   359,    98,
      99,   148,   149,   150,    52,   398,   460,     1,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,   349,    52,   276,   277,   497,   265,   409,   409,    52,
     -10,   241,   242,   243,   366,   135,   136,   352,   425,   296,
     166,  -167,    98,    99,   298,   299,   323,   102,   305,     1,
     307,     8,    56,   310,   151,   182,   183,   178,   410,    52,
      52,    57,    14,   159,   186,   132,    58,   133,   508,   262,
     282,    70,    71,   283,    69,    70,    71,    72,   263,    56,
     409,   409,   409,   409,   239,   409,   409,   413,    89,    69,
      70,    71,   315,    58,   417,   346,   414,   348,   103,   284,
     430,     9,    73,   418,   400,   456,   422,    12,   431,   159,
     464,   465,   466,   467,    74,   469,   470,   103,    74,    98,
      99,    94,   178,    37,   178,    30,    75,    69,    70,    71,
      75,   280,    38,    74,   443,   482,    43,   285,   485,   121,
      40,    30,    84,   444,    30,    75,   125,   291,    30,   291,
      15,    16,    17,    18,    46,   103,   155,   115,   116,   445,
      20,   266,    34,   314,    70,    71,    95,   244,   446,    41,
     316,    74,   117,   118,   119,    84,   153,   154,    34,    42,
     420,    34,   322,    75,   293,    34,   156,    44,    35,    27,
      45,    96,   363,   364,    50,   336,   338,   340,   342,   230,
      62,   231,   447,   379,    35,   380,    54,    35,   451,    55,
     291,    35,    59,    15,    16,    17,    18,    60,   461,   190,
     462,   324,    63,    20,   368,   369,   191,    61,   192,   193,
     194,   195,   472,   196,   474,   300,   301,   197,   385,   386,
      22,   302,   303,    23,    24,    25,    26,    64,    15,    16,
      17,    18,    27,   184,    70,    71,   185,    65,    20,   146,
     147,   198,    48,    66,    15,    16,    17,    18,   237,    70,
      71,   238,    68,   178,    20,    15,    16,    17,    18,    86,
     412,    19,    88,   408,   408,    20,    90,    27,    93,    21,
      91,   107,   510,   429,    92,   291,   278,    70,    71,   279,
     101,   108,    22,    27,   120,    23,    24,    25,    26,    15,
      16,    17,    18,   127,    27,   109,   110,   111,   112,    20,
     429,   124,   128,   113,   114,   131,   115,   116,   140,   141,
     142,   143,   144,   145,   423,   129,   408,   408,   408,   408,
     130,   408,   408,   312,    70,    71,   313,   134,    51,   137,
     429,   152,   160,   429,   162,   429,   403,   404,   405,   406,
      70,    71,   176,   335,    70,    71,   337,    70,    71,   339,
      70,    71,   341,    70,    71,    70,    71,   411,    70,    71,
     424,   165,   163,   164,   167,   168,   169,   170,   171,   173,
     172,   175,   174,   187,   181,   179,   486,   189,   227,   180,
     232,   228,   234,   229,   235,   236,   245,   251,   246,   247,
     248,   249,   254,   257,   250,   260,   252,   255,   256,   274,
     259,   261,   268,   264,   288,   297,   267,   281,   295,   327,
     286,   343,   287,   271,   355,   384,   272,   367,   188,   273,
     304,   306,   309,   308,   399,   487,   317,   311,   318,   504,
     325,   319,   326,  -173,   329,   331,   330,   370,   333,   332,
     334,   345,   347,   350,   353,   360,   354,   449,   362,   361,
     371,   356,   450,   372,   373,   463,   377,   391,     7,   378,
     376,   381,     0,     0,     0,     0,   382,   395,   383,   396,
       0,   389,   393,   392,   394,   492,   494,   415,   419,   436,
     437,   401,   402,   421,   432,   433,   438,   439,   434,   440,
     441,   442,   453,   452,   455,   468,   488,   457,   458,   471,
     476,   495,   477,   479,   483,   478,   480,   499,   501,   481,
     484,     0,   491,   493,     0,     0,   489,   490,   498,     0,
     500,   502,   503,   496,   425,   505,     0,   506,   507,   509,
     511,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   138,     0,   139
};

static const yytype_int16 yycheck[] =
{
      13,    56,    56,   227,   190,   229,   388,    56,    74,    22,
     248,    15,   423,    68,   414,    32,    29,     9,     9,    32,
     181,    75,    35,    36,    37,    74,    75,    56,     9,     0,
      12,    38,    38,    49,     9,    56,    10,    11,    12,    57,
     201,    70,    58,    64,   444,    62,   446,    38,    52,    67,
      68,   117,   118,   119,    67,    62,    62,    33,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   309,    85,   234,   235,   486,    68,   382,   383,    92,
      14,    56,    57,    58,    66,   101,   102,    68,    62,   250,
     152,    64,    67,    68,   255,   256,   282,    70,   259,    33,
     261,    14,    56,   264,   120,   167,   168,   162,   383,   122,
     123,    65,    62,   126,   169,     9,    70,    11,   500,    22,
       9,    10,    11,    12,     9,    10,    11,    12,    31,    56,
     435,   436,   437,   438,   189,   440,   441,    62,    65,     9,
      10,    11,    12,    70,    41,   306,    71,   308,    37,    38,
      56,     9,    37,    50,   378,   425,   394,     9,    64,   172,
     435,   436,   437,   438,    53,   440,   441,    37,    53,    67,
      68,    67,   227,    65,   229,    13,    65,     9,    10,    11,
      65,   236,     9,    53,    62,   455,    63,   241,   458,    85,
      36,    29,   241,    71,    32,    65,    92,   246,    36,   248,
       3,     4,     5,     6,     9,    37,     9,    57,    58,    62,
      13,   224,    13,   268,    10,    11,    12,   403,    71,    36,
     274,    53,    59,    60,    61,   274,   122,   123,    29,    36,
     391,    32,   281,    65,   247,    36,    39,    29,    13,    42,
      32,    37,    28,    29,    36,   300,   301,   302,   303,     9,
     266,    11,   413,     9,    29,    11,    65,    32,   419,     9,
     309,    36,    64,     3,     4,     5,     6,     9,     9,     9,
      11,   284,    63,    13,    57,    58,    16,     9,    18,    19,
      20,    21,   443,    23,   445,    48,    49,    27,    25,    26,
      30,    54,    55,    33,    34,    35,    36,    68,     3,     4,
       5,     6,    42,     9,    10,    11,    12,     9,    13,   115,
     116,    51,    17,    66,     3,     4,     5,     6,     9,    10,
      11,    12,    56,   378,    13,     3,     4,     5,     6,     9,
     385,     9,    65,   382,   383,    13,    64,    42,    62,    17,
      69,    45,   503,   398,    70,   394,     9,    10,    11,    12,
      70,    44,    30,    42,    70,    33,    34,    35,    36,     3,
       4,     5,     6,    66,    42,    46,    47,    48,    49,    13,
     425,    43,    64,    54,    55,     9,    57,    58,   109,   110,
     111,   112,   113,   114,   397,    64,   435,   436,   437,   438,
      64,   440,   441,     9,    10,    11,    12,    67,    42,    66,
     455,    66,    40,   458,    65,   460,     9,    10,    11,    12,
      10,    11,    12,     9,    10,    11,     9,    10,    11,     9,
      10,    11,     9,    10,    11,    10,    11,    12,    10,    11,
      12,     9,    69,    69,    66,    66,    56,    67,    63,     9,
      64,    62,    41,     9,    62,    68,   459,    56,    70,    68,
      11,    66,    62,    70,    62,    56,    67,    38,    65,    65,
      65,    65,    64,     9,    62,    22,    63,    62,    62,     7,
      62,    62,    56,    62,     8,    50,    64,    56,     9,     9,
      57,     9,    58,    69,     9,    11,    69,    19,   172,    69,
      64,    62,    65,    62,     9,   460,    64,    69,    63,   496,
      67,   277,    66,    66,    66,    63,    66,    66,    63,    65,
      63,    63,    63,    63,    63,    56,    64,     9,    62,    64,
      63,    68,     9,    63,    66,    11,    63,    62,     4,    65,
      69,    64,    -1,    -1,    -1,    -1,    65,    57,    65,    58,
      -1,    65,    64,    66,    65,    24,    24,    63,    62,    57,
      57,    69,    69,    64,    66,    68,    57,    66,    68,    57,
      57,    66,    66,    63,    70,    64,    69,    63,    70,    64,
      63,    29,    66,    63,    63,    66,    64,    24,    24,    64,
      64,    -1,    63,    63,    -1,    -1,    69,    69,    63,    -1,
      64,    64,    62,    70,    62,    64,    -1,    64,    64,    64,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   107,    -1,   108
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    33,    73,    74,    75,    78,     0,    74,    14,     9,
      32,    62,     9,    76,    62,     3,     4,     5,     6,     9,
      13,    17,    30,    33,    34,    35,    36,    42,    79,    80,
      81,    82,    87,   126,   127,   138,    77,    65,     9,   126,
      36,    36,    36,    63,    79,    79,     9,   128,    17,   126,
      79,    42,   126,   129,    65,     9,    56,    65,    70,    64,
       9,     9,   128,    63,    68,     9,    66,    84,    56,     9,
      10,    11,    12,    37,    53,    65,   131,   132,   133,   134,
     135,   136,   137,   140,   142,    83,     9,   128,    65,    65,
      64,    69,    70,    62,   129,    12,    37,   140,    67,    68,
     144,    70,    70,    37,   137,   140,   131,    45,    44,    46,
      47,    48,    49,    54,    55,    57,    58,    59,    60,    61,
      70,   129,    86,    85,    43,   129,    88,    66,    64,    64,
      64,     9,     9,    11,    67,   128,   128,    66,   133,   134,
     135,   135,   135,   135,   135,   135,   136,   136,   137,   137,
     137,   128,    66,   129,   129,     9,    39,    89,    90,   126,
      40,   141,    65,    69,    69,     9,   141,    66,    66,    56,
      67,    63,    64,     9,    41,    62,    12,   102,   140,    68,
      68,    62,   141,   141,     9,    12,   140,     9,    89,    56,
       9,    16,    18,    19,    20,    21,    23,    27,    51,    81,
      91,    92,    93,    98,    99,   101,   103,   104,   105,   106,
     107,   108,   109,   114,   115,   116,   117,   118,   119,   120,
     121,   124,   126,   127,   138,   142,   143,    70,    66,    70,
       9,    11,    11,    91,    62,    62,    56,     9,    12,   140,
       9,    56,    57,    58,   144,    67,    65,    65,    65,    65,
      62,    38,    63,    91,    64,    62,    62,     9,   112,    62,
      22,    62,    22,    31,    62,    68,   126,    64,    56,   102,
     102,    69,    69,    69,     7,   139,    91,    91,     9,    12,
     140,    56,     9,    12,    38,   131,    57,    58,     8,   130,
     131,   142,   111,   126,   130,     9,    91,    50,    91,    91,
      48,    49,    54,    55,    64,    91,    62,    91,    62,    65,
      91,    69,     9,    12,   140,    12,   131,    64,    63,   139,
       9,    38,   142,   144,   126,    67,    66,     9,   110,    66,
      66,    63,    65,    63,    63,     9,   140,     9,   140,     9,
     140,     9,   140,     9,   113,    63,    91,    63,    91,   130,
      63,     9,    68,    63,    64,     9,    68,    94,    15,    52,
      56,    64,    62,    28,    29,    12,    66,    19,    57,    58,
      66,    63,    63,    66,    56,    64,    69,    63,    65,     9,
      11,    64,    65,    65,    11,    25,    26,   122,   123,    65,
     125,    62,    66,    64,    65,    57,    58,    38,    62,     9,
     102,    69,    69,     9,    10,    11,    12,   100,   142,   143,
     100,    12,   140,    62,    71,    63,   122,    41,    50,    62,
      91,    64,   130,   126,    12,    62,    95,    96,    97,   140,
      56,    64,    66,    68,    68,    57,    57,    57,    57,    66,
      57,    57,    66,    62,    71,    62,    71,    91,    92,     9,
       9,    91,    63,    66,    94,    70,    97,    63,    70,    38,
      62,     9,    11,    11,   100,   100,   100,   100,    64,   100,
     100,    64,    91,    92,    91,    92,    63,    66,    66,    63,
      64,    64,    97,    63,    64,    97,   126,    95,    69,    69,
      69,    63,    24,    63,    24,    29,    70,    94,    63,    24,
      64,    24,    64,    62,    96,    64,    64,    64,   122,    64,
      91,    63
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 82 "syn.y"
    {
        printf("Syntaxe correcte\n");
        YYACCEPT;
    ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 89 "syn.y"
    {
            if (estDeclare(idfTable, (yyvsp[(3) - (4)].str))) {
                printf("Erreur sémantique : Double déclaration de la classe '%s' (ligne %d, colonne %d)\n", (yyvsp[(3) - (4)].str), nb_ligne, Col);
            } else {
                insertComplex(idfTable, (yyvsp[(3) - (4)].str), "IDF", "class", 0.0);
                pushScope((yyvsp[(3) - (4)].str)); // Empiler la portée de la classe
            }
        ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 96 "syn.y"
    {
            popScope(); // Sortie de la portée de la classe
        ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 100 "syn.y"
    {
            if (estDeclare(idfTable, (yyvsp[(3) - (6)].str))) {
                printf("Erreur sémantique : Double déclaration de la classe '%s' (ligne %d, colonne %d)\n", (yyvsp[(3) - (6)].str), nb_ligne, Col);
            } else {
                insertComplex(idfTable, (yyvsp[(3) - (6)].str), "IDF", "class", 0.0);
                pushScope((yyvsp[(3) - (6)].str));
            }
            if (!estDeclare(idfTable, (yyvsp[(5) - (6)].str))) {
                printf("Erreur sémantique : La classe parent '%s' n'est pas déclarée (ligne %d, colonne %d)\n", (yyvsp[(5) - (6)].str), nb_ligne, Col);
            }
        ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 110 "syn.y"
    {
            popScope();
        ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 120 "syn.y"
    {
        if (estDeclareDansaportee(idfTable, (yyvsp[(3) - (6)].str))) {
            printf("Erreur : Double déclaration de la constante '%s' (ligne %d, colonne %d)\n", (yyvsp[(3) - (6)].str), nb_ligne, Col);
        } else {
            if (strcmp(save_type, "int") != 0 && strcmp(save_type, "float") != 0 && strcmp(save_type, "double") != 0) {
                printf("Erreur : Incompatibilité de type pour '%s' (attendu %s, reçu nombre) (ligne %d, colonne %d)\n", 
                       (yyvsp[(3) - (6)].str), save_type, nb_ligne, Col);
            } else {
                insertComplex(idfTable, (yyvsp[(3) - (6)].str), "CST", save_type, 0.0);
                float valeur = (yyvsp[(5) - (6)].reel);
                maj_valeur(idfTable, (yyvsp[(3) - (6)].str), &valeur);
                sprintf(tmp, "%f", (yyvsp[(5) - (6)].reel));
                quadr("=", tmp, "vide", (yyvsp[(3) - (6)].str));
                   }
                }
        ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 137 "syn.y"
    {
        if (estDeclareDansaportee(idfTable, (yyvsp[(3) - (6)].str))) {
            printf("Erreur : Double déclaration de la constante '%s' (ligne %d, colonne %d)\n", (yyvsp[(3) - (6)].str), nb_ligne, Col);
        } else {
            if (strcmp(save_type, "String") != 0) {
                printf("Erreur : Incompatibilité de type pour '%s' (attendu %s, reçu chaîne) (ligne %d, colonne %d)\n", 
                       (yyvsp[(3) - (6)].str), save_type, nb_ligne, Col);
            } else {
                insertComplex(idfTable, (yyvsp[(3) - (6)].str), "CST", save_type, 0.0);
                quadr("=", (yyvsp[(5) - (6)].str), "vide", (yyvsp[(3) - (6)].str));
            }
        }
    ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 151 "syn.y"
    {
        if (estDeclareDansaportee(idfTable, (yyvsp[(3) - (6)].str))) {
            printf("Erreur : Double déclaration de la constante '%s' (ligne %d, colonne %d)\n", (yyvsp[(3) - (6)].str), nb_ligne, Col);
        } else {
            if (strcmp(save_type, "boolean") != 0 && strcmp(save_type, "int") != 0) {
                printf("Erreur : Incompatibilité de type pour '%s' (attendu %s, reçu booléen) (ligne %d, colonne %d)\n", 
                       (yyvsp[(3) - (6)].str), save_type, nb_ligne, Col);
            } else {
                insertComplex(idfTable, (yyvsp[(3) - (6)].str), "CST", save_type, 0.0);
                float valeur = (strcmp((yyvsp[(5) - (6)].str), "true") == 0) ? 1.0 : 0.0;
                maj_valeur(idfTable, (yyvsp[(3) - (6)].str), &valeur);
                quadr("=", (valeur == 1.0) ? "true" : "false", "vide", (yyvsp[(3) - (6)].str));
            }
        }
    ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 169 "syn.y"
    {
    if (estDeclareDansaportee(idfTable, (yyvsp[(2) - (3)].str))) {
        printf("Erreur : Double déclaration de la méthode '%s' (ligne %d, colonne %d)\n", (yyvsp[(2) - (3)].str), nb_ligne, Col);
    } else {
        strcpy(type_retour_methode, (yyvsp[(1) - (3)].str));
        strcpy(nom_fonction, (yyvsp[(2) - (3)].str)); // <<< ici on stocke le nom de la méthode
        insertComplex(idfTable, (yyvsp[(2) - (3)].str), "METH", type_retour_methode, 0.0);
        pushScope((yyvsp[(2) - (3)].str));
        printf("[DEBUG] Pushing scope : %s (ligne %d)\n", (yyvsp[(2) - (3)].str), nb_ligne);
    }
;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 179 "syn.y"
    {
    printf("[DEBUG] Popping scope : %s (ligne %d)\n", (yyvsp[(2) - (12)].str), nb_ligne);
    popScope();
;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 185 "syn.y"
    {
    if (estDeclareDansaportee(idfTable, (yyvsp[(2) - (3)].str))) {
        printf("Erreur : Double déclaration de la méthode '%s' (ligne %d, colonne %d)\n", (yyvsp[(2) - (3)].str), nb_ligne, Col);
    } else {
        strcpy(type_retour_methode, "void");  // Sauvegarde du type de retour "void"
        insertComplex(idfTable, (yyvsp[(2) - (3)].str), "METH", "void", 0.0);
        pushScope((yyvsp[(2) - (3)].str));  // 🔹 Empiler la portée AVANT d'ajouter les arguments
        printf("[DEBUG] Pushing scope : %s (ligne %d)\n", (yyvsp[(2) - (3)].str), nb_ligne);
    }
;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 194 "syn.y"
    {  // Pas de RETURN pour void
    printf("[DEBUG] Popping scope : %s (ligne %d)\n", (yyvsp[(2) - (10)].str), nb_ligne);
    popScope();
;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 201 "syn.y"
    {
    if (estDeclareDansaportee(idfTable, (yyvsp[(3) - (4)].str))) {
        printf("Erreur : Double déclaration de la méthode '%s' (ligne %d, colonne %d)\n", (yyvsp[(3) - (4)].str), nb_ligne, Col);
    } else {
        strcpy(type_retour_methode, (yyvsp[(2) - (4)].str));  // Sauvegarde du type de retour
        insertComplex(idfTable, (yyvsp[(3) - (4)].str), "METH", type_retour_methode, 0.0);
        pushScope((yyvsp[(3) - (4)].str));  // Empilage AVANT d'insérer les arguments
        printf("[DEBUG] Pushing scope : %s (ligne %d)\n", (yyvsp[(3) - (4)].str), nb_ligne);
    }
;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 210 "syn.y"
    {
    printf("[DEBUG] Popping scope : %s (ligne %d)\n", (yyvsp[(3) - (13)].str), nb_ligne);
    popScope();
;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 215 "syn.y"
    {
    if (estDeclareDansaportee(idfTable, (yyvsp[(3) - (4)].str))) {
        printf("Erreur : Double déclaration de la méthode '%s' (ligne %d, colonne %d)\n", (yyvsp[(3) - (4)].str), nb_ligne, Col);
    } else {
        strcpy(type_retour_methode, "void");
        insertComplex(idfTable, (yyvsp[(3) - (4)].str), "METH", "void", 0.0);
        pushScope((yyvsp[(3) - (4)].str));  //  Empiler la portée AVANT d'ajouter les arguments
        printf("[DEBUG] Pushing scope : %s (ligne %d)\n", (yyvsp[(3) - (4)].str), nb_ligne);
    }
;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 224 "syn.y"
    {  // Pas de RETURN pour void
    printf("[DEBUG] Popping scope : %s (ligne %d)\n", (yyvsp[(3) - (11)].str), nb_ligne);
    popScope();
;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 229 "syn.y"
    {
        if (strcmp((yyvsp[(1) - (5)].str), getCurrentScope()) != 0) {
            printf("Erreur sémantique : Le constructeur '%s' ne correspond pas au nom de la classe '%s' (ligne %d, colonne %d)\n",
                   (yyvsp[(1) - (5)].str), getCurrentScope(), nb_ligne, Col);
        }
        pushScope((yyvsp[(1) - (5)].str)); // Entrée dans la portée du constructeur
    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 235 "syn.y"
    {
        popScope(); // Sortie de la portée du constructeur
    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 242 "syn.y"
    {
        float val;
        char type1[50], type2[50];

        if (estDeclareDansaportee(idfTable, (yyvsp[(3) - (3)].str))) {
            printf("Erreur : Variable '%s' utilisée mais non déclarée (ligne %d, colonne %d)\n", (yyvsp[(3) - (3)].str), nb_ligne, Col);
        } else {
            // Vérification si $1 est une constante
            if (strcmp(get_codeentite(idfTable, (yyvsp[(1) - (3)].str)), "CST") == 0) {
                printf("Erreur : Tentative de modification de la constante '%s' (ligne %d, colonne %d)\n", (yyvsp[(1) - (3)].str), nb_ligne, Col);
            } else {
                strcpy(type1, get_type(idfTable, (yyvsp[(1) - (3)].str)));
                strcpy(type2, get_type(idfTable, (yyvsp[(3) - (3)].str)));

                if (strcmp(type1, type2) != 0) {
                    printf("Erreur sémantique : Incompatibilité de type entre '%s' et '%s' (ligne %d, colonne %d)\n", type1, type2, nb_ligne, Col);
                }
                get_val(idfTable, (yyvsp[(3) - (3)].str), &val);
                maj_valeur(idfTable, (yyvsp[(1) - (3)].str), &val);
            }
        }
        quadr("=",(yyvsp[(3) - (3)].str),"vide",(yyvsp[(1) - (3)].str));
    ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 265 "syn.y"
    {
        float val = (float)(yyvsp[(3) - (3)].reel);
        char type1[50];

        if (!estDeclareDansaportee(idfTable, (yyvsp[(1) - (3)].str))) {
            printf("Erreur : Variable '%s' utilisée mais non déclarée (ligne %d, colonne %d)\n", (yyvsp[(1) - (3)].str), nb_ligne, Col);
        } else {
            // Vérification si $1 est une constante
            if (strcmp(get_codeentite(idfTable, (yyvsp[(1) - (3)].str)), "CST") == 0) {
                printf("Erreur : Tentative de modification de la constante '%s' (ligne %d, colonne %d)\n", (yyvsp[(1) - (3)].str), nb_ligne, Col);
            } else {
                strcpy(type1, get_type(idfTable, (yyvsp[(1) - (3)].str)));
                
                if (strcmp(type1, "float") != 0) {
                    printf("Erreur sémantique : Incompatibilité de type entre '%s' et 'float' (ligne %d, colonne %d)\n", type1, nb_ligne, Col);
                }
                maj_valeur(idfTable, (yyvsp[(1) - (3)].str), &val);
            }
        }
        sprintf(tmp,"%f",(yyvsp[(3) - (3)].reel));
        quadr("=",tmp,"vide",(yyvsp[(1) - (3)].str));
    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 287 "syn.y"
    { 
     char type1[50];
        if (!estDeclareDansaportee(idfTable, (yyvsp[(1) - (3)].str))) {
            printf("Erreur : Variable '%s' utilisée mais non déclarée (ligne %d, colonne %d)\n", (yyvsp[(1) - (3)].str), nb_ligne, Col);
        } else {
            // Vérification si $1 est une constante
            if (strcmp(get_codeentite(idfTable, (yyvsp[(1) - (3)].str)), "CST") == 0) {
                printf("Erreur : Tentative de modification de la constante '%s' (ligne %d, colonne %d)\n", (yyvsp[(1) - (3)].str), nb_ligne, Col);
            } else {
                strcpy(type1, get_type(idfTable, (yyvsp[(1) - (3)].str)));
                
                if (strcmp(type1, "String") != 0) {
                    printf("Erreur sémantique : Incompatibilité de type (ligne %d, colonne %d)\n", nb_ligne, Col);
                }
                
            }
        }
        quadr("=",(yyvsp[(3) - (3)].str),"vide",(yyvsp[(1) - (3)].str));
    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 306 "syn.y"
    { 
        float val;
        char type1[50], type2[50];

        if (estDeclareDansaportee(idfTable, (yyvsp[(2) - (4)].str))) {
            printf("Erreur : Double déclaration de la variable '%s' (ligne %d, colonne %d)\n", (yyvsp[(2) - (4)].str), nb_ligne, Col);
        } else {
            insertComplex(idfTable, (yyvsp[(2) - (4)].str), "IDF", save_type, 0.0);
            maj_type(idfTable, (yyvsp[(2) - (4)].str), save_type);
        }

        if (!estDeclareDansaportee(idfTable, (yyvsp[(4) - (4)].str))) {
            printf("Erreur : Variable '%s' utilisée mais non déclarée (ligne %d, colonne %d)\n", (yyvsp[(4) - (4)].str), nb_ligne, Col);
        } else {
            if (strcmp(get_codeentite(idfTable, (yyvsp[(2) - (4)].str)), "CST") == 0) {
                printf("Erreur : Tentative de modification de la constante '%s' (ligne %d, colonne %d)\n", (yyvsp[(2) - (4)].str), nb_ligne, Col);
            } else {
                strcpy(type1, get_type(idfTable, (yyvsp[(2) - (4)].str)));
                strcpy(type2, get_type(idfTable, (yyvsp[(4) - (4)].str)));

                if (strcmp(type1, type2) != 0) {
                    printf("Erreur sémantique : Incompatibilité de type entre '%s' et '%s' (ligne %d, colonne %d)\n", type1, type2, nb_ligne, Col);
                }
                get_val(idfTable, (yyvsp[(4) - (4)].str), &val);
                maj_valeur(idfTable, (yyvsp[(2) - (4)].str), &val);
            }
        }
        quadr("=",(yyvsp[(4) - (4)].str),"vide",(yyvsp[(2) - (4)].str));
    ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 335 "syn.y"
    {
        char type1[50];  
        if (strcmp(get_codeentite(idfTable, (yyvsp[(2) - (4)].str)), "CST") == 0) {
                printf("Erreur : Tentative de modification de la constante '%s' (ligne %d, colonne %d)\n", (yyvsp[(2) - (4)].str), nb_ligne, Col);
            }
        else {insertComplex(idfTable, (yyvsp[(2) - (4)].str), "IDF", save_type, 0.0);
        maj_type(idfTable, (yyvsp[(2) - (4)].str), save_type);
        
     }
        quadr("=",(yyvsp[(4) - (4)].str),"vide",(yyvsp[(2) - (4)].str));
    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 346 "syn.y"
    {
        float val = (float)(yyvsp[(4) - (4)].reel);
        char type1[50];  
     if (strcmp(get_codeentite(idfTable, (yyvsp[(2) - (4)].str)), "CST") == 0) {
                printf("Erreur : Tentative de modification de la constante '%s' (ligne %d, colonne %d)\n", (yyvsp[(2) - (4)].str), nb_ligne, Col);
            }
        else {insertComplex(idfTable, (yyvsp[(2) - (4)].str), "IDF", save_type, 0.0);
        maj_type(idfTable, (yyvsp[(2) - (4)].str), save_type);    
        maj_valeur(idfTable, (yyvsp[(2) - (4)].str), &val);}
        sprintf(tmp,"%f",(yyvsp[(4) - (4)].reel));
        quadr("=",tmp,"vide",(yyvsp[(2) - (4)].str));
    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 358 "syn.y"
    {   
        float val;
        char type1[50], type2[50];
        if (!estDeclareDansaportee(idfTable, (yyvsp[(5) - (5)].str))) {
            printf("Erreur : Variable '%s' utilisée mais non déclarée (ligne %d, colonne %d)\n", (yyvsp[(5) - (5)].str), nb_ligne, Col);
        }
        else {
             if (estDeclareDansaportee(idfTable, (yyvsp[(3) - (5)].str))) {
            printf("Erreur : Variable '%s' utilisée mais non déclarée (ligne %d, colonne %d)\n", (yyvsp[(3) - (5)].str), nb_ligne, Col);
             if (strcmp(get_codeentite(idfTable, (yyvsp[(3) - (5)].str)), "CST") == 0) {
                printf("Erreur : Tentative de modification de la constante '%s' (ligne %d, colonne %d)\n", (yyvsp[(3) - (5)].str), nb_ligne, Col);
            }
        } else { 
            strcpy(type1, get_type(idfTable, (yyvsp[(5) - (5)].str)));
                strcpy(type2, get_type(idfTable, (yyvsp[(3) - (5)].str)));

                if (strcmp(type1, type2) != 0) {
                    printf("Erreur sémantique : Incompatibilité de type entre '%s' et '%s' (ligne %d, colonne %d)\n", type1, type2, nb_ligne, Col);
                } else{
                get_val(idfTable, (yyvsp[(5) - (5)].str), &val);
                maj_valeur(idfTable, (yyvsp[(3) - (5)].str), &val);}
        }
        }
        quadr("=",(yyvsp[(5) - (5)].str),"vide",(yyvsp[(3) - (5)].str));
    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 384 "syn.y"
    {  
         char type1[50];
         if (!estDeclareDansaportee(idfTable, (yyvsp[(3) - (5)].str))) {
            printf("Erreur : Variable '%s' utilisée mais non déclarée (ligne %d, colonne %d)\n", (yyvsp[(3) - (5)].str), nb_ligne, Col);
        } else {
            
            if (strcmp(get_codeentite(idfTable, (yyvsp[(3) - (5)].str)), "CST") == 0) {
                printf("Erreur : Tentative de modification de la constante '%s' (ligne %d, colonne %d)\n", (yyvsp[(3) - (5)].str), nb_ligne, Col);
            } else {
                strcpy(type1, get_type(idfTable, (yyvsp[(3) - (5)].str)));
                
                if (strcmp(type1, "String") != 0) {
                    printf("Erreur sémantique : Incompatibilité de type (ligne %d, colonne %d)\n", nb_ligne, Col);
                }
                
            }
        }
        quadr("=",(yyvsp[(5) - (5)].str),"vide",(yyvsp[(3) - (5)].str)); 
        ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 404 "syn.y"
    { 
        float val = (float)(yyvsp[(5) - (5)].reel);
        char type1[50];

        if (!estDeclareDansaportee(idfTable, (yyvsp[(3) - (5)].str))) {
            printf("Erreur : Variable '%s' utilisée mais non déclarée (ligne %d, colonne %d)\n", (yyvsp[(3) - (5)].str), nb_ligne, Col);
        } else {
            
            if (strcmp(get_codeentite(idfTable, (yyvsp[(3) - (5)].str)), "CST") == 0) {
                printf("Erreur : Tentative de modification de la constante '%s' (ligne %d, colonne %d)\n", (yyvsp[(3) - (5)].str), nb_ligne, Col);
            } else {
                strcpy(type1, get_type(idfTable, (yyvsp[(3) - (5)].str)));
                
                if (strcmp(type1, "float") != 0) {
                    printf("Erreur sémantique : Incompatibilité de type entre '%s' et 'float' (ligne %d, colonne %d)\n", type1, nb_ligne, Col);
                }
                maj_valeur(idfTable, (yyvsp[(3) - (5)].str), &val);
            }
        }
        
        sprintf(tmp,"%f",(yyvsp[(5) - (5)].reel));
        quadr("=",tmp,"vide",(yyvsp[(3) - (5)].str));  ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 438 "syn.y"
    {
            if (estDeclareDansaportee(idfTable, (yyvsp[(4) - (5)].str))) {
                printf("Erreur : Double déclaration de la matrice '%s' (ligne %d, colonne %d)\n", (yyvsp[(4) - (5)].str), nb_ligne, Col);
            } else {
                insertComplex(idfTable, (yyvsp[(4) - (5)].str), "IDF", save_type, 0.0);
                maj_type(idfTable, (yyvsp[(4) - (5)].str), save_type);
            }
            quadr("ADEC",(yyvsp[(4) - (5)].str),"vide","vide");
        ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 447 "syn.y"
    {
            if (estDeclareDansaportee(idfTable, (yyvsp[(6) - (7)].str))) {
                printf("Erreur : Double déclaration de la matrice '%s' (ligne %d, colonne %d)\n", (yyvsp[(6) - (7)].str), nb_ligne, Col);
            } else {
                insertComplex(idfTable, (yyvsp[(6) - (7)].str), "IDF", save_type, 0.0);
                maj_type(idfTable, (yyvsp[(6) - (7)].str), save_type);
            }
        ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 455 "syn.y"
    {
            char typeExist[50];
            if (!estDeclare(idfTable, (yyvsp[(1) - (6)].str))) {
                printf("Erreur : Utilisation de la matrice non déclarée '%s' (ligne %d, colonne %d)\n", (yyvsp[(1) - (6)].str), nb_ligne, Col);
            } else {
                strcpy(typeExist, get_type(idfTable, (yyvsp[(1) - (6)].str)));
                if (strcmp(typeExist, save_type) != 0) {
                    printf("Erreur sémantique : Incompatibilité de type entre '%s' et '%s' (ligne %d, colonne %d)\n", typeExist, save_type, nb_ligne, Col);
                } else {
                    maj_type(idfTable, (yyvsp[(1) - (6)].str), save_type);
                }
            }
        ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 469 "syn.y"
    {
            if (estDeclareDansaportee(idfTable, (yyvsp[(4) - (9)].str))) {
                printf("Erreur : Double déclaration de la matrice '%s' (ligne %d, colonne %d)\n", (yyvsp[(4) - (9)].str), nb_ligne, Col);
            } else {
                if (strcmp((yyvsp[(1) - (9)].str), (yyvsp[(7) - (9)].str)) != 0) {
                    printf("Erreur sémantique : Incompatibilité de type entre '%s' et '%s' (ligne %d, colonne %d)\n", (yyvsp[(1) - (9)].str), (yyvsp[(6) - (9)].str), nb_ligne, Col);
                } else {
                    insertComplex(idfTable, (yyvsp[(4) - (9)].str), "IDF", save_type, 0.0);
                }
            }
            quadr("ADEC",(yyvsp[(4) - (9)].str),"vide","vide");
        ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 481 "syn.y"
    {
            if (estDeclareDansaportee(idfTable, (yyvsp[(6) - (11)].str))) {
                printf("Erreur : Double déclaration de la matrice '%s' (ligne %d, colonne %d)\n", (yyvsp[(6) - (11)].str), nb_ligne, Col);
            } else {
                if (strcmp((yyvsp[(1) - (11)].str), (yyvsp[(9) - (11)].str)) != 0) {
                    printf("Erreur sémantique : Incompatibilité de type entre '%s' et '%s' (ligne %d, colonne %d)\n", (yyvsp[(1) - (11)].str), (yyvsp[(6) - (11)].str), nb_ligne, Col);
                } else {
                    insertComplex(idfTable, (yyvsp[(6) - (11)].str), "IDF", save_type, 0.0);
                }
            }
            quadr("ADEC",(yyvsp[(6) - (11)].str),"vide","vide");
        ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 493 "syn.y"
    {
            if (estDeclareDansaportee(idfTable, (yyvsp[(4) - (9)].str))) {
                printf("Erreur : Double déclaration de la matrice '%s' (ligne %d, colonne %d)\n", (yyvsp[(4) - (9)].str), nb_ligne, Col);
            } else {
                insertComplex(idfTable, (yyvsp[(4) - (9)].str), "IDF", save_type, 0.0);
                maj_type(idfTable, (yyvsp[(4) - (9)].str), save_type);
            }
            quadr("ADEC",(yyvsp[(4) - (9)].str),"vide","vide");
        ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 502 "syn.y"
    {
            if (estDeclareDansaportee(idfTable, (yyvsp[(6) - (11)].str))) {
                printf("Erreur : Double déclaration de la matrice '%s' (ligne %d, colonne %d)\n", (yyvsp[(6) - (11)].str), nb_ligne, Col);
            } else {
                insertComplex(idfTable, (yyvsp[(6) - (11)].str), "IDF", save_type, 0.0);
                maj_type(idfTable, (yyvsp[(6) - (11)].str), save_type);
            }
            quadr("ADEC",(yyvsp[(6) - (11)].str),"vide","vide");
        ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 511 "syn.y"
    {
                taille = (yyvsp[(2) - (3)].entier);  
                sprintf(tmp,"%f",taille);
                quadr("BOUNDS","0",tmp,"vide");
            ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 516 "syn.y"
    {
                if (!estDeclare(idfTable, (yyvsp[(2) - (3)].str))) {
                    printf("Erreur : Variable '%s' utilisée mais non déclarée (ligne %d, colonne %d)\n", (yyvsp[(2) - (3)].str), nb_ligne, Col);
                } else if (!estDeclareDansaportee(idfTable, (yyvsp[(2) - (3)].str))) {
                    printf("Erreur : Variable '%s' utilisée en dehors de sa portée (ligne %d, colonne %d)\n", (yyvsp[(2) - (3)].str), nb_ligne, Col);
                } else {
                    char typeVar[50];
                    strcpy(typeVar, get_type(idfTable, (yyvsp[(2) - (3)].str)));

                    if (strcmp(typeVar, "int") != 0) {
                        printf("Erreur sémantique : '%s' doit être un entier pour définir la taille de la matrice (ligne %d, colonne %d)\n", (yyvsp[(2) - (3)].str), nb_ligne, Col);
                    } else {
                        get_val(idfTable, (yyvsp[(2) - (3)].str), &taille);
                        sprintf(tmp,"%f",taille);
                        quadr("BOUNDS","0",tmp,"vide");
                    }
                }
            ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 534 "syn.y"
    {
                i = (yyvsp[(2) - (6)].entier);
                j = (yyvsp[(5) - (6)].entier);
                sprintf(tmp,"%f",i);
                quadr("BOUNDS","0",tmp,"vide");
                sprintf(tmp,"%f",j);
                quadr("BOUNDS","0",tmp,"vide");
            ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 542 "syn.y"
    {
                if (!estDeclare(idfTable, (yyvsp[(2) - (6)].str))) {
                    printf("Erreur : Variable '%s' utilisée mais non déclarée (ligne %d, colonne %d)\n", (yyvsp[(2) - (6)].str), nb_ligne, Col);
                } else if (!estDeclareDansaportee(idfTable, (yyvsp[(2) - (6)].str))) {
                    printf("Erreur : Variable '%s' utilisée en dehors de sa portée (ligne %d, colonne %d)\n", (yyvsp[(2) - (6)].str), nb_ligne, Col);
                } else {
                    char typeVar[50];
                    strcpy(typeVar, get_type(idfTable, (yyvsp[(2) - (6)].str)));
                    if (strcmp(typeVar, "int") != 0) {
                        printf("Erreur sémantique : '%s' doit être un entier pour définir la taille de la matrice (ligne %d, colonne %d)\n", (yyvsp[(2) - (6)].str), nb_ligne, Col);
                    } else {
                        get_val(idfTable, (yyvsp[(2) - (6)].str), &i);
                        j = (yyvsp[(5) - (6)].entier);
                        sprintf(tmp,"%f",i);
                        quadr("BOUNDS","0",tmp,"vide");
                        sprintf(tmp,"%f",j);
                        quadr("BOUNDS","0",tmp,"vide");
                    }
                }
            ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 562 "syn.y"
    {
                if (!estDeclare(idfTable, (yyvsp[(2) - (6)].str)) || !estDeclare(idfTable, (yyvsp[(5) - (6)].str))) {
                    printf("Erreur : variable utilisée comme indice mais non déclarées (ligne %d, colonne %d)\n", nb_ligne, Col);
                } else if (!estDeclareDansaportee(idfTable, (yyvsp[(2) - (6)].str)) || !estDeclareDansaportee(idfTable, (yyvsp[(5) - (6)].str))) {
                    printf("Erreur :variable utilisée comme indice en dehors de leur portée (ligne %d, colonne %d)\n", nb_ligne, Col);
                } else {
                    char typeVar1[50], typeVar2[50];
                    strcpy(typeVar1, get_type(idfTable, (yyvsp[(2) - (6)].str)));
                    strcpy(typeVar2, get_type(idfTable, (yyvsp[(5) - (6)].str)));

                    if (strcmp(typeVar1, "int") != 0 || strcmp(typeVar2, "int") != 0) {
                        printf("Erreur sémantique : '%s' et '%s' doivent être des entiers pour définir la taille de la matrice (ligne %d, colonne %d)\n", (yyvsp[(2) - (6)].str), (yyvsp[(5) - (6)].str), nb_ligne, Col);
                    } else {
                        get_val(idfTable, (yyvsp[(2) - (6)].str), &i);
                        get_val(idfTable, (yyvsp[(5) - (6)].str), &j);
                        sprintf(tmp,"%f",i);
                        quadr("BOUNDS","0",tmp,"vide");
                        sprintf(tmp,"%f",j);
                        quadr("BOUNDS","0",tmp,"vide");
                    }
                }
            ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 590 "syn.y"
    {   
            char typeVal[50];
            strcpy(typeVal, save_type); // Récupération du type attendu

            // Debug : affichage du type attendu et de la valeur fournie
            printf("[DEBUG] Type attendu : %s, Valeur fournie : %f (ligne %d, colonne %d)\n", typeVal, (yyvsp[(1) - (1)].reel), nb_ligne, Col);

            // Cas où le type attendu est float mais que la valeur est un entier (aucune erreur en Java, mais avertissement)
            if (strcmp(typeVal, "float") == 0 && (int)(yyvsp[(1) - (1)].reel) == (yyvsp[(1) - (1)].reel)) {
                printf("[AVERTISSEMENT] La valeur entière '%d' est affectée à un type '%s' (ligne %d, colonne %d)\n", (int)(yyvsp[(1) - (1)].reel), typeVal, nb_ligne, Col);
            } 
            // Cas où le type attendu est int mais que la valeur est un float avec une partie décimale
            else if (strcmp(typeVal, "int") == 0 && (float)(yyvsp[(1) - (1)].reel) != (int)(yyvsp[(1) - (1)].reel)) {
                printf("[ERREUR] La valeur '%f' ne peut pas être affectée à un type '%s' (ligne %d, colonne %d)\n", (yyvsp[(1) - (1)].reel), typeVal, nb_ligne, Col);
            } 
            // Cas où le type attendu est boolean mais que la valeur est différente de 0 ou 1
            else if (strcmp(typeVal, "boolean") == 0 && ((yyvsp[(1) - (1)].reel) != 0 && (yyvsp[(1) - (1)].reel) != 1)) {
                printf("[ERREUR] La valeur '%f' est invalide pour un type '%s' (ligne %d, colonne %d)\n", (yyvsp[(1) - (1)].reel), typeVal, nb_ligne, Col);
            } 
            else {
                printf("[DEBUG] Affectation correcte : Type '%s' avec valeur '%f'\n", typeVal, (yyvsp[(1) - (1)].reel));
            }
        ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 623 "syn.y"
    {
            if (!estDeclareDansaportee(idfTable,(yyvsp[(1) - (3)].str))) {
                printf("Erreur : Variable '%s' utilisée hors de sa portée (ligne %d, colonne %d)\n", (yyvsp[(1) - (3)].str), nb_ligne, Col);
            }
        ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 633 "syn.y"
    {
            if (!estDeclareDansaportee(idfTable,(yyvsp[(1) - (1)].str))) {
                printf("Erreur : Variable '%s' utilisée hors de sa portée (ligne %d, colonne %d)\n", (yyvsp[(1) - (1)].str), nb_ligne, Col);
            }
        ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 645 "syn.y"
    {
        if (!estDeclare(idfTable, (yyvsp[(1) - (3)].str))) {
            printf("Erreur : Variable '%s' utilisée mais non déclarée (ligne %d, colonne %d)\n", (yyvsp[(1) - (3)].str), nb_ligne, Col);
        }
        if (!estDeclareDansaportee(idfTable, (yyvsp[(1) - (3)].str))) {
            printf("Erreur : Variable '%s' utilisée hors de sa portée (ligne %d, colonne %d)\n", (yyvsp[(1) - (3)].str), nb_ligne, Col);
        }

        // Vérification si $1 est une constante
        if (strcmp(get_codeentite(idfTable, (yyvsp[(1) - (3)].str)), "CST") == 0) {
            printf("Erreur : Tentative de modification de la constante '%s' (ligne %d, colonne %d)\n", (yyvsp[(1) - (3)].str), nb_ligne, Col);
        } else {
            char typeVar[50];
            strcpy(typeVar, get_type(idfTable, (yyvsp[(1) - (3)].str)));
            if (strcmp(typeVar, "String") != 0) {
                printf("Erreur sémantique : Incompatibilité de type. '%s' est de type '%s' mais reçoit une chaîne (ligne %d, colonne %d)\n", (yyvsp[(1) - (3)].str), typeVar, nb_ligne, Col);
            } else { 
                   strcpy(nom_variable, (yyvsp[(1) - (3)].str));  
            }
        }
        quadr("=", (yyvsp[(3) - (3)].str),"vide",(yyvsp[(1) - (3)].str));
    ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 668 "syn.y"
    {   
        if (!estDeclare(idfTable, (yyvsp[(1) - (3)].str))) {
            printf("Erreur : Variable '%s' utilisée mais non déclarée (ligne %d, colonne %d)\n", (yyvsp[(1) - (3)].str), nb_ligne, Col);
        }
        if (!estDeclareDansaportee(idfTable, (yyvsp[(1) - (3)].str))) {
            printf("Erreur : Variable '%s' utilisée hors de sa portée (ligne %d, colonne %d)\n", (yyvsp[(1) - (3)].str), nb_ligne, Col);
        }

        // Vérification si $1 est une constante
        if (strcmp(get_codeentite(idfTable, (yyvsp[(1) - (3)].str)), "CST") == 0) {
            printf("Erreur : Tentative de modification de la constante '%s' (ligne %d, colonne %d)\n", (yyvsp[(1) - (3)].str), nb_ligne, Col);
        }  maj_valeur(idfTable, (yyvsp[(1) - (3)].str), &(yyvsp[(3) - (3)].reel));
        if(boolc==-1){
            quadr("=",factor_names[--factor_index],"vide",(yyvsp[(1) - (3)].str));
        }else{
            if(boolc==0){
                quadr("=","FALSE","vide",(yyvsp[(1) - (3)].str));
            }else{
                quadr("=","TRUE","vide",(yyvsp[(1) - (3)].str));
            }
            boolc = -1;
        }
        
    ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 693 "syn.y"
    {
        if (estDeclareDansaportee(idfTable, (yyvsp[(2) - (8)].str))) {
            printf("Erreur : Double déclaration de l'argument '%s' (ligne %d, colonne %d)\n", (yyvsp[(2) - (8)].str), nb_ligne, Col);
        } else {
             if (!estDeclareDansaportee(idfTable, (yyvsp[(1) - (8)].str))) {
             printf("Erreur : Variable '%s' utilisée mais non déclarée (ligne %d, colonne %d)\n", (yyvsp[(1) - (8)].str), nb_ligne, Col);}
             else{
            insertComplex(idfTable, (char*)(yyvsp[(2) - (8)].str), "IDF", save_type, 0.0);
            maj_type(idfTable, (char*)(yyvsp[(2) - (8)].str), (yyvsp[(1) - (8)].str)); }
        }
        quadr("new",(yyvsp[(5) - (8)].str),"vide","Tm");
        quadr("=","Tm","vide", (yyvsp[(2) - (8)].str));
    ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 707 "syn.y"
    {
        if (estDeclareDansaportee(idfTable, (yyvsp[(2) - (4)].str))) {
            printf("Erreur : Double déclaration de l'argument '%s' (ligne %d, colonne %d)\n", (yyvsp[(2) - (4)].str), nb_ligne, Col);
        } else { if (!estDeclareDansaportee(idfTable, (yyvsp[(1) - (4)].str))) {
             printf("Erreur : Variable '%s' utilisée mais non déclarée (ligne %d, colonne %d)\n", (yyvsp[(1) - (4)].str), nb_ligne, Col);}
             else{
            insertComplex(idfTable, (char*)(yyvsp[(2) - (4)].str), "IDF", save_type, 0.0);
            maj_type(idfTable, (char*)(yyvsp[(2) - (4)].str), (yyvsp[(1) - (4)].str));}
        }
    ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 717 "syn.y"
    {
    if (!estDeclareDansaportee(idfTable, (yyvsp[(1) - (4)].str))) {
        printf("Erreur : Variable '%s' utilisée mais non déclarée (ligne %d, colonne %d)\n", (yyvsp[(1) - (4)].str), nb_ligne, Col);
    } if (!estDeclareDansaportee(idfTable, (yyvsp[(3) - (4)].str))) {
        printf("Erreur : Variable '%s' utilisée mais non déclarée (ligne %d, colonne %d)\n", (yyvsp[(1) - (4)].str), nb_ligne, Col);
    }
     else {
        char* typeGauche = get_type(idfTable, (yyvsp[(1) - (4)].str));   // type de la variable
        char* typeDroit = get_type(idfTable, (yyvsp[(3) - (4)].str));              // type de la case du tableau récupéré via AFFTABLE

        if (strcmp(typeGauche, typeDroit) != 0) {
            printf("Erreur sémantique : Incompatibilité de type. '%s' est de type '%s' mais reçoit un '%s' (ligne %d, colonne %d)\n",
                (yyvsp[(1) - (4)].str), typeGauche, typeDroit, nb_ligne, Col);
        } else {
            strcpy(nom_variable, (yyvsp[(1) - (4)].str));
        strcat(tmp,tmp1);
        quadr("=",tmp,"vide",(yyvsp[(1) - (4)].str)); }
    }
;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 738 "syn.y"
    {
         // Vérifie si typeAffTable est bien compatible avec un float
    if (strcmp(typeAffTable, "float") != 0 && strcmp(typeAffTable, "int") != 0) {
        printf("Erreur sémantique : Incompatibilité de type. Le tableau '%s' est de type '%s' mais reçoit une valeur réelle (ligne %d, colonne %d)\n",
               (yyvsp[(1) - (3)].str), typeAffTable, nb_ligne, Col);
    } else {
        strcat(tmp,tmp1);
        sprintf(tmp2,"%f",(yyvsp[(3) - (3)].reel));
        quadr("=",tmp2,"vide",tmp);
    };}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 749 "syn.y"
    {
    if (strcmp(typeAffTable, "String") != 0) {
        printf("Erreur sémantique : Incompatibilité de type. Le tableau '%s' est de type '%s' mais reçoit une chaîne (ligne %d, colonne %d)\n",
               (yyvsp[(1) - (3)].str), typeAffTable, nb_ligne, Col);
    } else { //strcat(tmp,tmp1);
        quadr("=", (yyvsp[(3) - (3)].str), "vide", tmp);
    }
;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 758 "syn.y"
    {
    if (!estDeclareDansaportee(idfTable, (yyvsp[(1) - (3)].str))) {
        printf("Erreur : Variable '%s' utilisée hors de sa portée (ligne %d, colonne %d)\n", (yyvsp[(1) - (3)].str), nb_ligne, Col);
    } else if (strcmp(get_codeentite(idfTable, (yyvsp[(1) - (3)].str)), "CST") == 0) {
        printf("Erreur : Tentative d'incrémentation de la constante '%s' (ligne %d, colonne %d)\n", (yyvsp[(1) - (3)].str), nb_ligne, Col);
    } else {
        float valeur = 0.0;
        get_val(idfTable, (yyvsp[(1) - (3)].str), &valeur); // Récupération de la valeur actuelle
        valeur += 1; // Incrémentation
        maj_valeur(idfTable, (yyvsp[(1) - (3)].str), &valeur); // Mise à jour dans la table des symboles
        printf("Mise à jour de '%s' : Nouvelle valeur = %f\n", (yyvsp[(1) - (3)].str), valeur);
    }
    strcpy(nom_variable, (yyvsp[(1) - (3)].str)); // Sauvegarde avant modification
    quadr("+","1",(yyvsp[(1) - (3)].str),(yyvsp[(1) - (3)].str));
;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 773 "syn.y"
    {
    if (!estDeclareDansaportee(idfTable, (yyvsp[(3) - (3)].str))) {
        printf("Erreur : Variable '%s' utilisée mais non déclarée (ligne %d, colonne %d)\n", (yyvsp[(3) - (3)].str), nb_ligne, Col);
    } else {
        char* type_droit = get_type(idfTable, (yyvsp[(3) - (3)].str));

        if (strcmp(typeAffTable, type_droit) != 0) {
            printf("Erreur sémantique : Incompatibilité de type. Le tableau '%s' est de type '%s' mais reçoit un '%s' (ligne %d, colonne %d)\n",
                   (yyvsp[(1) - (3)].str), typeAffTable, type_droit, nb_ligne, Col);
        } else { strcat(tmp,tmp1);
            quadr("=", (yyvsp[(3) - (3)].str), "vide", tmp);
        }  
    }
;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 787 "syn.y"
    {
    if (!estDeclareDansaportee(idfTable, (yyvsp[(1) - (3)].str))) {
        printf("Erreur : Variable '%s' utilisée hors de sa portée (ligne %d, colonne %d)\n", (yyvsp[(1) - (3)].str), nb_ligne, Col);
    } else if (strcmp(get_codeentite(idfTable, (yyvsp[(1) - (3)].str)), "CST") == 0) {
        printf("Erreur : Tentative de décrémentation de la constante '%s' (ligne %d, colonne %d)\n", (yyvsp[(1) - (3)].str), nb_ligne, Col);
    } else {
        float valeur = 0.0;
        get_val(idfTable, (yyvsp[(1) - (3)].str), &valeur); // Récupération de la valeur actuelle
        valeur -= 1; // Décrémentation
        maj_valeur(idfTable, (yyvsp[(1) - (3)].str), &valeur); // Mise à jour dans la table des symboles
        printf("Mise à jour de '%s' : Nouvelle valeur = %f\n", (yyvsp[(1) - (3)].str), valeur);
    }
    strcpy(nom_variable, (yyvsp[(1) - (3)].str)); // Sauvegarde avant modification
    quadr("-",(yyvsp[(1) - (3)].str),"1",(yyvsp[(1) - (3)].str));
;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 813 "syn.y"
    {
    sprintf(tmp, "%d",deb_dowhile);
    quadr("BNE", tmp, tmp_name, tmp_compare_value);
    // Réinitialisation
    tmp_name[0] = '\0';
    tmp_compare_value[0] = '\0';
    ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 820 "syn.y"
    { deb_dowhile = qc ;;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 822 "syn.y"
    {
    // On génère d'abord le saut inconditionnel vers le début de la condition
    sprintf(tmp1, "%d", qc_save[qc_index - 1]);  // adresse début condition
    quadr("BR", tmp1, "vide", "vide");
    qc_index--;  // on décrémente après utilisation

    // On met à jour la branche conditionnelle pour sauter après la boucle (adresse de sortie)
    sprintf(tmp1, "%d", qc);
    updateQuad(jump_save[--jump_index], 1, tmp1);
;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 833 "syn.y"
    {
    qc_save[qc_index++] = qc;
;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 836 "syn.y"
    {
            if (estDeclareDansaportee(idfTable, (yyvsp[(1) - (3)].str))) {
                //printf("Erreur : Double déclaration de la variable '%s' (ligne %d, colonne %d)\n", $1, nb_ligne, Col);
            } else {
                insertComplex(idfTable, (yyvsp[(1) - (3)].str), "IDF", "int", 0.0);
                maj_type(idfTable, (yyvsp[(1) - (3)].str), "int");
                float val = (yyvsp[(3) - (3)].entier);
                maj_valeur(idfTable, (yyvsp[(1) - (3)].str), &val);
                (yyval.entier) = (yyvsp[(3) - (3)].entier);
            }
            strcpy(loop_var, (yyvsp[(1) - (3)].str)); // Stocke le nom de la variable de boucle
            sprintf(tmp,"%d",(yyvsp[(3) - (3)].entier));
            quadr("=",tmp,"vide",(yyvsp[(1) - (3)].str));
;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 852 "syn.y"
    {
        if(strcmp((yyvsp[(1) - (3)].str), loop_var) != 0 && strcmp((yyvsp[(3) - (3)].str), loop_var) != 0) {
            printf("Erreur ligne %d: La condition doit utiliser la variable de boucle '%s'\n", nb_ligne, loop_var);
            yyerror("Erreur de variable de boucle");
            YYERROR;
        }
        jump_save[jump_index++] = qc;
        // Inversion de BLE en BG pour la sortie de boucle
        quadr("BG", "", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
    ;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 862 "syn.y"
    {
        if(strcmp((yyvsp[(1) - (3)].str), loop_var) != 0 && strcmp((yyvsp[(3) - (3)].str), loop_var) != 0) {
            printf("Erreur ligne %d: La condition doit utiliser la variable de boucle '%s'\n", nb_ligne, loop_var);
            yyerror("Erreur de variable de boucle");
            YYERROR;
        }
        jump_save[jump_index++] = qc;
        // Inversion de BG en BL
        quadr("BL", "", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
    ;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 872 "syn.y"
    {
        if(strcmp((yyvsp[(1) - (3)].str), loop_var) != 0 && strcmp((yyvsp[(3) - (3)].str), loop_var) != 0) {
            printf("Erreur ligne %d: La condition doit utiliser la variable de boucle '%s'\n", nb_ligne, loop_var);
            yyerror("Erreur de variable de boucle");
            YYERROR;
        }
        jump_save[jump_index++] = qc;
        // Inversion de BLE en BG
        quadr("BG", "", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
    ;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 882 "syn.y"
    {
        if(strcmp((yyvsp[(1) - (3)].str), loop_var) != 0 && strcmp((yyvsp[(3) - (3)].str), loop_var) != 0) {
            printf("Erreur ligne %d: La condition doit utiliser la variable de boucle '%s'\n", nb_ligne, loop_var);
            yyerror("Erreur de variable de boucle");
            YYERROR;
        }
        jump_save[jump_index++] = qc;
        // Inversion de BGE en BL
        quadr("BL", "", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
    ;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 893 "syn.y"
    {
        if(strcmp((yyvsp[(1) - (3)].str), loop_var) != 0) {
            printf("Erreur ligne %d: La condition doit utiliser la variable de boucle '%s'\n", nb_ligne, loop_var);
            yyerror("Erreur de variable de boucle");
            YYERROR;
        }
        char numStr[50];
        sprintf(numStr, "%f", (yyvsp[(3) - (3)].reel));
        jump_save[jump_index++] = qc;
        quadr("BG", "", (yyvsp[(1) - (3)].str), numStr);
    ;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 904 "syn.y"
    {
        if(strcmp((yyvsp[(1) - (3)].str), loop_var) != 0) {
            printf("Erreur ligne %d: La condition doit utiliser la variable de boucle '%s'\n", nb_ligne, loop_var);
            yyerror("Erreur de variable de boucle");
            YYERROR;
        }
        char numStr[50];
        sprintf(numStr, "%f", (yyvsp[(3) - (3)].reel));
        jump_save[jump_index++] = qc;
        quadr("BL", "", (yyvsp[(1) - (3)].str), numStr);
    ;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 915 "syn.y"
    {
        if(strcmp((yyvsp[(1) - (3)].str), loop_var) != 0) {
            printf("Erreur ligne %d: La condition doit utiliser la variable de boucle '%s'\n", nb_ligne, loop_var);
            yyerror("Erreur de variable de boucle");
            YYERROR;
        }
        char numStr[50];
        sprintf(numStr, "%f", (yyvsp[(3) - (3)].reel));
        jump_save[jump_index++] = qc;
        quadr("BG", "", (yyvsp[(1) - (3)].str), numStr);
    ;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 926 "syn.y"
    {
        if(strcmp((yyvsp[(1) - (3)].str), loop_var) != 0) {
            printf("Erreur ligne %d: La condition doit utiliser la variable de boucle '%s'\n", nb_ligne, loop_var);
            yyerror("Erreur de variable de boucle");
            YYERROR;
        }
        char numStr[50];
        sprintf(numStr, "%f", (yyvsp[(3) - (3)].reel));
        jump_save[jump_index++] = qc;
        quadr("BL", "", (yyvsp[(1) - (3)].str), numStr);
    ;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 941 "syn.y"
    {
    if(strcmp((yyvsp[(1) - (3)].str), loop_var) != 0) {
        printf("Erreur ligne %d: L'incrémentation doit utiliser la variable de boucle '%s'\n", nb_ligne, loop_var);
        yyerror("Erreur de variable de boucle");
        YYERROR;
    }
    float valeur = 0.0;
    get_val(idfTable, (yyvsp[(1) - (3)].str), &valeur);
    valeur += 1;
    maj_valeur(idfTable, (yyvsp[(1) - (3)].str), &valeur);
    char valStr[32];
    sprintf(valStr, "%f", 1.0);
    quadr("+", valStr, (yyvsp[(1) - (3)].str), (yyvsp[(1) - (3)].str));  // (+ , 1 , i , i)
;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 955 "syn.y"
    {
    if(strcmp((yyvsp[(1) - (3)].str), loop_var) != 0) {
        printf("Erreur ligne %d: La décrémentation doit utiliser la variable de boucle '%s'\n", nb_ligne, loop_var);
        yyerror("Erreur de variable de boucle");
        YYERROR;
    }
    float valeur = 0.0;
    get_val(idfTable, (yyvsp[(1) - (3)].str), &valeur);
    valeur -= 1;
    maj_valeur(idfTable, (yyvsp[(1) - (3)].str), &valeur);
    char valStr[32];
    sprintf(valStr, "%f", 1.0);
    quadr("-", valStr, (yyvsp[(1) - (3)].str), (yyvsp[(1) - (3)].str));  // (- , 1 , i , i)
;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 970 "syn.y"
    {
    
    sprintf(tmp, "%d",deb_dowhile);
    quadr("BR",tmp,"vide","vide");
    sprintf(tmp, "%d",qc);
    updateQuad(deb_dowhile,1,tmp);
;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 977 "syn.y"
    {
    deb_dowhile = qc;
    // Génère le quad complet BE (adresse, var, valeur, vide)
    sprintf(tmp, "%d", qc+3);  // Adresse de saut
    quadr("BE", tmp, tmp_name, tmp_compare_value);
    // Réinitialisation
    tmp_name[0] = '\0';
    tmp_compare_value[0] = '\0';

;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 988 "syn.y"
    {
    sprintf(tmp, "%d", qc);
    updateQuad(fin_if,1,tmp);
;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 992 "syn.y"
    {
        sprintf(tmp, "%d", qc);
        updateQuad(fin_if,1,tmp);
       ;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 996 "syn.y"
    {
        sprintf(tmp, "%d", qc);
        updateQuad(fin_if,1,tmp);
        updateQuad(fin_ifelse,1,tmp);
       ;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 1001 "syn.y"
    {
    fin_ifelse = qc;
    quadr("BR","","vide","vide");
    sprintf(tmp, "%d", qc);
    updateQuad(deb_else,1,tmp);
;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1007 "syn.y"
    {
    deb_else = qc; // sauvgarder qc de BZ pour on peut faire une mise a jour 
    sprintf(tmp,"%d",boolc);
    quadr("BZ","",tmp,"vide");
;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1012 "syn.y"
    {
    fin_if = qc;
    quadr("BR","","vide","vide");
    sprintf(tmp, "%d", qc);
    updateQuad(deb_else,1,tmp);
;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1018 "syn.y"
    {
    deb_else = qc; // sauvgarder qc de BZ pour on peut faire une mise a jour 
    sprintf(tmp,"%d",boolc);
    quadr("BZ","",tmp,"vide");
;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1023 "syn.y"
    {
           if (!estDeclareDansaportee(idfTable, (yyvsp[(3) - (7)].str))) {
                printf("Erreur : Variable '%s' utilisée mais non déclarée (ligne %d, colonne %d)\n", (yyvsp[(3) - (7)].str), nb_ligne, Col);
            }
            if (qnt == 1){
                sprintf(tmp, "%d", qc);
                updateQuad(fin_if,1,tmp);
            }
            ;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 1035 "syn.y"
    {
    fin_if = qc ;
    quadr("BR","","vide","vide");
    qnt = 1 ;
;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 1040 "syn.y"
    {
    fin_if = qc ;
    quadr("BR","","vide","vide");
    qnt = 1 ;
;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 1045 "syn.y"
    {
    fin_if = qc ;
    quadr("BR","","vide","vide");
    qnt = 1 ;
;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 1050 "syn.y"
    {
    fin_if = qc ;
    quadr("BR","","vide","vide");
    qnt = 1 ;
;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 1062 "syn.y"
    {strcpy(save_type,(yyvsp[(1) - (1)].str));;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 1062 "syn.y"
    {strcpy(save_type,(yyvsp[(1) - (1)].str));;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 1062 "syn.y"
    {strcpy(save_type,(yyvsp[(1) - (1)].str));;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 1062 "syn.y"
    {strcpy(save_type,(yyvsp[(1) - (1)].str));;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 1062 "syn.y"
    {strcpy(save_type,(yyvsp[(1) - (1)].str));;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 1062 "syn.y"
    {strcpy(save_type,(yyvsp[(1) - (1)].str));;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 1067 "syn.y"
    {
                if (estDeclareDansaportee(idfTable, (yyvsp[(1) - (3)].str))) {
                    printf("Erreur : Double déclaration de la variable '%s' (ligne %d, colonne %d)\n", (yyvsp[(1) - (3)].str), nb_ligne, Col);
                } else {
                    insertComplex(idfTable, (char*)(yyvsp[(1) - (3)].str), "IDF", save_type, 0.0);
                }
            ;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 1074 "syn.y"
    {
                if (estDeclareDansaportee(idfTable, (yyvsp[(1) - (5)].str))) {
                    printf("Erreur : Double déclaration de la variable '%s' (ligne %d, colonne %d)\n", (yyvsp[(1) - (5)].str), nb_ligne, Col);
                } else {
                    insertComplex(idfTable, (char*)(yyvsp[(1) - (5)].str), "IDF", save_type, 0.0);
                    float valeur_initiale = (float)(yyvsp[(3) - (5)].reel);
                    maj_valeur(idfTable, (char*)(yyvsp[(1) - (5)].str), &valeur_initiale);
                }
                sprintf(tmp,"%f",(yyvsp[(3) - (5)].reel));
                quadr("=",tmp,"vide",(yyvsp[(1) - (5)].str));
            ;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 1085 "syn.y"
    {
                if (estDeclareDansaportee(idfTable, (yyvsp[(1) - (5)].str))) {
                    printf("Erreur : Double déclaration de la variable '%s' (ligne %d, colonne %d)\n", (yyvsp[(1) - (5)].str), nb_ligne, Col);
                } else if (strcmp(save_type, "String") != 0) {
                    printf("Erreur : Incompatibilité de type pour '%s' (attendu %s, obtenu string) (ligne %d, colonne %d)\n", (yyvsp[(1) - (5)].str), save_type, nb_ligne, Col);
                }  else {
                    insertComplex(idfTable, (char*)(yyvsp[(1) - (5)].str), "IDF", save_type, 0.0);    
                }
                quadr("=",(yyvsp[(3) - (5)].str),"vide",(yyvsp[(1) - (5)].str));
                
            ;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 1096 "syn.y"
    {
                if (estDeclareDansaportee(idfTable, (yyvsp[(1) - (3)].str))) {
                    printf("Erreur : Double déclaration de la variable '%s' (ligne %d, colonne %d)\n", (yyvsp[(1) - (3)].str), nb_ligne, Col);
                } else if (strcmp(save_type, "String") != 0) {
                    printf("Erreur : Incompatibilité de type pour '%s' (attendu %s, obtenu string) (ligne %d, colonne %d)\n", (yyvsp[(1) - (3)].str), save_type, nb_ligne, Col);
                } else {
                    insertComplex(idfTable, (char*)(yyvsp[(1) - (3)].str), "IDF", save_type, 0.0);
                }
                quadr("=",(yyvsp[(3) - (3)].str),"vide",(yyvsp[(1) - (3)].str));
            ;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 1106 "syn.y"
    {
                if (estDeclareDansaportee(idfTable, (yyvsp[(1) - (1)].str))) {
                    printf("Erreur : Double déclaration de la variable '%s' (ligne %d, colonne %d)\n", (yyvsp[(1) - (1)].str), nb_ligne, Col);
                } else {
                    insertComplex(idfTable, (char*)(yyvsp[(1) - (1)].str), "IDF", save_type, 0.0);
                }
            ;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 1113 "syn.y"
    { 
                if (estDeclareDansaportee(idfTable, (yyvsp[(1) - (3)].str))) {
                    printf("Erreur : Double déclaration de la variable '%s' (ligne %d, colonne %d)\n", (yyvsp[(1) - (3)].str), nb_ligne, Col);
                } else {
                    insertComplex(idfTable, (char*)(yyvsp[(1) - (3)].str), "IDF", save_type, 0.0);
                    float valeur_initiale = (yyvsp[(3) - (3)].reel);
                    maj_valeur(idfTable, (char*)(yyvsp[(1) - (3)].str), &valeur_initiale); 
                 
                }
                if(boolc==-1){
                    sprintf(tmp,"%f",(yyvsp[(3) - (3)].reel));
                    quadr("=",tmp,"vide",(yyvsp[(1) - (3)].str));
                }else{
                    if(boolc==0){
                        quadr("=","FALSE","vide",(yyvsp[(1) - (3)].str));
                    }else{
                        quadr("=","TRUE","vide",(yyvsp[(1) - (3)].str));
                    }
                    boolc = -1;
                }
                
            ;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1135 "syn.y"
    {
                if (estDeclareDansaportee(idfTable, (yyvsp[(1) - (5)].str))) {
                    printf("Erreur : Double déclaration de la variable '%s' (ligne %d, colonne %d)\n", (yyvsp[(1) - (5)].str), nb_ligne, Col);
                } else if (strcmp(save_type, "boolean") != 0 && strcmp(save_type, "int") != 0) {
                printf("Erreur : Incompatibilité de type pour '%s' (attendu %s, reçu booléen) (ligne %d, colonne %d)\n", 
                       (yyvsp[(3) - (5)].str), save_type, nb_ligne, Col);
            } else {
                insertComplex(idfTable, (yyvsp[(1) - (5)].str), "IDF", save_type, 0.0);
                float valeur = (strcmp((yyvsp[(3) - (5)].str), "true") == 0) ? 1.0 : 0.0;
                maj_valeur(idfTable, (yyvsp[(1) - (5)].str), &valeur);
                quadr("=", (valeur == 1.0) ? "true" : "false", "vide", (yyvsp[(1) - (5)].str));
                }
                ;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 1148 "syn.y"
    {
                if (estDeclareDansaportee(idfTable, (yyvsp[(1) - (3)].str))) {
                    printf("Erreur : Double déclaration de la variable '%s' (ligne %d, colonne %d)\n", (yyvsp[(1) - (3)].str), nb_ligne, Col);
                } else if (strcmp(save_type, "boolean") != 0 && strcmp(save_type, "int") != 0) {
                printf("Erreur : Incompatibilité de type pour '%s' (attendu %s, reçu booléen) (ligne %d, colonne %d)\n", 
                       (yyvsp[(3) - (3)].str), save_type, nb_ligne, Col);
            } else {
                insertComplex(idfTable, (yyvsp[(1) - (3)].str), "IDF", save_type, 0.0);
                float valeur = (strcmp((yyvsp[(3) - (3)].str), "true") == 0) ? 1.0 : 0.0;
                maj_valeur(idfTable, (yyvsp[(1) - (3)].str), &valeur);
                quadr("=", (valeur == 1.0) ? "true" : "false", "vide", (yyvsp[(1) - (3)].str));
                }

                ;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 1163 "syn.y"
    {
                    insertComplex(idfTable, (char*)(yyvsp[(2) - (2)].str), "IDF", save_type, 0.0);
                    maj_type(idfTable, (char*)(yyvsp[(2) - (2)].str), save_type); 
            ;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 1168 "syn.y"
    {    
                    insertComplex(idfTable, (char*)(yyvsp[(2) - (4)].str), "IDF", save_type, 0.0);
                    maj_type(idfTable, (char*)(yyvsp[(2) - (4)].str), save_type);
            ;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 1175 "syn.y"
    {  (yyval.reel) = (yyvsp[(1) - (1)].reel);  ;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 1177 "syn.y"
    {   (yyval.reel) = (yyvsp[(1) - (1)].reel); ;}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 1178 "syn.y"
    {  
                if((yyvsp[(1) - (3)].reel) || (yyvsp[(3) - (3)].reel)){
                            boolc = 1;
                            (yyval.reel)=1;
                        }else {
                            boolc = 0;
                            (yyval.reel)=0;
                        }
;}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 1189 "syn.y"
    {
    if((yyvsp[(1) - (3)].reel) && (yyvsp[(3) - (3)].reel)){
                boolc = 1;
                (yyval.reel)=1;
            }else {
                boolc = 0;
                (yyval.reel)=0;
            }
;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 1200 "syn.y"
    {
            sprintf(tmp_compare_value, "%d", (int)(yyvsp[(3) - (3)].reel));  // Store as int
            if((yyvsp[(1) - (3)].reel) > (yyvsp[(3) - (3)].reel)){
                boolc = 1;
                (yyval.reel)=1;
                
            }else {
                boolc = 0;
                (yyval.reel)=0;
            }
          ;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 1211 "syn.y"
    {
            sprintf(tmp_compare_value, "%d", (int)(yyvsp[(3) - (3)].reel));  // Store as int
            if((yyvsp[(1) - (3)].reel) < (yyvsp[(3) - (3)].reel)){
                boolc = 1;
                (yyval.reel)=1;
            }else {
                boolc = 0;
                (yyval.reel)=0;
            }
          ;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 1221 "syn.y"
    {
            sprintf(tmp_compare_value, "%d", (int)(yyvsp[(3) - (3)].reel));  // Store as int
            if((yyvsp[(1) - (3)].reel) >= (yyvsp[(3) - (3)].reel)){
                boolc = 1;
                (yyval.reel)=1;
            }else {
                boolc = 0;
                (yyval.reel)=0;
            }
          ;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 1231 "syn.y"
    {
            sprintf(tmp_compare_value, "%d", (int)(yyvsp[(3) - (3)].reel));  // Store as int
            if((yyvsp[(1) - (3)].reel) <= (yyvsp[(3) - (3)].reel)){
                boolc = 1;
                (yyval.reel)=1;
            }else {
                boolc = 0;
                (yyval.reel)=0;
            }
          ;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 1241 "syn.y"
    {
            sprintf(tmp_compare_value, "%d", (int)(yyvsp[(3) - (3)].reel));  // Store as int
            if((yyvsp[(1) - (3)].reel) != (yyvsp[(3) - (3)].reel)){
                boolc = 1;
                (yyval.reel)=1;
            }else {
                boolc = 0;
                (yyval.reel)=0;
            }
          ;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 1251 "syn.y"
    {
            sprintf(tmp_compare_value, "%d", (int)(yyvsp[(3) - (3)].reel));  // Store as int
            if((yyvsp[(1) - (3)].reel) == (yyvsp[(3) - (3)].reel)){
                boolc = 1;
                (yyval.reel)=1;
            }else {
                boolc = 0;
                (yyval.reel)=0;
            }
          ;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 1263 "syn.y"
    { 
            (yyval.reel) = (yyvsp[(1) - (3)].reel) + (yyvsp[(3) - (3)].reel);  // Calcul sémantique (correct)
            
            char *right = factor_names[--factor_index]; // Doit donner 2
            char *left  = factor_names[--factor_index]; // Doit donner 4 (mais donne 2 ?)
            sprintf(tmpb, "T%d", t++);
            quadr("+", left, right, tmpb);
            factor_names[factor_index++] = strdup(tmpb);
        ;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 1272 "syn.y"
    {
            (yyval.reel) = (yyvsp[(1) - (3)].reel) - (yyvsp[(3) - (3)].reel);
            
            char *right = factor_names[--factor_index];
            char *left  = factor_names[--factor_index];
            
            sprintf(tmpb, "T%d", t++);
            quadr("-", left, right, tmpb);
            
            factor_names[factor_index++] = strdup(tmpb);
            
            printf("Soustraction : %s - %s → %s\n", left, right, tmpb);
        ;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 1287 "syn.y"
    { 
        (yyval.reel) = (yyvsp[(1) - (3)].reel) * (yyvsp[(3) - (3)].reel);  // Multiplication
        printf("Résultat de la multiplication : %f\n", (yyval.reel));
        
        char *right = factor_names[--factor_index];
        char *left  = factor_names[--factor_index];
        sprintf(tmpb,"T%d",t);
        quadr("*",left,right,tmpb);
        factor_names[factor_index++] = strdup(tmpb);
        t += 1;
    ;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 1298 "syn.y"
    { 
        if ((yyvsp[(3) - (3)].reel) == 0) {
            printf("Erreur : Division par zéro (ligne %d, colonne %d)\n", nb_ligne, Col);
            (yyval.reel) = 0;
        } else {
            (yyval.reel) = (yyvsp[(1) - (3)].reel) / (yyvsp[(3) - (3)].reel);  // Division
            printf("Résultat de la division : %f\n", (yyval.reel));
        }
        
        char *right = factor_names[--factor_index];
        char *left  = factor_names[--factor_index];
        sprintf(tmpb,"T%d",t);
        quadr("/",left,right,tmpb);
        factor_names[factor_index++] = strdup(tmpb);
        t += 1;
    ;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 1314 "syn.y"
    { 
        if ((yyvsp[(3) - (3)].reel) == 0) {
            printf("Erreur : Modulo par zéro (ligne %d, colonne %d)\n", nb_ligne, Col);
            (yyval.reel) = 0;
        } else {
            (yyval.reel) = fmod((yyvsp[(1) - (3)].reel), (yyvsp[(3) - (3)].reel));  // Modulo
            printf("Résultat du modulo : %f\n", (yyval.reel));
        }
        
        char *right = factor_names[--factor_index];
        char *left  = factor_names[--factor_index];
        sprintf(tmpb,"T%d",t);
        quadr("%",left,right,tmpb);
        factor_names[factor_index++] = strdup(tmpb);
        t += 1;
    ;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 1331 "syn.y"
    { 
    if (!estDeclareDansaportee(idfTable, (yyvsp[(1) - (1)].str))) {
        printf("Erreur : Variable '%s' non déclarée (ligne %d, colonne %d)\n", (yyvsp[(1) - (1)].str), nb_ligne, Col);
    }
    else {
        float valeur = 0.0;
        get_val(idfTable, (yyvsp[(1) - (1)].str), &valeur);
        (yyval.reel) = valeur; // Récupérer la valeur de la variable
        factor_names[factor_index++] = strdup((yyvsp[(1) - (1)].str));
        
        strncpy(tmp_name, (yyvsp[(1) - (1)].str), sizeof(tmp_name)-1);
        tmp_name[sizeof(tmp_name)-1] = '\0';
        printf("[DEBUG] tmp_name = '%s'\n", tmp_name);  // Vérification


        strncpy(tmp_name_dowhile, (yyvsp[(1) - (1)].str), sizeof(tmp_name_dowhile)-1);
        tmp_name_dowhile[sizeof(tmp_name_dowhile)-1] = '\0';
        printf("[DEBUG] tmp_name = '%s'\n", tmp_name_dowhile);  // Vérification


    }

;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 1354 "syn.y"
    {
    char *num_str = malloc(32);  // Allouer une nouvelle chaîne
    sprintf(num_str, "%f", (yyvsp[(1) - (1)].reel));
    factor_names[factor_index++] = num_str;  // Stocker le nouveau pointeur
    printf("[DEBUG] Empile NUMB %f -> factor_names[%d] = %s\n", (yyvsp[(1) - (1)].reel), factor_index-1, num_str);
;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 1362 "syn.y"
    { (yyval.reel) = (yyvsp[(2) - (3)].reel); ;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 1363 "syn.y"
    { (yyval.reel) = !(yyvsp[(2) - (2)].reel); ;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 1368 "syn.y"
    {
            if (strcmp(type_retour_methode, "String") != 0) {
                printf("Erreur : Incompatibilité de type pour le retour (attendu : %s, trouvé : String) (ligne %d, colonne %d)\n",
                       type_retour_methode, nb_ligne, Col);
            }
            quadr("return",(yyvsp[(2) - (2)].str),"vide","vide");
        ;}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 1376 "syn.y"
    { 
       char* typeRetour = save_type; 
    if (typeRetour == NULL) {
        printf("Erreur : Type inconnu pour l'expression (ligne %d, colonne %d)\n", nb_ligne, Col);
    } else if (strcmp(type_retour_methode, typeRetour) != 0) {
        printf("Erreur : Incompatibilité de type pour le retour (attendu : %s, trouvé : %s) (ligne %d, colonne %d)\n",
               type_retour_methode, typeRetour, nb_ligne, Col);
    } else {
        float val = (yyvsp[(2) - (2)].reel);
        printf("[DEBUG] Retour de méthode : %s = %f\n", nom_fonction, val);
        maj_val_fonction(idfTable, nom_fonction , &val);
        
    }
    sprintf(tmp,"%f",(yyvsp[(2) - (2)].reel));
    quadr("return",tmp,"vide","vide");
;}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 1392 "syn.y"
    { (yyval.reel) = (yyvsp[(1) - (1)].reel); ;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 1393 "syn.y"
    { (yyval.reel) = (float)(yyvsp[(1) - (1)].entier); ;}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 1397 "syn.y"
    {
            if (!estDeclareDansaportee(idfTable, (yyvsp[(1) - (6)].str))) {
                printf("Erreur : Objet '%s' utilisé mais non déclaré dans la portée actuelle (ligne %d, colonne %d)\n", (yyvsp[(1) - (6)].str), nb_ligne, Col);

            if (!estDeclareDansaportee(idfTable, (yyvsp[(3) - (6)].str))) {
                printf("Erreur : Objet '%s' utilisé mais non déclaré dans la portée actuelle (ligne %d, colonne %d)\n", (yyvsp[(3) - (6)].str), nb_ligne, Col);
            }
            } 
            sprintf(tmp, "%s.%s", (yyvsp[(1) - (6)].str), (yyvsp[(3) - (6)].str));
            quadr("call",tmp,"vide","vide");
        ;}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 1408 "syn.y"
    {
            if (!estDeclareDansaportee(idfTable, (yyvsp[(1) - (3)].str))) {
                printf("Erreur : Objet '%s' utilisé mais non déclaré dans la portée actuelle (ligne %d, colonne %d)\n", (yyvsp[(1) - (3)].str), nb_ligne, Col);
                if (!estDeclareDansaportee(idfTable, (yyvsp[(3) - (3)].str))) {
                printf("Erreur : Objet '%s' utilisé mais non déclaré dans la portée actuelle (ligne %d, colonne %d)\n", (yyvsp[(3) - (3)].str), nb_ligne, Col);
            }
            } 
        ;}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 1416 "syn.y"
    {
            if (!estDeclareDansaportee(idfTable, (yyvsp[(1) - (4)].str))) {
                printf("Erreur : Tableau '%s' utilisé mais non déclaré dans la portée actuelle (ligne %d, colonne %d)\n", (yyvsp[(1) - (4)].str), nb_ligne, Col);
                if (!estDeclareDansaportee(idfTable, (yyvsp[(4) - (4)].str))) {
                printf("Erreur : Objet '%s' utilisé mais non déclaré dans la portée actuelle (ligne %d, colonne %d)\n", (yyvsp[(4) - (4)].str), nb_ligne, Col);
            }
            } 
        ;}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 1425 "syn.y"
    {
                if (!estDeclareDansaportee(idfTable, (yyvsp[(1) - (2)].str))) {
                    printf("Erreur : Tableau '%s' utilisé mais non déclaré dans la portée actuelle (ligne %d, colonne %d)\n", (yyvsp[(1) - (2)].str), nb_ligne, Col);
                } 
            strcpy(tmp,(yyvsp[(1) - (2)].str));   
             strcpy((yyval.str), (yyvsp[(1) - (2)].str));  // retourne le nom pour l’utiliser comme $1 plus tard
    strcpy(typeAffTable, get_type(idfTable, (yyvsp[(1) - (2)].str))); // on récupère son type
          ;}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 1433 "syn.y"
    {
                if ((yyvsp[(2) - (3)].entier) < 0 || (yyvsp[(2) - (3)].entier) >= taille) {
                    printf("Erreur : Indice hors bornes\n ");
                }
                float a = (yyvsp[(2) - (3)].entier);
                sprintf(tmp1,"[%f]",a);
            ;}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 1440 "syn.y"
    {
                if (!estDeclareDansaportee(idfTable, (yyvsp[(2) - (3)].str))) {
                    printf("Erreur : Variable '%s' utilisée mais non déclarée dans la portée actuelle (ligne %d, colonne %d)\n", (yyvsp[(2) - (3)].str), nb_ligne, Col);
                } else {
                    char typeVar[50];
                    strcpy(typeVar, get_type(idfTable, (yyvsp[(2) - (3)].str)));

                    if (strcmp(typeVar, "int") != 0) {
                        printf("Erreur sémantique : '%s' doit être un entier pour être un indice de la matrice (ligne %d, colonne %d)\n", (yyvsp[(2) - (3)].str), nb_ligne, Col);
                    } else {
                        float valeur;
                        get_val(idfTable, (yyvsp[(2) - (3)].str), &valeur);
                        if (valeur < 0 || valeur >= taille) {
                              printf("Erreur : Indice hors bornes\n ");
                        }
                    }
                }
                float valeur;
                get_val(idfTable, (yyvsp[(2) - (3)].str), &valeur);
                sprintf(tmp1,"[%f]",valeur);
            ;}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 1461 "syn.y"
    {
                if ((yyvsp[(2) - (6)].entier) < 0 || (yyvsp[(2) - (6)].entier) >= i-1 || (yyvsp[(5) - (6)].entier) < 0 || (yyvsp[(5) - (6)].entier) >= j-1) {
                      printf("Erreur : Indice hors bornes\n ");
                }
                float a = (yyvsp[(2) - (6)].entier);
                float b = (yyvsp[(5) - (6)].entier);
                sprintf(tmp1,"[%f][%f]",a,b);
            ;}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 1469 "syn.y"
    {
                if (!estDeclareDansaportee(idfTable, (yyvsp[(2) - (6)].str))) {
                    printf("Erreur : Variable '%s' utilisée mais non déclarée dans la portée actuelle (ligne %d, colonne %d)\n", (yyvsp[(2) - (6)].str), nb_ligne, Col);
                } else {
                    char typeVar[50];
                    strcpy(typeVar, get_type(idfTable, (yyvsp[(2) - (6)].str)));

                    if (strcmp(typeVar, "int") != 0) {
                        printf("Erreur sémantique : '%s' doit être un entier pour être un indice de la matrice (ligne %d, colonne %d)\n", (yyvsp[(2) - (6)].str), nb_ligne, Col);
                    } else {
                        float valeur;
                        get_val(idfTable, (yyvsp[(2) - (6)].str), &valeur);
                        if (valeur < 0 || valeur >= i-1 || (yyvsp[(5) - (6)].entier) < 0 || (yyvsp[(5) - (6)].entier) >= j-1) {
                              printf("Erreur : Indice hors bornes \n");
                        }
                    }
                }
                float valeur;
                float a = (yyvsp[(5) - (6)].entier) ;
                get_val(idfTable, (yyvsp[(2) - (6)].str), &valeur);
                sprintf(tmp1,"[%f][%f]",valeur,a);
            ;}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 1491 "syn.y"
    {
                if (estDeclareDansaportee(idfTable, (yyvsp[(2) - (6)].str)) == 0 || estDeclareDansaportee(idfTable, (yyvsp[(5) - (6)].str)) == 0) {
                    printf("Erreur : Une ou plusieurs variables utilisées mais non déclarées dans la portée actuelle (ligne %d, colonne %d)\n", nb_ligne, Col);
                } else {
                    char typeVar1[50], typeVar2[50];
                    strcpy(typeVar1, get_type(idfTable, (yyvsp[(2) - (6)].str)));
                    strcpy(typeVar2, get_type(idfTable, (yyvsp[(5) - (6)].str)));

                    if (strcmp(typeVar1, "int") != 0 || strcmp(typeVar2, "int") != 0) {
                        printf("Erreur sémantique : '%s' et '%s' doivent être des entiers pour être des indices de la matrice (ligne %d, colonne %d)\n", (yyvsp[(2) - (6)].str), (yyvsp[(5) - (6)].str), nb_ligne, Col);
                    } else {
                        float valeur1, valeur2;
                        get_val(idfTable, (yyvsp[(2) - (6)].str), &valeur1);
                        get_val(idfTable, (yyvsp[(5) - (6)].str), &valeur2);
                        if (valeur1 < 0 || valeur1 >= i-1 || valeur2 < 0 || valeur2 >= j-1) {
                              printf("Erreur : Indice hors bornes \n");
                        }
                    }
                }
                float valeur1, valeur2;
                get_val(idfTable, (yyvsp[(2) - (6)].str), &valeur1);
                get_val(idfTable, (yyvsp[(5) - (6)].str), &valeur2);
                sprintf(tmp1,"[%f][%f]",valeur1,valeur2);
            ;}
    break;



/* Line 1455 of yacc.c  */
#line 3986 "syn.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 1515 "syn.y"

int main() {
  
    // Initialisation des tables de symboles
    idfTable = createSymbolTable();
    separatorTable = createSymbolTable();
    keywordTable = createSymbolTable();

    yyparse();
    afficher_qdr();
    optimiser();
    afficher_qdr();

    generer_code_assembleur("output.asm", idfTable);
   // Affichage des tables des symboles après analyse
    printf("\n===== Table des Identificateurs =====\n");
    displayComplexTable(idfTable, "Identificateurs");

    printf("\n===== Table des Séparateurs =====\n");
    displaySimpleTable(separatorTable, "Séparateurs");

    printf("\n===== Table des Mots-Clés =====\n");
    displaySimpleTable(keywordTable, "Mots-clés");

    // Libération de la mémoire
    freeSymbolTable(idfTable);
    freeSymbolTable(separatorTable);
    freeSymbolTable(keywordTable);

    return 0 ;}

    

