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
#line 5 "compilador.y" /* yacc.c:339  */


#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"
#include "stack.h"
#define YYSTYPE long int

int yylex();
void yyerror(const char *s);

int num_vars;
char aux_string[128];

int ultimo_tipo;

// Implementar nivel lexico em stack
int nivel_lexico = -1;

int somente_identificador = 1;

id l_elem, elem_aux;

tipo_expressao pilha_expressao = NULL;
tipo_rotulo pilha_rotulos = NULL;

tipos_parametro tipo_parametro;

tipo_pilha_procedimentos pilha_procedimentos = NULL;



#line 101 "compilador.tab.c" /* yacc.c:339  */

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
   by #include "compilador.tab.h".  */
#ifndef YY_YY_COMPILADOR_TAB_H_INCLUDED
# define YY_YY_COMPILADOR_TAB_H_INCLUDED
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
    PROGRAM = 258,
    ABRE_PARENTESES = 259,
    FECHA_PARENTESES = 260,
    NUMERO = 261,
    VIRGULA = 262,
    PONTO_E_VIRGULA = 263,
    DOIS_PONTOS = 264,
    PONTO = 265,
    T_BEGIN = 266,
    T_END = 267,
    VAR = 268,
    IDENT = 269,
    ATRIBUICAO = 270,
    MAIS = 271,
    MENOS = 272,
    DIV = 273,
    ASTERISCO = 274,
    IGUAL = 275,
    DIFERENTE = 276,
    MENOR = 277,
    MENOR_IGUAL = 278,
    MAIOR = 279,
    MAIOR_IGUAL = 280,
    IF = 281,
    THEN = 282,
    ELSE = 283,
    WHILE = 284,
    DO = 285,
    AND = 286,
    OR = 287,
    PROCEDURE = 288,
    FUNCTION = 289,
    LABEL = 290,
    GOTO = 291,
    READ = 292,
    WRITE = 293,
    BOOLEAN = 294,
    INTEGER = 295,
    TRUE = 296,
    FALSE = 297,
    NEGACAO = 298
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_COMPILADOR_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 196 "compilador.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   150

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  186

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    55,    55,    55,    64,    64,    78,    79,    80,    80,
      84,    88,    91,    97,   101,   102,   106,   109,   106,   118,
     120,   126,   131,   139,   144,   152,   153,   158,   157,   176,
     183,   175,   194,   197,   201,   202,   206,   206,   212,   212,
     222,   223,   227,   228,   232,   232,   238,   242,   243,   244,
     244,   245,   246,   247,   248,   248,   252,   260,   261,   265,
     265,   269,   269,   280,   314,   314,   326,   326,   330,   339,
     351,   351,   369,   370,   374,   378,   382,   386,   390,   394,
     401,   405,   409,   413,   417,   421,   425,   429,   433,   438,
     442,   443,   448,   452,   455,   463,   463,   476,   476,   485,
     493,   498,   493,   517,   521,   528,   538,   551,   556
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "ABRE_PARENTESES",
  "FECHA_PARENTESES", "NUMERO", "VIRGULA", "PONTO_E_VIRGULA",
  "DOIS_PONTOS", "PONTO", "T_BEGIN", "T_END", "VAR", "IDENT", "ATRIBUICAO",
  "MAIS", "MENOS", "DIV", "ASTERISCO", "IGUAL", "DIFERENTE", "MENOR",
  "MENOR_IGUAL", "MAIOR", "MAIOR_IGUAL", "IF", "THEN", "ELSE", "WHILE",
  "DO", "AND", "OR", "PROCEDURE", "FUNCTION", "LABEL", "GOTO", "READ",
  "WRITE", "BOOLEAN", "INTEGER", "TRUE", "FALSE", "NEGACAO", "$accept",
  "programa", "$@1", "bloco", "$@2", "parte_declaracoes",
  "parte_declara_rotulos", "declara_rotulos", "parte_declara_vars",
  "declara_vars", "declara_var", "$@3", "$@4", "tipo", "lista_id_var",
  "lista_idents", "parte_declara_subrotinas", "declara_procedimento",
  "$@5", "declara_funcao", "$@6", "$@7", "declara_parametros",
  "parametros_formais", "secao_de_parametros_formais", "$@8", "$@9",
  "comando_composto", "comandos", "comando", "$@10", "comando_sem_rotulo",
  "$@11", "desvio", "comando_com_ident", "comando_fator_com_ident", "$@12",
  "comando_pos_ident", "$@13", "chamada_procedimento", "$@14",
  "lista_parametros", "lista_de_expressoes", "atribuicao", "$@15",
  "expressao", "relacao", "expressao_simples", "termo", "fator",
  "booleano", "comando_condicional", "$@16", "continuacao_condicional",
  "$@17", "comando_repetitivo", "$@18", "$@19",
  "lista_de_expressoes_impressao", "lista_variaveis_leitura", "leitura",
  "impressao", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298
};
# endif

#define YYPACT_NINF -145

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-145)))

#define YYTABLE_NINF -17

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -145,    10,    17,  -145,    19,    32,    36,  -145,    48,    60,
      57,  -145,  -145,    64,  -145,  -145,    52,    40,  -145,    74,
      95,   108,  -145,  -145,  -145,    85,   110,  -145,  -145,  -145,
      -2,  -145,   113,   116,   117,  -145,     1,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,   109,  -145,   111,  -145,  -145,  -145,
       8,  -145,  -145,   115,   107,    -2,  -145,  -145,  -145,  -145,
      -2,  -145,  -145,  -145,    79,    -1,  -145,  -145,    -2,  -145,
     112,    -2,    23,  -145,  -145,  -145,    49,   123,   123,   122,
    -145,    53,  -145,  -145,  -145,   125,  -145,   126,   128,  -145,
     103,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,
      -2,    -2,    -2,  -145,  -145,    76,   -10,    87,  -145,  -145,
     119,    77,   121,   127,   129,  -145,  -145,    -2,    -2,  -145,
    -145,  -145,  -145,    53,    -1,    -1,   -10,   -10,   -10,   -10,
     -10,   -10,    -1,  -145,  -145,  -145,   114,  -145,   131,  -145,
      -2,  -145,  -145,  -145,  -145,  -145,     6,  -145,    36,  -145,
      77,   -10,   100,   -10,    -2,   118,    53,  -145,   -10,   132,
      36,  -145,   121,    99,  -145,  -145,  -145,    -2,   105,  -145,
    -145,  -145,  -145,   106,  -145,    77,   133,   -10,  -145,    53,
      77,  -145,  -145,  -145,  -145,  -145
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,    24,     0,     0,
       0,     4,    23,     0,     9,     3,     0,    55,    16,     0,
       0,     0,     8,     7,     6,     0,     0,     5,    44,    49,
       0,   100,     0,     0,     0,    54,     0,    43,    46,    52,
      51,    53,    48,    47,    13,    15,     0,    27,    29,    12,
       0,    26,    25,     0,    64,     0,    88,    59,    93,    94,
       0,    92,    95,    73,    72,    83,    87,    89,     0,    56,
       0,     0,    55,    40,    14,    22,     0,    33,    33,     0,
      10,    55,    70,    50,    58,    67,    57,     0,    63,    91,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   101,   106,     0,   104,     0,    41,    42,
       0,     0,    38,     0,     0,    11,    45,     0,     0,    65,
      90,    61,    60,    55,    80,    81,    74,    75,    76,    77,
      78,    79,    82,    85,    84,    86,     0,   107,     0,   108,
       0,    21,    19,    20,    17,    36,     0,    35,     0,     4,
       0,    71,     0,    69,     0,    99,    55,   105,   103,     0,
       0,    32,    38,     0,    28,    30,    66,     0,     0,    97,
      96,   102,    18,     0,    34,     0,     0,    68,    62,    55,
       0,    39,     4,    98,    37,    31
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -145,  -145,  -145,  -144,  -145,  -145,  -145,  -145,  -145,  -145,
      92,  -145,  -145,  -118,  -145,  -129,  -145,  -145,  -145,  -145,
    -145,  -145,    59,  -145,   -23,  -145,  -145,   134,  -145,    70,
    -145,   -81,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,   -11,  -145,  -145,   -47,  -145,   -70,   -19,   -57,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    13,    14,    16,    22,    50,    23,    44,
      45,    46,   159,   144,    76,     8,    24,    25,    77,    26,
      78,   176,   113,   146,   147,   160,   148,    35,    36,    37,
      53,    38,    54,    39,    83,    61,    88,   122,   154,    84,
      85,   119,   152,    86,   117,    62,    63,    64,    65,    66,
      67,    40,    90,   170,   179,    41,    68,   136,   107,   105,
      42,    43
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     116,   106,    55,    89,    56,   164,    91,    92,    87,    72,
       3,   161,    57,    73,   162,    79,    80,   100,   101,   163,
       4,   103,    99,   126,   127,   128,   129,   130,   131,    28,
     102,   173,   165,     5,    17,   108,     6,    29,   185,    58,
      59,    60,   155,   133,   134,   135,    28,   151,   153,    30,
       7,    17,    31,     9,    29,    10,   110,   181,   111,    32,
      33,    34,   184,    17,    17,    18,    30,    29,    11,    31,
     158,    12,   124,   125,    15,   171,    32,    33,    34,    30,
     132,   137,    31,   138,   153,    19,    20,    21,    47,    32,
      33,    34,   139,    51,   140,    91,    92,   177,   183,    93,
      94,    95,    96,    97,    98,   166,    10,   167,   175,    48,
     178,    99,   167,    10,    49,   180,   142,   143,    52,    69,
      70,    71,    82,   -16,    81,    75,   104,   112,   115,   118,
     123,   120,   121,   141,   145,   149,    74,   114,   150,   174,
     172,   182,   109,   168,   156,   157,   169,     0,     0,     0,
      27
};

static const yytype_int16 yycheck[] =
{
      81,    71,     4,    60,     6,   149,    16,    17,    55,     8,
       0,     5,    14,    12,     8,     7,     8,    18,    19,   148,
       3,    68,    32,    93,    94,    95,    96,    97,    98,     6,
      31,   160,   150,    14,    11,    12,     4,    14,   182,    41,
      42,    43,   123,   100,   101,   102,     6,   117,   118,    26,
      14,    11,    29,     5,    14,     7,     7,   175,     9,    36,
      37,    38,   180,    11,    11,    13,    26,    14,     8,    29,
     140,    14,    91,    92,    10,   156,    36,    37,    38,    26,
      99,     5,    29,     7,   154,    33,    34,    35,    14,    36,
      37,    38,     5,     8,     7,    16,    17,   167,   179,    20,
      21,    22,    23,    24,    25,     5,     7,     7,     9,    14,
       5,    32,     7,     7,     6,     9,    39,    40,     8,     6,
       4,     4,    15,    14,     9,    14,    14,     4,     6,     4,
      27,     5,     4,    14,    13,     8,    44,    78,     9,   162,
       8,     8,    72,   154,    30,    14,    28,    -1,    -1,    -1,
      16
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    45,    46,     0,     3,    14,     4,    14,    59,     5,
       7,     8,    14,    47,    48,    10,    49,    11,    13,    33,
      34,    35,    50,    52,    60,    61,    63,    71,     6,    14,
      26,    29,    36,    37,    38,    71,    72,    73,    75,    77,
      95,    99,   104,   105,    53,    54,    55,    14,    14,     6,
      51,     8,     8,    74,    76,     4,     6,    14,    41,    42,
      43,    79,    89,    90,    91,    92,    93,    94,   100,     6,
       4,     4,     8,    12,    54,    14,    58,    62,    64,     7,
       8,     9,    15,    78,    83,    84,    87,    89,    80,    93,
      96,    16,    17,    20,    21,    22,    23,    24,    25,    32,
      18,    19,    31,    89,    14,   103,    91,   102,    12,    73,
       7,     9,     4,    66,    66,     6,    75,    88,     4,    85,
       5,     4,    81,    27,    92,    92,    91,    91,    91,    91,
      91,    91,    92,    93,    93,    93,   101,     5,     7,     5,
       7,    14,    39,    40,    57,    13,    67,    68,    70,     8,
       9,    91,    86,    91,    82,    75,    30,    14,    91,    56,
      69,     5,     8,    59,    47,    57,     5,     7,    86,    28,
      97,    75,     8,    59,    68,     9,    65,    91,     5,    98,
       9,    57,     8,    75,    57,    47
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    46,    45,    48,    47,    49,    49,    49,    49,
      50,    51,    51,    52,    53,    53,    55,    56,    54,    57,
      57,    58,    58,    59,    59,    60,    60,    62,    61,    64,
      65,    63,    66,    66,    67,    67,    69,    68,    70,    68,
      71,    71,    72,    72,    74,    73,    73,    75,    75,    76,
      75,    75,    75,    75,    75,    75,    77,    78,    78,    80,
      79,    82,    81,    81,    84,    83,    85,    85,    86,    86,
      88,    87,    89,    89,    90,    90,    90,    90,    90,    90,
      91,    91,    91,    91,    92,    92,    92,    92,    93,    93,
      93,    93,    93,    94,    94,    96,    95,    98,    97,    97,
     100,   101,    99,   102,   102,   103,   103,   104,   105
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     9,     0,     3,     2,     2,     2,     0,
       3,     3,     1,     2,     2,     1,     0,     0,     6,     1,
       1,     3,     1,     3,     1,     2,     2,     0,     6,     0,
       0,     9,     3,     0,     3,     1,     0,     5,     0,     4,
       3,     4,     3,     1,     0,     4,     1,     1,     1,     0,
       3,     1,     1,     1,     1,     0,     2,     1,     1,     0,
       3,     0,     4,     0,     0,     2,     3,     0,     3,     1,
       0,     3,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     3,     1,     1,     1,
       3,     2,     1,     1,     1,     0,     6,     0,     3,     0,
       0,     0,     6,     3,     1,     3,     1,     4,     4
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
        case 2:
#line 55 "compilador.y" /* yacc.c:1646  */
    {geraCodigo (NULL, "INPP");}
#line 1415 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 58 "compilador.y" /* yacc.c:1646  */
    {
      geraCodigo (NULL, "PARA");
   }
#line 1423 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 64 "compilador.y" /* yacc.c:1646  */
    {
      ++nivel_lexico;
   }
#line 1431 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 69 "compilador.y" /* yacc.c:1646  */
    {
      sprintf(aux_string, "DMEM  %d", encontra_qtd_simbolos_antes_de_funcao(variavel_simples, nivel_lexico));
      geraCodigo(NULL, aux_string);
      libera_simbolos_internos_de_funcao(nivel_lexico);
      --nivel_lexico;
   }
#line 1442 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 88 "compilador.y" /* yacc.c:1646  */
    {
      insere_rotulo_tabela(token, nivel_lexico);
   }
#line 1450 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 91 "compilador.y" /* yacc.c:1646  */
    {
      insere_rotulo_tabela(token, nivel_lexico);
   }
#line 1458 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 106 "compilador.y" /* yacc.c:1646  */
    { num_vars = 0; }
#line 1464 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 109 "compilador.y" /* yacc.c:1646  */
    {
      sprintf(aux_string, "AMEM  %d", num_vars);
      geraCodigo(NULL, aux_string);
      altera_tipo_tabela(ultimo_tipo, num_vars);
   }
#line 1474 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 118 "compilador.y" /* yacc.c:1646  */
    {
      ultimo_tipo = booleano;
   }
#line 1482 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 120 "compilador.y" /* yacc.c:1646  */
    {
      ultimo_tipo = inteiro;
   }
#line 1490 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 127 "compilador.y" /* yacc.c:1646  */
    {
      insere_vs_tabela(token, nivel_lexico, encontra_qtd_simbolos_antes_de_funcao(variavel_simples, nivel_lexico));
      ++num_vars;
   }
#line 1499 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 132 "compilador.y" /* yacc.c:1646  */
    {
      insere_vs_tabela(token, nivel_lexico, encontra_qtd_simbolos_antes_de_funcao(variavel_simples, nivel_lexico));
      ++num_vars;
   }
#line 1508 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 139 "compilador.y" /* yacc.c:1646  */
    {
      ++num_vars;
      if(tipo_parametro==parametro_referencia || tipo_parametro==parametro_valor)
         insere_pf_tabela(token, nivel_lexico, tipo_parametro);
   }
#line 1518 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 144 "compilador.y" /* yacc.c:1646  */
    {
      ++num_vars;
      if(tipo_parametro==parametro_referencia || tipo_parametro==parametro_valor)
         insere_pf_tabela(token, nivel_lexico, tipo_parametro);
   }
#line 1528 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 158 "compilador.y" /* yacc.c:1646  */
    {
      GERA_E_EMPILHA_ROTULO
      sprintf(aux_string, "DSVS %s", pilha_rotulos->rotulo);
      geraCodigo(NULL, aux_string);
      insere_procedimento_tabela(token, nivel_lexico+1, procedimento);
      sprintf(aux_string, "ENPR %d", nivel_lexico + 1);
      geraCodigo(tabela_de_simbolos->info_procedimento.rotulo, aux_string);
   }
#line 1541 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 166 "compilador.y" /* yacc.c:1646  */
    {
      sprintf(aux_string, "RTPR %d, %d", nivel_lexico + 1, tabela_de_simbolos->info_procedimento.qtd_parametros);
      geraCodigo(NULL, aux_string);
      geraCodigo(pilha_rotulos->rotulo, "NADA");
      DESEMPILHA_ROTULO(pilha_rotulos)
   }
#line 1552 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 176 "compilador.y" /* yacc.c:1646  */
    {
      GERA_E_EMPILHA_ROTULO
      sprintf(aux_string, "DSVS %s", pilha_rotulos->rotulo);
      geraCodigo(NULL, aux_string);
      insere_procedimento_tabela(token, nivel_lexico+1, funcao);
      sprintf(aux_string, "ENPR %d", nivel_lexico + 1);
      geraCodigo(tabela_de_simbolos->info_procedimento.rotulo, aux_string);
   }
#line 1565 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 183 "compilador.y" /* yacc.c:1646  */
    {
      atualiza_retorno_funcao(ultimo_tipo);
   }
#line 1573 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 185 "compilador.y" /* yacc.c:1646  */
    {
      sprintf(aux_string, "RTPR %d, %d", nivel_lexico + 1, tabela_de_simbolos->info_procedimento.qtd_parametros);
      geraCodigo(NULL, aux_string);
      geraCodigo(pilha_rotulos->rotulo, "NADA");
      DESEMPILHA_ROTULO(pilha_rotulos)
   }
#line 1584 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 194 "compilador.y" /* yacc.c:1646  */
    {
      tipo_parametro = 0;
      atualiza_parametros_procedimento();
   }
#line 1593 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 206 "compilador.y" /* yacc.c:1646  */
    {
      tipo_parametro = parametro_referencia;
      num_vars = 0;
   }
#line 1602 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 209 "compilador.y" /* yacc.c:1646  */
    {
      altera_tipo_tabela(ultimo_tipo, num_vars);
   }
#line 1610 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 212 "compilador.y" /* yacc.c:1646  */
    {
      tipo_parametro = parametro_valor;
      num_vars = 0;
   }
#line 1619 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 216 "compilador.y" /* yacc.c:1646  */
    {
      altera_tipo_tabela(ultimo_tipo, num_vars);
   }
#line 1627 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 232 "compilador.y" /* yacc.c:1646  */
    {
      l_elem = busca_simbolo_na_tabela(token, label);
      sprintf(aux_string, "ENRT %d, %d", nivel_lexico, encontra_qtd_simbolos_antes_de_funcao(variavel_simples, nivel_lexico));
      geraCodigo(l_elem->info_rotulo.rotulo, aux_string);

   }
#line 1638 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 244 "compilador.y" /* yacc.c:1646  */
    {strcpy(aux_string, token);}
#line 1644 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 252 "compilador.y" /* yacc.c:1646  */
    {
      elem_aux = busca_simbolo_na_tabela(token, label);
      sprintf(aux_string, "DSVR %s, %d, %d", elem_aux->info_rotulo.rotulo, elem_aux->nivel_lexico, nivel_lexico);
      geraCodigo(NULL, aux_string);
   }
#line 1654 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 265 "compilador.y" /* yacc.c:1646  */
    {strcpy(aux_string, token);}
#line 1660 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 269 "compilador.y" /* yacc.c:1646  */
    {
      EMPILHA_FUNCAO(busca_simbolo_na_tabela(aux_string, funcao))
      geraCodigo(NULL, "AMEM 1");
   }
#line 1669 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 272 "compilador.y" /* yacc.c:1646  */
    {
      if(pilha_procedimentos->item->info_procedimento.qtd_parametros != pilha_procedimentos->conta_parametros)
         imprimeErro("O número de parâmtros não coincide com declaração");
      sprintf(aux_string, "CHPR %s, %d", pilha_procedimentos->item->info_procedimento.rotulo, nivel_lexico);
      geraCodigo(NULL, aux_string);
      stack_push((stack_t**)&pilha_expressao, malloc(sizeof(struct t_tipo_expressao)));
      pilha_expressao->tipo=pilha_procedimentos->item->info_procedimento.tipo_retorno;
      DESEMPILHA_SIMPLES(pilha_procedimentos)
   }
#line 1683 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 280 "compilador.y" /* yacc.c:1646  */
    {
      elem_aux = busca_simbolo_na_tabela(aux_string, variavel_ou_funcao_ou_param);
      if(elem_aux->tipo == funcao){
         EMPILHA_FUNCAO(busca_simbolo_na_tabela(token, funcao))
         geraCodigo(NULL, "AMEM 1");
         if(pilha_procedimentos->item->info_procedimento.qtd_parametros != pilha_procedimentos->conta_parametros)
            imprimeErro("O número de parâmtros não coincide com declaração");
         sprintf(aux_string, "CHPR %s, %d", pilha_procedimentos->item->info_procedimento.rotulo, nivel_lexico);
         geraCodigo(NULL, aux_string);
         stack_push((stack_t**)&pilha_expressao, malloc(sizeof(struct t_tipo_expressao)));
         pilha_expressao->tipo=pilha_procedimentos->item->info_procedimento.tipo_retorno;
         DESEMPILHA_SIMPLES(pilha_procedimentos)
      }
      else {
         if(pilha_procedimentos){
            if (pilha_procedimentos->item->info_procedimento.parametros[pilha_procedimentos->conta_parametros].tipo_parametro == parametro_referencia){
               if(!somente_identificador)
                  imprimeErro("Argumento inválido");
               somente_identificador = 0;
               sprintf(aux_string, "CREN %d, %d", elem_aux->nivel_lexico, elem_aux->info_variavel.deslocamento);
            }
            else
               sprintf(aux_string, "%s %d, %d", COM_CARREGA_ELEM_AUX, elem_aux->nivel_lexico, elem_aux->info_variavel.deslocamento);
         }
         else
            sprintf(aux_string, "%s %d, %d", COM_CARREGA_ELEM_AUX, elem_aux->nivel_lexico, elem_aux->info_variavel.deslocamento);
         stack_push((stack_t**)&pilha_expressao, malloc(sizeof(struct t_tipo_expressao)));
         pilha_expressao->tipo=encontra_tipo(elem_aux);
         geraCodigo(NULL, aux_string);
      }
   }
#line 1719 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 314 "compilador.y" /* yacc.c:1646  */
    {
      EMPILHA_FUNCAO(busca_simbolo_na_tabela(aux_string, procedimento))
   }
#line 1727 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 316 "compilador.y" /* yacc.c:1646  */
    {
      if(pilha_procedimentos->item->info_procedimento.qtd_parametros != pilha_procedimentos->conta_parametros)
         imprimeErro("O número de parâmetros não coincide com declaração");
      sprintf(aux_string, "CHPR %s, %d", pilha_procedimentos->item->info_procedimento.rotulo, nivel_lexico);
      geraCodigo(NULL, aux_string);
      DESEMPILHA_SIMPLES(pilha_procedimentos)
   }
#line 1739 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 330 "compilador.y" /* yacc.c:1646  */
    {
      if(pilha_procedimentos){
         somente_identificador = 1;
         if (pilha_expressao->tipo != pilha_procedimentos->item->info_procedimento.parametros[pilha_procedimentos->conta_parametros].tipo_variavel)
            imprimeErro("os tipos de variavel nao coincidem");
         free(stack_pop((stack_t **)&pilha_expressao));
         ++pilha_procedimentos->conta_parametros;
      };
   }
#line 1753 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 339 "compilador.y" /* yacc.c:1646  */
    {
      if(pilha_procedimentos){
         somente_identificador = 1;
         if (pilha_expressao->tipo != pilha_procedimentos->item->info_procedimento.parametros[pilha_procedimentos->conta_parametros].tipo_variavel)
            imprimeErro("os tipos de variavel nao coincidem");
         free(stack_pop((stack_t **)&pilha_expressao));
         ++pilha_procedimentos->conta_parametros;
      };
   }
#line 1767 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 351 "compilador.y" /* yacc.c:1646  */
    {
      l_elem = busca_simbolo_na_tabela(aux_string, variavel_ou_parametro);
      if(!l_elem){
         sprintf(aux_string, "A variavel %s nao foi encontrada", aux_string);
         imprimeErro(aux_string);
      }
   }
#line 1779 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 357 "compilador.y" /* yacc.c:1646  */
    {
      // ADICIONAR ERRO CASO SIMBOLOS DE TIPOS DIFERENTES
      if(encontra_tipo(l_elem) != pilha_expressao->tipo)
         imprimeErro("os tipos de variavel nao coincidem");
      free(stack_pop((stack_t **)&pilha_expressao));
      sprintf(aux_string, "%s %d, %d", COM_ARMAZENA_L_ELEM, l_elem->nivel_lexico, l_elem->info_variavel.deslocamento);
      geraCodigo(NULL, aux_string);

   }
#line 1793 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 374 "compilador.y" /* yacc.c:1646  */
    {
      COMPARA_T_RELACAO_BOOLEANA_E_POP
      geraCodigo(NULL, "CMIG");
   }
#line 1802 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 378 "compilador.y" /* yacc.c:1646  */
    {
      COMPARA_T_RELACAO_BOOLEANA_E_POP
      geraCodigo(NULL, "CMDG");
   }
#line 1811 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 382 "compilador.y" /* yacc.c:1646  */
    {
      COMPARA_T_RELACAO_BOOLEANA_E_POP
      geraCodigo(NULL, "CMME");
   }
#line 1820 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 386 "compilador.y" /* yacc.c:1646  */
    {
      COMPARA_T_RELACAO_BOOLEANA_E_POP
      geraCodigo(NULL, "CMEG");
   }
#line 1829 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 390 "compilador.y" /* yacc.c:1646  */
    {
      COMPARA_T_RELACAO_BOOLEANA_E_POP
      geraCodigo(NULL, "CMMA");
   }
#line 1838 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 394 "compilador.y" /* yacc.c:1646  */
    {
      COMPARA_T_RELACAO_BOOLEANA_E_POP
      geraCodigo(NULL, "CMAG");
   }
#line 1847 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 401 "compilador.y" /* yacc.c:1646  */
    {
      COMPARA_T_EXPRESSAO_E_POP(inteiro)
      geraCodigo(NULL, "SOMA");
   }
#line 1856 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 405 "compilador.y" /* yacc.c:1646  */
    {
      COMPARA_T_EXPRESSAO_E_POP(inteiro)
      geraCodigo(NULL, "SUBT");
   }
#line 1865 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 409 "compilador.y" /* yacc.c:1646  */
    {
      COMPARA_T_EXPRESSAO_E_POP(booleano)
      geraCodigo(NULL, "DISJ");
   }
#line 1874 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 417 "compilador.y" /* yacc.c:1646  */
    {
      COMPARA_T_EXPRESSAO_E_POP(inteiro)
      geraCodigo(NULL, "MULT");
   }
#line 1883 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 421 "compilador.y" /* yacc.c:1646  */
    {
      COMPARA_T_EXPRESSAO_E_POP(inteiro)
      geraCodigo(NULL, "DIVI");
   }
#line 1892 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 425 "compilador.y" /* yacc.c:1646  */
    {
      COMPARA_T_EXPRESSAO_E_POP(booleano)
      geraCodigo(NULL, "CONJ");
   }
#line 1901 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 433 "compilador.y" /* yacc.c:1646  */
    {
      stack_push((stack_t**)&pilha_expressao, malloc(sizeof(struct t_tipo_expressao)));
      pilha_expressao->tipo=inteiro;
      sprintf(aux_string, "CRCT %s", token);
      geraCodigo(NULL, aux_string);
   }
#line 1912 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 438 "compilador.y" /* yacc.c:1646  */
    {
      stack_push((stack_t**)&pilha_expressao, malloc(sizeof(struct t_tipo_expressao)));
      pilha_expressao->tipo=booleano;
   }
#line 1921 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 443 "compilador.y" /* yacc.c:1646  */
    {
      if(!pilha_expressao->tipo==booleano)
         imprimeErro("Tipo inválido");
      geraCodigo(NULL, "NEGA");
   }
#line 1931 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 452 "compilador.y" /* yacc.c:1646  */
    {
      sprintf(aux_string, "CRCT 0");
      geraCodigo(NULL, aux_string);
   }
#line 1940 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 455 "compilador.y" /* yacc.c:1646  */
    {
      sprintf(aux_string, "CRCT 1");
      geraCodigo(NULL, aux_string);
   }
#line 1949 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 463 "compilador.y" /* yacc.c:1646  */
    {
      if(pilha_expressao->tipo != booleano)
         imprimeErro("a expressao deve retornar um booleano");
      free(stack_pop((stack_t **)&pilha_expressao));

      GERA_E_EMPILHA_ROTULO
      sprintf(aux_string, "DSVF %s", pilha_rotulos->rotulo);
      geraCodigo(NULL, aux_string);
   }
#line 1963 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 476 "compilador.y" /* yacc.c:1646  */
    {
      GERA_E_EMPILHA_ROTULO
      sprintf(aux_string, "DSVS %s", pilha_rotulos->rotulo);
      geraCodigo(NULL, aux_string);
      geraCodigo(pilha_rotulos->next->rotulo, "NADA");
   }
#line 1974 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 481 "compilador.y" /* yacc.c:1646  */
    {
      geraCodigo(pilha_rotulos->rotulo, "NADA");
      DESEMPILHA_ROTULO(pilha_rotulos)
      DESEMPILHA_ROTULO(pilha_rotulos)
   }
#line 1984 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 485 "compilador.y" /* yacc.c:1646  */
    {
      geraCodigo(pilha_rotulos->rotulo, "NADA");
      DESEMPILHA_ROTULO(pilha_rotulos)
   }
#line 1993 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 493 "compilador.y" /* yacc.c:1646  */
    {
      GERA_E_EMPILHA_ROTULO
      sprintf(aux_string, "NADA");
      geraCodigo(pilha_rotulos->rotulo, aux_string);
   }
#line 2003 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 498 "compilador.y" /* yacc.c:1646  */
    {
      if(pilha_expressao->tipo != booleano)
         imprimeErro("a expressao deve retornar um booleano");
      free(stack_pop((stack_t **)&pilha_expressao));

      GERA_E_EMPILHA_ROTULO
      sprintf(aux_string, "DSVF %s", pilha_rotulos->rotulo);
      geraCodigo(NULL, aux_string);
   }
#line 2017 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 507 "compilador.y" /* yacc.c:1646  */
    {
      sprintf(aux_string, "DSVS %s", pilha_rotulos->next->rotulo);
      geraCodigo(NULL, aux_string);
      geraCodigo(pilha_rotulos->rotulo, "NADA");
      DESEMPILHA_ROTULO(pilha_rotulos)
      DESEMPILHA_ROTULO(pilha_rotulos)
   }
#line 2029 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 517 "compilador.y" /* yacc.c:1646  */
    {
      free(stack_pop((stack_t **)&pilha_expressao));
      geraCodigo(NULL, "IMPR");
   }
#line 2038 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 521 "compilador.y" /* yacc.c:1646  */
    {
      free(stack_pop((stack_t **)&pilha_expressao));
      geraCodigo(NULL, "IMPR");
   }
#line 2047 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 528 "compilador.y" /* yacc.c:1646  */
    {
      l_elem = busca_simbolo_na_tabela(token, variavel_ou_parametro);
      if(!l_elem){
         sprintf(aux_string, "A variavel %s nao foi encontrada", token);
         imprimeErro(aux_string);
      }
      geraCodigo(NULL, "LEIT");
      sprintf(aux_string, "%s %d, %d", COM_ARMAZENA_L_ELEM, l_elem->nivel_lexico, l_elem->info_variavel.deslocamento);
      geraCodigo(NULL, aux_string);
   }
#line 2062 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 538 "compilador.y" /* yacc.c:1646  */
    {
      l_elem = busca_simbolo_na_tabela(token, variavel_ou_parametro);
      if(!l_elem){
         sprintf(aux_string, "A variavel %s nao foi encontrada", token);
         imprimeErro(aux_string);
      }
      geraCodigo(NULL, "LEIT");
      sprintf(aux_string, "%s %d, %d", COM_ARMAZENA_L_ELEM, l_elem->nivel_lexico, l_elem->info_variavel.deslocamento);
      geraCodigo(NULL, aux_string);
   }
#line 2077 "compilador.tab.c" /* yacc.c:1646  */
    break;


#line 2081 "compilador.tab.c" /* yacc.c:1646  */
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
#line 559 "compilador.y" /* yacc.c:1906  */


int main (int argc, char** argv) {
   FILE* fp;
   extern FILE* yyin;


   if (argc<2 || argc>2) {
         printf("usage compilador <arq>a %d\n", argc);
         return(-1);
      }

   fp=fopen (argv[1], "r");
   if (fp == NULL) {
      printf("usage compilador <arq>b\n");
      return(-1);
   }


   /* -------------------------------------------------------------------
   *  Inicia a Tabela de S�mbolos
   * ------------------------------------------------------------------- */

   yyin=fp;
   yyparse();

   return 0;
}
