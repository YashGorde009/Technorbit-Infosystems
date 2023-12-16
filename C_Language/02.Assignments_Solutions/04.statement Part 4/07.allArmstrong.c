// An Armstrong number is a number that is equal to the sum of it's own digits, each raised to the power of the number of digits in the number itself.
#include<stdio.h>
void main()
{
    int i, j, rgn, rem, temp, pow, sum, ans;
    printf("Enter Range & Get All Armstrong Numbers Till That Range But Before...\n");
    printf("Enter Range : ");
    scanf("%d", &rgn);

    printf("Armstrong Numbers (1 - %d) : ", rgn);
    for(i = 1; i <= rgn; i++)
    {
    temp = i;
    pow = 0;
    sum = 0;
    while(temp > 0)
    {
        temp /= 10;
        pow++;
    }

    temp = i;

    while(temp > 0)
    {   
        ans = 1;
        rem = temp % 10;

        for(j = 1; j<=pow; j++)
        {
            ans *= rem;
        }
        sum += ans;
        temp /= 10;
    }
    if(sum == i)
    {
        printf("%d ", i);
    }
    }
}