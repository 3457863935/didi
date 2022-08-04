#include<stdio.h>

struct test
{
	int a;
	char b;
	short c;
	char d[2];
	short e[4];
}*p;
int main()
{
	p=(struct test*)0x100000;
	printf("%p\n",p);
	printf("%p\n",p+0x1);
	printf("%p\n",p+0x1);
	printf("%p\n",(unsigned long)p+0x1);
	printf("%p\n",(unsigned long)p);
	printf("%p\n",(unsigned int*)p+0x1);
	printf("%p\n",(unsigned int*)p);
	return 0;
}
