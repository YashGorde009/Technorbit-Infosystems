#include<stdio.h>
void main() 
{
    int i, n, fact = 1;
    printf("Enter Num & Get It's Factorial : ");
    scanf("%d", &n);
    printf("Factorial of %d is : ", n);
    i = 2;
    while(i <= n)
    {
        fact *= i;
        i++;
    }
    printf("%d", fact);
}