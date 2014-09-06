#include <stdio.h>
int main(void)
{
    int decimal, octal, hexadecimal;
    int repeat, ri;

    scanf("%d", &repeat);
    for(ri = 1; ri <= repeat; ri++){
        scanf("%d%o%x", &decimal, &octal, &hexadecimal);
/*---------*/