#include <stdio.h>
int even(int n);
int main(void)
{
    int n, sum;
    int ri, repeat;

    scanf("%d", &repeat);
    for(ri = 1; ri <= repeat; ri++)
    {
	scanf("%d",&n);
	sum=0;
	while(n>0)
	{
	    if(even(n)==0)
	    {
		sum=sum+n;
	    }
	    scanf("%d",&n);
	}
        printf("The sum of the odd numbers is %d.\n", sum);
   }
}
int even(int n)
{
   int y;
   if(n%2==0)
   y=1;
   else
   y=0;
   return y;
}

