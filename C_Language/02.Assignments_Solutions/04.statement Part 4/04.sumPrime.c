#include<stdio.h>
void main() 
{
    int i, j, rgn, flag, sum = 0;
    printf("Enter Range & Get Sum Of All Prime Nums Till The Range But Before... \n");
    printf("Enter Range : ");
    scanf("%d", &rgn);

    for(i = 1; i <= rgn; i++)
    {
        flag = 0;
        for(j = 1; j <= i; j++)
        {
            if(i % j == 0)
            {
                flag++;
            }
        }
        if(flag == 2)
        {
            sum += i;
        }
    }
    printf("1 to %d Prime Nums Sum is %d\n", rgn, sum);
}