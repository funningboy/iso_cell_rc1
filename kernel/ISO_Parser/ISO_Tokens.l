%{
#include <string>
#include "ISO_Parser.hpp"
#define SAVE_TOKEN ISO_lval.iso_string = new std::string(yytext, yyleng)
#define TOKEN(t) (ISO_lval.token = t)
%}

%option prefix="ISO_"
%option noyywrap

%%

[ \t\n]                                ;
create_power_domain                    return TOKEN(TCREATE_POWER_DOMAIN);
default                                return TOKEN(TDEFAULT);
instances                              return TOKEN(TINSTANCES);
name                                   return TOKEN(TNAME);
boundary_ports                         return TOKEN(TBOUNDARY_PORTS);
create_isolation_rule                  return TOKEN(TCREATE_ISOLATION_RULE);
from                                   return TOKEN(TFROM);
to                                     return TOKEN(TTO);
either                                 return TOKEN(TEITHER);
isolation_output                       return TOKEN(TISOLATION_OUTPUT);
isolation_condition                    return TOKEN(TISOLATION_CONDITION);
high                                   return TOKEN(THIGH);
low                                    return TOKEN(TLOW);
define_isolation_cell                  return TOKEN(TDEFINE_ISOLATION_CELL);
cells                                  return TOKEN(TCELLS);
enable                                 return TOKEN(TENABLE);
valid_location                         return TOKEN(TVALID_LOCATION);
create_level_shifter_rule              return TOKEN(TCREATE_LEVEL_SHIFTER_RULE);
define_level_shifter_cell              return TOKEN(TDEFINE_LEVEL_SHIFTER_CELL);
input_voltage_range                    return TOKEN(TINPUT_VOLTAGE_RANGE);
output_voltage_range                   return TOKEN(TOUTPUT_VOLTAGE_RANGE);
direction                              return TOKEN(TDIRECTION);
up                                     return TOKEN(TUP);
down                                   return TOKEN(TDOWN);
create_nominal_condition               return TOKEN(TCREATE_NOMINAL_CONDITION);
voltage                                return TOKEN(TVOLTAGE);
domain_conditions                      return TOKEN(TDOMAIN_CONDITIONS);
create_power_mode                      return TOKEN(TCREATE_POWER_MODE);

[a-zA-Z_][a-zA-Z0-9_\/]*   SAVE_TOKEN; return TIDENTIFIER;
[0-9]+\.[0-9]*             SAVE_TOKEN; return TDOUBLE;
[0-9]+                     SAVE_TOKEN; return TINTEGER;
"="                                    return TOKEN(TEQUAL);
"<"                                    return TOKEN(TCLT);
">"                                    return TOKEN(TCGT);
"("                                    return TOKEN(TLPAREN);
")"                                    return TOKEN(TRPAREN);
"{"                                    return TOKEN(TLBRACE);
"}"                                    return TOKEN(TRBRACE);
"["                                    return TOKEN(TLSQUARE);
"]"                                    return TOKEN(TRSQUARE);
";"                                    return TOKEN(TEND);
"\\"                                   return TOKEN(TSLASH);
"!"                                    return TOKEN(TINV);
":"                                    return TOKEN(TCOLON);
"-"                                    return TOKEN(TMINUS);
"@"                                    return TOKEN(TAT);
. printf("Unknown token!\n"); yyterminate();

%%
