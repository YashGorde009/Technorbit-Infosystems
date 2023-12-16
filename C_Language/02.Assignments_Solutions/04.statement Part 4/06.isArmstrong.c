// An Armstrong number is a number that is equal to the sum of it's own digits, each raised to the power of the number of digits in the number itself.
#include<stdio.h>
void main()
{
    int i, n, rem, temp, pow = 0, sum = 0, ans;
    printf("Check Whether Number Is Armstrong But Before...\n");
    printf("Enter Number : ");
    scanf("%d", &n);

    temp = n;

    while(temp > 0)
    {
        temp /= 10;
        pow++;
    }

    temp = n;

    while(temp > 0)
    {   
        ans = 1;
        rem = temp % 10;

        for(i = 1; i<=pow; i++)
        {
            ans *= rem;
        }
        sum += ans;
        temp /= 10;
    }

    if(sum == n)
    {
        printf("%d is Armstrong\n", n);
    }
}