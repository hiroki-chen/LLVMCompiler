/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
     ID_token = 258,
     ADD_token = 259,
     MINUS_token = 260,
     MUL_token = 261,
     DIV_token = 262,
     MOD_token = 263,
     INC_token = 264,
     DEC_token = 265,
     EQ_token = 266,
     NEQ_token = 267,
     GEQ_token = 268,
     LEQ_token = 269,
     GT_token = 270,
     LT_token = 271,
     DECIMAL_token = 272,
     OCTAL_token = 273,
     HEX_token = 274,
     STRING_token = 275,
     CHAR_token = 276,
     IF_token = 277,
     ELSE_token = 278,
     DO_token = 279,
     WHILE_token = 280,
     FOR_token = 281,
     RETURN_token = 282,
     BREAK_token = 283,
     CONTINUE_token = 284,
     ASSIGN_token = 285,
     TRUE_token = 286,
     FALSE_token = 287,
     AND_token = 288,
     OR_token = 289,
     NOT_token = 290,
     DEF_token = 291,
     LBRACE = 292,
     RBRACE = 293,
     LPARENTHESIS = 294,
     RPARENTHESIS = 295,
     LSQUARE = 296,
     RSQUARE = 297,
     SEMICOLON = 298,
     COLON = 299,
     DOT = 300,
     COMMA = 301,
     LET_token = 302,
     VAR_token = 303,
     COMMA_token = 304
   };
#endif
/* Tokens.  */
#define ID_token 258
#define ADD_token 259
#define MINUS_token 260
#define MUL_token 261
#define DIV_token 262
#define MOD_token 263
#define INC_token 264
#define DEC_token 265
#define EQ_token 266
#define NEQ_token 267
#define GEQ_token 268
#define LEQ_token 269
#define GT_token 270
#define LT_token 271
#define DECIMAL_token 272
#define OCTAL_token 273
#define HEX_token 274
#define STRING_token 275
#define CHAR_token 276
#define IF_token 277
#define ELSE_token 278
#define DO_token 279
#define WHILE_token 280
#define FOR_token 281
#define RETURN_token 282
#define BREAK_token 283
#define CONTINUE_token 284
#define ASSIGN_token 285
#define TRUE_token 286
#define FALSE_token 287
#define AND_token 288
#define OR_token 289
#define NOT_token 290
#define DEF_token 291
#define LBRACE 292
#define RBRACE 293
#define LPARENTHESIS 294
#define RPARENTHESIS 295
#define LSQUARE 296
#define RSQUARE 297
#define SEMICOLON 298
#define COLON 299
#define DOT 300
#define COMMA 301
#define LET_token 302
#define VAR_token 303
#define COMMA_token 304




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 62 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.ypp"
{
  // Abstract syntax tree nodes.
  kaleidoscope::RootAST*                               rootAST;
  kaleidoscope::FunctionAST*                           functionAST;
  kaleidoscope::VariableExprAST*                           VariableExprAST;
  kaleidoscope::ExprAST*                               exprAST;
  kaleidoscope::PrototypeAST*                          prototypeAST;
  kaleidoscope::BlockAST*                              blockAST;

  std::vector<kaleidoscope::VariableExprAST>*          parameterList;
  std::string*                                         raw_string;
  char                                                 raw_char;
}
/* Line 1529 of yacc.c.  */
#line 161 "/Users/chenhaobin/Documents/LLVMCompiler/src/parser/parser.hh"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYLTYPE yylloc;
