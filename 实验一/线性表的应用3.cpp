#include <stdio.h>
#include <stdlib.h>

#define OK   1
#define ERROR   0
#define TRUE 1
#define FALSE 0
#define OVERFLOW   -2
typedef  int  ElemType;
typedef  int  Status;

//----- 顺序表的顺序存储表示 -----
#define LIST_INIT_SIZE 100 // 存储空间的初始分配量
#define LISTINCREMENT 10 // 存储空间的分配增量
typedef struct {
	ElemType	*elem;	// 存储空间的基址
	int length; // 表长
	int size;// 存储容量
	int increment; // 扩容时，增加的存储容量
} SqList;  //顺序表结构类型定义

// 构造一个空顺序表 
Status InitSqlist(SqList &L) {
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW);
	L.length = 0;
	L.size = LIST_INIT_SIZE;
	L.increment = LISTINCREMENT;
	return OK;
}

// 判顺序表是否为空表 
Status ListEmpty(SqList L) {
	if (L.length == 0) return TRUE;
	else return FALSE;
}


//输出顺序表函数
void OutList_Sq(SqList L)
{
	int i;
	ElemType  e;
	if (ListEmpty(L)) {
		printf("这是一个空表！");
	}
	else
	{
		printf("顺序表为：");
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
	printf("第一次使用必须初始化！\n");
	do {
		printf("\n 主菜单 \n");
		printf(" 1 初始化有序表 ");
		printf(" 2 结束程序运行 ");
		printf("\n-------------------------------------------------------------------\n");
		printf("请输入您的选择( 1, 2)");
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
