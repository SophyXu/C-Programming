#include <stdio.h>
#include <math.h>
int main(void)
{
    int i, n;
    double mypow;

    scanf("%d", &n);
    for(i=0;i<=n;i++)
    {
       mypow=pow(3,i);
       printf("pow(3,%d) = %.0f\n",i,mypow);
    }
}