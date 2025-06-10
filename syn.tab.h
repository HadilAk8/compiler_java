
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

/* Line 1676 of yacc.c  */
#line 43 "syn.y"

    int entier;
    char *str;
    float reel;



/* Line 1676 of yacc.c  */
#line 112 "syn.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


