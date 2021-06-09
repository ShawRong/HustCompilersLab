#include <stdlib.h>
#include <string.h>
#define STACK_INIT_SIZE  1000;
#define STACKINCERMENT 100;

typedef enum TinyCCategory{
    Variable,
    Function,
    Block
} TinyCCategory;

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

typedef struct FunctionDepictor_t {
    FormalScope formalscope;
} FunctionDepictor_t;

typedef FunctionDepictor_t* FunctionDepictor;

typedef union Depictor {
    FunctionDepictor funcdsp;
} Depictor;

typedef struct GlobalScopeEntry{
    char* name;
    Depictor depictor;
    struct GlobalScopeEntry* next;
} GlobalScopeEntry;

typedef GlobalScopeEntry* GlobalScope;


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

void InitScopeStack(ScopeStack* stack);

void DestroyScopeStack(ScopeStack* stack);

void PushScopeStack(ScopeStack* stack, Scope scope);

void PopScopeStack(ScopeStack* stack, Scope* scope);

//global
GlobalScope AddIntoGlobal(GlobalScope global_symtable, char* name, Depicotr depictor);

//local
LocalScope AddIntoLocal(LocalScope local_symtable, char* name, TinyCCategory category,  LocalScope embeddscope);

//formal
FormalScope AddIntoFormal(Formal formal_symtable,  char* name, LocalScope functionscope);

//find
GlobalScope FindInGlobal(ScopeStack* stack, char* function_name);

//find
LocalScope FindInLocal(LocalScope localscope, char* local_name, TinyCCategory category);

//find
LocalScope FindInFunc(ScopeStack* stack, char* function_name, char* local_name, TinyCCategory category);

//find
FormalScope FindInFormal(ScopeStack* stack, char* function_name, char* param_name);

//new
FormalScope NewFormalScope(){
    FormalScope tmp = (FormalScope)malloc(sizeof(FormalScopeEntry));
    tmp.name = 
}
