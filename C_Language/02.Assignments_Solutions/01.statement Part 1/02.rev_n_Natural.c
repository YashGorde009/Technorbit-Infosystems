#include<stdio.h>
void main() 
{
    int rgn;
    printf("Enter Range : ");
    scanf("%d", &rgn); // Get's The Range

    
    while(rgn >= 1) 
    {
        printf("%d ", rgn);
        rgn--;
    }
}