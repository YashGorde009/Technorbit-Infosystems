#include<stdio.h>
void main() 
{
    int n, temp, rem, product = 1;
    printf("Enter A Num & Get It's Digits Product : ");
    scanf("%d", &n);

    temp = n;

    while(temp > 0)
    {
        rem = temp % 10;
        product *= rem;
        temp /= 10;
    }

    printf("The Sum of digits of %d is %d\n", n, product);
}