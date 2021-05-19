%error-verbose
%locations
%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "def.h"
extern int yylineno;
extern char *yytext;
extern FILE *yyin;
void yyerror(const char*);
void display(struct node *,int);
%}

%union {
	int    type_int;
	char   type_id[32];
	struct node *ptr;
};

%type <ptr> EXP_Stmt Exp T_Identifier_NonT


%start S

%token <type_int> T_IntConstant 
%token <type_id> T_Identifier

%left '+' '-'
%left '*' '/'
%right U_neg

%%

S   :   EXP_Stmt                    { display($1, 0); }
    |   S EXP_Stmt                  { display($2, 0); }
    ;

EXP_Stmt:   T_Identifier_NonT '=' Exp ';'  { $$=mknode(EXP_STMT,$1,$3,NULL,yylineno); }
    ;

T_Identifier_NonT: T_Identifier       { $$=mknode(T_Identifier,NULL,NULL,NULL,yylineno); strcpy($$->type_id,$1);}
                 ;

Exp   :   Exp '+' Exp                 { $$=mknode('+',$1,$3,NULL,yylineno); strcpy($$->type_id,"+"); }
    |   Exp '-' Exp                   { $$=mknode('-',$1,$3,NULL,yylineno); strcpy($$->type_id,"-"); }
    |   Exp '*' Exp                   { $$=mknode('*',$1,$3,NULL,yylineno); strcpy($$->type_id,"*"); }
    |   Exp '/' Exp                   { $$=mknode('/',$1,$3,NULL,yylineno); strcpy($$->type_id,"/"); }
    |   '-' Exp %prec U_neg           { $$=mknode(UMINUS,$2,NULL,NULL,yylineno); strcpy($$->type_id,"UMINUS"); }
    |   T_IntConstant                 { $$=mknode(T_IntConstant,NULL,NULL,NULL,yylineno); $$->type_int = $1; }
    |   T_Identifier                  { $$=mknode(T_Identifier,NULL,NULL,NULL,yylineno); strcpy($$->type_id,$1); }
    |   '(' Exp ')'                   { $$=$2; }
    ;

%%

int main() {
    return yyparse();
}
