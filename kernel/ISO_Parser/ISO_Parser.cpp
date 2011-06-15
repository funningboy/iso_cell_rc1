
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

/* Substitute the variable and function names.  */
#define yyparse         ISO_parse
#define yylex           ISO_lex
#define yyerror         ISO_error
#define yylval          ISO_lval
#define yychar          ISO_char
#define yydebug         ISO_debug
#define yynerrs         ISO_nerrs


/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"

        #include <iostream>
        #include <sstream>
        #include <vector>
        #include <algorithm>

	#include <stdlib.h> 
        #include <stdio.h>
        #include <assert.h>

        #include "kernel/ISO_Lib/ISO_CreateIsolationRule.h"
        #include "kernel/ISO_Lib/ISO_CreatePowerDomain.h"
        #include "kernel/ISO_Lib/ISO_DefineIsolationCell.h"
        #include "kernel/ISO_Lib/ISO_CreateNominalCondition.h"
        #include "kernel/ISO_Lib/ISO_CreatePowerMode.h"
        #include "kernel/ISO_Context/ISO_Table.h"

        using namespace std;
        using namespace xISOPower;

        ISO_Table  *t_iso_table;

        extern int ISO_lex();
        void ISO_error(const char *s) { printf("ERROR: %s\n", s); }

        enum ISO_TYPE {
             ISO_TYPE_HIGH,
             ISO_TYPE_LOW,
             ISO_TYPE_FROM,
             ISO_TYPE_TO,
             ISO_TYPE_EITHER,
             ISO_TYPE_UP,
             ISO_TYPE_DOWN,
             ISO_TYPE_ON,
             ISO_TYPE_OFF,
             ISO_TYPE_undef
        }; 

        bool                                         ISO_Default;
        std::string                                  ISO_Name;
        std::string                                  ISO_From;
        std::string                                  ISO_To;
        std::string                                  ISO_Condition;
        std::string                                  ISO_Enable;
        std::string                                  ISO_Voltage;
        ISO_TYPE                                     ISO_Out_HL;
        ISO_TYPE                                     ISO_ONOFF;
        ISO_TYPE                                     ISO_FMTO;
        ISO_TYPE                                     ISO_UPDN;

       
        std::vector<std::string>                     vv;
        std::vector<std::string>                     vv1;
        std::vector<std::string>                     vv2;
        std::map<std::string,std::string>            mm;


        std::vector< ISO_CreatePowerDomain*      >   CtPowerDomainVec;
        std::vector< ISO_CreateIsolationRule*    >   CtIsolationRuleVec;
        std::vector< ISO_DefineIsolationCell*    >   DefIsolationCellVec;
        std::vector< ISO_CreateNominalCondition* >   CtNominalConditionVec;
        std::vector< ISO_CreatePowerMode*        >   CtPowerModeVec;

        typedef std::vector<std::string>::iterator   vv_iter;


/* Line 189 of yacc.c  */
#line 72 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"

void set_Clear_All(){

ISO_Default     = false;
ISO_Name        = "";
ISO_From        = "";
ISO_To          = "";
ISO_Condition   = "";
ISO_Enable      = ""; 
ISO_Voltage     = "";
ISO_Out_HL      = ISO_TYPE_undef;
ISO_FMTO        = ISO_TYPE_undef; 
ISO_UPDN        = ISO_TYPE_undef;

vv.clear();
vv1.clear();
vv2.clear();
mm.clear();

}

/* Line 189 of yacc.c  */
#line 97 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"

void set_CreatePowerDomain(){

  ISO_CreatePowerDomain *iso_c_p_d = new ISO_CreatePowerDomain();
  assert( iso_c_p_d != NULL && "ISO_Parser->set_CreatePowerDomain" );

                         iso_c_p_d->set_ISO_Default(ISO_Default);
                         iso_c_p_d->set_ISO_Name(ISO_Name);
                         iso_c_p_d->set_ISO_Instances(vv1);
                         iso_c_p_d->set_ISO_BoundaryPorts(vv2);

  CtPowerDomainVec.push_back(iso_c_p_d);

  set_Clear_All();
}

/* Line 189 of yacc.c  */
#line 118 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"

void set_CreateIsolationRule(){

  ISO_CreateIsolationRule *iso_c_i_r = new ISO_CreateIsolationRule();
  assert( iso_c_i_r != NULL && "ISO_Parser->set_CreateIsolationRule" );

                           iso_c_i_r->set_ISO_Name(ISO_Name);
                           iso_c_i_r->set_ISO_From(ISO_From);
                           iso_c_i_r->set_ISO_To(ISO_To);
                    
                       if( ISO_ONOFF == ISO_TYPE_ON )
                           iso_c_i_r->set_ISO_Condition(ISO_CreateIsolationRule::ISO_COND_ON,ISO_Condition);
                       else
                           iso_c_i_r->set_ISO_Condition(ISO_CreateIsolationRule::ISO_COND_OFF,ISO_Condition);


                       if( ISO_Out_HL == ISO_TYPE_HIGH )
                           iso_c_i_r->set_ISO_OUT_HL(ISO_CreateIsolationRule::ISO_OUT_H);
                       else
                           iso_c_i_r->set_ISO_OUT_HL(ISO_CreateIsolationRule::ISO_OUT_L);
                           
  CtIsolationRuleVec.push_back(iso_c_i_r);

  set_Clear_All();
}

/* Line 189 of yacc.c  */
#line 149 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"

void set_DefineIsolationCell(){

  assert( !vv1.empty() && "ISO_Parser->set_DefineIsolationCell" );

  for(vv_iter v_it  = vv1.begin();
              v_it != vv1.end();   ++v_it){

  ISO_DefineIsolationCell *iso_d_i_c = new  ISO_DefineIsolationCell();
 
  assert( iso_d_i_c != NULL && "ISO_Parser->set_DefineIsolationCell" );

                           iso_d_i_c->set_ISO_Cell((*v_it));
                           iso_d_i_c->set_ISO_Enable(ISO_Enable);

                       if( ISO_FMTO == ISO_TYPE_FROM )
                           iso_d_i_c->set_ISO_Location(ISO_DefineIsolationCell::ISO_LOC_FROM);
                       else
                           iso_d_i_c->set_ISO_Location(ISO_DefineIsolationCell::ISO_LOC_TO);
 

    DefIsolationCellVec.push_back(iso_d_i_c);
  }

 set_Clear_All();
}

/* Line 189 of yacc.c  */
#line 181 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"

void set_CreateNominalCondition(){

  ISO_CreateNominalCondition * iso_c_n_c = new ISO_CreateNominalCondition();

  assert( iso_c_n_c != NULL && "ISO_Parser->set_CreateNominalCondition" );

          iso_c_n_c->set_ISO_Name(ISO_Name);
          iso_c_n_c->set_ISO_Voltage(atof(ISO_Voltage.c_str()));

  CtNominalConditionVec.push_back(iso_c_n_c);

 set_Clear_All();
}

/* Line 189 of yacc.c  */
#line 200 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
 
void set_CreatePowerMode(){

    ISO_CreatePowerMode *iso_c_p_d = new ISO_CreatePowerMode();

    assert( iso_c_p_d != NULL &&  
            !mm.empty()       && "ISO_Parser->set_CreatePowerMode" );

    iso_c_p_d->set_ISO_Name(ISO_Name); 
    iso_c_p_d->set_ISO_Default(ISO_Default); 
    iso_c_p_d->set_ISO_DomainCondition(mm);
 
    CtPowerModeVec.push_back(iso_c_p_d);

    set_Clear_All(); 
}

/* Line 189 of yacc.c  */
#line 221 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"

void set_ISO_Table(){

     ISO_Table *iso_table = new ISO_Table();

     assert( iso_table != NULL && "ISO_Parser->set_ISO_Table");

     iso_table->set_ISO_CreatePowerDomainVec(CtPowerDomainVec);
     iso_table->set_ISO_CreateIsolationRuleVec(CtIsolationRuleVec);
     iso_table->set_ISO_DefineIsolationCellVec(DefIsolationCellVec);
     iso_table->set_ISO_CreateNominalConditionVec(CtNominalConditionVec);
     iso_table->set_ISO_CreatePowerModeVec(CtPowerModeVec);

     CtPowerDomainVec.clear();
     CtIsolationRuleVec.clear();
     DefIsolationCellVec.clear();
     CtNominalConditionVec.clear();
     CtPowerModeVec.clear();
  
     t_iso_table = iso_table;

}


/* Line 189 of yacc.c  */
#line 308 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
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
     TCREATE_POWER_DOMAIN = 258,
     TDEFAULT = 259,
     TINSTANCES = 260,
     TNAME = 261,
     TBOUNDARY_PORTS = 262,
     TCREATE_ISOLATION_RULE = 263,
     TFROM = 264,
     TTO = 265,
     TEITHER = 266,
     TISOLATION_OUTPUT = 267,
     TISOLATION_CONDITION = 268,
     THIGH = 269,
     TLOW = 270,
     TDEFINE_ISOLATION_CELL = 271,
     TCELLS = 272,
     TENABLE = 273,
     TVALID_LOCATION = 274,
     TCREATE_LEVEL_SHIFTER_RULE = 275,
     TDEFINE_LEVEL_SHIFTER_CELL = 276,
     TINPUT_VOLTAGE_RANGE = 277,
     TOUTPUT_VOLTAGE_RANGE = 278,
     TDIRECTION = 279,
     TUP = 280,
     TDOWN = 281,
     TCREATE_NOMINAL_CONDITION = 282,
     TVOLTAGE = 283,
     TDOMAIN_CONDITIONS = 284,
     TCREATE_POWER_MODE = 285,
     TIDENTIFIER = 286,
     TINTEGER = 287,
     TDOUBLE = 288,
     TEQUAL = 289,
     TCLT = 290,
     TCGT = 291,
     TLPAREN = 292,
     TRPAREN = 293,
     TLBRACE = 294,
     TRBRACE = 295,
     TRSQUARE = 296,
     TLSQUARE = 297,
     TEND = 298,
     TSLASH = 299,
     TINV = 300,
     TCOLON = 301,
     TMINUS = 302,
     TAT = 303
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 250 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"


        std::string      *iso_string;
        int              *iso_int;
	int              token;




/* Line 214 of yacc.c  */
#line 402 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 414 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.cpp"

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
#define YYFINAL  32
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   136

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNRULES -- Number of states.  */
#define YYNSTATES  149

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      45,    46,    47,    48
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    13,    16,    19,    22,
      25,    28,    31,    33,    36,    38,    41,    43,    46,    48,
      51,    53,    56,    58,    61,    63,    66,    69,    73,    79,
      86,    92,    99,   103,   108,   112,   117,   121,   126,   130,
     135,   139,   144,   148,   153,   158,   164,   170,   177,   181,
     186,   190,   195,   199,   204,   208,   213,   217,   222,   226,
     231,   235,   240,   244,   249,   255,   262,   268,   275,   279,
     284,   288,   293,   297,   302,   306,   311,   315,   320,   326,
     333,   336,   340,   342,   344,   346,   348,   350,   352,   354,
     358,   363,   365
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      50,     0,    -1,    51,    -1,    52,    -1,    51,    52,    -1,
       3,    53,    -1,     8,    54,    -1,    16,    55,    -1,    20,
      56,    -1,    21,    57,    -1,    27,    58,    -1,    30,    59,
      -1,    60,    -1,    53,    60,    -1,    61,    -1,    54,    61,
      -1,    62,    -1,    55,    62,    -1,    63,    -1,    56,    63,
      -1,    64,    -1,    57,    64,    -1,    65,    -1,    58,    65,
      -1,    66,    -1,    59,    66,    -1,    47,     4,    -1,    47,
       4,    44,    -1,    47,     5,    39,    71,    40,    -1,    47,
       5,    39,    71,    40,    44,    -1,    47,     7,    39,    71,
      40,    -1,    47,     7,    39,    71,    40,    44,    -1,    47,
       6,    31,    -1,    47,     6,    31,    44,    -1,    47,     6,
      31,    -1,    47,     6,    31,    44,    -1,    47,     9,    31,
      -1,    47,     9,    31,    44,    -1,    47,    10,    31,    -1,
      47,    10,    31,    44,    -1,    47,    12,    67,    -1,    47,
      12,    67,    44,    -1,    47,    13,    31,    -1,    47,    13,
      31,    44,    -1,    47,    13,    45,    31,    -1,    47,    13,
      45,    31,    44,    -1,    47,    17,    39,    71,    40,    -1,
      47,    17,    39,    71,    40,    44,    -1,    47,    18,    31,
      -1,    47,    18,    31,    44,    -1,    47,    19,    68,    -1,
      47,    19,    68,    44,    -1,    47,     6,    31,    -1,    47,
       6,    31,    44,    -1,    47,     9,    31,    -1,    47,     9,
      31,    44,    -1,    47,    10,    31,    -1,    47,    10,    31,
      44,    -1,    47,    17,    31,    -1,    47,    17,    31,    44,
      -1,    47,    18,    31,    -1,    47,    18,    31,    44,    -1,
      47,    19,    68,    -1,    47,    19,    68,    44,    -1,    47,
      22,    33,    46,    33,    -1,    47,    22,    33,    46,    33,
      44,    -1,    47,    23,    33,    46,    33,    -1,    47,    23,
      33,    46,    33,    44,    -1,    47,    24,    69,    -1,    47,
      24,    69,    44,    -1,    47,     6,    31,    -1,    47,     6,
      31,    44,    -1,    47,    28,    33,    -1,    47,    28,    33,
      44,    -1,    47,    28,    32,    -1,    47,    28,    32,    44,
      -1,    47,     6,    31,    -1,    47,     6,    31,    44,    -1,
      47,    29,    39,    70,    40,    -1,    47,    29,    39,    70,
      40,    44,    -1,    47,     4,    -1,    47,     4,    44,    -1,
      14,    -1,    15,    -1,     9,    -1,    10,    -1,    11,    -1,
      25,    -1,    26,    -1,    31,    48,    31,    -1,    70,    31,
      48,    31,    -1,    31,    -1,    71,    31,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   314,   314,   318,   319,   322,   323,   324,   325,   326,
     327,   328,   332,   333,   337,   338,   342,   343,   347,   348,
     352,   353,   357,   358,   361,   362,   366,   367,   368,   369,
     370,   371,   372,   373,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   394,   395,   396,   397,
     398,   399,   404,   405,   406,   407,   408,   409,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     430,   431,   432,   433,   434,   435,   439,   440,   441,   442,
     443,   444,   448,   449,   452,   453,   454,   457,   458,   461,
     462,   466,   467
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TCREATE_POWER_DOMAIN", "TDEFAULT",
  "TINSTANCES", "TNAME", "TBOUNDARY_PORTS", "TCREATE_ISOLATION_RULE",
  "TFROM", "TTO", "TEITHER", "TISOLATION_OUTPUT", "TISOLATION_CONDITION",
  "THIGH", "TLOW", "TDEFINE_ISOLATION_CELL", "TCELLS", "TENABLE",
  "TVALID_LOCATION", "TCREATE_LEVEL_SHIFTER_RULE",
  "TDEFINE_LEVEL_SHIFTER_CELL", "TINPUT_VOLTAGE_RANGE",
  "TOUTPUT_VOLTAGE_RANGE", "TDIRECTION", "TUP", "TDOWN",
  "TCREATE_NOMINAL_CONDITION", "TVOLTAGE", "TDOMAIN_CONDITIONS",
  "TCREATE_POWER_MODE", "TIDENTIFIER", "TINTEGER", "TDOUBLE", "TEQUAL",
  "TCLT", "TCGT", "TLPAREN", "TRPAREN", "TLBRACE", "TRBRACE", "TRSQUARE",
  "TLSQUARE", "TEND", "TSLASH", "TINV", "TCOLON", "TMINUS", "TAT",
  "$accept", "program", "iso_contains_stmt", "iso_contain_stmt",
  "create_power_domains", "create_isolation_rules",
  "define_isolation_cells", "create_level_shifter_rules",
  "define_level_shifter_cells", "create_nominal_conditions",
  "create_power_modes", "create_power_domain", "create_isolation_rule",
  "define_isolation_cell", "create_level_shifter_rule",
  "define_level_shifter_cell", "create_nominal_condition",
  "create_power_mode", "iso_high_low_stmt", "iso_from_to_stmt",
  "iso_up_down_stmt", "iso_conds_stmt", "iso_vectors_stmt", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    52,    52,    52,
      52,    52,    53,    53,    54,    54,    55,    55,    56,    56,
      57,    57,    58,    58,    59,    59,    60,    60,    60,    60,
      60,    60,    60,    60,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    62,    62,    62,    62,
      62,    62,    63,    63,    63,    63,    63,    63,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      65,    65,    65,    65,    65,    65,    66,    66,    66,    66,
      66,    66,    67,    67,    68,    68,    68,    69,    69,    70,
      70,    71,    71
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     2,     1,     2,     1,     2,     1,     2,
       1,     2,     1,     2,     1,     2,     2,     3,     5,     6,
       5,     6,     3,     4,     3,     4,     3,     4,     3,     4,
       3,     4,     3,     4,     4,     5,     5,     6,     3,     4,
       3,     4,     3,     4,     3,     4,     3,     4,     3,     4,
       3,     4,     3,     4,     5,     6,     5,     6,     3,     4,
       3,     4,     3,     4,     3,     4,     3,     4,     5,     6,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       4,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     5,    12,     0,     6,    14,     0,     7,    16,
       0,     8,    18,     0,     9,    20,     0,    10,    22,     0,
      11,    24,     1,     4,    26,     0,     0,     0,    13,     0,
       0,     0,     0,     0,    15,     0,     0,     0,    17,     0,
       0,     0,    19,     0,     0,     0,     0,     0,     0,    21,
       0,     0,    23,    80,     0,     0,    25,    27,     0,    32,
       0,    34,    36,    38,    82,    83,    40,    42,     0,     0,
      48,    84,    85,    86,    50,    52,    54,    56,    58,    60,
      62,     0,     0,    87,    88,    68,    70,    74,    72,    81,
      76,     0,    91,     0,    33,     0,    35,    37,    39,    41,
      43,    44,     0,    49,    51,    53,    55,    57,    59,    61,
      63,     0,     0,    69,    71,    75,    73,    77,     0,     0,
      92,    28,    30,    45,    46,    64,    66,     0,     0,    78,
      29,    31,    47,    65,    67,    89,     0,    79,    90
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     8,     9,    10,    12,    15,    18,    21,    24,    27,
      30,    13,    16,    19,    22,    25,    28,    31,    76,    84,
      95,   129,   103
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -49
static const yytype_int8 yypact[] =
{
      -3,   -19,    -6,    10,    12,    13,    14,    16,    42,    -3,
     -49,    46,   -19,   -49,    34,    -6,   -49,    37,    10,   -49,
      39,    12,   -49,    15,    13,   -49,    -5,    14,   -49,     0,
      16,   -49,   -49,   -49,    18,    19,    33,    26,   -49,    35,
      36,    38,    11,   -29,   -49,    29,    40,    -2,   -49,    41,
      43,    44,   -49,    45,    47,    -2,    48,    49,   -11,   -49,
      52,     3,   -49,    50,    53,    31,   -49,   -49,    54,    51,
      54,    55,    56,    57,   -49,   -49,    58,    59,    60,    54,
      61,   -49,   -49,   -49,    62,    63,    64,    65,    66,    67,
      68,    27,    69,   -49,   -49,    70,    72,    73,    74,   -49,
      75,    82,   -49,   -28,   -49,   -21,   -49,   -49,   -49,   -49,
     -49,    76,   -20,   -49,   -49,   -49,   -49,   -49,   -49,   -49,
     -49,    71,    88,   -49,   -49,   -49,   -49,   -49,    32,   -10,
     -49,    78,    79,   -49,    80,    81,    83,    95,    84,    85,
     -49,   -49,   -49,   -49,   -49,   -49,    97,   -49,   -49
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -49,   -49,   -49,    77,   -49,   -49,   -49,   -49,   -49,   -49,
     -49,    86,   115,   113,   112,   110,   108,   106,   -49,    22,
     -49,   -49,   -48
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
       1,    60,    77,   130,    63,     2,    64,    81,    82,    83,
     130,   130,   131,     3,    93,    94,    78,     4,     5,   132,
     134,   138,   105,    61,     6,    74,    75,     7,    11,    65,
     139,   112,    53,    54,    55,    97,    98,    56,    57,    58,
      39,    14,    32,    40,    41,    49,    42,    43,    50,    51,
      34,    35,    36,    37,    45,    46,    47,    17,    68,    20,
      23,    26,    67,    29,    69,    70,    71,    72,    79,    73,
     101,    80,    85,   121,    86,    87,    88,    90,    89,     0,
     137,    91,    92,    96,   100,   102,    33,     0,     0,     0,
       0,   111,     0,     0,    99,   104,     0,     0,    38,   106,
     107,   108,   109,   110,   135,   113,   114,   115,   116,   117,
     118,   119,   120,   128,   123,   122,   124,   125,   126,   127,
     133,   136,   140,   141,   142,   143,   145,   144,   148,   147,
      44,    48,   146,    52,    59,    62,    66
};

static const yytype_int8 yycheck[] =
{
       3,     6,    31,    31,     4,     8,     6,     9,    10,    11,
      31,    31,    40,    16,    25,    26,    45,    20,    21,    40,
      40,    31,    70,    28,    27,    14,    15,    30,    47,    29,
      40,    79,    17,    18,    19,    32,    33,    22,    23,    24,
       6,    47,     0,     9,    10,     6,    12,    13,     9,    10,
       4,     5,     6,     7,    17,    18,    19,    47,    39,    47,
      47,    47,    44,    47,    31,    39,    31,    31,    39,    31,
      39,    31,    31,    46,    31,    31,    31,    55,    31,    -1,
      48,    33,    33,    31,    31,    31,     9,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    44,    44,    -1,    -1,    12,    44,
      44,    44,    44,    44,    33,    44,    44,    44,    44,    44,
      44,    44,    44,    31,    44,    46,    44,    44,    44,    44,
      44,    33,    44,    44,    44,    44,    31,    44,    31,    44,
      15,    18,    48,    21,    24,    27,    30
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     8,    16,    20,    21,    27,    30,    50,    51,
      52,    47,    53,    60,    47,    54,    61,    47,    55,    62,
      47,    56,    63,    47,    57,    64,    47,    58,    65,    47,
      59,    66,     0,    52,     4,     5,     6,     7,    60,     6,
       9,    10,    12,    13,    61,    17,    18,    19,    62,     6,
       9,    10,    63,    17,    18,    19,    22,    23,    24,    64,
       6,    28,    65,     4,     6,    29,    66,    44,    39,    31,
      39,    31,    31,    31,    14,    15,    67,    31,    45,    39,
      31,     9,    10,    11,    68,    31,    31,    31,    31,    31,
      68,    33,    33,    25,    26,    69,    31,    32,    33,    44,
      31,    39,    31,    71,    44,    71,    44,    44,    44,    44,
      44,    31,    71,    44,    44,    44,    44,    44,    44,    44,
      44,    46,    46,    44,    44,    44,    44,    44,    31,    70,
      31,    40,    40,    44,    40,    33,    33,    48,    31,    40,
      44,    44,    44,    44,    44,    31,    48,    44,    31
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
#line 314 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { set_ISO_Table(); ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 322 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { set_CreatePowerDomain();      ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 323 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { set_CreateIsolationRule();    ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 324 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { set_DefineIsolationCell();    ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 325 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    {/* set_CreateLevelShifterRule();*/ ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 326 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    {/* s set_DefineLevelShifterCell();*/ ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 327 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { set_CreateNominalCondition(); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 328 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { set_CreatePowerMode();        ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 366 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { ISO_Default = true;   ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 367 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { ISO_Default = true;   ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 368 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { vv1 = vv; vv.clear(); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 369 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { vv1 = vv; vv.clear(); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 370 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { vv2 = vv; vv.clear(); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 371 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { vv2 = vv; vv.clear(); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 372 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { ISO_Name = (*(yyvsp[(3) - (3)].iso_string)); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 373 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { ISO_Name = (*(yyvsp[(3) - (4)].iso_string)); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 378 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { ISO_Name = (*(yyvsp[(3) - (3)].iso_string)); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 379 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { ISO_Name = (*(yyvsp[(3) - (4)].iso_string)); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 380 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { ISO_From = (*(yyvsp[(3) - (3)].iso_string)); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 381 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { ISO_From = (*(yyvsp[(3) - (4)].iso_string)); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 382 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { ISO_To   = (*(yyvsp[(3) - (3)].iso_string)); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 383 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { ISO_To   = (*(yyvsp[(3) - (4)].iso_string)); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 384 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    {;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 385 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    {;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 386 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { ISO_Condition = (*(yyvsp[(3) - (3)].iso_string)); ISO_ONOFF = ISO_TYPE_ON;  ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 387 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { ISO_Condition = (*(yyvsp[(3) - (4)].iso_string)); ISO_ONOFF = ISO_TYPE_ON;  ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 388 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { ISO_Condition = (*(yyvsp[(4) - (4)].iso_string)); ISO_ONOFF = ISO_TYPE_OFF; ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 389 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { ISO_Condition = (*(yyvsp[(4) - (5)].iso_string)); ISO_ONOFF = ISO_TYPE_OFF; ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 394 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { vv1 = vv; vv.clear(); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 395 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { vv1 = vv; vv.clear(); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 396 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { ISO_Enable = (*(yyvsp[(3) - (3)].iso_string)); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 397 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { ISO_Enable = (*(yyvsp[(3) - (4)].iso_string)); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 398 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    {;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 399 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    {;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 404 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    {  ISO_Name = (*(yyvsp[(3) - (3)].iso_string)); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 405 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    {  ISO_Name = (*(yyvsp[(3) - (4)].iso_string)); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 406 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    {  ISO_From = (*(yyvsp[(3) - (3)].iso_string)); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 407 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    {  ISO_From = (*(yyvsp[(3) - (4)].iso_string)); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 408 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    {  ISO_To   = (*(yyvsp[(3) - (3)].iso_string)); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 409 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    {  ISO_To   = (*(yyvsp[(3) - (4)].iso_string)); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 414 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { ISO_Name = (*(yyvsp[(3) - (3)].iso_string)); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 430 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { ISO_Name    = (*(yyvsp[(3) - (3)].iso_string)); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 431 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { ISO_Name    = (*(yyvsp[(3) - (4)].iso_string)); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 432 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { ISO_Voltage = (*(yyvsp[(3) - (3)].iso_string)); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 433 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { ISO_Voltage = (*(yyvsp[(3) - (4)].iso_string)); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 434 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { ISO_Voltage = (*(yyvsp[(3) - (3)].iso_string)); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 435 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { ISO_Voltage = (*(yyvsp[(3) - (4)].iso_string)); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 439 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { ISO_Name    = (*(yyvsp[(3) - (3)].iso_string)); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 440 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { ISO_Name    = (*(yyvsp[(3) - (4)].iso_string)); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 441 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    {;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 442 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    {;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 443 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { ISO_Default = true; ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 444 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { ISO_Default = true; ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 448 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { ISO_Out_HL = ISO_TYPE_HIGH; ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 449 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { ISO_Out_HL = ISO_TYPE_LOW;  ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 452 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { ISO_FMTO = ISO_TYPE_FROM;   ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 453 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { ISO_FMTO = ISO_TYPE_TO;     ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 454 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { ISO_FMTO = ISO_TYPE_EITHER; ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 457 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { ISO_UPDN = ISO_TYPE_UP;     ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 458 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { ISO_UPDN = ISO_TYPE_DOWN;   ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 461 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { mm[(*(yyvsp[(1) - (3)].iso_string))] = (*(yyvsp[(3) - (3)].iso_string)); ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 462 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { mm[(*(yyvsp[(2) - (4)].iso_string))] = (*(yyvsp[(4) - (4)].iso_string)); ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 466 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { vv.push_back((*(yyvsp[(1) - (1)].iso_string))); ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 467 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"
    { vv.push_back((*(yyvsp[(2) - (2)].iso_string))); ;}
    break;



/* Line 1455 of yacc.c  */
#line 2210 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.cpp"
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
#line 471 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"


