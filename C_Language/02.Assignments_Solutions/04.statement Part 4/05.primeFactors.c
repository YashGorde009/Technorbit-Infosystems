#include<stdio.h>
void main() 
{
    int i, j, count, rgn;
    printf("Enter A Number & Get It's All Prime Factors But Before...\n");
    printf("Enter Number : ");
    scanf("%d", &rgn);

    if(rgn > 1)
    {
    for(i = 1; i <= rgn; i++)
    {
        count = 0;
        for(j = 1; j <= i; j++)
        {
            if(i % j == 0)
            {
                count++;
            }
        }
        if(count == 2 && rgn % i == 0)
        {
            printf("%d ", i);
        }
    }
    }
    else if( rgn <= 1)
    {
        printf("Invalid Number\n");
    }
}