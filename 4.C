#include <stdio.h>
int main(void)
{
    int i, m, sum;
    int repeat, ri;
    scanf("%d", &repeat);
    for(ri = 1; ri <= repeat; ri++){
	scanf("%d", &m);
	sum=0;
	for(i=m;i<=100;i++)
	{
	   sum=sum+i;
	}
        printf("sum = %d\n", sum);
    }
    }

