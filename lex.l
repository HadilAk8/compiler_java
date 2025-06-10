%{
   
    #include "syn.tab.h"
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include"quad.h" 
    #include "ts.h"
   
    extern SymbolTable *idfTable;
    extern SymbolTable *separatorTable;
    extern SymbolTable *keywordTable;
    extern int nb_ligne;
    extern int Col;
    extern YYSTYPE yylval;

    

   
%}

chiffre [0-9]
idf [a-zA-Z_$][a-zA-Z0-9_]*
real [-]?{chiffre}+\.{chiffre}+
integer [-]?{chiffre}+
chaine \"[^\"]*\"
logic (true|false)

%%

"int"       { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(keywordTable, yytext, "MOT_CLE"); printf("Mot clé reconnu: %s\n", yytext); return mc_int; }
"float"     { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(keywordTable, yytext, "MOT_CLE"); printf("Mot clé reconnu: %s\n", yytext); return mc_float; }
"double"    { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(keywordTable, yytext, "MOT_CLE"); printf("Mot clé reconnu: %s\n", yytext); return mc_double; }
"char"      { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(keywordTable, yytext, "MOT_CLE"); printf("Mot clé reconnu: %s\n", yytext); return mc_char; }
"boolean"   { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(keywordTable, yytext, "MOT_CLE"); printf("Mot clé reconnu: %s\n", yytext); return mc_boolean; }
"println"   { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(keywordTable, yytext, "MOT_CLE"); printf("Mot clé reconnu: %s\n", yytext); return mc_print; }
"out"       { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(keywordTable, yytext, "MOT_CLE"); printf("Mot clé reconnu: %s\n", yytext); return mc_out; }
"class"     { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(keywordTable, yytext, "MOT_CLE"); printf("Mot clé reconnu: %s\n", yytext); return mc_class; }
"System"    { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(keywordTable, yytext, "MOT_CLE"); printf("Mot clé reconnu: %s\n", yytext); return mc_system; }
"void"      { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(keywordTable, yytext, "MOT_CLE"); printf("Mot clé reconnu: %s\n", yytext); return mc_void; }
"return"    { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(keywordTable, yytext, "MOT_CLE"); printf("Mot clé reconnu: %s\n", yytext); return mc_return; }
"switch"    { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(keywordTable, yytext, "MOT_CLE"); printf("Mot clé reconnu: %s\n", yytext); return mc_switch; }
"if"        { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(keywordTable, yytext, "MOT_CLE"); printf("Mot clé reconnu: %s\n", yytext); return mc_if; }
"else"      { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(keywordTable, yytext, "MOT_CLE"); printf("Mot clé reconnu: %s\n", yytext); return mc_else; }
"else if"   { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(keywordTable, yytext, "MOT_CLE"); printf("Mot clé reconnu: %s\n", yytext); return mc_elseif; }
"while"     { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(keywordTable, yytext, "MOT_CLE"); printf("Mot clé reconnu: %s\n", yytext); return mc_while; }
"for"       { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(keywordTable, yytext, "MOT_CLE"); printf("Mot clé reconnu: %s\n", yytext); return mc_for; }
"do"        { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(keywordTable, yytext, "MOT_CLE"); printf("Mot clé reconnu: %s\n", yytext); return mc_do; }
"case"      { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(keywordTable, yytext, "MOT_CLE"); printf("Mot clé reconnu: %s\n", yytext); return mc_case; }
"break"     { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(keywordTable, yytext, "MOT_CLE"); printf("Mot clé reconnu: %s\n", yytext); return mc_break; }
"default"   { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(keywordTable, yytext, "MOT_CLE"); printf("Mot clé reconnu: %s\n", yytext); return mc_default; }
"try"       { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(keywordTable, yytext, "MOT_CLE"); printf("Mot clé reconnu: %s\n", yytext); return mc_try; }
"catch"     { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(keywordTable, yytext, "MOT_CLE"); printf("Mot clé reconnu: %s\n", yytext); return mc_catch; }
"finally"   { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(keywordTable, yytext, "MOT_CLE"); printf("Mot clé reconnu: %s\n", yytext); return mc_finally; }
"extends"   { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(keywordTable, yytext, "MOT_CLE"); printf("Mot clé reconnu: %s\n", yytext); return mc_extends; }
"public"    { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(keywordTable, yytext, "MOT_CLE"); printf("Mot clé reconnu: %s\n", yytext); return mc_public; }
"private"   { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(keywordTable, yytext, "MOT_CLE"); printf("Mot clé reconnu: %s\n", yytext); return mc_private; }
"protected" { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(keywordTable, yytext, "MOT_CLE"); printf("Mot clé reconnu: %s\n", yytext); return mc_protected; }
"static"    { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(keywordTable, yytext, "MOT_CLE"); printf("Mot clé reconnu: %s\n", yytext); return mc_static; }
"new"       { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(keywordTable, yytext, "MOT_CLE"); printf("Mot clé reconnu: %s\n", yytext); return mc_new; }
"this"      { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(keywordTable, yytext, "MOT_CLE"); printf("Mot clé reconnu: %s\n", yytext); return mc_this; }
"throws"    { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(keywordTable, yytext, "MOT_CLE"); printf("Mot clé reconnu: %s\n", yytext); return mc_throws; }
"Exception" { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(keywordTable, yytext, "MOT_CLE"); printf("Mot clé reconnu: %s\n", yytext); return mc_exception; }
"String"    { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(keywordTable, yytext, "MOT_CLE"); printf("Mot clé reconnu: %s\n", yytext); return mc_string; }
"args"      { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(keywordTable, yytext, "MOT_CLE"); printf("Mot clé reconnu: %s\n", yytext); return mc_args; }
"&&"        { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(separatorTable, yytext, "SEP"); printf("Séparateur reconnu: %s\n", yytext); return mc_and; }
"||"        { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(separatorTable, yytext, "SEP"); printf("Séparateur reconnu: %s\n", yytext); return mc_or; }
"=="        { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(separatorTable, yytext, "SEP"); printf("Séparateur reconnu: %s\n", yytext); return mc_eq; }
"<="        { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(separatorTable, yytext, "SEP"); printf("Séparateur reconnu: %s\n", yytext); return mc_le; }
">="        { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(separatorTable, yytext, "SEP"); printf("Séparateur reconnu: %s\n", yytext); return mc_ge; }
"!="        { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(separatorTable, yytext, "SEP"); printf("Séparateur reconnu: %s\n", yytext); return mc_neq;}
"throw"     { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(keywordTable, yytext, "MOT_CLE"); printf("Mot clé reconnu: %s\n", yytext); return mc_throw;}
"ArithmeticException" {yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(keywordTable, yytext, "MOT_CLE"); printf("Mot clé reconnu: %s\n", yytext); return mc_arithmetic_exception;}
"print"     { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(keywordTable, yytext, "MOT_CLE"); printf("Mot clé reconnu: %s\n", yytext); return mc_print;}
"final"     { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertSimple(keywordTable, yytext, "MOT_CLE"); printf("Mot clé reconnu: %s\n", yytext); return mc_final;}

[{}<>+-/*%.():;,=!|&\[\]] { Col += yyleng; searchOrInsertSimple(separatorTable, yytext, "SEP"); printf("Séparateur reconnu: %s\n", yytext); return yytext[0]; }
{logic}  { yylval.str = strdup(yytext); Col += yyleng; searchOrInsertComplex(idfTable, yytext, "IDF", "", 0); printf("Booléen reconnu: %s\n", yytext); return logic; }
{idf} {  yylval.str=strdup(yytext); Col += yyleng;
 printf("Identificateur reconnu: %s\n", yytext);
 return idf; }
{real} {  yylval.reel=atof(yytext); Col += yyleng;  printf("Réel reconnu: %s\n", yytext); return real; }
{integer} { yylval.entier=atoi(yytext);  Col += yyleng;  printf("Entier reconnu: %s\n", yytext); return integer; }
{chaine}  { yylval.str = strdup(yytext); Col += yyleng;  printf("Chaine reconnue: %s\n", yytext); return chaine; }
"//".*          { Col += yyleng; }
"/*"([^*]|\*+[^*/])*\*+"/"   { Col += yyleng; }

[ \t]           { Col += yyleng; }

\n              { nb_ligne++; Col = 1; }

.               {  printf("Erreur lexicale à la ligne %d, colonne %d: %s\n", nb_ligne, Col); }


%%


