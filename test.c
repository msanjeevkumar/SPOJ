#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)&&n!=42)
		printf("%d\n",n);
	scanf("%d",&n);
	return 0;
}

