#include<stdio.h>
int main()
{
//	int i=123,n;
//	while(i /= 10)
//	{
//		n++;
//	 } 
//	 printf("%d",n);
//	int i,j,line;
//	scanf("%d",&line);
//	for(i=0;i<line;i++)
//	{
//		for(j=0;j<line-1-i;j++)
//		{
//			printf(" ");
//		}
//		for(j=0;j<2*i+1;j++)
//		{
//			printf("*");	
//		}
//		printf("\n");
//	}
//	for(i=line-2;i>=0;i--)
//	{
//		for(j=0;j<line-1-i;j++)
//		{
//			printf(" ");
//		}
//		for(j=0;j<2*i+1;j++)
//		{
//			printf("*");	
//		}
//		prints("\n");
//	}
//	
//	int sum=20,a=20,b,c;
//	while(a>=2)
//	{
//		 b=a/2;
//		 c=a%2;
//		 a=b+c;
//		sum +=b;
//	}
//	printf("%d",sum);
	int a,b,c,d,e;
	for(a=1;a<=5;a++)
	{
		for(b=1;b<=5;b++)
		{
			for(c=1;c<=5;c++)
			{
				for(d=1;d<=5;d++)
				{
					for(e=1;e<=5;e++)
					{
						if(((b==2)+(a==3)==1)&&
						   ((b==2)+(e==4)==1)&&
						   ((c==1)+(d==2)==1)&&
						   ((c==5)+(d==3)==1)&&
						   ((e==4)+(a==1)==1))
						   {
						   		if(a*b*c*d*e==120)
								   {
								   	printf("a=%d b=%d c=%d d=%d e=%d\n",a,b,c,d,e);
								   }
						   }
					}
				}
			}
		}
	}
	return 0;
}
