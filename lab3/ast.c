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
	case EXP_STMT:      
			printf("%*c表达式语句：\n",indent,' ');
                        display(T->ptr[0],indent+3);
			display(T->ptr[1],indent+3);
                        break;
	case T_Identifier:	        
			printf("%*cID： %s\n",indent,' ',T->type_id);
                        break;
	case T_IntConstant:	        
			printf("%*cINT：%d\n",indent,' ',T->type_int);
                        break;
	case '+':
	case '-':
	case '*':
	case '/':
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

