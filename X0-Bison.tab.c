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
#line 1 "X0-Bison.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <string.h>
#include <math.h>

#define bool 			int
#define true 			1
#define false 			0

#define SYM_TABLE 		200				// Max Capicity of symbol table
#define ID_NAME_LEN		20				// Max length of ident
#define ADDRESS_MAX		8000			// Upper bound of the address
#define DEPTH_MAX		10				// Max depth of declaration, Un used
#define CODE_MAX		1000			// Max Virtual Machine code amount
#define STACK_SIZE		8000			// Max Run-Time stack element amount
#define STRING_LEN		201				// Max length of const string
#define ERROR_MAG_NUM	1145141919810	// For error processing
#define MAX_ARR_DIM		10				// Max dimension of the array
#define FLOAT_EPS		0.001			// Using for float opran comparing

typedef unsigned char byte;
int cnt = 0;
enum object {
	constant_int,
	constant_real,
	constant_bool,
	constant_string,
	constant_char,
	variable_int,
	variable_real,
	variable_bool,
	variable_string,
	variable_char,
	constant_int_array,
	variable_int_array,
	constant_real_array,
	variable_real_array,
	constant_char_array,
	variable_char_array,
	constant_bool_array,
	variable_bool_array,
	constant_string_array,
	variable_string_array,
};

struct symbol_table {
	char 	name[ID_NAME_LEN];
	enum 	object kind;
	int 	addr;
	byte 	val[STRING_LEN];			// Use byte to store all kind of data, use pointer to specify them
	int		init_or_not;
	int		array_size;
	int 	array_const_or_not;
	int 	array_dim[MAX_ARR_DIM];
//	void*	val;						// Using pointer to specify unlimitted length constant string @todo: in the future.
};

struct symbol_table table[SYM_TABLE];	// Store all symbol

enum data_type {
	integer,		real,
	single_char,	boolean,
	str,
};

struct data_stack {
	enum 	data_type t;				// current un-used
	byte 	val[STRING_LEN];
};

enum fct {
	lit,	opr,	lod,
	sto,	cal,	ini,
	jmp,	jpc,	off,
};

struct instruction {
	enum 	fct f;
	int 	lev;						// Used for type identifying
										// For all ato lod opr, this should be use to specify type
										// 2 for integer
										// 3 for real
										// 4 for string
										// 5 for bool
										// 6 for char
	byte	opr[STRING_LEN];
};

struct instruction code[CODE_MAX];		// Store V-Machine code

int			sym_tab_tail;
int			vm_code_pointer = 0;
char		id_name[ID_NAME_LEN];
int			outter_int;
float		outter_real;
bool		outter_bool;
char		outter_char;
char		outter_string[STRING_LEN];
int			output_int;
float		output_real;
bool		output_bool;
char		output_char;
char		output_string[STRING_LEN];
int			err_num;
int			constant_decl_or_not = 0;
int 		var_decl_with_init_or_not = 0;
int			cur_decl_type = -1;
char		curr_read_write_ident[ID_NAME_LEN];
int 		curr_address = 3;
int 		inbuf_int;
float		inbuf_real;
char		inbuf_char;
char		inbuf_string[STRING_LEN];
char		inbuf_bool[6];
int			bool_flag;
int			arr_size = 0;
int			tmp_arr_list[MAX_ARR_DIM];
int			tmp_arr_dim_idx = 0;
struct 		data_stack s[STACK_SIZE];
int 		stack_top = 2;
int 		array_offset;
int 		tmp_arr_cur_dim;
int 		glob_var_addr;
int			back_patch_list[STRING_LEN];
int			back_patch_idx = 0;
int 		curr_ident_array_or_not = 0;
int			static_back_patch_idx;
int			static_back_patch_val;
int			else_compound;

struct expression_result {
	enum	data_type	t;
	int		res_int;
	float	res_real;
	bool	res_bool;
	char	res_char;
	char	res_string[STRING_LEN];
};

struct expression_result e_res;

FILE*		fin;
FILE*		ftable;
FILE*		fcode;
FILE*		foutput;
FILE*		fresult;
char		fname;
int 		err;
extern int	line;

void 		init();
void		enter(enum object k);
void 		gen(enum fct x, int y, byte* z);


#line 225 "X0-Bison.tab.c" /* yacc.c:339  */

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
   by #include "X0-Bison.tab.h".  */
#ifndef YY_YY_X0_BISON_TAB_H_INCLUDED
# define YY_YY_X0_BISON_TAB_H_INCLUDED
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
    BOOLSYM = 258,
    BREAKSYM = 259,
    CALLSYM = 260,
    CASESYM = 261,
    CHARSYM = 262,
    CONSTSYM = 263,
    CONTINUESYM = 264,
    DOSYM = 265,
    ELSESYM = 266,
    EXITSYM = 267,
    FORSYM = 268,
    INTSYM = 269,
    IFSYM = 270,
    MAINSYM = 271,
    READSYM = 272,
    REALSYM = 273,
    REPEATSYM = 274,
    RR = 275,
    RL = 276,
    STRINGSYM = 277,
    SWITCHSYM = 278,
    UNTILSYM = 279,
    WHILESYM = 280,
    WRITESYM = 281,
    LBRACE = 282,
    RBRACE = 283,
    LBRACKET = 284,
    RBRACKET = 285,
    BECOMES = 286,
    COMMA = 287,
    LSS = 288,
    LEQ = 289,
    GTR = 290,
    GEQ = 291,
    EQL = 292,
    NEQ = 293,
    PLUS = 294,
    INCPLUS = 295,
    MINUS = 296,
    INCMINUS = 297,
    TIMES = 298,
    DEVIDE = 299,
    LPAREN = 300,
    RPAREN = 301,
    MOD = 302,
    SEMICOLON = 303,
    XOR = 304,
    AND = 305,
    OR = 306,
    NOT = 307,
    YAJU = 308,
    YARIMASUNESYM = 309,
    KIBONOHANASYM = 310,
    IDENT = 311,
    INTEGER = 312,
    STRING = 313,
    CHAR = 314,
    BOOL = 315,
    REAL = 316
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 160 "X0-Bison.y" /* yacc.c:355  */

	char 	*ident;
	int 	number;
	char 	*text;
	char 	single_char;
	int 	flag;
	double 	realnumber;

#line 336 "X0-Bison.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_X0_BISON_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 353 "X0-Bison.tab.c" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   198

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  165

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   316

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   191,   191,   195,   190,   201,   202,   203,   206,   207,
     207,   212,   212,   212,   213,   217,   213,   220,   221,   224,
     251,   313,   314,   315,   316,   317,   320,   321,   324,   378,
     382,   388,   393,   394,   395,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   412,   415,   418,
     422,   425,   422,   432,   435,   441,   501,   501,   509,   512,
     515,   556,   618,   621,   627,   628,   631,   631,   645,   650,
     651,   660,   670,   677,   680,   683,   688,   691,   694,   697,
     700,   703,   706,   709,   712,   717,   720,   727,   730,   735,
     738,   745,   748,   751,   756,   759,   796,   801,   806,   811,
     816,   821
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BOOLSYM", "BREAKSYM", "CALLSYM",
  "CASESYM", "CHARSYM", "CONSTSYM", "CONTINUESYM", "DOSYM", "ELSESYM",
  "EXITSYM", "FORSYM", "INTSYM", "IFSYM", "MAINSYM", "READSYM", "REALSYM",
  "REPEATSYM", "RR", "RL", "STRINGSYM", "SWITCHSYM", "UNTILSYM",
  "WHILESYM", "WRITESYM", "LBRACE", "RBRACE", "LBRACKET", "RBRACKET",
  "BECOMES", "COMMA", "LSS", "LEQ", "GTR", "GEQ", "EQL", "NEQ", "PLUS",
  "INCPLUS", "MINUS", "INCMINUS", "TIMES", "DEVIDE", "LPAREN", "RPAREN",
  "MOD", "SEMICOLON", "XOR", "AND", "OR", "NOT", "YAJU", "YARIMASUNESYM",
  "KIBONOHANASYM", "IDENT", "INTEGER", "STRING", "CHAR", "BOOL", "REAL",
  "$accept", "program", "$@1", "$@2", "declaration_list",
  "declaration_stat", "$@3", "$@4", "$@5", "$@6", "$@7", "identlist",
  "identdef", "typeenum", "identarraylist", "identarraydef",
  "dimensionlist", "dimension", "statement_list", "statement",
  "continue_stat", "break_stat", "if_statement", "$@8", "$@9",
  "while_statement", "write_statement", "read_statement",
  "compound_statement", "$@10", "for_statement", "do_statement", "var",
  "expression_list", "expression_statement", "expression", "$@11",
  "simple_expr", "SINGLEOPR", "OPR", "additive_expr", "PLUSMINUS", "term",
  "TIMESDEVIDE", "factor", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316
};
# endif

#define YYPACT_NINF -83

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-83)))

#define YYTABLE_NINF -67

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -9,   -83,    13,    15,   -83,   117,   -83,   -40,   -83,    65,
     -29,    21,     9,   -83,    14,    32,   -83,   -83,    33,    36,
     -83,   -83,   -83,   -36,   -83,   -83,   -83,    24,   -83,   -83,
     -83,   -83,   -83,    77,   -83,     4,   117,   -83,   -83,   -83,
     -83,   -83,   -83,   -83,   -83,   -83,   -83,    51,   -83,    38,
     -83,   -27,   146,    -8,   -83,   -83,   -83,   -83,    64,   -36,
     -36,    41,   -36,   -36,   117,    46,   -36,   -83,   -19,   -21,
     -83,    66,   -83,    84,   -83,    83,   -83,   -83,     8,   -83,
     -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,
     -83,   -27,   -27,   -83,   -83,   -83,   -27,    60,    62,    74,
      75,    76,    82,    90,    91,    48,   -83,    37,   -83,    72,
     -27,    60,   -83,    62,    92,   -83,   -36,     8,    -8,   -83,
     107,   109,   116,    66,   -36,   -36,    21,    98,    21,    99,
     -83,   -83,   -36,   -83,    81,   -83,   -83,   -83,   -83,   -83,
     -83,   100,   101,   106,   105,   143,   -83,   -83,   -83,   -83,
     -83,    72,   -83,   -83,   108,   -36,   144,   -83,   -83,   112,
     -83,    21,    21,   -83,   -83
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     2,     0,     0,     1,     7,    23,     0,    25,     0,
       0,     0,     0,    21,     0,     0,    24,    22,     0,     0,
      56,    73,    74,     0,    65,    75,   101,    60,    96,    98,
     100,    99,    97,    43,     6,     0,     3,    33,    44,    45,
      36,    37,    39,    38,    40,    41,    42,    95,    35,     0,
      68,     0,    69,    85,    89,    48,    11,    47,     0,     0,
       0,     0,     0,     0,     7,     0,     0,     5,    19,     0,
      17,     9,    26,     0,    32,     0,    64,    95,    72,    78,
      79,    80,    81,    76,    77,    87,    88,    84,    82,    83,
      71,     0,     0,    91,    92,    93,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    94,     0,    62,     0,
       0,     0,     8,     0,     0,     4,     0,    70,    86,    90,
      19,    12,     0,    15,     0,     0,     0,     0,     0,     0,
      57,    61,     0,    31,     0,    29,    20,    18,    27,    10,
      67,     0,     0,     0,     0,    49,    55,    53,    54,    63,
      28,     0,    13,    16,     0,     0,     0,    30,    59,     0,
      51,     0,     0,    58,    52
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -83,   -83,   -83,   -83,   -83,   127,   -83,   -83,   -83,   -83,
     -83,    67,    50,   154,    68,    54,   -83,    17,   125,   -34,
     -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -11,   -83,
     -83,   -83,   -46,   -83,   -83,   -22,   -83,   -83,   119,   -83,
     -48,   -83,    80,   -83,   -82
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    73,    33,    34,   114,    97,   141,    98,
     142,    69,    70,    35,    71,    72,   134,   135,    36,    37,
      38,    39,    40,   156,   162,    41,    42,    43,    44,    64,
      45,    46,    47,   107,    48,    49,    75,    50,    51,    91,
      52,    92,    53,    96,    54
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      58,    65,    74,    78,    21,    77,    22,     1,    55,    23,
     109,   111,   110,     4,   119,   102,    25,    26,    23,    57,
      27,    28,    29,    30,    31,    32,    26,   112,   136,    27,
      28,    29,    30,    31,    32,    93,    94,   100,   101,    95,
     103,   104,     5,   117,   108,    77,    77,    85,    20,    86,
      77,     6,     7,    66,    59,     8,     9,    10,    11,    60,
      68,    12,    13,    14,    77,    15,    16,   131,     6,   132,
      17,    74,     8,    18,    19,    20,   130,    61,    62,    13,
       6,    63,   -66,    16,     8,     9,    76,    17,    21,    99,
      22,    13,   106,    23,   140,    16,    24,    27,   113,    17,
      25,    26,   143,   144,    27,    28,    29,    30,    31,    32,
     149,   150,   115,   151,   116,   145,   120,   147,   122,   124,
       6,     7,   126,   125,     8,     9,    10,    11,   127,   133,
      12,    13,    14,   159,    15,    16,   128,   129,   110,    17,
     139,   111,    18,    19,    20,   109,   146,   148,   152,   153,
     163,   164,   154,   155,   -50,   160,   158,    21,   161,    22,
      67,   137,    23,    56,   121,    24,   123,   138,   157,    25,
      26,    90,   118,    27,    28,    29,    30,    31,    32,    79,
      80,    81,    82,    83,    84,    85,    21,    86,    22,   105,
       0,     0,     0,     0,     0,    87,    88,    89,    25
};

static const yytype_int16 yycheck[] =
{
      11,    23,    36,    51,    40,    51,    42,    16,    48,    45,
      29,    32,    31,     0,    96,    61,    52,    53,    45,    48,
      56,    57,    58,    59,    60,    61,    53,    48,   110,    56,
      57,    58,    59,    60,    61,    43,    44,    59,    60,    47,
      62,    63,    27,    91,    66,    91,    92,    39,    27,    41,
      96,     3,     4,    29,    45,     7,     8,     9,    10,    45,
      56,    13,    14,    15,   110,    17,    18,    30,     3,    32,
      22,   105,     7,    25,    26,    27,    28,    45,    45,    14,
       3,    45,    31,    18,     7,     8,    48,    22,    40,    25,
      42,    14,    46,    45,   116,    18,    48,    56,    32,    22,
      52,    53,   124,   125,    56,    57,    58,    59,    60,    61,
     132,    30,    28,    32,    31,   126,    56,   128,    56,    45,
       3,     4,    46,    48,     7,     8,     9,    10,    46,    57,
      13,    14,    15,   155,    17,    18,    46,    46,    31,    22,
      48,    32,    25,    26,    27,    29,    48,    48,    48,    48,
     161,   162,    46,    48,    11,    11,    48,    40,    46,    42,
      33,   111,    45,     9,    97,    48,    98,   113,   151,    52,
      53,    52,    92,    56,    57,    58,    59,    60,    61,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    64,
      -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    16,    63,    64,     0,    27,     3,     4,     7,     8,
       9,    10,    13,    14,    15,    17,    18,    22,    25,    26,
      27,    40,    42,    45,    48,    52,    53,    56,    57,    58,
      59,    60,    61,    66,    67,    75,    80,    81,    82,    83,
      84,    87,    88,    89,    90,    92,    93,    94,    96,    97,
      99,   100,   102,   104,   106,    48,    75,    48,    90,    45,
      45,    45,    45,    45,    91,    97,    29,    67,    56,    73,
      74,    76,    77,    65,    81,    98,    48,    94,   102,    33,
      34,    35,    36,    37,    38,    39,    41,    49,    50,    51,
     100,   101,   103,    43,    44,    47,   105,    69,    71,    25,
      97,    97,    94,    97,    97,    80,    46,    95,    97,    29,
      31,    32,    48,    32,    68,    28,    31,   102,   104,   106,
      56,    73,    56,    76,    45,    48,    46,    46,    46,    46,
      28,    30,    32,    57,    78,    79,   106,    74,    77,    48,
      97,    70,    72,    97,    97,    90,    48,    90,    48,    97,
      30,    32,    48,    48,    46,    48,    85,    79,    48,    97,
      11,    46,    86,    90,    90
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    64,    65,    63,    66,    66,    66,    67,    68,
      67,    69,    70,    67,    71,    72,    67,    73,    73,    74,
      74,    75,    75,    75,    75,    75,    76,    76,    77,    78,
      78,    79,    80,    80,    80,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    82,    83,    84,
      85,    86,    84,    87,    88,    89,    91,    90,    92,    93,
      94,    94,    95,    95,    96,    96,    98,    97,    97,    99,
      99,    99,    99,   100,   100,   100,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   102,   102,   103,   103,   104,
     104,   105,   105,   105,   106,   106,   106,   106,   106,   106,
     106,   106
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     6,     2,     1,     0,     3,     0,
       4,     0,     0,     6,     0,     0,     6,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     3,     4,     1,
       3,     1,     2,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     2,     2,     5,
       0,     0,     9,     5,     5,     5,     0,     4,     9,     7,
       1,     4,     1,     3,     2,     1,     0,     4,     1,     1,
       3,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1
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
#line 191 "X0-Bison.y" /* yacc.c:1646  */
    {	
						}
#line 1572 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 195 "X0-Bison.y" /* yacc.c:1646  */
    {
						
						}
#line 1580 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 206 "X0-Bison.y" /* yacc.c:1646  */
    { /* Why can't me add sth after typeenum?? */ }
#line 1586 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 207 "X0-Bison.y" /* yacc.c:1646  */
    { 
						  	constant_decl_or_not = 0; 
							memset(tmp_arr_list, 0, sizeof tmp_arr_list); 
							tmp_arr_dim_idx = 0;
						}
#line 1596 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 212 "X0-Bison.y" /* yacc.c:1646  */
    { constant_decl_or_not = 1; }
#line 1602 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 212 "X0-Bison.y" /* yacc.c:1646  */
    { constant_decl_or_not = 0; }
#line 1608 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 213 "X0-Bison.y" /* yacc.c:1646  */
    { 
						  	constant_decl_or_not = 1; 
							memset(tmp_arr_list, 0, sizeof tmp_arr_list); 
							tmp_arr_dim_idx = 0;
						}
#line 1618 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 217 "X0-Bison.y" /* yacc.c:1646  */
    { constant_decl_or_not = 0; }
#line 1624 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 224 "X0-Bison.y" /* yacc.c:1646  */
    {
							if (constant_decl_or_not == 1) {		// Constant without initialize, error
								yyerror("Constants require initialization!\n");
								return 1;
							} 
							else {
								var_decl_with_init_or_not = 0;
								strcpy(id_name, (yyvsp[0].ident));
								switch (cur_decl_type) {
									case 2:
										enter(variable_int);
										break;
									case 3:
										enter(variable_real);
										break;
									case 4:
										enter(variable_string);
										break;
									case 5:
										enter(variable_bool);
										break;
									case 6:
										enter(variable_char);
										break;
								}
							}
	 					}
#line 1656 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 251 "X0-Bison.y" /* yacc.c:1646  */
    {
						  	if (constant_decl_or_not == 1) {		// Constant declaration
								if (cur_decl_type != (yyvsp[0].number)) {
									yyerror("Inconpitable type!\n");
								}
								else {
								strcpy(id_name, (yyvsp[-2].ident));
									switch (cur_decl_type) {
										case 2:
											enter(constant_int);
											break;
										case 3:
											enter(constant_real);
											break;
										case 4:
											enter(constant_string);
											break;
										case 5:
											enter(constant_bool);
											break;
										case 6:
											enter(constant_char);
											break;
									}
								}
							}
							else {									// Variable declaration, pre-init required?
								var_decl_with_init_or_not = 1;
								strcpy(id_name, (yyvsp[-2].ident));
									switch (cur_decl_type) {
										case 2:
											enter(variable_int);
											break;
										case 3:
											enter(variable_real);
											break;
										case 4:
											enter(variable_string);
											break;
										case 5:
											enter(variable_bool);
											break;
										case 6:
											enter(variable_char);
											break;
									}
								//}
								int id_addr = 0;
								enum object tmp;
								for (int i = 1; i <= sym_tab_tail; i++) {
									if (strcmp((yyvsp[-2].ident), table[i].name) == 0) {
										id_addr = table[i].addr;
										tmp = table[i].kind;
										break;
									}
								}
								gen(sto, cur_decl_type, (byte*)id_addr);
								var_decl_with_init_or_not = 0;
							}
					  	}
#line 1721 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 313 "X0-Bison.y" /* yacc.c:1646  */
    { cur_decl_type = 2; }
#line 1727 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 314 "X0-Bison.y" /* yacc.c:1646  */
    { cur_decl_type = 4; }
#line 1733 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 315 "X0-Bison.y" /* yacc.c:1646  */
    { cur_decl_type = 5; }
#line 1739 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 316 "X0-Bison.y" /* yacc.c:1646  */
    { cur_decl_type = 3; }
#line 1745 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 317 "X0-Bison.y" /* yacc.c:1646  */
    { cur_decl_type = 6; }
#line 1751 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 324 "X0-Bison.y" /* yacc.c:1646  */
    {
							arr_size = (yyvsp[-1].number);
							strcpy(id_name, (yyvsp[-3].ident));
							int i;
							for (i = 0; i < MAX_ARR_DIM; i++) {
								int tmp;
								tmp = tmp_arr_list[i];
								tmp_arr_list[i] = tmp_arr_list[MAX_ARR_DIM - 1 - i];
								tmp_arr_list[MAX_ARR_DIM - 1 - i] = tmp;
							}
							if (constant_decl_or_not == 1) {
								switch (cur_decl_type) {
									case 2:
										enter(constant_int_array);
										break;
									case 3:
										enter(constant_real_array);
										break;
									case 4:
										enter(constant_string_array);
										break;
									case 5:
										enter(constant_bool_array);
										break;
									case 6:
										enter(constant_char_array);
										break;
								}
							}
							else {
								switch (cur_decl_type) {
									case 2:
										enter(variable_int_array);
										break;
									case 3:
										enter(variable_real_array);
										break;
									case 4:
										enter(variable_string_array);
										break;
									case 5:
										enter(variable_bool_array);
										break;
									case 6:
										enter(variable_char_array);
										break;
								}
							}
							memset(tmp_arr_list, 0, sizeof tmp_arr_list);
							tmp_arr_dim_idx = 0;
							arr_size = 0;
						}
#line 1808 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 378 "X0-Bison.y" /* yacc.c:1646  */
    {
							(yyval.number) = (yyvsp[0].number);
							tmp_arr_list[tmp_arr_dim_idx++] = (yyvsp[0].number);
						}
#line 1817 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 382 "X0-Bison.y" /* yacc.c:1646  */
    {
						  	(yyval.number) = (yyvsp[-2].number) * (yyvsp[0].number);
							tmp_arr_list[tmp_arr_dim_idx++] = (yyvsp[0].number);
					  	}
#line 1826 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 388 "X0-Bison.y" /* yacc.c:1646  */
    {
							(yyval.number) = (yyvsp[0].number);
						}
#line 1834 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 418 "X0-Bison.y" /* yacc.c:1646  */
    {
							static_back_patch_val = vm_code_pointer;
							memcpy((void*)code[static_back_patch_idx].opr, (const void*)&static_back_patch_val, STRING_LEN);
						}
#line 1843 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 422 "X0-Bison.y" /* yacc.c:1646  */
    {
							static_back_patch_val = vm_code_pointer + 1;
							memcpy((void*)code[static_back_patch_idx].opr, (const void*)&static_back_patch_val, STRING_LEN);
					  	}
#line 1852 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 425 "X0-Bison.y" /* yacc.c:1646  */
    { else_compound = 1; }
#line 1858 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 425 "X0-Bison.y" /* yacc.c:1646  */
    { 
							static_back_patch_val = vm_code_pointer;
							memcpy((void*)code[static_back_patch_idx].opr, (const void*)&static_back_patch_val, STRING_LEN);
							else_compound = 0; 
						}
#line 1868 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 435 "X0-Bison.y" /* yacc.c:1646  */
    {
							int opran = 19;
							gen(opr, (yyvsp[-2].number), (byte*)opran);
						}
#line 1877 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 441 "X0-Bison.y" /* yacc.c:1646  */
    {
							int id_addr;
							enum object tmp;
							for (int i = 1; i <= sym_tab_tail; i++) {
								if (strcmp(curr_read_write_ident, table[i].name) == 0) {
									id_addr = table[i].addr;
									tmp = table[i].kind;
									break;
								}
							}
							int lev, opran;
							switch (tmp) {
								case constant_int:
								case constant_int_array:
									yyerror("Trying to change constant variable!\n");
									break;
								case variable_int:
								case variable_int_array:
									lev = 2;
									break;
								case constant_real:
								case constant_real_array:
									yyerror("Trying to change constant variable!\n");
									break;
								case variable_real:
								case variable_real_array:
									lev = 3;
									break;
								case constant_string:
								case constant_string_array:
									yyerror("Trying to change constant variable!\n");
									break;
								case variable_string:
								case variable_string_array:
									lev = 4;
									break;
								case constant_char:
								case constant_char_array:
									yyerror("Trying to change constant variable!\n");
									break;
								case variable_char:
								case variable_char_array:
									lev = 6;
									break;
								case constant_bool:
								case constant_bool_array:
									yyerror("Trying to change constant variable!\n");
									break;
								case variable_bool:
								case variable_bool_array:
									lev = 5;
									break;
							}
							opran = 20;
							gen(opr, lev, (byte*)opran);
							opran = id_addr;
							gen(sto, lev, (byte*)opran);
						}
#line 1940 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 501 "X0-Bison.y" /* yacc.c:1646  */
    {
							static_back_patch_idx = vm_code_pointer;
							int opran = 0;
							if (!else_compound) gen(jpc, 0, (byte*)opran);
							else gen(jmp, 0, (byte*)opran);
						}
#line 1951 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 515 "X0-Bison.y" /* yacc.c:1646  */
    {
							array_offset = 0;
							(yyval.number) = -1;												// var == -1 means IDENT not exists, for := using
							char name_buf[81];
							strcpy(name_buf, (yyvsp[0].ident));
							int i, flag = 0;
							for (i = 1; i <= sym_tab_tail; i++) {
								if (strcmp(name_buf, table[i].name) == 0) {
									flag++;
									if (flag == 1) strcpy(curr_read_write_ident, (yyvsp[0].ident));
									switch (table[i].kind) {
										case constant_int:
										case variable_int:
											(yyval.number) = 2;
											break;
										case constant_real:
										case variable_real:
											(yyval.number) = 3;
											break;
										case constant_string:
										case variable_string:
											(yyval.number) = 4;
											break;
										case constant_char:
										case variable_char:
											(yyval.number) = 6;
											break;
										case constant_bool:
										case variable_bool:
											(yyval.number) = 5;
											break;
									}
								}
							}
							if (flag == 0) {
								yyerror("Undefined variable!\n");
							}
							else if (flag > 1) {
								yyerror("Duplicated variable defination!\n");
							}
						}
#line 1997 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 556 "X0-Bison.y" /* yacc.c:1646  */
    {
						  	// curr_ident_array_or_not = 1;
						  	(yyval.number) = -1;
							char name_buf[81];
							int idx = -1, cnt = 0, opran = 0, base_addr;
							strcpy(name_buf, (yyvsp[-3].ident));
							int i, flag = 0;
							for (i = 1; i <= sym_tab_tail; i++) {
								if (strcmp(name_buf, table[i].name) == 0) {
									flag++;
									if (flag == 1) {
										idx = i;
										base_addr = table[i].addr;
										strcpy(curr_read_write_ident, (yyvsp[-3].ident));
									}
									switch (table[i].kind) {
										case constant_int_array:
										case variable_int_array:
											(yyval.number) = 2;
											break;
										case constant_real_array:
										case variable_real_array:
											(yyval.number) = 3;
											break;
										case constant_string_array:
										case variable_string_array:
											(yyval.number) = 4;
											break;
										case constant_char_array:
										case variable_char_array:
											(yyval.number) = 6;
											break;
										case constant_bool_array:
										case variable_bool_array:
											(yyval.number) = 5;
											break;
									}
								}
							}
							for (i = 0; i < MAX_ARR_DIM; i++) {
								tmp_arr_list[i] = table[idx].array_dim[i];
								if (tmp_arr_list[i]) cnt++;
							}
							for (i = MAX_ARR_DIM - 1; i >= 0; i--) {
								if (tmp_arr_list[i]) {
									tmp_arr_list[i] = 1;
									break;
								}
							}
							opran = base_addr;
							gen(off, cnt, (byte*)opran);
							opran = 0;
							tmp_arr_dim_idx = 0;
							if (flag == 0) {
								yyerror("Undefined variable!\n");
							}
							else if (flag > 1) {
								yyerror("Duplicated variable defination!\n");
							}
					  	}
#line 2062 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 618 "X0-Bison.y" /* yacc.c:1646  */
    {
							(yyval.number) = (yyvsp[0].number);
						}
#line 2070 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 621 "X0-Bison.y" /* yacc.c:1646  */
    {
						  	(yyvsp[-2].number) = (yyvsp[0].number);
							(yyval.number) = (yyvsp[-2].number);
					  	}
#line 2079 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 631 "X0-Bison.y" /* yacc.c:1646  */
    {
							glob_var_addr = find_addr_of_ident(curr_read_write_ident);
						}
#line 2087 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 634 "X0-Bison.y" /* yacc.c:1646  */
    {
							(yyval.number) = 0;
							if ((yyvsp[-3].number) == -1) {
								yyerror("Variable not defined!\n");
							}
							// if (curr_ident_array_or_not) {
							// 	back_patch_list[back_patch_idx++] = vm_code_pointer;
							// 	glob_var_addr = -1;
							// }
							gen(sto, (yyvsp[-3].number), (byte*)glob_var_addr);
						}
#line 2103 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 645 "X0-Bison.y" /* yacc.c:1646  */
    {
						  	(yyval.number) = (yyvsp[0].number);
					  	}
#line 2111 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 650 "X0-Bison.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[0].number); }
#line 2117 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 651 "X0-Bison.y" /* yacc.c:1646  */
    { 
						  	(yyval.number) = 5; 						// res is bool
							int opran;
							if ((yyvsp[-2].number) != (yyvsp[0].number)) {
								yyerror("Different type between bool operator!\n");
							}
							opran = (yyvsp[-1].number) + 6;					// reference line 1284 and line 679
							gen(opr, (yyvsp[-2].number), (byte*)opran);
						}
#line 2131 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 660 "X0-Bison.y" /* yacc.c:1646  */
    { 
						  	(yyval.number) = (yyvsp[-1].number);
						  	int var_addr = find_addr_of_ident(curr_read_write_ident);
							gen(lod, 2, (byte*)var_addr);
							int opran = 1;
							gen(lit, 2, (byte*)&opran);
							opran = ((yyvsp[0].number) == 1 ? 2 : 3);
							gen(opr, 2, (byte*)opran);
							gen(sto, 2, (byte*)var_addr);
						}
#line 2146 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 670 "X0-Bison.y" /* yacc.c:1646  */
    { 
						  	// @todo: Finish stuff like ++a --a 
						  	(yyval.number) = (yyvsp[0].number); 
							int var_addr = find_addr_of_ident(curr_read_write_ident);
						}
#line 2156 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 677 "X0-Bison.y" /* yacc.c:1646  */
    {
							(yyval.number) = 1;
						}
#line 2164 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 680 "X0-Bison.y" /* yacc.c:1646  */
    {
						  	(yyval.number) = 2;
					  	}
#line 2172 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 683 "X0-Bison.y" /* yacc.c:1646  */
    {
						  	(yyval.number) = 3;
					  	}
#line 2180 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 688 "X0-Bison.y" /* yacc.c:1646  */
    {
							(yyval.number) = 1;
						}
#line 2188 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 691 "X0-Bison.y" /* yacc.c:1646  */
    {
						  	(yyval.number) = 2;
					  	}
#line 2196 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 694 "X0-Bison.y" /* yacc.c:1646  */
    {
						  	(yyval.number) = 3;
					  	}
#line 2204 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 697 "X0-Bison.y" /* yacc.c:1646  */
    {
						  	(yyval.number) = 4;
					  	}
#line 2212 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 700 "X0-Bison.y" /* yacc.c:1646  */
    {
						  	(yyval.number) = 5;
					  	}
#line 2220 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 703 "X0-Bison.y" /* yacc.c:1646  */
    {
						  	(yyval.number) = 6;
					  	}
#line 2228 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 706 "X0-Bison.y" /* yacc.c:1646  */
    {
						  	(yyval.number) = 7;
					  	}
#line 2236 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 709 "X0-Bison.y" /* yacc.c:1646  */
    {
						  	(yyval.number) = 8;
					 	}
#line 2244 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 712 "X0-Bison.y" /* yacc.c:1646  */
    {
						  	(yyval.number) = 9;
					 	}
#line 2252 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 717 "X0-Bison.y" /* yacc.c:1646  */
    {
							(yyval.number) = (yyvsp[0].number);
						}
#line 2260 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 720 "X0-Bison.y" /* yacc.c:1646  */
    {
							(yyval.number) = type_max((yyvsp[-2].number), (yyvsp[0].number));
							int opran = ((yyvsp[-1].number) == 1 ? 2 : 3);
							gen(opr, (yyval.number), (byte*)opran);
					  	}
#line 2270 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 727 "X0-Bison.y" /* yacc.c:1646  */
    {
							(yyval.number) = 1;
						}
#line 2278 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 730 "X0-Bison.y" /* yacc.c:1646  */
    {
						  	(yyval.number) = 2;
					 	}
#line 2286 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 735 "X0-Bison.y" /* yacc.c:1646  */
    {
							(yyval.number) = (yyvsp[0].number);
						}
#line 2294 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 738 "X0-Bison.y" /* yacc.c:1646  */
    {
							(yyval.number) = type_max((yyvsp[-2].number), (yyvsp[0].number));
							int opran = ((yyvsp[-1].number) == 1 ? 4 : ((yyvsp[-1].number) == 2 ? 5 : 6));
							gen(opr, (yyval.number), (byte*)opran);
					  	}
#line 2304 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 745 "X0-Bison.y" /* yacc.c:1646  */
    {
							(yyval.number) = 1;
						}
#line 2312 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 748 "X0-Bison.y" /* yacc.c:1646  */
    {
						  	(yyval.number) = 2;
					  	}
#line 2320 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 751 "X0-Bison.y" /* yacc.c:1646  */
    {
						  	(yyval.number) = 3;
					  	}
#line 2328 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 756 "X0-Bison.y" /* yacc.c:1646  */
    {
							(yyval.number) = (yyvsp[-1].number);
						}
#line 2336 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 759 "X0-Bison.y" /* yacc.c:1646  */
    {
						  	(yyval.number) = (yyvsp[0].number);
							int constant_or_not = 0, idx = -1;
							int i;
							for (i = 1; i <= sym_tab_tail; i++) {
								if (strcmp(table[i].name, curr_read_write_ident) == 0) {
									switch (table[i].kind) {
										case constant_int:
										case constant_real:
										case constant_bool:
										case constant_char:
										case constant_string:
											idx = i;
											constant_or_not = 1;
											break;
									}
									break;
								}
							}
							if (constant_or_not) {										// using constant variable
								gen(lit, (yyvsp[0].number), table[idx].val);
							}
							else {
								int var_addr = find_addr_of_ident(curr_read_write_ident);
								int i;
								for (i = 1; i <= sym_tab_tail; i++) {
									if (strcmp(table[i].name, curr_read_write_ident) == 0) {
										if (table[i].init_or_not == 1) {
											memcpy((void*)&s[table[i].addr].val, (const void*)&table[i].val, STRING_LEN);
											break;
										}
									}
								}
								gen(lod, (yyvsp[0].number), (byte*)var_addr);
							}
							stack_top++;
					  	}
#line 2378 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 796 "X0-Bison.y" /* yacc.c:1646  */
    {
						  	(yyval.number) = 2;
							outter_int = (yyvsp[0].number);
							gen(lit, 2, (byte*)&outter_int);
					  	}
#line 2388 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 801 "X0-Bison.y" /* yacc.c:1646  */
    {
						  	(yyval.number) = 3;
							outter_real = (yyvsp[0].realnumber);
							gen(lit, 3, (byte*)&outter_real);
					  	}
#line 2398 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 806 "X0-Bison.y" /* yacc.c:1646  */
    {
						  	(yyval.number) = 4;
							strcpy(outter_string, (yyvsp[0].text));
							gen(lit, 4, outter_string);
					  	}
#line 2408 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 811 "X0-Bison.y" /* yacc.c:1646  */
    {
						  	(yyval.number) = 5;
							outter_bool = (yyvsp[0].flag);
							gen(lit, 5, (byte*)&outter_bool);
					  	}
#line 2418 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 816 "X0-Bison.y" /* yacc.c:1646  */
    {
						  	(yyval.number) = 6;
							outter_char = (yyvsp[0].single_char);
							gen(lit, 6, (byte*)&outter_char);
					  	}
#line 2428 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 821 "X0-Bison.y" /* yacc.c:1646  */
    {
						  	(yyval.number) = 7;
					  	}
#line 2436 "X0-Bison.tab.c" /* yacc.c:1646  */
    break;


#line 2440 "X0-Bison.tab.c" /* yacc.c:1646  */
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
#line 826 "X0-Bison.y" /* yacc.c:1906  */


void init() {
	sym_tab_tail 		= 0;
	vm_code_pointer 	= 0 ;
	outter_int 			= 0;
	outter_real 		= 0.0;
	outter_char 		= 0;
	outter_bool 		= false;
	err_num				= 0;
	strcpy(outter_string, "\0");
}

int yyerror(char *s) {
	err_num++;
	printf("%s in line %d.\n", s, line);
	fprintf(foutput, "%s in line %d.\n", s, line);
	return 0;
}

void gen(enum fct x, int y, byte z[STRING_LEN]) {
	if (vm_code_pointer > CODE_MAX) {
		printf("Program is too long!\n");
		exit(1);
	}
	// if (z > ADDRESS_MAX) {
	// 	printf("Acquiring address out of bound\n");
	// 	exit(1);
	// }
	code[vm_code_pointer].f 	= x;
	code[vm_code_pointer].lev 	= y;
	if (x == lit) memcpy((void*)(code[vm_code_pointer].opr), (const void*)z, STRING_LEN); // @todo: Fatal Problem, should be research!!!!
	else memcpy((void*)(code[vm_code_pointer].opr), (const void*)&z, STRING_LEN);
	vm_code_pointer++;
}

void enter(enum object k) {
	sym_tab_tail++;
	strcpy(table[sym_tab_tail].name, id_name);
	table[sym_tab_tail].kind = k;
	table[sym_tab_tail].init_or_not = 0;
	switch (k) {
		case constant_int:
			memcpy((void*)&table[sym_tab_tail].val, (const void*)&outter_int, STRING_LEN);
			break;
		case constant_real:
			memcpy((void*)&table[sym_tab_tail].val, (const void*)&outter_real, STRING_LEN);
			break;
		case constant_string:
			memcpy((void*)&table[sym_tab_tail].val, (const void*)&outter_string, STRING_LEN);
			break;
		case constant_char:
			memcpy((void*)&table[sym_tab_tail].val, (const void*)&outter_char, STRING_LEN);
			break;
		case constant_bool:
			memcpy((void*)&table[sym_tab_tail].val, (const void*)&outter_bool, STRING_LEN);
			break;
		case variable_int:
			if (var_decl_with_init_or_not) {
				memcpy((void*)&table[sym_tab_tail].val, (const void*)&outter_int, STRING_LEN);
				table[sym_tab_tail].init_or_not = 1;
			}
			table[sym_tab_tail].addr = curr_address++;
			break;
		case variable_real:
			if (var_decl_with_init_or_not) {
				memcpy((void*)&table[sym_tab_tail].val, (const void*)&outter_real, STRING_LEN);
				table[sym_tab_tail].init_or_not = 1;
			}
			table[sym_tab_tail].addr = curr_address++;
			break;
		case variable_string:
			if (var_decl_with_init_or_not) {
				memcpy((void*)&table[sym_tab_tail].val, (const void*)&outter_string, STRING_LEN);
				table[sym_tab_tail].init_or_not = 1;
			}
			table[sym_tab_tail].addr = curr_address++;
			break;
		case variable_char:
			if (var_decl_with_init_or_not) {
				memcpy((void*)&table[sym_tab_tail].val, (const void*)&outter_char, STRING_LEN);
				table[sym_tab_tail].init_or_not = 1;
			}
			table[sym_tab_tail].addr = curr_address++;
			break;
		case variable_bool:
			if (var_decl_with_init_or_not) {
				memcpy((void*)&table[sym_tab_tail].val, (const void*)&outter_bool, STRING_LEN);
				table[sym_tab_tail].init_or_not = 1;
			}
			table[sym_tab_tail].addr = curr_address++;
			break;
		case constant_int_array:
		case constant_real_array:
		case constant_bool_array:
		case constant_char_array:
		case constant_string_array:
			table[sym_tab_tail].array_const_or_not = 1;
		case variable_int_array:
		case variable_real_array:
		case variable_bool_array:
		case variable_char_array:
		case variable_string_array:
			table[sym_tab_tail].addr = curr_address;
			table[sym_tab_tail].array_size = arr_size;
			curr_address += arr_size;
			int j;
			for (j = 0; j < MAX_ARR_DIM; j++) {
				table[sym_tab_tail].array_dim[j] = tmp_arr_list[j];
			}
			break;
	}
}

void display_sym_tab() {			// @todo: Finish sym-table displaying
	int i, j;
	for (i = 1; i <= sym_tab_tail; i++) {
		switch (table[i].kind) {
			case constant_int:
				printf("%10d\tconstant\tinteger\t%20s:\t", i, table[i].name);
				printf("value = %d\n", *((int*)&table[i].val));
				fprintf(ftable, "%10d\tconstant\tinteger\t%20s:\t", i, table[i].name);
				fprintf(ftable, "value = %d\n", *((int*)&table[i].val));
				break;
			case constant_real:
				printf("%10d\tconstant\treal\t%20s:\t", i, table[i].name);
				printf("value = %f\n", *((float*)&table[i].val));
				fprintf(ftable, "%10d\tconstant\treal\t%20s:\t", i, table[i].name);
				fprintf(ftable, "value = %f\n", *((float*)&table[i].val));
				break;
			case constant_char:
				printf("%10d\tconstant\tchar\t%20s:\t", i, table[i].name);
				printf("value = %c\n", *((char*)&table[i].val));
				fprintf(ftable, "%10d\tconstant\tchar\t%20s:\t", i, table[i].name);
				fprintf(ftable, "value = %c\n", *((char*)&table[i].val));
				break;
			case constant_string:
				printf("%10d\tconstant\tstring\t%20s:\t", i, table[i].name);
				printf("value = %s\n", table[i].val);
				fprintf(ftable, "%10d\tconstant\tstring\t%20s:\t", i, table[i].name);
				fprintf(ftable, "value = %s\n", table[i].val);
				break;
			case constant_bool:
				printf("%10d\tconstant\tbool\t%20s:\t", i, table[i].name);
				printf("value = %s\n", (*((int*)&table[i].val) == 0) ? "false" : "true");
				fprintf(ftable, "%10d\tconstant\tbool\t%20s:\t", i, table[i].name);
				fprintf(ftable, "value = %s\n", (*((int*)&table[i].val) == 0) ? "false" : "true");
				break;
			case variable_int:
				printf("%10d\tvariable\tinteger\t%20s\taddress:%10d => ", i, table[i].name, table[i].addr);
				printf("Initialized or not = %d\n", table[i].init_or_not);
				fprintf(ftable, "%10d\tvariable\tinteger\t%20s:\t", i, table[i].name);
				fprintf(ftable, "Initialized or not = %d\n", table[i].init_or_not);
				break;
			case variable_real:
				printf("%10d\tvariable\treal\t%20s:\taddress:%10d => ", i, table[i].name, table[i].addr);
				printf("Initialized or not = %d\n", table[i].init_or_not);
				fprintf(ftable, "%10d\tvariable\treal\t%20s:\t", i, table[i].name);
				fprintf(ftable, "Initialized or not = %d\n", table[i].init_or_not);
				break;
			case variable_char:
				printf("%10d\tvariable\tcahr\t%20s:\taddress:%10d => ", i, table[i].name, table[i].addr);
				printf("Initialized or not = %d\n", table[i].init_or_not);
				fprintf(ftable, "%10d\tvariable\tchar\t%20s:\t", i, table[i].name);
				fprintf(ftable, "Initialized or not = %d\n", table[i].init_or_not);
				break;
			case variable_string:
				printf("%10d\tvariable\tstring\t%20s\taddress:%10d => ", i, table[i].name, table[i].addr);
				printf("Initialized or not = %d\n", table[i].init_or_not);
				fprintf(ftable, "%10d\tvariable\tstring\t%20s:\t", i, table[i].name);
				fprintf(ftable, "Initialized or not = %d\n", table[i].init_or_not);
				break;
			case variable_bool:
				printf("%10d\tvariable\tbool\t%20s:\taddress:%10d => ", i, table[i].name, table[i].addr);
				printf("Initialized or not = %d\n", table[i].init_or_not);
				fprintf(ftable, "%10d\tvariable\tbool\t%20s:\t", i, table[i].name);
				fprintf(ftable, "Initialized or not = %d\n", table[i].init_or_not);
				break;
			case constant_int_array:
			case constant_real_array:
			case constant_bool_array:
			case constant_char_array:
			case constant_string_array:
				printf("%10d\tconstant\tarray\t%20s:\taddress:%10d => Dimension:", i, table[i].name, table[i].addr);
				for (j = 0; j < MAX_ARR_DIM; j++) {
					printf("%2d%c", table[i].array_dim[j], j == MAX_ARR_DIM - 1 ? '\n' : ',');
				}
				fprintf(ftable, "%10d\tconstant\tarray\t%20s:\taddress:%10d\n", i, table[i].name, table[i].addr);
				break;
			case variable_int_array:
			case variable_real_array:
			case variable_bool_array:
			case variable_char_array:
			case variable_string_array:
				printf("%10d\tvariable\tarray\t%20s:\taddress:%10d => Dimension:", i, table[i].name, table[i].addr);
				for (j = 0; j < MAX_ARR_DIM; j++) {
					printf("%2d%c", table[i].array_dim[j], j == MAX_ARR_DIM - 1 ? '\n' : ',');
				}
				fprintf(ftable, "%10d\tvariable\tarray\t%20s:\taddress:%10d\n", i, table[i].name, table[i].addr);
				break;
		}
	}
}

int find_addr_of_ident(char *s) {
	int addr = -1;
	int i;
	for (i = 1; i <= sym_tab_tail; i++) {
		if (strcmp(table[i].name, s) == 0) {
			addr = table[i].addr;
			break;
		}
	}
	return addr;
}

void interpret() {
	// Unknown error of unexpected output!
	int 		pc = 0;
	int 		base = 1;
	struct 		instruction i;
	int			addr;
	int			iter;
	int			jter;
	int			res;
	int 		addr_to_find_array_in_table;
	int			bool_opr1, bool_opr2;
	memset(inbuf_string, 0, sizeof inbuf_string);
	printf("Start X0\n");
	fprintf(fresult, "Start X0\n");
	do {
		i = code[pc];
		pc = pc + 1;
		switch (i.f) {
			case lit:
				stack_top++;
				memcpy((void*)(&(s[stack_top].val)), (const void*)(&i.opr), STRING_LEN);
				switch (i.lev) {
					case 2:
						s[stack_top].t = integer;
						break;
					case 3:
						s[stack_top].t = real;
						break;
					case 4:
						s[stack_top].t = str;
						break;
					case 5:
						s[stack_top].t = boolean;
						break;
					case 6:
						s[stack_top].t = single_char;
						break;
				}
				break;
			case opr:
				switch (*(int*)&(i.opr)) {
					case 0:								// return
						stack_top = base - 1;
						pc = *(int*)(&(s[stack_top + 3].val));
						base = *(int*)(&(s[stack_top + 2].val));
						break;
					case 1:								// Negative
						break;
					case 2:								// 2 opr +
						stack_top--;
						switch (s[stack_top].t) {
							case integer:
								switch (s[stack_top + 1].t) {
									case integer:
										outter_int = *(int*)&s[stack_top].val + *(int*)&s[stack_top + 1].val;
										memcpy((void*)s[stack_top].val, (const void*)&outter_int, STRING_LEN);
										s[stack_top].t = integer;
										break;
									case real:
										s[stack_top + 1].t = real;
										s[stack_top].t = real;
										outter_real = (float)*(int*)&s[stack_top].val + *(float*)&s[stack_top + 1].val;
										memcpy((void*)s[stack_top].val, (const void*)&outter_real, STRING_LEN);
										break;
									default: {
										yyerror("Operators Incompitable!\n");
									}
								}
								break;
							case real:
								switch (s[stack_top + 1].t) {
									case real:
										outter_real = *(float*)&s[stack_top].val + *(float*)&s[stack_top + 1].val;
										memcpy((void*)s[stack_top].val, (const void*)&outter_real, STRING_LEN);
										s[stack_top].t = real;
										break;
									case integer:
										s[stack_top + 1].t = real;
										s[stack_top].t = real;
										outter_real = *(float*)&s[stack_top].val + (float)*(int*)&s[stack_top + 1].val;
										memcpy((void*)s[stack_top].val, (const void*)&outter_real, STRING_LEN);
										break;
								}
								break;
							case str:
								// @todo: implement strcat
								break;
							case single_char:
							case boolean: 
								yyerror("Operant not support + operation!\n");
								break;
							
						}
						break;
					case 3:								// 2 opr -
						stack_top--;
						switch (s[stack_top].t) {
							case integer:
								switch (s[stack_top + 1].t) {
									case integer:
										outter_int = *(int*)&s[stack_top].val - *(int*)&s[stack_top + 1].val;
										memcpy((void*)s[stack_top].val, (const void*)&outter_int, STRING_LEN);
										s[stack_top].t = integer;
										break;
									case real:
										s[stack_top + 1].t = real;
										s[stack_top].t = real;
										outter_real = (float)*(int*)&s[stack_top].val - *(float*)&s[stack_top + 1].val;
										memcpy((void*)s[stack_top].val, (const void*)&outter_real, STRING_LEN);
										break;
									default: {
										yyerror("Operators Incompitable!\n");
									}
								}
								break;
							case real:
								switch (s[stack_top + 1].t) {
									case real:
										outter_real = *(float*)&s[stack_top].val - *(float*)&s[stack_top + 1].val;
										memcpy((void*)s[stack_top].val, (const void*)&outter_real, STRING_LEN);
										s[stack_top].t = real;
										break;
									case integer:
										s[stack_top + 1].t = real;
										s[stack_top].t = real;
										outter_real = *(float*)&s[stack_top].val - (float)*(int*)&s[stack_top + 1].val;
										memcpy((void*)s[stack_top].val, (const void*)&outter_real, STRING_LEN);
										break;
								}
								break;
							case str:
								break;
							case single_char:
							case boolean: 
								yyerror("Operant not support - operation!\n");
								break;
						}
						break;
					case 4:								// 2 opr *
						stack_top--;
						switch (s[stack_top].t) {
							case integer:
								switch (s[stack_top + 1].t) {
									case integer:
										outter_int = *(int*)&s[stack_top].val * *(int*)&s[stack_top + 1].val;
										memcpy((void*)s[stack_top].val, (const void*)&outter_int, STRING_LEN);
										s[stack_top].t = integer;
										break;
									case real:
										s[stack_top + 1].t = real;
										s[stack_top].t = real;
										outter_real = (float)*(int*)&s[stack_top].val * *(float*)&s[stack_top + 1].val;
										memcpy((void*)s[stack_top].val, (const void*)&outter_real, STRING_LEN);
										break;
									default: {
										yyerror("Operators Incompitable!\n");
									}
								}
								break;
							case real:
								switch (s[stack_top + 1].t) {
									case real:
										outter_real = *(float*)&s[stack_top].val * *(float*)&s[stack_top + 1].val;
										memcpy((void*)s[stack_top].val, (const void*)&outter_real, STRING_LEN);
										s[stack_top].t = real;
										break;
									case integer:
										s[stack_top + 1].t = real;
										s[stack_top].t = real;
										outter_real = *(float*)&s[stack_top].val * (float)*(int*)&s[stack_top + 1].val;
										memcpy((void*)s[stack_top].val, (const void*)&outter_real, STRING_LEN);
										break;
								}
								break;
							case str:
							case single_char:
							case boolean: 
								yyerror("Operant not support * operation!\n");
								break;
						}
						break;
					case 5:								// 2 opr /
						stack_top--;
						switch (s[stack_top].t) {
							case integer:
								switch (s[stack_top + 1].t) {
									case integer:
										outter_int = *(int*)&s[stack_top].val / *(int*)&s[stack_top + 1].val;
										memcpy((void*)s[stack_top].val, (const void*)&outter_int, STRING_LEN);
										s[stack_top].t = integer;
										break;
									case real:
										s[stack_top + 1].t = real;
										s[stack_top].t = real;
										outter_real = (float)*(int*)&s[stack_top].val / *(float*)&s[stack_top + 1].val;
										memcpy((void*)s[stack_top].val, (const void*)&outter_real, STRING_LEN);
										break;
									default: {
										yyerror("Operators Incompitable!\n");
									}
								}
								break;
							case real:
								switch (s[stack_top + 1].t) {
									case real:
										outter_real = *(float*)&s[stack_top].val / *(float*)&s[stack_top + 1].val;
										memcpy((void*)s[stack_top].val, (const void*)&outter_real, STRING_LEN);
										s[stack_top].t = real;
										break;
									case integer:
										s[stack_top + 1].t = real;
										s[stack_top].t = real;
										outter_real = *(float*)&s[stack_top].val / (float)*(int*)&s[stack_top + 1].val;
										memcpy((void*)s[stack_top].val, (const void*)&outter_real, STRING_LEN);
										break;
								}
								break;
							case str:
							case single_char:
							case boolean: 
								yyerror("Operant not support / operation!\n");
								break;
						}
						break;
					case 6:								// 2 opr %
						stack_top--;
						switch (s[stack_top].t) {
							case integer:
								switch (s[stack_top + 1].t) {
									case integer:
										outter_int = *(int*)&s[stack_top].val % *(int*)&s[stack_top + 1].val;
										memcpy((void*)s[stack_top].val, (const void*)&outter_int, STRING_LEN);
										s[stack_top].t = integer;
										break;
									default: {
										yyerror("Operators Incompitable!\n");
									}
								}
								break;
							case real:
							case str:
							case single_char:
							case boolean: 
								yyerror("Operant not support / operation!\n");
								break;
						}
						break;
					case 7:								// 2 opr ==
						stack_top--;
						switch (i.lev) {				// 2 opran should be with the same type
							case 2:
								outter_int = *(int*)&s[stack_top].val == *(int*)&s[stack_top + 1].val;
								memcpy((void*)s[stack_top].val, (const void*)&outter_int, STRING_LEN);
								s[stack_top].t = boolean;
								break;
							case 3:
								outter_int = abs(*(float*)&s[stack_top].val - *(float*)&s[stack_top + 1].val) < FLOAT_EPS ? 1 : 0;
								memcpy((void*)s[stack_top].val, (const void*)&outter_int, STRING_LEN);
								s[stack_top].t = boolean;
								break;
							case 4:
								outter_int = !strcmp(s[stack_top].val, s[stack_top + 1].val);
								memcpy((void*)s[stack_top].val, (const void*)&outter_int, STRING_LEN);
								s[stack_top].t = boolean;
								break;
							case 5:
								bool_opr1 = *(int*)&s[stack_top].val, bool_opr2 = *(int*)&s[stack_top + 1].val;
								outter_int = (bool_opr1 * bool_opr2 || (!bool_opr1 && !bool_opr2)) ? 1 : 0;
								memcpy((void*)s[stack_top].val, (const void*)&outter_int, STRING_LEN);
								s[stack_top].t = boolean;
								break;
							case 6:
								outter_int = *(char*)&s[stack_top].val == *(char*)&s[stack_top + 1].val;
								memcpy((void*)s[stack_top].val, (const void*)&outter_int, STRING_LEN);
								s[stack_top].t = boolean;
								break;
						}
						break;
					case 8:								// 2 opr !=
						stack_top--;
						switch (i.lev) {				// 2 opran should be with the same type
							case 2:
								outter_int = !(*(int*)&s[stack_top].val == *(int*)&s[stack_top + 1].val);
								memcpy((void*)s[stack_top].val, (const void*)&outter_int, STRING_LEN);
								s[stack_top].t = boolean;
								break;
							case 3:
								outter_int = !(abs(*(float*)&s[stack_top].val - *(float*)&s[stack_top + 1].val) < FLOAT_EPS ? 1 : 0);
								memcpy((void*)s[stack_top].val, (const void*)&outter_int, STRING_LEN);
								s[stack_top].t = boolean;
								break;
							case 4:
								outter_int = strcmp(s[stack_top].val, s[stack_top + 1].val);
								memcpy((void*)s[stack_top].val, (const void*)&outter_int, STRING_LEN);
								s[stack_top].t = boolean;
								break;
							case 5:
								bool_opr1 = *(int*)&s[stack_top].val, bool_opr2 = *(int*)&s[stack_top + 1].val;
								outter_int = !((bool_opr1 * bool_opr2 || (!bool_opr1 && !bool_opr2)) ? 1 : 0);
								memcpy((void*)s[stack_top].val, (const void*)&outter_int, STRING_LEN);
								s[stack_top].t = boolean;
								break;
							case 6:
								outter_int = !(*(char*)&s[stack_top].val == *(char*)&s[stack_top + 1].val);
								memcpy((void*)s[stack_top].val, (const void*)&outter_int, STRING_LEN);
								s[stack_top].t = boolean;
								break;
						}
						break;
					case 9:								// 2 opr <
						break;
					case 10:							// 2 opr <=
						break;
					case 11:							// 2 opr >
						break;
					case 12:							// 2 opr >=
						break;
					case 13:							// 2 opr &&
						break;
					case 14:							// 2 opr ||
						break;
					case 15:							// 2 opr ^^
						break;
					case 16:							// 1 opr !
						break;
					case 17:							// 1 opr ++
						break;
					case 18:							// 1 opr --
						break;
					case 19:
						//printf("OUTPUT:\n");
						switch (s[stack_top].t) {
							case integer:
								printf("%d\n", *(int*)&s[stack_top].val);  
								break;
							case real:
								printf("%f\n", *(float*)&s[stack_top].val);        // e1 at this unit but when convert to %f it can't be displayed correctly.
								break;
							case str:
								printf("%s\n", s[stack_top].val);
								break;
							case boolean:
								printf("%s\n", (*(int*)&s[stack_top].val) == 0 ? "false" : "true");
								break;
							case single_char:
								printf("%c\n", *(char*)&s[stack_top].val);
								break;
						}
						stack_top--;
						break;
					case 20:							// input
						stack_top++;
						//printf("INPUT:\n");
						switch (i.lev) {
							case 2:
								scanf("%d", &inbuf_int);
								memcpy((void*)(&(s[stack_top].val)), (const void*)&inbuf_int, STRING_LEN);
								s[stack_top].t = integer;
								break;
							case 3:
								scanf("%f", &inbuf_real);
								memcpy((void*)(&(s[stack_top].val)), (const void*)&inbuf_real, STRING_LEN);
								s[stack_top].t = real;
								break;
							case 4:
								scanf("%s", inbuf_string);
								memcpy((void*)(&(s[stack_top].val)), (const void*)inbuf_string, STRING_LEN);
								s[stack_top].t = str;
								getchar();
								break;
							case 5:
								scanf("%s", &inbuf_bool);
								bool_flag = strcmp(inbuf_bool, "false");
								memcpy((void*)(&(s[stack_top].val)), (const void*)&bool_flag, STRING_LEN);
								s[stack_top].t = boolean;
								getchar();
								break;
							case 6:
								scanf("%c", &inbuf_char);
								memcpy((void*)(&(s[stack_top].val)), (const void*)&inbuf_char, STRING_LEN);
								s[stack_top].t = single_char;
								getchar();
								break;
						}
						break;
					case 21: 						// <<

						break;
					case 22:						// >>

						break;
				}
				break;
			case lod:
				stack_top++;
				addr = *(int*)&(i.opr);
				if (addr == -1) {

				}
				else {
					memcpy((void*)(&(s[stack_top].val)), (const void*)(&(s[addr].val)), STRING_LEN);
					switch (i.lev) {
						case 2:
							s[stack_top].t = integer;
							break;
						case 3:
							s[stack_top].t = real;
							break;
						case 4:
							s[stack_top].t = str;
							break;
						case 5:
							s[stack_top].t = boolean;
							break;
						case 6:
							s[stack_top].t = single_char;
							break;
					}
				}
				break;
			case sto:
				addr = *(int*)&(i.opr);
				memcpy((void*)(&(s[addr].val)), (const void*)(&(s[stack_top].val)), STRING_LEN);
				switch (i.lev) {
					case 2:
						s[stack_top].t = integer;
						break;
					case 3:
						s[stack_top].t = real;
						break;
					case 4:
						s[stack_top].t = str;
						break;
					case 5:
						s[stack_top].t = boolean;
						break;
					case 6:
						s[stack_top].t = single_char;
						break;
				}
				stack_top--;
				break;
			case cal:
				break;
			case ini:
				stack_top = stack_top + *(int*)&i.opr;
				break;
			case jmp:
				pc = *(int*)&i.opr;
				break;
			case jpc:
				if (*(int*)&s[stack_top].val == 0) {		// jump when condition not true
					pc = *(int*)&i.opr;
				}
				stack_top--;
				break;
			case off:
				res = 0;
				addr_to_find_array_in_table = *(int*)&i.opr;
				for (iter = 1; iter <= sym_tab_tail; iter++) {
					if (table[iter].addr == addr_to_find_array_in_table) {
						for (jter = 0; jter < MAX_ARR_DIM; jter++) {
							tmp_arr_list[jter] = table[iter].array_dim[jter];
						}
						break;
					}
				}
				for (iter = 0; iter < i.lev; iter++) {
					res += (*(int*)&s[stack_top].val) * tmp_arr_list[i.lev - iter - 1];
					stack_top--;
				}
				res += *(int*)&i.opr;
				for (iter = pc; iter < vm_code_pointer; iter++) {
					if (code[iter].f == lod || code[iter].f == sto) {
						back_patch(iter, (byte*)res);
						break;
					}
				}
				break;
		}
		//print_data_stack();
	} while (pc != vm_code_pointer);
}

int type_max(int a, int b) {
	return a > b ? a : b;
}

void back_patch(int ins_idx, byte op[STRING_LEN]) {
	memcpy((void*)code[ins_idx].opr, (const void*)&op, STRING_LEN);
}

void listall() {
	int i;
	char name[][5] = {
		{"lit"}, {"opr"}, {"lod"}, {"sto"},
		{"cal"}, {"ini"}, {"jmp"}, {"jpc"}, {"off"}
	};
	for (i = 0; i < vm_code_pointer; i++) {
		if (code[i].f == lit) {
			switch (code[i].lev) {
				case 2:
					printf("%4d %s %4d %4d\n", i, name[code[i].f], code[i].lev, *(int*)(&(code[i].opr)));
					fprintf(fcode, "%4d %s %4d %4d\n", i, name[code[i].f], code[i].lev, *(int*)(&(code[i].opr)));
					break;
				case 3:
					printf("%4d %s %4d %4f\n", i, name[code[i].f], code[i].lev, *(float*)(&(code[i].opr)));
					fprintf(fcode, "%4d %s %4d %4f\n", i, name[code[i].f], code[i].lev, *(float*)(&(code[i].opr)));
					break;
				case 4:
					printf("%4d %s %4d %s\n", i, name[code[i].f], code[i].lev, (code[i].opr));
					fprintf(fcode, "%4d %s %4d %s\n", i, name[code[i].f], code[i].lev, (code[i].opr));
					break;
				case 5:
					printf("%4d %s %4d %s\n", i, name[code[i].f], code[i].lev, *(int*)(&(code[i].opr)) == 1 ? "true" : "false");
					fprintf(fcode, "%4d %s %4d %s\n", i, name[code[i].f], code[i].lev, *(int*)(&(code[i].opr)) == 1 ? "true" : "false");
					break;
				case 6:
					printf("%4d %s %4d %4c\n", i, name[code[i].f], code[i].lev, *(char*)(&(code[i].opr)));
					fprintf(fcode, "%4d %s %4d %4c\n", i, name[code[i].f], code[i].lev, *(char*)(&(code[i].opr)));
					break;
			}
		}
		else {
			printf("%4d %s %4d %4d\n", i, name[code[i].f], code[i].lev, *(int*)(&(code[i].opr)));
			fprintf(fcode, "%4d %s %4d %4d\n", i, name[code[i].f], code[i].lev, *(int*)(&(code[i].opr)));
		}
	}
}

void print_data_stack() {
	int i = 3;
	for (; i <= stack_top; i++) {
		switch (s[i].t) {
			case integer:
				printf("%d\t\t%d\n", i, *(int*)&s[i].val);
				break;
			case real:
				printf("%d\t\t%f\n", i, *(float*)&s[i].val);
				break;
			case str:
				printf("%d\t\t%s\n", i, s[i].val);
				break;
			case boolean:
				printf("%d\t\t%s\n", i, *(int*)&s[i].val == 0 ? "false" : "true");
				break;
			case single_char:
				printf("%d\t\t%c\n", i, *(char*)&s[i].val);
				break;
		}
	}
	printf("==========================================================================\n");
}

int main(int argc, int **argv) {
	int tok;
	fcode = fopen("fcode", "w+");
	ftable = fopen("ftable", "w+");
	fresult = fopen("fresult", "w+");
	if (argc != 2) {
		printf("Please specific ONE source code file!\n");
		return 0;
	}
	FILE *f = fopen(argv[1], "r");
	if (!f) {
		perror(argv[1]);
		return 1;
	}
	redirectInput(f);
	init();
	int opran = 0;
	//while (tok = yylex()) printf("%d\n", tok);
	yyparse();
	display_sym_tab();
	listall();
	interpret();
	listall();
	//print_data_stack();
}
