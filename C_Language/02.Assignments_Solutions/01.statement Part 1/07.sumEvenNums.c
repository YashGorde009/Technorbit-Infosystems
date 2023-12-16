#include<stdio.h>
void main() 
{
    int i, rgn, sum = 0; 
    printf("Enter Range : ");
    scanf("%d", &rgn);
    i = 1; 
    while(i <= rgn) 
    {
        if(i % 2 == 0) // even codn
        {
        sum += i;
        }
        i++;
    }

    printf("Sum Of 1 to %d Even Numbers = %d\n", rgn, sum);
}