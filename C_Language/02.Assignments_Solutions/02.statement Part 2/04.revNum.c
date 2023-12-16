#include<stdio.h>
void main() 
{
    int n, temp, rem, rev = 0;
    printf("Enter A Num & Get It's Reverse : ");
    scanf("%d", &n);

    temp = n;

    while(temp > 0)
    {
        rem = temp % 10;
        rev = rev * 10 + rem;
        temp /= 10;
    }

    printf("The Reverse of %d is %d\n", n, rev);
}