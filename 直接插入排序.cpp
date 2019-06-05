#include<stdio.h>
#define MAXSIZE 100 
typedef struct
{
	int r[MAXSIZE];
	int length;
}SqList;

void SelectSort(SqList &L)
{
	int i,j;
	int min,temp;
	for(i=0;i<L.length;i++)
	{
		min=i;
		for(j=i+1;j<L.length;j++)
			if(L.r[j]<L.r[min])
				min=j;
		if(i!=min)
		{
			temp=L.r[i];
			L.r[i]=L.r[min];
			L.r[min]=temp;
		}
	}
}
		
int main()
{
	SqList L;
	int i,m;
 	printf("Input length:");
		scanf("%d",&m);
	L.length=m;
	printf("Input %d numbers : \n",m);
	for(i = 0; i < m; i++)
	{
		scanf("%d", &L.r[i]);
	}

    printf("The elements before sort is : ");
		for(i = 0; i< m; i++)
		{
			printf("%d ", L.r[i]);
		}
	printf("\n");


    SelectSort(L);
    
    printf("The elements after sort is : ");
		for(i = 0; i < m; i++)
		{
			printf("%d ",L.r[i]);
		}
	printf("\n");

	}	

