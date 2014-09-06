#include <stdio.h>
int main(void)
{
    int repeat, ri;
    int minutes, seconds;
    double cost, mile;

    scanf("%d", &repeat);
    for(ri = 1; ri <= repeat; ri++){
        scanf("%lf%d%d", &mile, &minutes, &seconds);
/*---------*/
	printf("cost = %.0f\n", cost);
    }
}