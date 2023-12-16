#include<stdio.h>
void main() 
{
    int n, freq = 0, rem1, rem2, temp1, temp2;
    printf("Enter A Num & Get Every digits Frequency : ");
    scanf("%d", &n);

    temp1 = n;

    while(temp1 > 0)
    {
        rem1 = temp1 % 10;
        temp2 = n;
        freq = 0;
        while(temp2 > 0)
        {
            rem2 = temp2 % 10;
            if(rem2 == rem1)
            {
                freq++;
            }
            temp2 /= 10;
        }
        printf("The Frequency of %d is %d\n", rem1, freq);
        temp1 /= 10;
    }
}