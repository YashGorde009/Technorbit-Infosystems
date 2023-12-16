#include<stdio.h>
void main() 
{
    int n, pow, i, ans = 1;
    printf("Enter Num : ");
    scanf("%d", &n);
    printf("Enter Power Of Num : ");
    scanf("%d", &pow);

    for(i = 1; i <= pow; i++)
    {
        ans *= n;
    }
    
    printf("%d to power %d = %d\n", n, pow, ans);
}