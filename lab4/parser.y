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

%type <ptr> Stmts Stmt Exp T_Identifier_NonT VarDecls VarDecl Specifier DecList ID AssignStmt PrintStmt ReturnStmt CallStmt CallExpr String Actuals PActuals ExpList Program FuncDecl FuncSign FuncBlock RetType FuncName Args _Args Arg Ret FuncRet IfStmt IfTest TestExpr StmtsBlock WhileStmt WhileTest BreakStmt ContinueStmt ReadInt ReadInt_NotT


%start Program

%token <type_int> T_IntConstant 
%token <type_id> T_Identifier
%token <type_id> T_Int
%token <type_string> T_StringConstant
%token <type_id> T_Print
%token <type_id> T_ReadInt
%token <type_id> T_Return
%token <type_id> T_Void
%token <type_id> T_While
%token <type_id> T_If
%token <type_id> T_Else
%token <type_id> T_Break
%token <type_id> T_Continue
%token <type_id> T_Le
%token <type_id> T_Ge
%token <type_id> T_Eq
%token <type_id> T_Ne
%token <type_id> T_And
%token <type_id> T_Or

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
       | FuncDecl Program       { $$=mknode(PROGRAM,$1,$2,NULL,yylineno); display($1,0); }
       ;

FuncDecl: FuncRet FuncSign FuncBlock { $$=mknode(FUNCDECL,$1,$2,$3,yylineno); }
        ;

FuncSign: FuncName '(' Args ')'                   { $$=mknode(FUNCSIGN,$1,$3,NULL,yylineno); strcpy($$->type_id,$1); }
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
    |   CallStmt		           { $$=$1; }
    |   ReturnStmt                         { $$=$1; }
    |   IfStmt                             { $$=$1; }
    |   WhileStmt                          { $$=$1; }
    |   BreakStmt                          { $$=$1; }
    |   ContinueStmt                       { $$=$1; }
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

IfStmt:    IfTest Then StmtsBlock EndThen EndIf                  { $$=mknode(IFSTMT,$1,$3,NULL,yylineno); }
      |    IfTest Then StmtsBlock EndThen Else StmtsBlock EndIf  { $$=mknode(IFSTMT,$1,$3,$6,yylineno); }
      ;

IfTest : If TestExpr                { $$=mknode(IFTEST,$2,NULL,NULL,yylineno); }
       ;

TestExpr:   '(' Exp ')'             { $$=$2; }
        ;

StmtsBlock: '{' Stmts '}'           { $$=mknode(STMTSBLOCK,$2,NULL,NULL,yylineno); }
          ;

If:         T_If                    { /* empty */ }
  ;

Then:       /* empty */             { /* empty */ }
    ;

EndThen:    /* empty */             { /* empty */ }
       ;

Else:       T_Else                  { /* empty */ }
    ;

EndIf:      /* empty */             { /* empty */ }
     ;

WhileStmt:  WhileTest Do StmtsBlock EndWhile   { $$=mknode(WHILESTMT,$1,$3,NULL,yylineno); }
         ;

WhileTest:  While TestExpr          { $$=mknode(WHILETEST,$2,NULL,NULL,yylineno); }
         ;

While:      T_While                 { /* empty */ }
     ;    

Do:         /* empty */             { /* empty */ }
  ;

EndWhile:   /* empty */             { /* empty */ }
        ;

BreakStmt:  T_Break ';'             { $$=mknode(T_Break,NULL,NULL,NULL,yylineno); strcpy($$->type_id,"BREAK"); }
         ;

ContinueStmt: T_Continue ';'        { $$=mknode(T_Continue,NULL,NULL,NULL,yylineno); strcpy($$->type_id,"Continue"); }
            ;

Exp   :   Exp '+' Exp                 { $$=mknode('+',$1,$3,NULL,yylineno); strcpy($$->type_id,"+"); }
    |   Exp '-' Exp                   { $$=mknode('-',$1,$3,NULL,yylineno); strcpy($$->type_id,"-"); }
    |   Exp '*' Exp                   { $$=mknode('*',$1,$3,NULL,yylineno); strcpy($$->type_id,"*"); }
    |   Exp '/' Exp                   { $$=mknode('/',$1,$3,NULL,yylineno); strcpy($$->type_id,"/"); }
    |   '-' Exp %prec '!'             { $$=mknode(UMINUS,$2,NULL,NULL,yylineno); strcpy($$->type_id,"UMINUS"); }
    |   T_IntConstant                 { $$=mknode(T_IntConstant,NULL,NULL,NULL,yylineno); $$->type_int = $1; }
    |   T_Identifier                  { $$=mknode(T_Identifier,NULL,NULL,NULL,yylineno); strcpy($$->type_id,$1); }
    |   '(' Exp ')'                   { $$=$2; }
    |   CallExpr                      { $$=$1; }
    |   Exp '%' Exp		      { $$=mknode('%',$1,$3,NULL,yylineno); strcpy($$->type_id,"%"); }
    |   Exp '>' Exp                   { $$=mknode('>',$1,$3,NULL,yylineno); strcpy($$->type_id,">"); }
    |   Exp '<' Exp                   { $$=mknode('<',$1,$3,NULL,yylineno); strcpy($$->type_id,"<"); }
    |   Exp T_Ge Exp                  { $$=mknode(T_Ge,$1,$3,NULL,yylineno); strcpy($$->type_id,">="); }
    |   Exp T_Le Exp                  { $$=mknode(T_Le,$1,$3,NULL,yylineno); strcpy($$->type_id,"<="); }
    |   Exp T_Eq Exp                  { $$=mknode(T_Eq,$1,$3,NULL,yylineno); strcpy($$->type_id,"=="); }
    |   Exp T_Ne Exp                  { $$=mknode(T_Ne,$1,$3,NULL,yylineno); strcpy($$->type_id,"!="); }
    |   Exp T_Or Exp                  { $$=mknode(T_Or,$1,$3,NULL,yylineno); strcpy($$->type_id,"OR"); }
    |   Exp T_And Exp                 { $$=mknode(T_And,$1,$3,NULL,yylineno); strcpy($$->type_id,"AND"); }
    |   '!' Exp                       { $$=mknode(NOT,$2,NULL,NULL,yylineno); strcpy($$->type_id,"NOT"); }
    |   ReadInt                       { $$=$1; }
    ;

ReadInt: ReadInt_NotT '(' String ')' { $$=mknode(READINT,$1,$3,NULL,yylineno); strcpy($$->type_id, "READINT"); }
       ;

ReadInt_NotT:T_ReadInt               { $$=mknode(T_ReadInt,NULL,NULL,NULL,yylineno); }
            ;

%%

int main() {
    return yyparse();
}
