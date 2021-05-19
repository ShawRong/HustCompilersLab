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
	struct node *ptr;
} YYLVAL;

#define YYSTYPE YYLVAL

%}

%option yylineno

OPERATOR        [-/+*()=;]
INTEGER         [0-9]+
IDENTIFIER      [_a-zA-Z][_a-zA-Z0-9]*
WHITESPACE      [ \t]*

%%
{OPERATOR}      { return yytext[0]; }
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
