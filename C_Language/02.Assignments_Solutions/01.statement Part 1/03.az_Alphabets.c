#include<stdio.h>
void main() 
{
    char ch = 'A';
    while(ch <= 'Z') 
    {
        printf("%c = %d\n", ch, ch);
        ch++;
    }
}