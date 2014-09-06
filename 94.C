#include "stdio.h"
int countdigit(int number, int digit);
int main(void)
{
    int count, digit, in;
    int repeat, ri;

    scanf("%d",&repeat);
    for(ri = 1; ri <= repeat; ri++){
        scanf("%d%d", &in, &digit);
	count=countdigit(in,digit);
        printf("Number %d of digit %d: %d\n", in, digit, count);
    }
}
int countdigit(int number, int digit)
{
    int a, b, count;
    count=0;
    if (number<0)
    number=-1*number;
    a=number;
    b=number%10;
    while(a!=0)
    {
    if(b==digit)
    {
       count++;
    }
    a=number/10;
    b=a%10;
	}
    return count;
}
