#include <stdio.h>
int main(void)
{
    int sum, x, j;
    int repeat, ri;

    scanf("%d", &repeat);
    for(ri = 1; ri <= repeat; ri++)
    {
	sum=0;
	scanf("%d", &x);
	while(x>0)
	{
	if(x%2==0)
	sum=sum+x;
	scanf("%d", &x);
	}
	printf("The sum of the even numbers is %d.\n", sum);
    }
}