// A prime number is a natural number greater than 1 that is divisible only by 1 and itself.(1 is not prime number)
#include<stdio.h>
void main() 
{
    int i, n, flag = 0;
    printf("Check Whether A Num Is Prime But Before ...  \n");
    printf("Enter Num : ");
    scanf("%d", &n);

    for(i = 2; i < n; i++)
    {
        if(n % i == 0)
        {
            printf("%d is Not a prime\n", n);
            flag = 1;
            break;
        }
    }

    if(flag == 0 && n > 1)
    {
        printf("%d is a Prime\n", n);
    }
    else if(n <= 1)
    {
        printf("%d is Neither Prime Nor Composite\n", n);
    }
}