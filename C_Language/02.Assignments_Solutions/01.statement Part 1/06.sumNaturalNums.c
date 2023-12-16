#include<stdio.h>
void main() 
{
    int i, rgn, sum = 0; 
    printf("Enter Range : ");
    scanf("%d", &rgn);
    i = 1; 
    while(i <= rgn) 
    {
        sum += i;
        i++;
    }

    printf("Sum Of 1 to %d Natural Numbers = %d\n", rgn, sum);
}