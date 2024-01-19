// 5.Write a C program to count number of vowels and number of consonants in the given string.
#include<stdio.h>
#include<stdlib.h>
void main() 
{
    int i, size = 1, vowelCount = 0, consonantCount = 0;
    char* string, ch1, ch2;
    string = (char*)malloc(sizeof(char));
    *(string + 0) = '\0';
    printf("Enter String :\n");

    i = 0;
    do
    {
        scanf("%c", &ch1);
        if(ch1 != '\n')
        {
            size++;
            string = (char*)realloc(string, size);
            *(string + i) = ch1;
            *(string + i + 1) = '\0';
            i++;
        }
    }while(ch1 != '\n');

    i = 0;
    while(*(string + i) != '\0')
    {
        while(*(string + i) == ' ')
        {
            i++;
        }
        while(*(string + i) != ' ' && *(string + i) != '\0')
        {
            ch2 = *(string + i);
            if(ch2 == 'a' || ch2 == 'A' || ch2 == 'e' || ch2 == 'E' || ch2 == 'i' || ch2 == 'I' || ch2 == 'o' || ch2 == 'O' || ch2 == 'u' || ch2 == 'U')
            {
                vowelCount++;
            }
            else
            {
                consonantCount++;
            }
            i++;
        }
    }
    printf("Vowels : %d Consonants : %d\n", vowelCount, consonantCount);
    free(string);
}