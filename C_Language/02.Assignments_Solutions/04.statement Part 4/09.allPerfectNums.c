// A Perfect Number is a number that is equal to the sum of its factors, excluding itself;
#include<stdio.h>
void main()
{
    int i, j, rgn, facSum;
    printf("Enter Range & Get All Perfect Numbers Till That Range But Before...\n");
    printf("Enter Range : ");
    scanf("%d", &rgn);

    printf("Perfect Number (1 - %d) : ", rgn);
    for(i = 1; i <= rgn; i++)
    {
    facSum = 0;
    for(j = 1; j <= i/2; j++)
    {
        if(i % j == 0)
        {
            facSum += j;
        }
    }
    if(i == facSum)
    {
        printf("%d ", i);
    }
    }
}