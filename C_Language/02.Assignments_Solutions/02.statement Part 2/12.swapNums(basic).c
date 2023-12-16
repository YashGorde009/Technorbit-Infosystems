#include<stdio.h>
void main() 
{
    int n1, n2, temp;
    printf("Let's Swap Two Number But Before...\n");
    printf("Enter Num1 : ");
    scanf("%d", &n1);
    printf("Enter Nun2 : ");
    scanf("%d", &n2);

    printf("Before swapping...\nnum1 = %d and num2 = %d\n", n1, n2);

    temp = n1;
    n1 = n2;
    n2 = temp;
    
    printf("After swapping...\nnum1 = %d and num2 = %d\n", n1, n2);

}