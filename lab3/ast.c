#include "def.h"
struct node * mknode(int kind,struct node *first,struct node *second, struct node *third,int pos ) {
  struct node *T=(struct node *)malloc(sizeof(struct node));
  T->kind=kind;
  T->ptr[0]=first;
  T->ptr[1]=second;
  T->ptr[2]=third;
  T->pos=pos;
  return T;
}

void display(struct node *T,int indent)  {//对抽象语法树的先根遍历
  int i=1;
  struct node *T0;
  if (T)
	{
	switch (T->kind) {
	case PROGRAM:
			if(T == NULL){
				printf("NOthing In this Program.");				
				break;			
			}
			if(T->ptr[1] == NULL){
				display(T->ptr[0],indent+3);
			}else{
				display(T->ptr[0],indent+3);
				display(T->ptr[1],indent+3);
			}
			break;
	case ASSIGN:      
			printf("%*c表达式语句：\n",indent,' ');
                        display(T->ptr[0],indent+3);
			display(T->ptr[1],indent+3);
                        break;
	case PRINT:
			printf("%*c输出语句：\n", indent, ' ');
			display(T->ptr[0],indent+3);
			display(T->ptr[1],indent+3);
                        break;
	case VARDECL:
			printf("%*c变量声明：\n", indent, ' ');
			display(T->ptr[0],indent+3);
			display(T->ptr[1],indent+3);
                        break;
	case CALL:
			printf("%*c函数调用：\n", indent, ' ');			
			if(T->ptr[1] == NULL){
				display(T->ptr[0],indent+3);
			}else{
				display(T->ptr[0],indent+3);
				display(T->ptr[1],indent+3);
			}
			break;
	case RETURN:
			printf("%*cRETURN语句：\n", indent, ' ');			
			if(T->ptr[1] == NULL){
				display(T->ptr[0],indent+3);
			}else{
				display(T->ptr[0],indent+3);
				display(T->ptr[1],indent+3);
			}
			break;
	case ARGUMENTS:
			printf("%*c函数形参表：\n", indent, ' ');
			display(T->ptr[0],indent+3);
			break;
	case ARGUMENT:
			printf("%*c函数形参：\n", indent, ' ');
			display(T->ptr[0],indent+3);
			display(T->ptr[1],indent+3);
	case FUNCDECL:
			printf("%*c函数定义：\n", indent, ' ');
			display(T->ptr[0],indent+3);
			display(T->ptr[1],indent+3);
			display(T->ptr[2],indent+3);
			break;
	case FUNCSIGN:
			printf("%*c函数签名：\n", indent, ' ');
			display(T->ptr[0],indent+3);
			display(T->ptr[1],indent+3);
			break;
	case FUNCRET:
			printf("%*c函数返回类型：\n", indent, ' ');
			display(T->ptr[0],indent+3);
			break;	
 	case FUNCBLOCK:
			printf("%*c函数体：\n", indent, ' ');
			display(T->ptr[0],indent+3);
			display(T->ptr[1],indent+3);
			break;
	case STMTS:
			printf("%*cSTATEMENTS：\n", indent, ' ');
			if(T->ptr[1] == NULL){
				display(T->ptr[0],indent+3);
			}else{
				display(T->ptr[0],indent+3);
				display(T->ptr[1],indent+3);
			}
			break;			
	case T_Int:
			printf("%*cINT类型\n",indent,' ');
			break;
	case T_Void:     
			printf("%*cVOID类型\n",indent,' ');
			break;
	case T_Identifier:	        
			printf("%*cID： %s\n",indent,' ',T->type_id);
                        break;
	case T_IntConstant:	        
			printf("%*cINT：%d\n",indent,' ',T->type_int);
                        break;
	case T_StringConstant:
			printf("%*cSTRING: %s\n", indent, ' ', T->type_string);
			break;
	case T_Return:
			printf("%*cRETURN:\n",indent,' ');
			break;
	case '+':
	case '-':
	case '*':
	case '/':
	case ',':
	case ';':
                    	printf("%*c%s\n",indent,' ',T->type_id);
                    	display(T->ptr[0],indent+3);
                    	display(T->ptr[1],indent+3);
                    	break;
	case UMINUS:    
			printf("%*c%s\n",indent,' ',T->type_id);
                    	display(T->ptr[0],indent+3);
                    	break;
         }
      }
}

