#include <stdio.h>
int main(void)
{
    int i, m, n;
    int repeat, ri;
    double sum;
    scanf("%d", &repeat);
    for(ri = 1; ri <= repeat; ri++){
	scanf("%d%d", &m, &n);
	sum=0;
	for(i=m;i<=n;i++)
	   {
	      sum=sum+1.0/i;
	   }
	printf("sum = %.3f\n", sum);
     }
    }