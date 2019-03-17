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
//----- ջ��˳��洢��ʾ -----
#define STACK_INIT_SIZE 10 // �洢�ռ�ĳ�ʼ������
#define STACKINCREMENT 5// �洢�ռ�ķ�������
typedef struct {
	ElemType *base;
	int  *top;
	int  stackSize;
	} SqStack;
	
// ����һ����ջ S
Status InitStack(SqStack &S){
	S.base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
		if(!S.base) exit (OVERFLOW);
	S.top = S.base;
	S.stackSize = STACK_INIT_SIZE;
	return OK;
}

//��ջ����
Status Push (SqStack &S, ElemType e) {
//�������д���룬�����㷨�����������μ��α��Ϳμ�����½�
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


//��ջ����
Status Pop (SqStack &S, ElemType &e) {
//���ڴ���д���룬�����㷨�����������μ��α��Ϳμ�����½�
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

// ��ջ S �Ƿ�Ϊ��ջ
Status StackEmpty(SqStack S){
	if (S.top == S.base) return  TRUE;
		else return  FALSE;
	}
	



//���˳��ջ����
void OutStack(SqStack S)
{  
	ElemType  e;
		if(TRUE == StackEmpty(S)){
			printf("����һ����ջ��");
			}
		else
			while(FALSE == StackEmpty(S)){
				Pop(S,e);
				printf("%6d", e);
			}
printf("\n");
}	

//�Զ��庯����
int In(char c){
	if(  c=='+' ||  c=='-' ||  c=='*' ||  c=='/'   ||   c=='('  ||  c==')'  ||  c=='#')
		return 1;
	else
		return 0;
}
//�������c��ֵ�������������1�����򷵻�0


//�ж�c1��c2����������������ȼ�������'<','>','='
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
							printf("������Ŵ���");	
							exit(0);
						}
					else
						a = '<';
					break;
					
		case ')':	if  (	c1=='#')	
						{
							printf("������Ŵ���");	
							exit(0);
						}
					else if(c1=='(')	
						a = '=';
						else a = '>';
			        break;
					
		case '#':   if  (	c1=='(')	
						{
							printf("������Ŵ���");	
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
        if (! In(ch)){Push(OPND,ch); ch = getchar(); }  // ch������������ջ
            else
                 switch (Precede(GetTop(OPTR),ch)) { //�Ƚ�����Ȩ
                         case '<' :    //��ǰ�ַ�chѹ��OPTRջ��������һ�ַ�ch
                                      Push(OPTR, ch);  ch = getchar();  break;
                         case '>' :    //����OPTRջ������������㣬������������ջ
                                      Pop(OPTR, theta);
                                      Pop(OPND, b);  Pop(OPND, a);
                                      Push(OPND, Operate(a, theta, b)); break;
                         case '=' :    //�����Ų�������һ�ַ�
                                      Pop(OPTR,x);    ch = getchar();   break;
                                  } // switch
     } // while
     OutStack(OPND); 
  return GetTop(OPND);} // EvaluateExpression
  
  



//������
main()
{ 	
	
	int cord; ElemType a;
	printf("��һ��ʹ�ñ����ʼ����\n");
	
		printf("\n ���˵� \n");
		printf(" 1 ��ʼ��˳��ջ ");
		printf(" 2 ����һ��Ԫ�� ");
		printf(" 3 ɾ��ջ��Ԫ�� ");
		printf(" 4 ������������ ");
		printf("\n-------------------------------------------------------------------\n");
		printf("����������ѡ��( 1, 2, 3, 4)");
		
		printf("\n");
	
			OperandType  EvaluateExpression();
			
	
	
}

