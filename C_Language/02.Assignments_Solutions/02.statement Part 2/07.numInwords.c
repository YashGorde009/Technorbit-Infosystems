#include<stdio.h>
void main() 
{
    int n, rev = 0, rem, temp;
    printf("Enter A Num & Get It's Word Formate : ");
    scanf("%d", &n);

    temp = n;

    while(temp > 0)
    {
        rem = temp % 10;
        rev = rev * 10 + rem;
        temp /= 10;
    }

    while(rev > 0)
    {
        rem = rev % 10;
        switch(rem) 
        {
            case 0 : printf("Zero ");
                    break;
            case 1 : printf("One ");
                    break;
            case 2 : printf("Two ");
                    break;
            case 3 : printf("Three ");
                    break;
            case 4 : printf("Four ");
                    break;
            case 5 : printf("Five ");
                    break;
            case 6 : printf("Six ");
                    break;
            case 7 : printf("Seven ");
                    break;
            case 8 : printf("Eight ");
                    break;
            case 9 : printf("Nine ");
                    break;
        }
        rev /= 10;
    }
    
}