#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdarg.h"
#include "y.tab.h"
#include "scope.h"

enum node_kind  { UMINUS, ASSIGN, PRINT, VARDECL, CALL, RETURN, ARGUMENTS, ARGUMENT, FUNCDECL, FUNCSIGN, FUNCBLOCK, STMTS, PROGRAM, FUNCRET, READINT, IF, ELSE, IFTEST, IFSTMT, WHILETEST, WHILESTMT, STMTSBLOCK, NOT};

struct opn{
    int kind;                  //标识操作的类型
    int type;                  //标识操作数的类型
    union {
        int     const_int;      //整常数值，立即数
        char    const_char;    //字符常数值，立即数
        char    id[33];        //变量或临时变量的别名或标号字符串
        };
    int level;                 //变量的层号，0表示是全局变量，数据保存在静态数据区
    int offset;                 //变量单元偏移量，或函数在符号表的定义位置序号，目标代码生成时用
};

typedef struct node {    //以下对结点属性定义没有考虑存储效率，只是简单地列出要用到的一些属性
	enum node_kind kind;               //结点类型
	union {
		  char type_id[33];             //由标识符生成的叶结点
		  int type_int;                 //由整常数生成的叶结点
		  char* type_string;
	      };
    	struct node *ptr[3];                   //子树指针，由kind确定有多少棵子树
    	int pos;
}node;


struct node *mknode(int kind,struct node *first,struct node *second, struct node *third,int pos );


