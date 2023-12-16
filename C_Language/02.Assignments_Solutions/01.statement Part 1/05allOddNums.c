#include<stdio.h>
void main() 
{
    int i; 

    i = 1;
    while(i <= 100) 
    {
        if(i % 2 != 0) // odd condn 
        {
        printf("%d ", i);
        } 
        i++;
    }
}