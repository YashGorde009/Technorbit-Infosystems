#include<stdio.h>
void main() 
{
    int i, rgn;
    printf("Enter Range : ");
    scanf("%d", &rgn); // Get's The Range

    i = 1;
    while(i <= rgn) 
    {
        printf("%d ", i);
        i++;
    }
}