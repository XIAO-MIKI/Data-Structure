#include <stdio.h>
#include <stdlib.h>

#define OK   1
#define ERROR   0
#define TRUE 1
#define FALSE 0
#define OVERFLOW   -2
typedef  int  ElemType;
typedef  int  Status;

//----- ˳����˳��洢��ʾ -----
#define LIST_INIT_SIZE 100 // �洢�ռ�ĳ�ʼ������
#define LISTINCREMENT 10 // �洢�ռ�ķ�������
typedef struct {
	ElemType	*elem;	// �洢�ռ�Ļ�ַ
	int length; // ��
	int size;// �洢����
	int increment; // ����ʱ�����ӵĴ洢����
} SqList;  //˳���ṹ���Ͷ���

// ����һ����˳��� 
Status InitSqlist(SqList &L) {
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW);
	L.length = 0;
	L.size = LIST_INIT_SIZE;
	L.increment = LISTINCREMENT;
	return OK;
}

// ��˳����Ƿ�Ϊ�ձ� 
Status ListEmpty(SqList L) {
	if (L.length == 0) return TRUE;
	else return FALSE;
}


//���˳�����
void OutList_Sq(SqList L)
{
	int i;
	ElemType  e;
	if (ListEmpty(L)) {
		printf("����һ���ձ�");
	}
	else
	{
		printf("˳���Ϊ��");
		for (i = 0; i < L.length; i++)
			printf("%6d", L.elem[i]);
	}
	printf("\n");
}

void MergeList(List La,List Lb,List Lc)
{
	InitList(Lc);
	int i = j = 1;
	int k = 0;
	La_len = ListLength(La);
	Lb_len = ListLength(Lb);
	while((i <= La_len) && (j <= Lb_len)){
		GetElem(La,i,ai);
		GetElem(Lb,j,bj);
		if	(ai <= bj){
			ListInsert(Lc,++k,ai);
			++i;
		}
		else		
	}
 } 


int main()
{
	SqList La,Lb,Lc;
	int cord, i; ElemType a;
	printf("��һ��ʹ�ñ����ʼ����\n");
	do {
		printf("\n ���˵� \n");
		printf(" 1 ��ʼ������� ");
		printf(" 2 ������������ ");
		printf("\n-------------------------------------------------------------------\n");
		printf("����������ѡ��( 1, 2)");
		scanf("%d", &cord);
		printf("\n");
		switch (cord) {
		case 1:
			InitSqlist(La);
			OutList_Sq(La);
			InitSqlist(Lb);
			OutList_Sq(Lb);
			break;
		case 2:
			exit(0);
		}
	} while (cord <= 2);
	return 0;
}
