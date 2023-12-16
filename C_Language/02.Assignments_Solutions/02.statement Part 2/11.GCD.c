#include<stdio.h>
void main() 
{
    int i, n1, n2, GCD;
    printf("Let's Find GCD Of Two Numbers But Before...\n");
    printf("Enter Num1 : ");
    scanf("%d", &n1);
    printf("Enter Num2 : ");
    scanf("%d", &n2);

    printf("GCD of %d & %d = ", n1, n2);

    for(i = 1; i <= n1 && i <= n2; i++)
    {
        if(n1 % i == 0 && n2 % i == 0) {
            GCD = i;
        }
    }
    printf("%d", GCD);
}