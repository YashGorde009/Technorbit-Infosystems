#include<stdio.h>
void main() 
{
    int n, temp, rem;
    printf("Enter A Num & Get It's 1st and Last Digits Sum : ");
    scanf("%d", &n);

    temp = n;

    while(temp > 0)
    {
        rem = temp % 10;
        temp /= 10;
    }

    printf("The Sum of %d & %d = %d\n", rem, n%10, rem + n%10);
}