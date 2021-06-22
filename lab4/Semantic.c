#include "def.h"
#include "MyFunction.h"

char *newAlias() {
    static int no=1;
    char s[10];
    itoa(no++,s);
    return strcat0("v",s);
}

char *newLabel() {
    static int no=1;
    char s[10];
    itoa(no++,s);
    return strcat0("label",s);
}

char *newTemp(){
    static int no=1;
    char s[10];
    itoa(no++,s);
    return strcat0("temp",s);
}


void semantic_error(int line,char *msg1,char *msg2){
    //这里可以只收集错误信息，最后一次显示
    printf("在%d行,%s %s\n",line,msg1,msg2);
}

//down there to do

struct codenode *genIR(int op,struct opn opn1,struct opn opn2,struct opn result){
    struct codenode *h=(struct codenode *)malloc(sizeof(struct codenode));
    h->op=op;
    h->opn1=opn1;
    h->opn2=opn2;
    h->result=result;
    h->next=h->prior=h;
    return h;
}

//生成一条标号语句，返回头指针
struct codenode *genLabel(char *label){
    struct codenode *h=(struct codenode *)malloc(sizeof(struct codenode));
    h->op=LABEL;
    strcpy(h->result.id,label);
    h->next=h->prior=h;
    return h;
}

//生成GOTO语句，返回头指针
struct codenode *genGoto(char *label){
    struct codenode *h=(struct codenode *)malloc(sizeof(struct codenode));
    h->op=GOTO;
    strcpy(h->result.id,label);
    h->next=h->prior=h;
    return h;
}

//合并多个中间代码的双向循环链表，首尾相连
struct codenode *merge(int num,...){
    struct codenode *h1,*h2,*p,*t1,*t2;
    va_list ap;
    va_start(ap,num);
    h1=va_arg(ap,struct codenode *);
    while (--num>0) {
        h2=va_arg(ap,struct codenode *);
        if (h1==NULL) h1=h2;
        else if (h2){
            t1=h1->prior;
            t2=h2->prior;
            t1->next=h2;
            t2->next=h1;
            h1->prior=t2;
            h2->prior=t1;
            }
        }
    va_end(ap);
    return h1;
}

//输出中间代码
void prnIR(struct codenode *head){
    char opnstr1[32],opnstr2[32],resultstr[32];
    struct codenode *h=head;
    do {
        if (h->opn1.kind==T_IntConstant)
             sprintf(opnstr1,"#%d",h->opn1.const_int);
        if (h->opn1.kind==T_Identifier)
             sprintf(opnstr1,"%s",h->opn1.id);
        if (h->opn2.kind==T_IntConstant)
             sprintf(opnstr2,"#%d",h->opn2.const_int);
        if (h->opn2.kind==T_Identifier)
             sprintf(opnstr2,"%s",h->opn2.id);
        sprintf(resultstr,"%s",h->result.id);
        switch (h->op) {
            //to do assign
	    //case ASSIGNOP:  printf("  %s := %s\n",resultstr,opnstr1);
            //                break;
            case '+':
            case '-':
            case '*':
            case '/': printf("  %s := %s %c %s\n",resultstr,opnstr1, \
                      h->op=='+'?'+':h->op=='-'?'-':h->op=='*'?'*':'\\',opnstr2);
                      break;
            case FUNCTION: printf("\nFUNCTION %s :\n",h->result.id);
                           break;
            case ARGUMENT:    printf("  PARAM %s\n",h->result.id);
                           break;
            case LABEL:    printf("LABEL %s :\n",h->result.id);
                           break;
            case GOTO:     printf("  GOTO %s\n",h->result.id);
                           break;
            case T_Le:      printf("  IF %s <= %s GOTO %s\n",opnstr1,opnstr2,resultstr);
                           break;
            case '<':      printf("  IF %s < %s GOTO %s\n",opnstr1,opnstr2,resultstr);
                           break;
            case T_Ge:      printf("  IF %s >= %s GOTO %s\n",opnstr1,opnstr2,resultstr);
                           break;
            case '>':      printf("  IF %s > %s GOTO %s\n",opnstr1,opnstr2,resultstr);
                           break;
            case T_Eq:       printf("  IF %s == %s GOTO %s\n",opnstr1,opnstr2,resultstr);
                           break;
            case T_Ne:      printf("  IF %s != %s GOTO %s\n",opnstr1,opnstr2,resultstr);
                           break;
            case ARG:      printf("  ARG %s\n",h->result.id);
                           break;
            case CALL:     if (!strcmp(opnstr1,"write"))
                                printf("  CALL  %s\n", opnstr1);
                            else
                                printf("  %s := CALL %s\n",resultstr, opnstr1);
                           break;
            case RETURN:   if (h->result.kind)
                                printf("  RETURN %s\n",resultstr);
                           else
                                printf("  RETURN\n");
                           break;

        }
    h=h->next;
    } while (h!=head);
}



//up there to do

void prn_symbol(){ //显示符号表
    int i=0;
    printf("%6s %6s %6s %4s %6s\n","变量名","别 名","层 号","标记","偏移量");
    for(i=0;i<symbolTable.index;i++)
        printf("%6s %6s %6d %4c %6d\n",symbolTable.symbols[i].name,\
                symbolTable.symbols[i].alias,symbolTable.symbols[i].level,\
                symbolTable.symbols[i].flag,symbolTable.symbols[i].offset);
}

int searchSymbolTable(char *name) {
    int i,flag=0;
    for(i=symbolTable.index-1;i>=0;i--){
        if (symbolTable.symbols[i].level==0)
            flag=1;
        if (flag && symbolTable.symbols[i].level==1)
            continue;   //跳过前面函数的形式参数表项
        if (!strcmp(symbolTable.symbols[i].name, name))  return i;
    }
    return -1;
}

int fillSymbolTable(char *name,char *alias,int level,char flag,int offset) {
    //首先根据name查符号表，不能重复定义 重复定义返回-1
    int i;
    /*符号查重，考虑外部变量声明前有函数定义，
    其形参名还在符号表中，这时的外部变量与前函数的形参重名是允许的*/
    for(i=symbolTable.index-1; i>=0 && (symbolTable.symbols[i].level==level||level==0); i--) {
        if (level==0 && symbolTable.symbols[i].level==1) continue;  //外部变量和形参不必比较重名
        if (!strcmp(symbolTable.symbols[i].name, name))  return -1;
        }
    //填写符号表内容
    strcpy(symbolTable.symbols[symbolTable.index].name,name);
    strcpy(symbolTable.symbols[symbolTable.index].alias,alias);
    symbolTable.symbols[symbolTable.index].level=level;
    symbolTable.symbols[symbolTable.index].flag=flag;
    symbolTable.symbols[symbolTable.index].offset=offset;
    return symbolTable.index++; //返回的是符号在符号表中的位置序号，中间代码生成时可用序号取到符号别名
}

//填写临时变量到符号表，返回临时变量在符号表中的位置
int fill_Temp(char *name,int level,char flag,int offset) {
    strcpy(symbolTable.symbols[symbolTable.index].name,"");
    strcpy(symbolTable.symbols[symbolTable.index].alias,name);
    symbolTable.symbols[symbolTable.index].level=level;
    symbolTable.symbols[symbolTable.index].flag=flag;
    symbolTable.symbols[symbolTable.index].offset=offset;
    return symbolTable.index++; //返回的是临时变量在符号表中的位置序号
}

void ext_var_list(node *T){  //处理变量列表
    int rtn,num=1;
    switch (T->kind){
        case ',':
                T->ptr[0]->offset=T->offset;          //外部变量的偏移量向下传递
                T->ptr[1]->offset=T->offset+T->width; //外部变量的偏移量向下传递
                ext_var_list(T->ptr[0]);
                ext_var_list(T->ptr[1]);
                T->num=T->ptr[1]->num+1;
                break;
        case T_Identifier:
            rtn=fillSymbolTable(T->type_id,newAlias(),LEV,'V',T->offset);  //最后一个变量名
            if (rtn==-1)
                semantic_error(T->pos,T->type_id, "变量重复定义");
            else T->place=rtn;
            T->num=1;
            break;
        }
    }

int  match_param(int i,node *T){
    int j,num=symbolTable.symbols[i].paramnum;
    int pos=T->pos;
    T=T->ptr[1];
    if (num==0 && T==NULL) return 1;
    for (j=1;j<=num;j++) {
        if (!T){
            semantic_error(pos,"", "函数调用参数太少!");
            return 0;
            }
        T=T->ptr[1];
    }
    if (T){ //num个参数已经匹配完，还有实参表达式
        semantic_error(pos,"", "函数调用参数太多!");
        return 0;
        }
    return 1;
}

void boolExp(node *T){  //布尔表达式，参考文献[2]p84的思想
  struct opn opn1,opn2,result;
  int op;
  int rtn;
  if (T)
	{
	switch (T->kind) {
	case T_Ge:
	case T_Le:
	case T_Eq:
	case T_Ne:
	case '>':
        case '<':
                    T->ptr[0]->offset=T->ptr[1]->offset=T->offset;
                    Exp(T->ptr[0]);
                    T->width=T->ptr[0]->width;
                    Exp(T->ptr[1]);
                    if (T->width<T->ptr[1]->width) T->width=T->ptr[1]->width;
                    opn1.kind=T_Identifier; strcpy(opn1.id,symbolTable.symbols[T->ptr[0]->place].alias);
                    opn1.offset=symbolTable.symbols[T->ptr[0]->place].offset;
                    opn2.kind=T_Identifier; strcpy(opn2.id,symbolTable.symbols[T->ptr[1]->place].alias);
                    opn2.offset=symbolTable.symbols[T->ptr[1]->place].offset;
                    result.kind=T_Identifier; strcpy(result.id,T->Etrue);
                    if (strcmp(T->type_id, "<")==0)
                            op='<';
                    else if (strcmp(T->type_id,"<=")==0)
                            op=T_Le;
                    else if (strcmp(T->type_id,">")==0)
                            op='>';
                    else if (strcmp(T->type_id,">=")==0)
                            op=T_Ge;
                    else if (strcmp(T->type_id,"==")==0)
                            op=T_Eq;
                    else if (strcmp(T->type_id,"!=")==0)
                            op=T_Ne;
                    T->code=genIR(op,opn1,opn2,result);
                    T->code=merge(4,T->ptr[0]->code,T->ptr[1]->code,T->code,genGoto(T->Efalse));
                    break;
        case T_And: 
        case T_Or:
                    if (T->kind==T_And) {
                        strcpy(T->ptr[0]->Etrue,newLabel());
                        strcpy(T->ptr[0]->Efalse,T->Efalse);
                        }
                    else {
                        strcpy(T->ptr[0]->Etrue,T->Etrue);
                        strcpy(T->ptr[0]->Efalse,newLabel());
                        }
                    strcpy(T->ptr[1]->Etrue,T->Etrue);
                    strcpy(T->ptr[1]->Efalse,T->Efalse);
                    T->ptr[0]->offset=T->ptr[1]->offset=T->offset;
                    boolExp(T->ptr[0]);
                    T->width=T->ptr[0]->width;
                    boolExp(T->ptr[1]);
                    if (T->width<T->ptr[1]->width) T->width=T->ptr[1]->width;
                    if (T->kind==T_And)
                        T->code=merge(3,T->ptr[0]->code,genLabel(T->ptr[0]->Etrue),T->ptr[1]->code);
                    else
                        T->code=merge(3,T->ptr[0]->code,genLabel(T->ptr[0]->Efalse),T->ptr[1]->code);
                    break;
        case NOT:   strcpy(T->ptr[0]->Etrue,T->Efalse);
                    strcpy(T->ptr[0]->Efalse,T->Etrue);
                    boolExp(T->ptr[0]);
                    T->code=T->ptr[0]->code;
                    break;
        }
	}
}


void Exp(node *T)
{//处理基本表达式，参考文献[2]p82的思想
  int rtn,num,width;
  node *T0;
  struct opn opn1,opn2,result;
  if (T)
	{
	switch (T->kind) {
	case T_Identifier:    //查符号表，获得符号表中的位置，类型送type
                rtn=searchSymbolTable(T->type_id);
                if (rtn==-1)
                    semantic_error(T->pos,T->type_id, "变量未定义");
                if (symbolTable.symbols[rtn].flag=='F')
                    semantic_error(T->pos,T->type_id, "是函数名，类型不匹配");
                else {
                    T->place=rtn;       //结点保存变量在符号表中的位置
                    T->code=NULL;       //标识符不需要生成TAC
                    T->offset=symbolTable.symbols[rtn].offset;
                    T->width=0;   //未再使用新单元
                    }
                break;
    	case T_IntConstant:   T->place=fill_Temp(newTemp(),LEV,'T',T->offset); //为整常量生成一个临时变量
                opn1.kind=T_IntConstant;opn1.const_int=T->type_int;
                result.kind=T_Identifier; strcpy(result.id,symbolTable.symbols[T->place].alias);
                result.offset=symbolTable.symbols[T->place].offset;
                T->code=genIR(ASSIGN,opn1,opn2,result);
                T->width=4;
                break;
	case T_And:   //按算术表达式方式计算布尔值，未写完
	case T_Or:    //按算术表达式方式计算布尔值，未写完
	case T_Ge:
	case T_Le:
	case T_Eq:
	case T_Ne:
	case '>':
        case '<':
                T->ptr[0]->offset=T->ptr[1]->offset=T->offset;
                Exp(T->ptr[0]);
                Exp(T->ptr[1]);
                break;
	case '+':
	case '-':
	case '*':
	case '/':   T->ptr[0]->offset=T->offset;
                Exp(T->ptr[0]);
                T->ptr[1]->offset=T->offset+T->ptr[0]->width;
                Exp(T->ptr[1]);
                //判断T->ptr[0]，T->ptr[1]类型是否正确，可能根据运算符生成不同形式的代码，给T的type赋值
                //下面的类型属性计算，没有考虑错误处理情况
                opn1.kind=T_Identifier; strcpy(opn1.id,symbolTable.symbols[T->ptr[0]->place].alias);
                opn2.kind=T_Identifier; strcpy(opn2.id,symbolTable.symbols[T->ptr[1]->place].alias);
                result.kind=T_Identifier; strcpy(result.id,symbolTable.symbols[T->place].alias);
                T->code=merge(3,T->ptr[0]->code,T->ptr[1]->code,genIR(T->kind,opn1,opn2,result));
                break;
	case NOT:   //未写完整
                break;
	case UMINUS://未写完整
                break;
	}
  }
}


void semantic_Analysis(node *T)
{//对抽象语法树的先根遍历,按display的控制结构修改完成符号表管理和语义检查和TAC生成（语句部分）
  int rtn,num,width;
  struct ASTNode *T0;
  struct opn opn1,opn2,result;
  if (T)
	{
	switch (T->kind) {
	case FUNCDECL:      //填写函数定义信息到符号表
            T->width=0;     //函数的宽度设置为0，不会对外部变量的地址分配产生影响
            T->offset=DX;   //设置局部变量在活动记录中的偏移量初值
            semantic_Analysis(T->ptr[1]); //处理函数名和参数结点部分，这里不考虑用寄存器传递参数
            T->offset+=T->ptr[1]->width;   //用形参单元宽度修改函数局部变量的起始偏移量
            T->ptr[2]->offset=T->offset;
            strcpy(T->ptr[2]->Snext,newLabel());  //函数体语句执行结束后的位置属性
            semantic_Analysis(T->ptr[2]);         //处理函数体结点
            //计算活动记录大小,这里offset属性存放的是活动记录大小，不是偏移
            symbolTable.symbols[T->ptr[1]->place].offset=T->offset+T->ptr[2]->width;
            T->code=merge(3,T->ptr[1]->code,T->ptr[2]->code,genLabel(T->ptr[2]->Snext));          //函数体的代码作为函数的代码
            break;
	case FUNCSIGN:      //根据返回类型，函数名填写符号表
            rtn=fillSymbolTable(T->type_id,newAlias(),LEV,'F',0);//函数不在数据区中分配单元，偏移量为0
            if (rtn==-1){
                semantic_error(T->pos,T->type_id, "函数重复定义");
                break;
                }
            else T->place=rtn;
            result.kind=T_Identifier;   strcpy(result.id,T->type_id);
            result.offset=rtn;
            T->offset=DX;   //设置形式参数在活动记录中的偏移量初值
            if (T->ptr[1]) { //判断是否有参数
                T->ptr[1]->offset=T->offset;
                semantic_Analysis(T->ptr[1]);  //处理函数参数列表
                T->width=T->ptr[1]->width;
                symbolTable.symbols[rtn].paramnum=T->ptr[1]->num;
                T->code=merge(2,T->code,T->ptr[1]->code);  //连接函数名和参数代码序列
                }
            else symbolTable.symbols[rtn].paramnum=0,T->width=0;
            break;
	case ARGUMENTS:    //处理函数形式参数列表
            T=T->ptr[0];
	    T->ptr[0]->offset=T->offset;
            semantic_Analysis(T->ptr[0]);
            if (T->ptr[1]){
                T->ptr[1]->offset=T->offset+T->ptr[0]->width;
                semantic_Analysis(T->ptr[1]);
                T->num=T->ptr[0]->num+T->ptr[1]->num;        //统计参数个数
                T->width=T->ptr[0]->width+T->ptr[1]->width;  //累加参数单元宽度
                T->code=merge(2,T->ptr[0]->code,T->ptr[1]->code);  //连接参数代码
                }
            else {
                T->num=T->ptr[0]->num;
                T->width=T->ptr[0]->width;
                T->code=T->ptr[0]->code;
                }
            break;
	case  ARGUMENT:
            rtn=fillSymbolTable(T->ptr[1]->type_id,newAlias(),1,'P',T->offset);
            if (rtn==-1)
                semantic_error(T->ptr[1]->pos,T->ptr[1]->type_id, "参数名重复定义");
            else T->ptr[1]->place=rtn;
            T->num=1;       //参数个数计算的初始值
            T->width=4;  //参数宽度
            result.kind=T_Identifier;   strcpy(result.id, symbolTable.symbols[rtn].alias);
            result.offset=T->offset;
            T->code=genIR(ARGUMENT,opn1,opn2,result);     //生成：FUNCTION 函数名
            break;
	case STMTSBLOCK:
            LEV++;
            //设置层号加1，并且保存该层局部变量在符号表中的起始位置在symbol_scope_TX
            symbol_scope_TX.TX[symbol_scope_TX.top++]=symbolTable.index;
            T->width=0;
            T->code=NULL;
            if (T->ptr[0]){
                T->ptr[0]->offset=T->offset+T->width;
                strcpy(T->ptr[0]->Snext,T->Snext);  //S.next属性向下传递
                semantic_Analysis(T->ptr[0]);       //处理复合语句的语句序列
                T->width+=T->ptr[0]->width;
                T->code=merge(2,T->code,T->ptr[0]->code);
                }
             LEV--;    //出复合语句，层号减1
             symbolTable.index=symbol_scope_TX.TX[--symbol_scope_TX.top]; //删除该作用域中的符号
             break;
    	case ';':
            T->code=NULL;
            if (T->ptr[0]){
                T->ptr[0]->offset=T->offset;
                semantic_Analysis(T->ptr[0]);   //处理一个局部变量定义
                T->code=T->ptr[0]->code;
                T->width=T->ptr[0]->width;
                }
            if (T->ptr[1]) {
                T->ptr[1]->offset=T->offset+T->ptr[0]->width;
                semantic_Analysis(T->ptr[1]);   //处理剩下的局部变量定义
                T->code=merge(2,T->code,T->ptr[1]->code);
                T->width+=T->ptr[1]->width;
                }
                break;
	//todo	stmts
	case STMTS:
                if (!T->ptr[0]) { T->code=NULL; T->width=0; break;}   //空语句序列
                if (T->ptr[1]) //2条以上语句连接，生成新标号作为第一条语句结束后到达的位置
                    strcpy(T->ptr[0]->Snext,newLabel());
                else     //语句序列仅有一条语句，S.next属性向下传递
                    strcpy(T->ptr[0]->Snext,T->Snext);
                T->ptr[0]->offset=T->offset;
                semantic_Analysis(T->ptr[0]);
                T->code=T->ptr[0]->code;
                T->width=T->ptr[0]->width;
                if (T->ptr[1]){     //2条以上语句连接,S.next属性向下传递
                    strcpy(T->ptr[1]->Snext,T->Snext);
                    T->ptr[1]->offset=T->offset;  //顺序结构共享单元方式
//                  T->ptr[1]->offset=T->offset+T->ptr[0]->width; //顺序结构顺序分配单元方式
                    semantic_Analysis(T->ptr[1]);
                    //序列中第1条为表达式语句，返回语句，复合语句时，第2条前不需要标号
                    if (T->ptr[0]->kind==RETURN)
                        T->code=merge(2,T->code,T->ptr[1]->code);
                    else
                        T->code=merge(3,T->code,genLabel(T->ptr[0]->Snext),T->ptr[1]->code);
                    if (T->ptr[1]->width>T->width) T->width=T->ptr[1]->width; //顺序结构共享单元方式
//                        T->width+=T->ptr[1]->width;//顺序结构顺序分配单元方式
                    }
                break;
	case IFSTMT:
                strcpy(T->ptr[0]->ptr[0]->ptr[0]->Etrue,newLabel());  //设置条件语句真假转移位置
                strcpy(T->ptr[0]->ptr[0]->ptr[0]->Efalse,T->Snext);
                T->ptr[0]->ptr[0]->ptr[0]->offset=T->ptr[1]->ptr[0]->offset=T->offset;
                boolExp(T->ptr[0]->ptr[0]->ptr[0]);
                T->width=T->ptr[0]->ptr[0]->ptr[0]->width;
                strcpy(T->ptr[1]->ptr[0]->Snext,T->Snext);
                semantic_Analysis(T->ptr[1]->ptr[0]);      //if子句
                if (T->width<T->ptr[1]->ptr[0]->width) T->width=T->ptr[1]->ptr[0]->width;
                T->code=merge(3,T->ptr[0]->ptr[0]->ptr[0]->code, genLabel(T->ptr[0]->ptr[0]->ptr[0]->Etrue),T->ptr[1]->ptr[0]->code);
                break;  //控制语句都还没有处理offset和width属性
	case IFELSESTMT:
                strcpy(T->ptr[0]->ptr[0]->ptr[0]->Etrue,newLabel());  //设置条件语句真假转移位置
                strcpy(T->ptr[0]->ptr[0]->ptr[0]->Efalse,newLabel());
                T->ptr[0]->ptr[0]->ptr[0]->offset=T->ptr[1]->ptr[0]->offset=T->ptr[2]->ptr[0]->offset=T->offset;
                boolExp(T->ptr[0]->ptr[0]->ptr[0]);      //条件，要单独按短路代码处理
                T->width=T->ptr[0]->ptr[0]->ptr[0]->width;
                strcpy(T->ptr[1]->ptr[0]->Snext,T->Snext);
                semantic_Analysis(T->ptr[1]->ptr[0]);      //if子句
                if (T->width<T->ptr[1]->ptr[0]->width) T->width=T->ptr[1]->ptr[0]->width;
                strcpy(T->ptr[2]->ptr[0]->Snext,T->Snext);
                semantic_Analysis(T->ptr[2]->ptr[0]);      //else子句
                if (T->width<T->ptr[2]->ptr[0]->width) T->width=T->ptr[2]->ptr[0]->width;
                T->code=merge(6,T->ptr[0]->ptr[0]->ptr[0]->code,genLabel(T->ptr[0]->ptr[0]->ptr[0]->Etrue),T->ptr[1]->ptr[0]->code,\
                              genGoto(T->Snext),genLabel(T->ptr[0]->ptr[0]->ptr[0]->Efalse),T->ptr[2]->ptr[0]->code);
                break;
	case WHILESTMT: strcpy(T->ptr[0]->ptr[0]->ptr[0]->Etrue,newLabel());  //子结点继承属性的计算
                strcpy(T->ptr[0]->ptr[0]->ptr[0]->Efalse,T->Snext);
                T->ptr[0]->ptr[0]->ptr[0]->offset=T->ptr[1]->ptr[0]->offset=T->offset;
                boolExp(T->ptr[0]->ptr[0]->ptr[0]);      //循环条件，要单独按短路代码处理
                T->width=T->ptr[0]->ptr[0]->ptr[0]->width;
                strcpy(T->ptr[1]->ptr[0]->Snext,newLabel());
                semantic_Analysis(T->ptr[1]->ptr[0]);      //循环体
                if (T->width<T->ptr[1]->ptr[0]->width) T->width=T->ptr[1]->ptr[0]->width;
                T->code=merge(5,genLabel(T->ptr[1]->ptr[0]->Snext),T->ptr[0]->ptr[0]->ptr[0]->code, \
                genLabel(T->ptr[0]->ptr[0]->ptr[0]->Etrue),T->ptr[1]->ptr[0]->code,genGoto(T->ptr[1]->ptr[0]->Snext));
                break;
	case RETURN:if (T->ptr[1]){
                    T->ptr[1]->offset=T->offset;
                    Exp(T->ptr[1]);

				 /*需要判断返回值类型是否匹配*/

                    T->width=T->ptr[1]->width;
                    result.kind=T_Identifier; strcpy(result.id,symbolTable.symbols[T->ptr[1]->place].alias);
                    result.offset=symbolTable.symbols[T->ptr[1]->place].offset;
                    T->code=merge(2,T->ptr[1]->code,genIR(RETURN,opn1,opn2,result));
                    }
                else{
                    T->width=0;
                    result.kind=0;
                    T->code=genIR(RETURN,opn1,opn2,result);
                    }
                break;
	case T_Identifier:
    	case T_IntConstant:
	case T_And:
	case T_Or:
	case T_Ge:
	case T_Le:
	case T_Eq:
	case T_Ne:
	case '>':
        case '<':
	case '+':
	case '-':
	case '*':
	case '/':
	case NOT:
	case UMINUS:
	//to do assign and func call in stmts
                    Exp(T);          //处理基本表达式
                    break;
    }
    }
}


void semantic_Analysis0(node *T) {
    symbolTable.index=0;
    fillSymbolTable("read","",0,'F',4);
    symbolTable.symbols[0].paramnum=0;//read的形参个数
    fillSymbolTable("write","",0,'F',4);
    symbolTable.symbols[1].paramnum=1;
    fillSymbolTable("x","",1,'P',12);
    symbol_scope_TX.TX[0]=0;  //外部变量在符号表中的起始序号为0
    symbol_scope_TX.top=1;
    T->offset=0;              //外部变量在数据区的偏移量
    semantic_Analysis(T);
    prnIR(T->code);
} 

