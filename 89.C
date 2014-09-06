#include <stdio.h>
double fact(int n);
int main(void)
{
    int n;
    double factorial;
    double fact(int n);

    scanf ("%d", &n);
    factorial=fact(n);
    printf("%d! = %f\n", n, factorial);
}
double fact(int n)
{
   double y;
   int i;
   y=1;
   for(i=1;i<=n;i++)
   {
       y=y*i;
   }
   return y;
}
