%option noyywrap
%option yylineno

%{
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstdint>
#include <string>

#include <parser/parser.hh>
#include <llvm/Support/raw_ostream.h>

extern void yyerror(const char* error_information);
int yycolumn = 1;

#define YY_USER_ACTION yylloc.first_line = yylineno;            \
                       yylloc.first_column = yycolumn;          \
                       for (char c : std::string(yytext)) {     \
                           if (c == '\n' || c == '\r') {        \
                               yycolumn = 1;                    \
                           } else {                             \
                               yycolumn++;                      \
                           }                                    \
                       }                                        \
                       yylloc.last_line = yylineno;             \
                       yylloc.last_column = yycolumn - 1;
%}

DECIMAL     ([0-9]+\.?[0-9]*|\.[0-9]+)
OCTAL       0([0-7]+)
HEX         (0x|0X)([0-9a-fA-F]+)
ID          [[:alpha:]_][[:alpha:][:digit:]_]*
EMPTY       [ \t\n\r]+
COMMENT     #[^\n\r]*(\n|\r|\n\r)
BEGIN       \/\*
STRING      \"[^\"]*\"
CHAR        '\\?.'

%%
{COMMENT} { ; }

"if"         { return IF_token; }
"else"       { return ELSE_token; }
"do"         { return DO_token; }
"while"      { return WHILE_token; }
"true"       { return TRUE_token; }
"false"      { return FALSE_token; }
"return"     { return RETURN_token; }
"continue"   { return CONTINUE_token; }
"break"      { return BREAK_token; }
"for"        { return FOR_token; }
"def"        { return DEF_token; }
"and"        { return AND_token; }
"or"         { return OR_token; }
"not"        { return NOT_token; }
"var"        { return VAR_token; }
"let"        { return LET_token; }

{HEX}        { yylval.raw_string = new std::string(std::to_string(std::stoul(std::string(yytext, yyleng), nullptr, 16))); return HEX_token; }
{OCTAL}      { yylval.raw_string = new std::string(std::to_string(std::stoul(std::string(yytext, yyleng), nullptr, 8))); return OCTAL_token; }
{DECIMAL}    { yylval.raw_string = new std::string(yytext, yyleng); return DECIMAL_token; }

"["          { return LSQUARE; }
"]"          { return RSQUARE; }
"{"          { return LBRACE; }
"}"          { return RBRACE; }
"("          { return LPARENTHESIS; }
")"          { return RPARENTHESIS; }
"."          { return DOT; }
","          { return COMMA; }

"=="         { return EQ_token; }
">="         { return GEQ_token; }
"<="         { return LEQ_token; }
"<"          { return LT_token; }
">"          { return GT_token; }
"!="         { return NEQ_token; }

"="          { return ASSIGN_token; }

"++"         { return INC_token; }
"--"         { return DEC_token; }
"+"          { return ADD_token; }
"-"          { return MINUS_token; }
"*"          { return MUL_token; }
"/"          { return DIV_token; }
"%"          { return MOD_token; }

{ID}         { yylval.raw_string = new std::string(yytext, yyleng); return ID_token; }
{CHAR}       { yylval.raw_char = yytext[1]; return CHAR_token; }
{STRING}     { yylval.raw_string = new std::string(yytext, yyleng); return STRING_token; }
{EMPTY}      { ; }

. { 
  llvm::errs() << "Error: Unknown character!";
}

<<EOF>> { yyterminate(); }

%%