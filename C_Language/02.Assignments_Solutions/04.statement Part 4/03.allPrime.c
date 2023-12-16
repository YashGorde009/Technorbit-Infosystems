// A prime number is a natural number greater than 1 that is divisible only by 1 and itself.(1 is not prime number)
#include<stdio.h>
void main() 
{
    int i, j, rgn, flag;
    printf("Enter A Range Get All Prime Number till The Range But Before ...  \n");
    printf("Enter Range : ");
    scanf("%d", &rgn);

    if(rgn > 1)
    {
    for(i = 2; i <= rgn; i++)
    {
        flag = 0;
        for(j = 2; j < i; j++)
        {
            if(i % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            printf("%d ", i);
        }
    }
    }
    else
    {
        printf("Invalid Range\n");
    }

}
