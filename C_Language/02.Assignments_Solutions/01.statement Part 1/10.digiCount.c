#include<stdio.h>
void main() 
{
    int n, temp, count = 0; 
    printf("Enter A Num & Get It's digit count : ");
    scanf("%d", &n);
    temp = n;

    while(temp > 0) 
    {
        temp /= 10;
        count++;
    }

    printf("Total Digits In %d = %d\n", n, count);


}