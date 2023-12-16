#include<stdio.h>
void main() 
{
    int n, temp, rem, sum = 0;
    printf("Enter A Num & Get It's Digits Sum : ");
    scanf("%d", &n);

    temp = n;

    while(temp > 0)
    {
        rem = temp % 10;
        sum += rem;
        temp /= 10;
    }

    printf("The Sum of digits of %d is %d\n", n, sum);
}