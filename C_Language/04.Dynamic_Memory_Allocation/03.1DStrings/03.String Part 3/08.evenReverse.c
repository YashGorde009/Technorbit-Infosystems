// 8.Write a C program which accept string from user and reverse words from that string which are of even wordLength.
#include<stdio.h>
#include<stdlib.h>

void main() 
{
    int i, j, k, size = 1, wordLength, temp;
    char ch;
    char* string = NULL;

    string = (char*)malloc(sizeof(char));
    *(string + 0) = '\0';

    printf("Enter String : \n");

    i = 0;
    do
    {
        scanf("%c", &ch);
        if(ch != '\n')
        {
            size++;
            string = (char*)realloc(string, size);
            *(string + i) = ch;
            *(string + i + 1) = '\0';
            i++;
        }
    }while(ch != '\n');

    i = 0;
    while(*(string + i) != '\0')
    {
        wordLength = 0;

        while(*(string + i) == ' ')
        {
            i++;
        }

        while(*(string + i) != ' ' && *(string + i) != '\0')
        {
            wordLength++;
            i++;
        }

        if(wordLength % 2 == 0) // even condn
        {
            j = i - 1;
            k = i - 1;

            while(j >= 0 && *(string + j - 1) != ' ')
            {
                j--;
            }
            j++;
            while(j <= k)
            {
                temp = *(string + j);
                *(string + j) = *(string + k);
                *(string + k) = temp;
                j++;
                k--;
            }
        }
    }
    printf("%s", string);
    free(string);
}