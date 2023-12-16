// A Perfect Number is a number that is equal to the sum of its factors, excluding itself;
#include<stdio.h>
void main()
{
    int i, n, facSum = 0;
    printf("Check Whether Number Is Perfect But Before...\n");
    printf("Enter Number : ");
    scanf("%d", &n);

    for(i = 1; i <= n/2; i++)
    {
        if(n % i == 0)
        {
            facSum += i;
        }
    }
    if(n == facSum)
    {
        printf("%d is Perfect\n", n);
    }
    else
    {
        printf("%d is Not Perfect\n", n);
    }
}