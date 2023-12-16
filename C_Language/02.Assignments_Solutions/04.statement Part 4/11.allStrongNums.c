// A strong number is a positive integer that equals the sum of the factorials of it's digits. For example, 145 is strong number because 1! + 4! + 5! = 145.
#include<stdio.h>
void main() 
{
    int i, j, n, rgn, temp, rem, ans, ansSum = 0;
    printf("Enter Range & Get Every Strong Number Till That Range But Before...\n");
    printf("Enter Range : ");
    scanf("%d", &rgn);

    printf("Strong Numbers (1 - %d) : ", rgn);

    for(i = 1; i <= rgn; i++)
    {

    temp = i; 
    ansSum = 0;
    while(temp > 0)
    {   
        ans = 1;
        rem = temp % 10;
        for(j = 2; j <= rem; j++)
        {
            ans *= j;
        }
        ansSum += ans;
        temp /= 10;
    }
    if(ansSum == i)
    {
        printf("%d  ", i);
    }
    }
}