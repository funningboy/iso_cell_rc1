
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
     TMODULE = 258,
     TEDMODULE = 259,
     TINPUT = 260,
     TOUTPUT = 261,
     TWIRE = 262,
     TEND = 263,
     TRSQUARE = 264,
     TLSQUARE = 265,
     TCOLON = 266,
     TINV = 267,
     TAND = 268,
     TNAND = 269,
     TOR = 270,
     TNOR = 271,
     TXOR = 272,
     TXNOR = 273,
     TBUF = 274,
     TNOT = 275,
     TDFF = 276,
     TLIBRARY = 277,
     TDESIGN = 278,
     TIDENTIFIER = 279,
     TINTEGER = 280,
     TDOUBLE = 281,
     TCEQ = 282,
     TCNE = 283,
     TCLT = 284,
     TCLE = 285,
     TCGT = 286,
     TCGE = 287,
     TEQUAL = 288,
     TLPAREN = 289,
     TRPAREN = 290,
     TLBRACE = 291,
     TRBRACE = 292,
     TCOMMA = 293,
     TDOT = 294,
     TPLUS = 295,
     TMINUS = 296,
     TMUL = 297,
     TDIV = 298
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 1628 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"


        std::string      *sc_string;
        int              *sc_int;
	int              token;



/* Line 1676 of yacc.c  */
#line 104 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.hpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE SC_lval;


