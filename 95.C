#include "stdio.h"
int is(int number);
int main(void)
{
    int i, m, n;
    int repeat, ri;

    scanf("%d", &repeat);
    for(ri = 1; ri <= repeat; ri++)
    {
	scanf("%d%d", &m, &n);
	printf("result:\n");
	for(i=m;i<=n;i++)
	{
	    if(is(i))
	    {
	       printf("%d\n", i);
	    }
	}
    }
}
int is(int number)
{
   int a,b,c,d,y;
   a=number%10;
   b=number/10%10;
   c=number/10/10%10;
   d=number/10/10/10%10;
   if(a*a*a+b*b*b+c*c*c+d*d*d==number)
   y=1;
   else
   y=0;
   return y;
}

