#include<stdio.h>
void main() 
{
    int i, n; 
    printf("Enter A Num & Get It's Table : ");
    scanf("%d", &n);
    i = 1; 
    while(i <= 10) 
    {
        printf("%d X %d = %d\n", n,  i, n*i);
        i++;
    }

}