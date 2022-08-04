#include<stdio.h>
int main()
{
//	int a=1,b=2,c=3,d=4,e=5,i;
//	int *p[5]={&a,&b,&c,&d,&e};
//	for(i=0;i<5;i++)
//	{
//		printf("%d\n",*(p[i]));
//		printf("%p\n",p[i]);
//	}
	int a[2][3]={{1,2,3},{4,5,6}};
	int (*p)[2][3]=&a;
	int i,j;
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d ",(*p)[i][j]);
		}
		printf("\n");
	}
	return 0;
}
