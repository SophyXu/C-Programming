#include "stdio.h"
#include "math.h"
int prime(int m);
int main(void)
{
    int count, i, m, n, sum;
    int repeat, ri;
    scanf("%d", &repeat);
    for(ri = 1; ri <= repeat; ri++){
        scanf("%d%d", &m, &n);
	sum=0;
	count=0;
	for(i=m;i<=n;i++)
	{
	   if (prime(i))
	   {
	      sum=sum+i;
	      count++;
	   }
	}
        printf("Count = %d, sum = %d\n", count, sum);
    }
}
int prime(int m)
{
    int i;
    for(i=2;i<=m-1;i++)
    {
       if (m%i==0)
       break;
    }
    return i==m;
}