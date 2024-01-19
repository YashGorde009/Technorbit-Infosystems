// 3.Write a C program which accept sentence from user and print number of words of even and odd length from that sentence.
#include<stdio.h>
#include<stdlib.h>
void main() 
{
    int i, stringSize = 1, wordLength, evenCount = 0, oddCount = 0;
    char* string, ch;
    string = (char*)malloc(stringSizeof(char));
    *(string + 0) =  '\0';
    printf("Enter String : \n");

    i = 0;
    do
    {   
        scanf("%c", &ch);
        if(ch != '\n')
        {
            stringSize++;
            string = (char*)realloc(string , stringSize);
            *(string + i) = ch;
            *(string + i + 1) = '\0';
            i++;
        }
    }while(ch != '\n');

    i = 0;
    while(*(string + i) != '\0')
    {
        wordLength = 0;
        while(*(string + i) != ' ' && *(string + i) != '\0')
        {
            wordLength++;
            i++;
        }

        if(wordLength > 0)
        {
            if((wordLength % 2) == 0)
            {
                evenCount++;
            }
            else 
            {
                oddCount++;
            }
        }
        else
        {
            i++;
        }
    }
    printf("Even : %d Odd : %d\n", evenCount, oddCount);
    free(string);
}