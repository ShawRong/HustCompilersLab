#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdarg.h"
#include "y.tab.h"

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

struct codenode {   //三地址TAC代码结点,采用双向循环链表存放中间语言代码
        int  op;                          //TAC代码的运算符种类
        struct opn opn1,opn2,result;          //2个操作数和运算结果
        struct codenode  *next,*prior;
};

struct node {    //以下对结点属性定义没有考虑存储效率，只是简单地列出要用到的一些属性
	enum node_kind kind;               //结点类型
	union {
		  char type_id[33];             //由标识符生成的叶结点
		  int type_int;                 //由整常数生成的叶结点
		  char* type_string;
	      };
    struct node *ptr[3];                   //子树指针，由kind确定有多少棵子树
    int level;                    //层号
    int place;                    //表示结点对应的变量或运算结果临时变量在符号表的位置序号
    char Etrue[15],Efalse[15];      //对布尔表达式的翻译时，真假转移目标的标号
    char Snext[15];               //该结点对应语句执行后的下一条语句位置标号
    struct codenode *code;         //该结点中间代码链表头指针
    char op[10];
    int pos;                     //语法单位所在位置行号
    int offset;                   //偏移量
    int width;                   //各种数据占用的字节数
};


struct node *mknode(int kind,struct node *first,struct node *second, struct node *third,int pos );



