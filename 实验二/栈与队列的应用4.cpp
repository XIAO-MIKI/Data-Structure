#include <stdio.h>
#include <stdlib.h>
#define OK   1
#define ERROR   0
#define TRUE  1
#define FALSE  0
#define OVERFLOW   -2
typedef  int ElemType;
typedef  char Status;
typedef  char OperandType;
//----- 栈的顺序存储表示 -----
#define STACK_INIT_SIZE 10 // 存储空间的初始分配量
#define STACKINCREMENT 5// 存储空间的分配增量
typedef struct {
	ElemType *base;
	int  *top;
	int  stackSize;
	} SqStack;
	
// 构造一个空栈 S
Status InitStack(SqStack &S){
	S.base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
		if(!S.base) exit (OVERFLOW);
	S.top = S.base;
	S.stackSize = STACK_INIT_SIZE;
	return OK;
}

//入栈函数
Status Push (SqStack &S, ElemType e) {
//请在填此写代码，将该算法补充完整，参见课本和课件相关章节
	if(S.top-S.base >= S.stackSize){
		S.base = (ElemType * ) realloc (S.base,
					(S.stackSize+STACKINCREMENT) * sizeof (ElemType));
		if(!S.base) exit(OVERFLOW);
		S.top = S.base + S.stackSize;
		S.stackSize += STACKINCREMENT;
	}
		*S.top++ = e;
		return OK; 
}


//出栈函数
Status Pop (SqStack &S, ElemType &e) {
//请在此填写代码，将该算法补充完整，参见课本和课件相关章节
	if(S.top == S.base) return ERROR;
	e = *--S.top;
	return OK;
}


int Operate(char c1,char op,char c2){
	int a;
	switch(op){
		case '+':a=c1+c2;break;
		case '-':a=c1-c2;break;
		case '*':a=c1*c2;break;
		case '/':a=c1/c2;break;
	} 
	return a;
} 

char GetTop(SqStack &S){
	char e;
	if(S.top == S.base) return ERROR;
	e = *(S.top-1);
	return e;
}

// 判栈 S 是否为空栈
Status StackEmpty(SqStack S){
	if (S.top == S.base) return  TRUE;
		else return  FALSE;
	}
	



//输出顺序栈函数
void OutStack(SqStack S)
{  
	ElemType  e;
		if(TRUE == StackEmpty(S)){
			printf("这是一个空栈！");
			}
		else
			while(FALSE == StackEmpty(S)){
				Pop(S,e);
				printf("%6d", e);
			}
printf("\n");
}	

//自定义函数：
int In(char c){
	if(  c=='+' ||  c=='-' ||  c=='*' ||  c=='/'   ||   c=='('  ||  c==')'  ||  c=='#')
		return 1;
	else
		return 0;
}
//如果变量c的值是运算符，返回1，否则返回0


//判断c1和c2所储存运算符的优先级，返回'<','>','='
char Precede(char c1,char c2){
	char a;
	switch(c2){
		case '+':
					
		case '-':   if	(    c1=='('  ||  c1=='#'  )
						a = '<';
					else 
						a = '>';
					break;
		
		case '*':
			
		case '/':   if	(    c1=='+'  ||  c1=='-'  || c1=='('  ||  c1=='#'   )
						a = '<';
					else 
						a = '>';
					break;
		
		case '(':   if	(    c1==')')
						{
							printf("输入符号错误");	
							exit(0);
						}
					else
						a = '<';
					break;
					
		case ')':	if  (	c1=='#')	
						{
							printf("输入符号错误");	
							exit(0);
						}
					else if(c1=='(')	
						a = '=';
						else a = '>';
			        break;
					
		case '#':   if  (	c1=='(')	
						{
							printf("输入符号错误");	
							exit(0);
						}
					else if(c1=='#')	
						a = '=';
						else a = '>';
			        break;		
		}
		return a;
} 
	
OperandType  EvaluateExpression(){
	SqStack OPTR,OPND;
	char ch;
	ElemType theta,b,a,x;
	InitStack (OPTR);
	Push(OPTR,'#') ;
  	InitStack (OPND);
	ch = getchar( );
    while (ch!= '#' || GetTop(OPTR) != '#') {
        if (! In(ch)){Push(OPND,ch); ch = getchar(); }  // ch不是运算符则进栈
            else
                 switch (Precede(GetTop(OPTR),ch)) { //比较优先权
                         case '<' :    //当前字符ch压入OPTR栈，读入下一字符ch
                                      Push(OPTR, ch);  ch = getchar();  break;
                         case '>' :    //弹出OPTR栈顶的运算符运算，并将运算结果入栈
                                      Pop(OPTR, theta);
                                      Pop(OPND, b);  Pop(OPND, a);
                                      Push(OPND, Operate(a, theta, b)); break;
                         case '=' :    //脱括号并接收下一字符
                                      Pop(OPTR,x);    ch = getchar();   break;
                                  } // switch
     } // while
     OutStack(OPND); 
  return GetTop(OPND);} // EvaluateExpression
  
  



//主函数
main()
{ 	
	
	int cord; ElemType a;
	printf("第一次使用必须初始化！\n");
	
		printf("\n 主菜单 \n");
		printf(" 1 初始化顺序栈 ");
		printf(" 2 插入一个元素 ");
		printf(" 3 删除栈顶元素 ");
		printf(" 4 结束程序运行 ");
		printf("\n-------------------------------------------------------------------\n");
		printf("请输入您的选择( 1, 2, 3, 4)");
		
		printf("\n");
	
			OperandType  EvaluateExpression();
			
	
	
}

