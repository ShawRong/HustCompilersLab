%{
#include "y.tab.h"
#include "string.h"
#include "def.h"
int yycolumn=1;
#define YY_USER_ACTION    	yylloc.first_line=yylloc.last_line=yylineno; yylloc.first_column=yycolumn;	yylloc.last_column=yycolumn+yyleng-1; yycolumn+=yyleng;

void yyerror(const char *msg);
void unrecognized_char(char c);

typedef union {
	int type_int;
	char type_id[32];
	char* type_string;
	struct node *ptr;
} YYLVAL;

#define YYSTYPE YYLVAL

%}

%option yylineno

OPERATOR        [-/+*()=,;{}]
INTEGER         [0-9]+
STRING		\042[^\042\n]*\042
IDENTIFIER      [_a-zA-Z][_a-zA-Z0-9]*
WHITESPACE      [ \t]*
SINGLE_COMMENT1     ("//"[^\n]*)
SINGLE_COMMENT2     ("#"[^\n]*)

%%
{OPERATOR}      { return yytext[0]; }
"int"           { return T_Int; }
"void"          { return T_Void; }
"return"        { return T_Return; }
"print"         { return T_Print; }
"readint"           { return T_ReadInt; }
"while"             { return T_While; }
"if"                { return T_If; }
"else"              { return T_Else; }
"break"             { return T_Break; }
"continue"          { return T_Continue; }
"<="                { return T_Le; }
">="                { return T_Ge; }
"=="                { return T_Eq; }
"!="                { return T_Ne; }
"&&"                { return T_And; }
"||"                { return T_Or; }


{SINGLE_COMMENT1}   { /* skip for single line comment */    }
{SINGLE_COMMENT2}   { /* skip for single line comment */    }

{STRING}        { yylval.type_string = strdup(yytext); return T_StringConstant; }
{INTEGER}       { yylval.type_int = atoi(yytext); return T_IntConstant; }
{IDENTIFIER}    { strcpy(yylval.type_id, yytext); return T_Identifier; }
{WHITESPACE}    { /* ignore every whitespcace */ }
\n              { yycolumn = 1; }
.               { unrecognized_char(yytext[0]); }
%%

int yywrap(void) { 
    return 1;
}

void unrecognized_char(char c) {
    char buf[32] = "Unrecognized character: ?";
    buf[24] = c;
    yyerror(buf);
}

void yyerror(const char *msg) {
    printf("Error at line %d:\n\t%s\n", yylineno, msg);
    exit(1);
}
