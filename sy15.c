#include<stdio.h>
#pragma pack(1)
struct S
{
	char a;
	double b;
};
#pragma pack()
int main()
{
	struct S s1;
	printf("%d\n",sizeof(s1)); 
	return 0;
}
