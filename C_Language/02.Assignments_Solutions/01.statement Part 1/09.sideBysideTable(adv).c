#include<stdio.h>
void main() 
{
    int i, j, n; 
    printf("Enter A Num & Get All Tables(1 to N) : ");
    scanf("%d", &n);

    for(i = 1; i <= 10; i++)
    {
        for(j = 1; j <= n; j++){
            printf("%d\t", i*j);
        }
        printf("\n");
    }
}