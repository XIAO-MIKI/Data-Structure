#include <stdio.h>
#define MAXSIZE 100 
typedef struct
{
	int r[MAXSIZE];
	int length;
}SqList;

void InsertSort(SqList &L)
{	
	int i,j; 
	for(i=2;i<=L.length;++i)
		if(L.r[i]<L.r[i-1])
			{
				L.r[0]=L.r[i];
				for(j=i-1;L.r[j]>L.r[0];--j)
				L.r[j+1]=L.r[j];
				L.r[j+1]=L.r[0];
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
	for(i = 1; i <= m; i++)
		{
		scanf("%d", &L.r[i]);
		}

    printf("The elements before sort is : ");
	for(i = 1; i<= m; i++)
		{
			printf("%d ", L.r[i]);
		}
	printf("\n");


    InsertSort(L);
    
    printf("The elements after sort is : ");
	for(i = 1; i <= m; i++)
		{
			printf("%d ",L.r[i]);
		}
	printf("\n");

	}	

