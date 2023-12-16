#include<stdio.h>
void main() 
{
    int n, rem, temp ; 
    printf("Enter A Num & Get It's First & Last Digits : ");
    scanf("%d", &n);

    temp = n;
    
    while(temp > 0) 
    {
        rem = temp % 10;
        temp /= 10;
    }

    printf("First Digit of %d is %d\n", n, rem);
    printf("First Last of %d is %d\n", n, n%10);

}