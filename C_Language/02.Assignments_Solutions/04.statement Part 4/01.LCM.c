#include<stdio.h>
void main() 
{
    int n1, n2, LCM, max;
    printf("Enter Two Numbers & Get LCM But Before...  \n");
    printf("Enter Num1 : ");
    scanf("%d", &n1);
    printf("Enter Num2 : ");
    scanf("%d", &n2);

    max = (n1 > n2) ? n1 : n2; // Gives Maximum Num

    // or
     
    // max = (n1, n2); // Gives Maximum Num

    while(1)
    {
        if(max % n1 == 0 && max % n2 == 0)
        {
            printf("LCM Of %d & %d is %d", n1, n2, max);
            break;
        }
        max++;
    }
}