#include <stdio.h>
int main(void)
{
    int time1, time2, hour, minutes,a,b,c,d;

   scanf("%d%d", &time1, &time2);
   a=time1/100;
   b=time1%100;
   c=time2/100;
   d=time2%100;
   if (b<d)
   {
      minutes=d-b;
      hour=c-a;
   }
   else
   {
      minutes=60+d-b;
      hour=c-a-1;
   }
   printf("The train journey time is %d hours %d minutes.\n", hour, minutes);
}