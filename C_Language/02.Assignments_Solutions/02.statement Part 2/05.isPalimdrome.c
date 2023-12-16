#include<stdio.h>
void main() 
{
    int n, temp, rem, rev = 0;
    printf("Enter A Num & Check Whether The Num Is Palimdrome : ");
    scanf("%d", &n);

    temp = n;

    while(temp > 0)
    {
        rem = temp % 10;
        rev = rev * 10 + rem;
        temp /= 10;
    }
    if(rev == n)
    {
        printf("The Num %d is Palimdrome\n", n);
    }
    else
    {
        printf("The Num %d is Not Palimdrome\n", n);
    }
}