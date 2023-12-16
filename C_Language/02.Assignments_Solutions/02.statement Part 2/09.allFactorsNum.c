#include<stdio.h>
void main() 
{
    int i, n;
    printf("Enter Num & Get It's All Factors : ");
    scanf("%d", &n);
    printf("Factors of %d are : ", n);
    for(i = 1; i <= n; i++)
    {
        if(n % i == 0) 
        {
            printf("%d  ", i);
        }
    }
}