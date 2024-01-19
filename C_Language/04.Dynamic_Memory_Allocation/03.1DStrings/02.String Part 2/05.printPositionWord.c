// 5.which accept sentence from user and position from user and print the word at that position.
#include<stdio.h>
#include<stdlib.h>
void main() 
{
    int i, stringSize = 1, position, wordCount = 0;
    char* string, ch, currentChar, nextChar;
    string = (char*)malloc(sizeof(char));
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

    printf("Enter Position : \n");
    scanf("%d", &position);

    i = 0;
    while(*(string + i) != '\0')
    {
        currentChar = *(string + i);
        nextChar = *(string + i + 1);
        
        if(currentChar != ' ' && (nextChar == ' ' || nextChar == '\0'))
        {
            wordCount++;
        }
        if(wordCount == position)
        {
            while(i > 0 && *(string + i - 1) != ' ')
            {
                i--;
            }
            while(*(string + i) != ' ' && *(string + i) != '\0')
            {
                printf("%c", *(string + i));
                i++;
            }
            break;
        }
        i++;
    }
    free(string);
}