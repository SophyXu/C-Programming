#include "stdio.h"
#include "math.h"
int jiecheng(int i);
double funcos(double e, double x);
int main(void)
{
    int repeat, ri;
    double e, sum, x;

    scanf("%d", &repeat);
    for(ri = 1; ri <= repeat; ri++)
    {
        scanf("%le%le", &e, &x);
	sum=funcos(e,x);
        printf("sum = %f\n", sum);
    }
}
int jiecheng(int i)
{
   int m;
   int y;
   y=1;
   for(m=1;m<=i;m++)
   {
       y=y*m;
    }
    return y;
}
double funcos(double e, double x)
{
   double y, b;
   int i, j;
   y=0;
   i=0;
   b=x^i/jiecheng(i);
   while(b>=e)
   {
       y=y+j*x^i/jiecheng(i);
       i=i+2;
       j=-j;
       b=x^i/jiecheng(i);
   }
   y=y+b;
   return y;
}