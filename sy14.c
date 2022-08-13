#include<stdio.h>
#include<string.h>
int main()
{
	char a[10]="abcdefg";
	char b[]="hello";
//	strncpy(a,b,4);
	strncat(a,b,4);
	printf("%s\n",a);
}
