#include "scope.h"

void InitScopeStack(ScopeStack* stack){
    stack->base = (Scope*) malloc(STACK_INIT_SIZE * sizeof(Scope));
    stack->top = stack->base;
    stack->stacksize = STACK_INIT_SIZE;
    return;
}

void DestroyScopeStack(ScopeStack* stack){
    if(stack->base){
        free(stack->base);
    }
    stack->base = NULL;
    stack->top = NULL;
    return;
}

void PushScopeStack(ScopeStack* stack, Scope scope){
    if((stack->top - stack-> base) / sizeof(Scope) >= stack->stacksize){
        stack->base = (Scope*) realloc(stack->base, (stack->stacksize + STACKINCERMENT) * sizeof(Scope));
        stack->top = stack->base + stack->stacksize;
        stack->stacksize += STACKINCERMENT;
    }
    *stack->top++ = scope;
    return;
}

void PopScopeStack(ScopeStack* stack, Scope* scope){
    *scope = *--stack->top;
    return;
}

//global
GlobalScope AddIntoGlobal(GlobalScope global_symtable, char* name, Depicotr depictor){
    char* cache = (char*)malloc(sizeof(char) * strlen(name));
    strcpy(cache, name);
    GlobalScope tmp = (GlobalScope)malloc(sizeof(GlobalScopeEntry));
    tmp->name = cache;
    tmp->depictor = depictor;
    tmp->next = global_symtable;
    return tmp;
}

//local
LocalScope AddIntoLocal(LocalScope local_symtable, char* name, TinyCCategory category,  LocalScope embeddscope){
    char* cache = (char*)malloc(sizeof(char) * strlen(name));
    strcpy(cache, name);
    LocalScope tmp = (LocalScope)malloc(sizeof(LocalScopeEntry));
    tmp->name = cache;
    tmp->category = category;
    tmp->embededscope = embeddscope;
    tmp->next = local_symtable;
    return tmp;
}

//formal
FormalScope AddIntoFormal(Formal formal_symtable,  char* name, LocalScope functionscope){
    char* cache = (char*)malloc(sizeof(char) * strlen(name));
    strcpy(cache, name);
    FormalScope tmp = (FormalScope)malloc(sizeof(FormalScopeEntry));
    tmp->name = cache;
    tmp->functionscope = functionscope;
    tmp->next = formal_symtable;
    return tmp;
}

//find
GlobalScope FindInGlobal(ScopeStack* stack, char* function_name){
    GlobalScope globalscope = stack->base->globalscope;
    while(globalscop){
        if(!strcmp(globalscope -> name, function_name)){
            return globalscope;
        }
        globalscope = globalscope->next;
    }
    return NULL;
}

//find
LocalScope FindInLocal(LocalScope localscope, char* local_name, TinyCCategory category){
    while(localscope){
	if(!strcmp(localscope->name, local_name) && localscope->category == category){
            return localscope;
        }
	if(localscope->category == Block){
            LocalScope result = FindInLocal(localscope->embededscope, local_name, category);
	    if(result){
                return result;
            }
        }
    }
    return NULL;
}

//find
LocalScope FindInFunc(ScopeStack* stack, char* function_name, char* local_name, TinyCCategory category){
    GlobalScope globalscope = stack->base->globalscope;
    LocalScope localscope = NULL;
    while(globalscope){
        if(!strcmp(globalscope -> name, function_name)){
            localscope = globalscope->depictor.localdsp->localscope;
            break;
        }
        globalscope = globalscope->next;
    }
    return FindInLocal(localscope, local_name, category);
}

//find
FormalScope FindInFormal(ScopeStack* stack, char* function_name, char* param_name){
    GlobalScope globalscope = stack->base->globalscope;
    FormalScope formalscope = NULL;
    while(globalscope){
        if(!strcmp(globalscope -> name, function_name)){
            formalscope = globalscop->depictor.formaldsp->formalscope;
            break;
        }
        globalscope = globalscope->next;
    }
    while(formalscope){
        if(!strcmp(formalscope->name, param_name)){
            return formalscope;
        }
        formalscope = formalscope -> next;
    }
    return NULL;
}
