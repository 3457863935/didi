#include<stdio.h>
#include<string.h>
int main()
{
//	int k;
//	char a[]="abcdef";
//	scanf("%d",&k);
//	char b[]="bcdefa";
//	int len=strlen(a);
//	for(k=1;k<=len;k++)
//	{
//		char a[]="abcdef";
//		left_move(a,k);
//		if(strcmp(a,b)==0)
//		{
//			printf("yes\n");
//			break;
//		}
//	}
//	printf("%s\n",a);	
	int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	int k=7,x=3,y=3,ret;
	ret=find(a,k,&x,&y);
	if(ret==1)
	{
		printf("找到了，坐标为：%d,%d",x,y); 
	}
	else
	{
		printf("不存在"); 
	}
	return 0;
}
int find(int a[3][3],int k,int *px,int *py)
{
	int x=0;
	int y=*py-1;
	while(x<=*px-1&&y>=0)
	{
		if(a[x][y]>k)
		{
			y--;
		}
		else if(a[x][y]<k)
		{
			x++;
		}
		else
		{
			*px=x;
			*py=y;
			return 1;
		}
	}
	return 0;
}
void left_move(char *a,int k)
{
	int i,j;
	char temp;
	int len=strlen(a);
	for(i=0;i<k;i++)
	{
		temp=*a;
		for(j=0;j<len-1;j++)
		{
			*(a+j)=*(a+j+1);
		}
		*(a+len-1)=temp;
	}
}
