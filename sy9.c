#include<stdio.h>
int main()
{
	int a=1;
	char* p=(char*)&a;
	if(*p==1)
	{
		printf("Ð¡¶Ë\n");
	}
	else
	{
		printf("´ó¶Ë\n");
	}
	return 0;	
} 
