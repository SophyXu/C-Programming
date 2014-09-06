#include <stdio.h>
#include <math.h>
double fact(int n);
int main(void)
{
    int i;
    int repeat, ri;
    double item, s, x;
    scanf("%d", &repeat);
    for(ri = 1; ri <= repeat; ri++)
    {
        scanf("%lf", &x);
	s=0;
	i=1;
	if(x<0)
	x=-1*x;
	while(pow(x,i)/fact(i)>=0.00001)
	{
	   s=s+pow(x,i)/fact(i);
	   i++;
	}
      	printf("s = %.2f\n", s);
    }
}
double fact(int n)
{
    double y;
    int i;
    y=1;
    for(i=1;i<=n;i++)
    y=y*i;
    return y;
}