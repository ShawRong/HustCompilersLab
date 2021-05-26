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
        char*   type_string;
	struct node *ptr;
};

%type <ptr> Stmts Stmt Exp T_Identifier_NonT VarDecls VarDecl Specifier DecList ID AssignStmt PrintStmt ReturnStmt CallStmt CallExpr String Actuals PActuals ExpList Program FuncDecl FuncSign FuncBlock RetType FuncName Args _Args Arg Ret FuncRet


%start Program

%token <type_int> T_IntConstant 
%token <type_id> T_Identifier
%token <type_id> T_Int
%token <type_string> T_StringConstant
%token <type_id> T_Print
%token <type_id> T_ReadInt
%token <type_id> T_Return
%token <type_id> T_Void
%token <type_id> T_While T_If T_Else T_Break T_Continue T_Le T_Ge T_Eq T_Ne T_And T_Or

%left '='
%left T_Or
%left T_And
%left T_Eq T_Ne
%left '<' '>' T_Le T_Ge
%left '+' '-'
%left '*' '/' '%'
%right '!'

%%
Program: /*empty*/		{ $$=NULL; }
       | FuncDecl Program       { display($1,0); }
       ;

FuncDecl: FuncRet FuncSign FuncBlock { $$=mknode(FUNCDECL,$1,$2,$3,yylineno); }
        ;

FuncSign: FuncName '(' Args ')'                   { $$=mknode(FUNCSIGN,$1,$3,NULL,yylineno); }
        ;

FuncBlock : '{' VarDecls Stmts '}'                  { $$=mknode(FUNCBLOCK,$2,$3,NULL,yylineno); }
        ;

FuncRet: RetType         { $$=mknode(FUNCRET,$1,NULL,NULL,yylineno); }
       ;

RetType : T_Int          { $$=mknode(T_Int,NULL,NULL,NULL,yylineno); strcpy($$->type_id,"Int"); }
	| T_Void         { $$=mknode(T_Void,NULL,NULL,NULL,yylineno); strcpy($$->type_id,"Void"); }
        ;

FuncName : ID  { $$=$1; }
         ;

Args: /*empty*/          { $$=NULL; }
    | _Args              { $$=mknode(ARGUMENTS,$1,NULL,NULL,yylineno); }
    ;

_Args: Arg               { $$=$1; }
     | Arg ',' _Args     { $$=mknode(',',$1,$3,NULL,yylineno); }
     ;

Arg  : Specifier ID { $$=mknode(ARGUMENT,$1,$2,NULL,yylineno); }
     ;

VarDecls : /*empty*/             { $$=NULL; }
         | VarDecl ';' VarDecls  { $$=mknode(';',$1,$3,NULL,yylineno); }
         ; 

VarDecl: Specifier DecList 	       { $$=mknode(VARDECL,$1,$2,NULL,yylineno); }
       ;

Specifier: T_Int		       { $$ = mknode(T_Int,NULL,NULL,NULL,yylineno); strcpy($$->type_id,"Int"); }
         ;

DecList: ID                  { $$=$1; }
       | ID ',' DecList      { $$=mknode(',',$1,$3,NULL,yylineno); strcpy($$->type_id,","); }
       ;

ID: T_Identifier	     { $$=mknode(T_Identifier,NULL,NULL,NULL,yylineno); strcpy($$->type_id,$1); }
  ;



Stmts   :   Stmt                    	{ $$=mknode(STMTS,$1,NULL,NULL,yylineno); }
    	|   Stmt Stmts                  { $$=mknode(STMTS,$1,$2,NULL,yylineno); }
    	;

Stmt:   AssignStmt                         { $$=$1; }
    |   PrintStmt                          { $$=$1; }
    |   CallStmt		       { $$=$1; }
    |   ReturnStmt                     { $$=$1; }
    ;

AssignStmt: T_Identifier_NonT '=' Exp ';'  { $$=mknode(ASSIGN,$1,$3,NULL,yylineno); }
      ;

T_Identifier_NonT: T_Identifier        { $$=mknode(T_Identifier,NULL,NULL,NULL,yylineno); strcpy($$->type_id,$1);}
                 ;

PrintStmt: T_Print '(' String PActuals ')' ';'  { $$=mknode(PRINT,$3,$4,NULL,yylineno); }
     ;

String: T_StringConstant                             { $$=mknode(T_StringConstant,NULL,NULL,NULL,yylineno); $$->type_string = $1; }
      ;

PActuals: /*empty*/		      { $$=NULL; }
       | ExpList                      { $$=$1; }
       ;

ExpList: ',' Exp		      { $$=$2; }
       | ',' Exp ExpList              { $$=mknode(',',$2,$3,NULL,yylineno); strcpy($$->type_id,",");}
       ;

ReturnStmt: Ret Exp ';'      { $$=mknode(RETURN,$1,$2,NULL,yylineno); }
          | Ret ';'          { $$=mknode(RETURN,$1,NULL,NULL,yylineno); }
	  ;

Ret       : T_Return         { $$=mknode(T_Return,NULL,NULL,NULL,yylineno); }
          ;

CallStmt  : CallExpr ';'     { $$=$1; }
          ;

CallExpr  : ID '(' Actuals ')'  { $$=mknode(CALL,$1,$3,NULL,yylineno); }
          | ID '(' ')'          { $$=mknode(CALL,$1,NULL,NULL,yylineno); }
	  ;

Actuals   : Exp             { $$=$1; } 
          | Exp ',' Actuals { $$=mknode(',',$1,$3,NULL,yylineno); strcpy($$->type_id,","); }
          ;

IfStmt:    If TestExpr Then StmtsBlock EndThen EndIf                  { /* empty */ }
      |    If TestExpr Then StmtsBlock EndThen Else StmtsBlock EndIf  { /* empty */ }
      ;

TestExpr:   '(' Expr ')'            { /* empty */ }
        ;

StmtsBlock: '{' Stmts '}'           { /* empty */ }
          ;

If:         T_If                    { _BEG_IF; printf("_begIf_%d:\n", _i); }
  ;

Then:       /* empty */             { printf("\tjz _elIf_%d\n", _i); }
    ;

EndThen:    /* empty */             { printf("\tjmp _endIf_%d\n_elIf_%d:\n", _i, _i); }
       ;

Else:       T_Else                  { /* empty */ }
    ;

EndIf:      /* empty */             { printf("_endIf_%d:\n\n", _i); _END_IF; }
     ;

WhileStmt:  While TestExpr Do StmtsBlock EndWhile   { /* empty */ }
         ;

While:      T_While                 { _BEG_WHILE; printf("_begWhile_%d:\n", _w); }
     ;    

Do:         /* empty */             { printf("\tjz _endWhile_%d\n", _w); }
  ;

EndWhile:   /* empty */             { printf("\tjmp _begWhile_%d\n_endWhile_%d:\n\n", _w, _w); _END_WHILE; }
        ;

BreakStmt:  T_Break ';'             { printf("\tjmp _endWhile_%d\n", _w); }
         ;

ContinueStmt: T_Continue ';'        { printf("\tjmp _begWhile_%d\n", _w); }
            ;

ReadInt:  T_ReadInt '(' T_StringConstant ')' { printf("\treadint %s\n", $3); }
       ;

Exp   :   Exp '+' Exp                 { $$=mknode('+',$1,$3,NULL,yylineno); strcpy($$->type_id,"+"); }
    |   Exp '-' Exp                   { $$=mknode('-',$1,$3,NULL,yylineno); strcpy($$->type_id,"-"); }
    |   Exp '*' Exp                   { $$=mknode('*',$1,$3,NULL,yylineno); strcpy($$->type_id,"*"); }
    |   Exp '/' Exp                   { $$=mknode('/',$1,$3,NULL,yylineno); strcpy($$->type_id,"/"); }
    |   '-' Exp %prec '!'           { $$=mknode(UMINUS,$2,NULL,NULL,yylineno); strcpy($$->type_id,"UMINUS"); }
    |   T_IntConstant                 { $$=mknode(T_IntConstant,NULL,NULL,NULL,yylineno); $$->type_int = $1; }
    |   T_Identifier                  { $$=mknode(T_Identifier,NULL,NULL,NULL,yylineno); strcpy($$->type_id,$1); }
    |   '(' Exp ')'                   { $$=$2; }
    |   CallExpr                      { $$=$1; }
    ;



%%

int main() {
    return yyparse();
}
