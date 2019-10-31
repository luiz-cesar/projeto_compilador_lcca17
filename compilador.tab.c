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

// Implementar nivel lexico em stack
int nivel_lexico = -1;

id l_elem, elem_aux;

tipo_expressao pilha_expressao = NULL;
tipo_rotulo pilha_rotulos = NULL;

tipos_parametro tipo_parametro;

tipo_pilha_procedimentos pilha_procedimentos = NULL;



#line 97 "compilador.tab.c" /* yacc.c:339  */

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
    FUNCTION = 289
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

#line 183 "compilador.tab.c" /* yacc.c:358  */

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
#define YYLAST   124

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  148

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    48,    48,    48,    57,    57,    71,    72,    72,    76,
      80,    81,    85,    88,    85,    97,   101,   106,   114,   119,
     127,   128,   133,   132,   151,   158,   150,   169,   172,   176,
     177,   181,   181,   188,   188,   198,   202,   203,   203,   208,
     212,   212,   213,   214,   215,   219,   220,   224,   224,   228,
     228,   240,   273,   273,   286,   290,   296,   305,   305,   323,
     329,   337,   341,   345,   349,   353,   357,   364,   368,   372,
     375,   379,   383,   387,   390,   394,   400,   404,   409,   404,
     418,   418,   427,   435,   440,   435
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
  "DO", "AND", "OR", "PROCEDURE", "FUNCTION", "$accept", "programa", "$@1",
  "bloco", "$@2", "parte_declaracoes", "parte_declara_vars",
  "declara_vars", "declara_var", "$@3", "$@4", "tipo", "lista_id_var",
  "lista_idents", "parte_declara_subrotinas", "declara_procedimento",
  "$@5", "declara_funcao", "$@6", "$@7", "declara_parametros",
  "parametros_formais", "secao_de_parametros_formais", "$@8", "$@9",
  "comando_composto", "comandos", "comando", "comando_sem_rotulo", "$@10",
  "comando_com_ident", "comando_fator_com_ident", "$@11",
  "comando_pos_ident", "$@12", "chamada_procedimento", "$@13",
  "lista_parametros", "lista_de_expressoes", "atribuicao", "$@14",
  "expressao", "relacao", "expressao_simples", "termo", "fator",
  "comando_condicional", "$@15", "$@16", "continuacao_condicional", "$@17",
  "comando_repetitivo", "$@18", "$@19", YY_NULLPTR
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
     285,   286,   287,   288,   289
};
# endif

#define YYPACT_NINF -109

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-109)))

#define YYTABLE_NINF -13

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
    -109,    26,    32,  -109,    58,    43,    61,  -109,    55,    66,
      62,  -109,  -109,    41,  -109,  -109,    -3,    14,  -109,    65,
      67,  -109,  -109,  -109,  -109,  -109,  -109,    38,  -109,  -109,
      10,    69,  -109,  -109,  -109,    68,  -109,    70,  -109,  -109,
      71,  -109,  -109,  -109,  -109,  -109,    33,     1,  -109,    38,
    -109,    72,  -109,  -109,  -109,    54,    74,    74,  -109,  -109,
    -109,    79,  -109,    81,    73,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    38,  -109,  -109,    75,
      76,    78,    80,    83,    38,    38,  -109,  -109,  -109,    38,
       1,     1,    -5,    -5,    -5,    -5,    -5,    -5,     1,  -109,
    -109,  -109,    57,  -109,  -109,  -109,  -109,    37,  -109,    61,
    -109,    82,    -5,    59,    -5,    38,  -109,    14,    85,    61,
    -109,    78,    60,  -109,  -109,  -109,    38,    63,    77,  -109,
    -109,    64,  -109,    84,    86,    -5,  -109,    14,    87,  -109,
    -109,    88,  -109,  -109,  -109,  -109,    14,  -109
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,    19,     0,     0,
       0,     4,    18,     0,     8,     3,     0,    38,    12,     0,
       0,     7,     6,    21,    20,     5,    40,     0,    83,    44,
       0,     0,    39,    42,    43,     9,    11,     0,    22,    24,
      52,    75,    47,    76,    77,    60,    59,    70,    74,     0,
      35,     0,    37,    10,    17,     0,    28,    28,    57,    41,
      46,     0,    45,    51,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,    36,     0,
       0,    33,     0,     0,     0,     0,    53,    49,    48,     0,
      67,    68,    61,    62,    63,    64,    65,    66,    69,    72,
      71,    73,     0,    16,    15,    13,    31,     0,    30,     0,
       4,     0,    58,     0,    56,     0,    78,     0,     0,     0,
      27,    33,     0,    23,    25,    54,     0,     0,     0,    85,
      14,     0,    29,     0,     0,    55,    50,     0,     0,    34,
       4,    82,    32,    26,    80,    79,     0,    81
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -109,  -109,  -109,  -103,  -109,  -109,  -109,  -109,    89,  -109,
    -109,  -109,  -109,   -96,  -109,  -109,  -109,  -109,  -109,  -109,
      40,  -109,   -26,  -109,  -109,    90,  -109,    91,  -108,  -109,
    -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,   -15,  -109,
    -109,   -43,  -109,   -67,   -32,   -60,  -109,  -109,  -109,  -109,
    -109,  -109,  -109,  -109
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    13,    14,    16,    21,    35,    36,    37,
     118,   105,    55,     8,    22,    23,    56,    24,    57,   134,
      82,   107,   108,   119,   109,    29,    30,    31,    32,    40,
      59,    43,    63,    88,   115,    60,    61,    86,   113,    62,
      84,    44,    45,    46,    47,    48,    33,    64,   128,   145,
     146,    34,    49,   102
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      92,    93,    94,    95,    96,    97,    77,   123,    17,   129,
      18,    65,    66,   122,    99,   100,   101,   112,   114,    74,
      75,    17,    50,   131,    26,    17,     3,    73,    26,   141,
      19,    20,    76,    90,    91,     4,    27,   143,   147,    28,
      27,    98,   120,    28,    41,   121,   116,     6,   114,    65,
      66,    15,    42,    67,    68,    69,    70,    71,    72,   135,
       9,    79,    10,    80,   125,    73,   126,    10,   136,   133,
     126,    10,     5,   138,    11,     7,    12,    52,    81,    38,
      78,    39,   -12,    85,    54,    87,    58,   117,   110,   103,
     104,   106,   111,   130,   140,   132,   124,    83,   139,    89,
     127,   142,     0,     0,   137,     0,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   144,     0,     0,     0,
       0,    51,     0,     0,    53
};

static const yytype_int16 yycheck[] =
{
      67,    68,    69,    70,    71,    72,    49,   110,    11,   117,
      13,    16,    17,   109,    74,    75,    76,    84,    85,    18,
      19,    11,    12,   119,    14,    11,     0,    32,    14,   137,
      33,    34,    31,    65,    66,     3,    26,   140,   146,    29,
      26,    73,     5,    29,     6,     8,    89,     4,   115,    16,
      17,    10,    14,    20,    21,    22,    23,    24,    25,   126,
       5,     7,     7,     9,     5,    32,     7,     7,     5,     9,
       7,     7,    14,     9,     8,    14,    14,     8,     4,    14,
       8,    14,    14,     4,    14,     4,    15,    30,     8,    14,
      14,    13,     9,     8,     8,   121,    14,    57,    14,    26,
     115,    14,    -1,    -1,    27,    -1,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    36,    37,     0,     3,    14,     4,    14,    48,     5,
       7,     8,    14,    38,    39,    10,    40,    11,    13,    33,
      34,    41,    49,    50,    52,    60,    14,    26,    29,    60,
      61,    62,    63,    81,    86,    42,    43,    44,    14,    14,
      64,     6,    14,    66,    76,    77,    78,    79,    80,    87,
      12,    62,     8,    43,    14,    47,    51,    53,    15,    65,
      70,    71,    74,    67,    82,    16,    17,    20,    21,    22,
      23,    24,    25,    32,    18,    19,    31,    76,     8,     7,
       9,     4,    55,    55,    75,     4,    72,     4,    68,    26,
      79,    79,    78,    78,    78,    78,    78,    78,    79,    80,
      80,    80,    88,    14,    14,    46,    13,    56,    57,    59,
       8,     9,    78,    73,    78,    69,    76,    30,    45,    58,
       5,     8,    48,    38,    14,     5,     7,    73,    83,    63,
       8,    48,    57,     9,    54,    78,     5,    27,     9,    14,
       8,    63,    14,    38,    28,    84,    85,    63
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    35,    37,    36,    39,    38,    40,    40,    40,    41,
      42,    42,    44,    45,    43,    46,    47,    47,    48,    48,
      49,    49,    51,    50,    53,    54,    52,    55,    55,    56,
      56,    58,    57,    59,    57,    60,    61,    61,    61,    62,
      64,    63,    63,    63,    63,    65,    65,    67,    66,    69,
      68,    68,    71,    70,    72,    73,    73,    75,    74,    76,
      76,    77,    77,    77,    77,    77,    77,    78,    78,    78,
      78,    79,    79,    79,    79,    80,    80,    82,    83,    81,
      85,    84,    84,    87,    88,    86
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     9,     0,     3,     2,     2,     0,     2,
       2,     1,     0,     0,     6,     1,     3,     1,     3,     1,
       1,     1,     0,     6,     0,     0,     9,     3,     0,     3,
       1,     0,     5,     0,     4,     3,     3,     2,     0,     1,
       0,     3,     1,     1,     1,     1,     1,     0,     3,     0,
       4,     0,     0,     2,     3,     3,     1,     0,     3,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     3,     1,     1,     1,     0,     0,     9,
       0,     3,     0,     0,     0,     6
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
#line 48 "compilador.y" /* yacc.c:1646  */
    {geraCodigo (NULL, "INPP");}
#line 1370 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 51 "compilador.y" /* yacc.c:1646  */
    {
      geraCodigo (NULL, "PARA");
   }
#line 1378 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 57 "compilador.y" /* yacc.c:1646  */
    {
      ++nivel_lexico;
   }
#line 1386 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 62 "compilador.y" /* yacc.c:1646  */
    {
      sprintf(aux_string, "DMEM  %d", encontra_qtd_simbolos_antes_de_funcao(variavel_simples, nivel_lexico));
      geraCodigo(NULL, aux_string);
      libera_simbolos_internos_de_funcao(nivel_lexico);
      --nivel_lexico;
   }
#line 1397 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 85 "compilador.y" /* yacc.c:1646  */
    { num_vars = 0; }
#line 1403 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 88 "compilador.y" /* yacc.c:1646  */
    {
      sprintf(aux_string, "AMEM  %d", num_vars);
      geraCodigo(NULL, aux_string);
      altera_tipo_tabela(inteiro, num_vars);
   }
#line 1413 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 102 "compilador.y" /* yacc.c:1646  */
    {
      insere_vs_tabela(token, nivel_lexico, encontra_qtd_simbolos_antes_de_funcao(variavel_simples, nivel_lexico));
      ++num_vars;
   }
#line 1422 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 107 "compilador.y" /* yacc.c:1646  */
    {
      insere_vs_tabela(token, nivel_lexico, encontra_qtd_simbolos_antes_de_funcao(variavel_simples, nivel_lexico));
      ++num_vars;
   }
#line 1431 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 114 "compilador.y" /* yacc.c:1646  */
    {
      ++num_vars;
      if(tipo_parametro==parametro_referencia || tipo_parametro==parametro_valor)
         insere_pf_tabela(token, nivel_lexico, tipo_parametro);
   }
#line 1441 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 119 "compilador.y" /* yacc.c:1646  */
    {
      ++num_vars;
      if(tipo_parametro==parametro_referencia || tipo_parametro==parametro_valor)
         insere_pf_tabela(token, nivel_lexico, tipo_parametro);
   }
#line 1451 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 133 "compilador.y" /* yacc.c:1646  */
    {
      GERA_E_EMPILHA_ROTULO
      sprintf(aux_string, "DSVS %s", pilha_rotulos->rotulo);
      geraCodigo(NULL, aux_string);
      insere_procedimento_tabela(token, nivel_lexico+1, procedimento);
      sprintf(aux_string, "ENPR %d", nivel_lexico + 1);
      geraCodigo(tabela_de_simbolos->info_procedimento.rotulo, aux_string);
   }
#line 1464 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 141 "compilador.y" /* yacc.c:1646  */
    {
      sprintf(aux_string, "RTPR %d, n", nivel_lexico + 1);
      geraCodigo(NULL, aux_string);
      geraCodigo(pilha_rotulos->rotulo, "NADA");
      DESEMPILHA_ROTULO(pilha_rotulos)
   }
#line 1475 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 151 "compilador.y" /* yacc.c:1646  */
    {
      GERA_E_EMPILHA_ROTULO
      sprintf(aux_string, "DSVS %s", pilha_rotulos->rotulo);
      geraCodigo(NULL, aux_string);
      insere_procedimento_tabela(token, nivel_lexico+1, funcao);
      sprintf(aux_string, "ENPR %d", nivel_lexico + 1);
      geraCodigo(tabela_de_simbolos->info_procedimento.rotulo, aux_string);
   }
#line 1488 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 158 "compilador.y" /* yacc.c:1646  */
    {
      atualiza_retorno_funcao(inteiro);
   }
#line 1496 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 160 "compilador.y" /* yacc.c:1646  */
    {
      sprintf(aux_string, "RTPR %d, n", nivel_lexico + 1);
      geraCodigo(NULL, aux_string);
      geraCodigo(pilha_rotulos->rotulo, "NADA");
      DESEMPILHA_ROTULO(pilha_rotulos)
   }
#line 1507 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 169 "compilador.y" /* yacc.c:1646  */
    {
      tipo_parametro = 0;
      atualiza_parametros_procedimento();
   }
#line 1516 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 181 "compilador.y" /* yacc.c:1646  */
    {
      tipo_parametro = parametro_referencia;
      num_vars = 0;
   }
#line 1525 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 184 "compilador.y" /* yacc.c:1646  */
    {
      altera_tipo_tabela(inteiro, num_vars);
   }
#line 1533 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 188 "compilador.y" /* yacc.c:1646  */
    {
      tipo_parametro = parametro_valor;
      num_vars = 0;
   }
#line 1542 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 192 "compilador.y" /* yacc.c:1646  */
    {
      altera_tipo_tabela(inteiro, num_vars);
   }
#line 1550 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 212 "compilador.y" /* yacc.c:1646  */
    {strcpy(aux_string, token);}
#line 1556 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 224 "compilador.y" /* yacc.c:1646  */
    {strcpy(aux_string, token);}
#line 1562 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 228 "compilador.y" /* yacc.c:1646  */
    {
      EMPILHA_FUNCAO(busca_simbolo_na_tabela(aux_string, funcao))
      geraCodigo(NULL, "AMEM 1");
      num_vars = 0;
   }
#line 1572 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 232 "compilador.y" /* yacc.c:1646  */
    {
      if(pilha_procedimentos->item->info_procedimento.qtd_parametros != num_vars)
         imprimeErro("O número de parâmtros não coincide com declaração");
      sprintf(aux_string, "CHPR %s, %d", pilha_procedimentos->item->info_procedimento.rotulo, nivel_lexico);
      geraCodigo(NULL, aux_string);
      stack_push((stack_t**)&pilha_expressao, malloc(sizeof(struct t_tipo_expressao)));
      pilha_expressao->tipo=pilha_procedimentos->item->info_procedimento.tipo_retorno;
      DESEMPILHA_SIMPLES(pilha_procedimentos)
   }
#line 1586 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 240 "compilador.y" /* yacc.c:1646  */
    {
      elem_aux = busca_simbolo_na_tabela(aux_string, variavel_ou_funcao_ou_param);
      if(elem_aux->tipo == funcao){
         EMPILHA_FUNCAO(busca_simbolo_na_tabela(token, funcao))
         geraCodigo(NULL, "AMEM 1");
         num_vars = 0;
         if(pilha_procedimentos->item->info_procedimento.qtd_parametros != num_vars)
            imprimeErro("O número de parâmtros não coincide com declaração");
         sprintf(aux_string, "CHPR %s, %d", pilha_procedimentos->item->info_procedimento.rotulo, nivel_lexico);
         geraCodigo(NULL, aux_string);
         stack_push((stack_t**)&pilha_expressao, malloc(sizeof(struct t_tipo_expressao)));
         pilha_expressao->tipo=pilha_procedimentos->item->info_procedimento.tipo_retorno;
         DESEMPILHA_SIMPLES(pilha_procedimentos)
      }
      else {
         if(pilha_procedimentos){
            if(pilha_expressao)
               imprimeErro("Argumento inválido");
            if (pilha_procedimentos->item->info_procedimento.parametros[num_vars].tipo_parametro == parametro_referencia)
               sprintf(aux_string, "CREN %d,%d", elem_aux->nivel_lexico, elem_aux->info_variavel.deslocamento);
            else
               sprintf(aux_string, "%s %d,%d", COM_CARREGA_ELEM_AUX, elem_aux->nivel_lexico, elem_aux->info_variavel.deslocamento);
         }
         else
            sprintf(aux_string, "%s %d,%d", COM_CARREGA_ELEM_AUX, elem_aux->nivel_lexico, elem_aux->info_variavel.deslocamento);
         stack_push((stack_t**)&pilha_expressao, malloc(sizeof(struct t_tipo_expressao)));
         pilha_expressao->tipo=encontra_tipo(elem_aux);
         geraCodigo(NULL, aux_string);
      }
   }
#line 1621 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 273 "compilador.y" /* yacc.c:1646  */
    {
      EMPILHA_FUNCAO(busca_simbolo_na_tabela(aux_string, procedimento))
      num_vars = 0;
   }
#line 1630 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 276 "compilador.y" /* yacc.c:1646  */
    {
      if(pilha_procedimentos->item->info_procedimento.qtd_parametros != num_vars)
         imprimeErro("O número de parâmtros não coincide com declaração");
      sprintf(aux_string, "CHPR %s, %d", pilha_procedimentos->item->info_procedimento.rotulo, nivel_lexico);
      geraCodigo(NULL, aux_string);
      DESEMPILHA_SIMPLES(pilha_procedimentos)
   }
#line 1642 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 290 "compilador.y" /* yacc.c:1646  */
    {
      if (pilha_expressao->tipo != pilha_procedimentos->item->info_procedimento.parametros[num_vars].tipo_variavel)
         imprimeErro("os tipos de variavel nao coincidem");
      free(stack_pop((stack_t **)&pilha_expressao));
      ++num_vars;
   }
#line 1653 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 296 "compilador.y" /* yacc.c:1646  */
    {
      if (pilha_expressao->tipo != pilha_procedimentos->item->info_procedimento.parametros[num_vars].tipo_variavel)
         imprimeErro("os tipos de variavel nao coincidem");
      free(stack_pop((stack_t **)&pilha_expressao));
      ++num_vars;
   }
#line 1664 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 305 "compilador.y" /* yacc.c:1646  */
    {
      l_elem = busca_simbolo_na_tabela(aux_string, variavel_ou_parametro);
      if(!l_elem){
         sprintf(aux_string, "A variavel %s nao foi encontrada", aux_string);
         imprimeErro(aux_string);
      }
   }
#line 1676 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 311 "compilador.y" /* yacc.c:1646  */
    {
      // ADICIONAR ERRO CASO SIMBOLOS DE TIPOS DIFERENTES
      if(encontra_tipo(l_elem) != pilha_expressao->tipo)
         imprimeErro("os tipos de variavel nao coincidem");
      free(stack_pop((stack_t **)&pilha_expressao));
      sprintf(aux_string, "%s %d,%d", COM_ARMAZENA_L_ELEM, l_elem->nivel_lexico, l_elem->info_variavel.deslocamento);
      geraCodigo(NULL, aux_string);

   }
#line 1690 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 323 "compilador.y" /* yacc.c:1646  */
    {
      if(pilha_expressao->tipo != booleano)
         imprimeErro("a expressao deve retornar um booleano");
      free(stack_pop((stack_t **)&pilha_expressao));
      ;
   }
#line 1701 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 329 "compilador.y" /* yacc.c:1646  */
    {
      if(pilha_expressao->tipo != booleano)
         imprimeErro("a expressao deve retornar um booleano");
      free(stack_pop((stack_t **)&pilha_expressao));
   }
#line 1711 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 337 "compilador.y" /* yacc.c:1646  */
    {
      COMPARA_T_RELACAO_BOOLEANA_E_POP
      geraCodigo(NULL, "CMIG");
   }
#line 1720 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 341 "compilador.y" /* yacc.c:1646  */
    {
      COMPARA_T_RELACAO_BOOLEANA_E_POP
      geraCodigo(NULL, "CMDG");
   }
#line 1729 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 345 "compilador.y" /* yacc.c:1646  */
    {
      COMPARA_T_RELACAO_BOOLEANA_E_POP
      geraCodigo(NULL, "CMME");
   }
#line 1738 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 349 "compilador.y" /* yacc.c:1646  */
    {
      COMPARA_T_RELACAO_BOOLEANA_E_POP
      geraCodigo(NULL, "CMIG");
   }
#line 1747 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 353 "compilador.y" /* yacc.c:1646  */
    {
      COMPARA_T_RELACAO_BOOLEANA_E_POP
      geraCodigo(NULL, "CMMA");
   }
#line 1756 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 357 "compilador.y" /* yacc.c:1646  */
    {
      COMPARA_T_RELACAO_BOOLEANA_E_POP
      geraCodigo(NULL, "CMAG");
   }
#line 1765 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 364 "compilador.y" /* yacc.c:1646  */
    {
      COMPARA_T_EXPRESSAO_E_POP
      geraCodigo(NULL, "SOMA");
   }
#line 1774 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 368 "compilador.y" /* yacc.c:1646  */
    {
      COMPARA_T_EXPRESSAO_E_POP
      geraCodigo(NULL, "SUBT");
   }
#line 1783 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 372 "compilador.y" /* yacc.c:1646  */
    {
      COMPARA_T_EXPRESSAO_E_POP
   }
#line 1791 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 379 "compilador.y" /* yacc.c:1646  */
    {
      COMPARA_T_EXPRESSAO_E_POP
      geraCodigo(NULL, "MULT");
   }
#line 1800 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 383 "compilador.y" /* yacc.c:1646  */
    {
      COMPARA_T_EXPRESSAO_E_POP
      geraCodigo(NULL, "DIVI");
   }
#line 1809 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 387 "compilador.y" /* yacc.c:1646  */
    {
      COMPARA_T_EXPRESSAO_E_POP
   }
#line 1817 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 394 "compilador.y" /* yacc.c:1646  */
    {
      stack_push((stack_t**)&pilha_expressao, malloc(sizeof(struct t_tipo_expressao)));
      pilha_expressao->tipo=inteiro;
      sprintf(aux_string, "CRCT %s", token);
      geraCodigo(NULL, aux_string);
   }
#line 1828 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 404 "compilador.y" /* yacc.c:1646  */
    {
      GERA_E_EMPILHA_ROTULO
      sprintf(aux_string, "DSVF %s", pilha_rotulos->rotulo);
      geraCodigo(NULL, aux_string);
   }
#line 1838 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 409 "compilador.y" /* yacc.c:1646  */
    {
      GERA_E_EMPILHA_ROTULO
      sprintf(aux_string, "DSVF %s", pilha_rotulos->rotulo);
      geraCodigo(NULL, aux_string);
   }
#line 1848 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 418 "compilador.y" /* yacc.c:1646  */
    {
      GERA_E_EMPILHA_ROTULO
      sprintf(aux_string, "DSVS %s", pilha_rotulos->rotulo);
      geraCodigo(NULL, aux_string);
      geraCodigo(pilha_rotulos->next->rotulo, "NADA");
   }
#line 1859 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 423 "compilador.y" /* yacc.c:1646  */
    {
      geraCodigo(pilha_rotulos->rotulo, "NADA");
      DESEMPILHA_ROTULO(pilha_rotulos)
      DESEMPILHA_ROTULO(pilha_rotulos)
   }
#line 1869 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 427 "compilador.y" /* yacc.c:1646  */
    {
      geraCodigo(pilha_rotulos->rotulo, "NADA");
      DESEMPILHA_ROTULO(pilha_rotulos)
   }
#line 1878 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 435 "compilador.y" /* yacc.c:1646  */
    {
      GERA_E_EMPILHA_ROTULO
      sprintf(aux_string, "NADA");
      geraCodigo(pilha_rotulos->rotulo, aux_string);
   }
#line 1888 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 440 "compilador.y" /* yacc.c:1646  */
    {
      GERA_E_EMPILHA_ROTULO
      sprintf(aux_string, "DSVF %s", pilha_rotulos->rotulo);
      geraCodigo(NULL, aux_string);
   }
#line 1898 "compilador.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 445 "compilador.y" /* yacc.c:1646  */
    {
      sprintf(aux_string, "DSVS %s", pilha_rotulos->next->rotulo);
      geraCodigo(NULL, aux_string);
      geraCodigo(pilha_rotulos->rotulo, "NADA");
      DESEMPILHA_ROTULO(pilha_rotulos)
      DESEMPILHA_ROTULO(pilha_rotulos)
   }
#line 1910 "compilador.tab.c" /* yacc.c:1646  */
    break;


#line 1914 "compilador.tab.c" /* yacc.c:1646  */
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
#line 454 "compilador.y" /* yacc.c:1906  */


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

