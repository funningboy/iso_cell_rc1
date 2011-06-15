
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 250 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.y"


        std::string      *iso_string;
        int              *iso_int;
	int              token;




/* Line 1676 of yacc.c  */
#line 110 "/home/sean/桌面/iso_cell_rc1/kernel/ISO_Parser/ISO_Parser.hpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE ISO_lval;


