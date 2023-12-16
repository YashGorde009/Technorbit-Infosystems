// A strong number is a positive integer that equals the sum of the factorials of it's digits. For example, 145 is strong number because 1! + 4! + 5! = 145.
#include<stdio.h>
void main() 
{
    int i, n, temp, rem, ans, ansSum = 0;
    printf("Check Whether A Number Is Strong But Before...\n");
    printf("Enter Number : ");
    scanf("%d", &n);
    temp = n; 
    while(temp > 0)
    {   
        ans = 1;
        rem = temp % 10;
        for(i = 2; i <= rem; i++)
        {
            ans *= i;
        }
        ansSum += ans;
        temp /= 10;
    }
    if(ansSum == n)
    {
        printf("%d is Strong", n);
    }
    else
    {
        printf("%d is Not Strong", n);
    }
}