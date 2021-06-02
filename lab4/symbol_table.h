#include <stdlib.h>
#define STACK_INIT_SIZE  1000;
#define STACKINCERMENT 100;

typedef enum TinyCCategory{
    Variable,
    Function,
} TinyCCategory;

typedef struct FunctionDepictor {
    char* functionanme;
    FormalScope formalscope;
    LocalScope localScope;
} FunctionDepictor;

typedef union Depictor {
    FunctionDepictor funcdsp;
} Depictor;

typedef struct GlobalScopeEntry{
    char* name;
    TinyCCategory category;
    Depictor depictor;
    struct GlobalScopeEntry* next;
} GlobalScopeEntry;

typedef GlobalScopeEntry* GlobalScope;


//Local
typedef struct LocalScopeEntry {
    char* name;
    TinyCCategory category;
    struct LocalScopeEntry* embededscope;
    struct LocalScopeEntry* next;
} LocalScopeEntry;

typedef struct LocalScopeEntry* LocalScope;

//Params
typedef struct FormalScopeEntry {
    char* name;
    LocalScope functionscope;
    struct FormalScopeEntry* next;
} FormalScopeEntry;

typedef FormalScopeEntry* FormalScope;


typedef enum ScopeType {
    ScopeLocal,
    ScopeFormal,
    ScopeGlobal,
    ScopeNone
} ScopeType;

typedef struct Scope{
    ScopeType type;
    union {
        LocalScope localscope;
        FormalScope formalscope;
        GlobalScope globalscope;
    };
} Scope;

typedef struct ScopeStack {
    Scope* base;
    Scope* top;
    int stacksize;
} ScopeStack;

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
GlobalScope AddIntoGlobal(GlobalScope global_symtable, char* name, TinyCCategory category, Depicotr depictor){
    char* cache = (char*)malloc(sizeof(char) * strlen(name));
    strcpy(cache, name);
    GlobalScope tmp = (GlobalScope)malloc(sizeof(GlobalScopeEntry));
    tmp->name = cache;
    tmp->category = category;
    tmp->depictor = depictor;
    tmp->next = global_symtable;
    return tmp;
}

//local
LocalScope AddIntoLocal(LocalScope local_symtable, char* name, TinyCCategory category, char* type,  LocalScope embeddscope){
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
FormalScope AddIntoFormal(Formal formal_symtable,  char* name,  char* type, LocalScope functionscope){
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
LocalScope FindInLocal(ScopeStack* stack, char* function_name, char* local_name, TinyCCategory category){
    GlobalScope globalscope = stack->base->globalscope;
    LocalScope localscope = NULL;
    while(globalscope){
        if(!strcmp(globalscope -> name, function_name)){
            localscope = globalscope->depictor.localdsp->localscope;
            break;
        }
        globalscope = globalscope->next;
    }
    while(localscope){
        if(!strcmp(localscop->name, local_name) && localscope->category == category){
            return localscope;
        }
        localscope = localscope->next;
    }
    return NULL;
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
