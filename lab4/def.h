#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdarg.h"
#include "y.tab.h"
#define MAXLENGTH   200
#define DX 3*sizeof(int)

enum node_kind  { UMINUS, ASSIGN, PRINT, VARDECL, CALL, RETURN, ARGUMENTS, ARGUMENT, FUNCDECL, FUNCSIGN, FUNCBLOCK, STMTS, PROGRAM, FUNCRET, READINT, IF, ELSE, IFTEST, IFSTMT, WHILETEST, WHILESTMT, STMTSBLOCK, NOT, IFELSESTMT};

int LEV;

struct opn{
    int kind;    //标识联合成员的属性
    union {
        int     const_int;      //整常数值，立即数
        char    const_char;     //字符常数值，立即数
        char    id[33];         //变量或临时变量的别名或标号字符串
        };
    int level;                  //变量的层号，0表示是全局变量，数据保存在静态数据区
    int offset;                 //偏移量，目标代码生成时用
};

struct codenode {   //三地址TAC代码结点,采用单链表存放中间语言代码
        int  op;
        struct opn opn1,opn2,result;
        struct codenode  *next,*prior;
    };



typedef struct node {    //以下对结点属性定义没有考虑存储效率，只是简单地列出要用到的一些属性
	enum node_kind kind;               //结点类型
	union {
		  char type_id[33];             //由标识符生成的叶结点
		  int type_int;                 //由整常数生成的叶结点
		  char* type_string;
	      };
    	struct node *ptr[3];                   //子树指针，由kind确定有多少棵子树
    	int pos;    //位置行号
	char Etrue[15],Efalse[15];       //对布尔表达式的翻译时，真假转移目标的标号	
	int offset;
        int num;
	int place;
	int width;
	struct codenode * code;
	char Snext[15];               //结点对应语句S执行后的下一条语句位置标号
}node;

struct symbol {
	char name[33];   //变量或函数名
    	int level;        //层号
    	int  paramnum;  //对函数适用，记录形式参数个数
    	char alias[10];   //别名，为解决嵌套层次使用
    	char flag;       //符号标记，函数：'F'  变量：'V'   参数：'P'  临时变量：'T'
	char offset;      //外部变量和局部变量在其静态数据区或活动记录中的偏移量，
	//或记录函数活动记录大小，目标代码生成时使用
    	//函数入口等实验可能会用到的属性...
};

struct symboltable{
    struct symbol symbols[MAXLENGTH];
    int index;
} symbolTable;


struct symbol_scope_begin {
    	//当前作用域的符号在符号表的起始位置序号,这是一个栈结构,当使用顺序表作为符号表时，进入、退出一个作用域时需要对其操作，以完成符号表的管理。对其它形式的符号表，不一定需要此数据结构
    	int TX[30];
    	int top;
} symbol_scope_TX;



struct node *mknode(int kind,struct node *first,struct node *second, struct node *third,int pos);
void semantic_Analysis0(node *T);
void semantic_Analysis(node *T);
void boolExp(node *T);
void Exp(node *T);
void objectCode(struct codenode *head);



