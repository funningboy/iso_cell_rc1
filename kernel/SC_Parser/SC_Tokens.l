%{
#include <string>
#include "SC_Parser.hpp"
#define SAVE_TOKEN SC_lval.sc_string = new std::string(yytext, yyleng)
#define TOKEN(t) (SC_lval.token = t)
%}

%option prefix="SC_"
%option noyywrap

%%

[ \t\n]                                ;
module                                 return TOKEN(TMODULE);   
endmodule                              return TOKEN(TEDMODULE);
input                                  return TOKEN(TINPUT);
output                                 return TOKEN(TOUTPUT);
wire                                   return TOKEN(TWIRE);
and                                    return TOKEN(TAND);
nand                                   return TOKEN(TNAND);
or                                     return TOKEN(TOR);
nor                                    return TOKEN(TNOR);
xor                                    return TOKEN(TXOR);
xnor                                   return TOKEN(TXNOR);
buf                                    return TOKEN(TBUF);
not                                    return TOKEN(TNOT);
dff                                    return TOKEN(TDFF);
Library                                return TOKEN(TLIBRARY);
Design                                 return TOKEN(TDESIGN);
[a-zA-Z_][a-zA-Z0-9_]*     SAVE_TOKEN; return TIDENTIFIER;
[0-9]+\.[0-9]*             SAVE_TOKEN; return TDOUBLE;
[0-9]+                     SAVE_TOKEN; return TINTEGER;
"="                                    return TOKEN(TEQUAL);
"=="                                   return TOKEN(TCEQ);
"!="                                   return TOKEN(TCNE);
"<"                                    return TOKEN(TCLT);
"<="                                   return TOKEN(TCLE);
">"                                    return TOKEN(TCGT);
">="                                   return TOKEN(TCGE);
"("                                    return TOKEN(TLPAREN);
")"                                    return TOKEN(TRPAREN);
"{"                                    return TOKEN(TLBRACE);
"}"                                    return TOKEN(TRBRACE);
"["                                    return TOKEN(TLSQUARE);
"]"                                    return TOKEN(TRSQUARE);
":"                                    return TOKEN(TCOLON);
"."                                    return TOKEN(TDOT);
","                                    return TOKEN(TCOMMA);
"+"                                    return TOKEN(TPLUS);
"-"                                    return TOKEN(TMINUS);
"*"                                    return TOKEN(TMUL);
"/"                                    return TOKEN(TDIV);
";"                                    return TOKEN(TEND);
"~"                                    return TOKEN(TINV);
. printf("Unknown token!\n"); yyterminate();

%%
