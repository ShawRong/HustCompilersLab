#include "scope.h"
#include "def.h"

typedef node* Node;
//scope trial
void ScopeTrial(Node tree, Scope scope, ScopeStack* stack){
    if(tree == NULL){
    	return;
    }
    if(!strcmp(tree, PROGRAM)){
        PushScopeStack(stack, scope);
    } else if(!strcmp(tree->name, FUNCDECL)){
        FunctionDepictor funcdsp;
        funcdsp = tree.depictor.funcdsp;
        //Push function forrmals into scope stack
        scope.type = ScopeFormal;
        scope.formalscope = funcdsp->formalscope;
        PushScopeStack(stack, scope);
        //Push function body into scope stack
        scope.type = ScopeLocal;
        scope.localscope = funcdsp->formalscope->functionscope;
        PushScopeStack(stack, scope);
    } else if(!strcmp(tree->name, STMTSBLOCK)){
        // Judge if this block is function body
        if(tree->localscope != GetStackTop(stack) -> localscope){
            scope.type = ScopeLocal;
            scope.localscope = tree->localscope;
            PushScopeStack(stack, scope);
        }
    } else if(!strcmp(tree->name, "SPRIGHTBRACE")){ // SPRIGHTBRACE
        Scope top;
        PopScopeStack(stack, &top);
        //Judge if it is function
        if(top.type == ScopeLocal && GetStackTop(stack)->type == ScopeFormal){
            PopScopeStack(stack, &top);
        }
        scope = *GetStackTop(stack);
    } else if(!strcmp(tree->name, ASSIGN) && )
}
