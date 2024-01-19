// 11.Write a C program which accepts a string from user which contains a character from ‘b’ to ‘y’.
#include<stdio.h>
#include<stdlib.h>
void main()
{
    int i, size = 1;
    char* string, ch1, ch2;
    string = (char*)malloc(sizeof(char));
    *(string + 0) = '\0';
    printf("Enter String : \n");

    i = 0;
    do{
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

    printf("Output String : \n");
    
    i = 0;
    while(*(string + i) != '\0')
    {
        // skips spaces
        while(*(string + i) == ' ')
        {
            i++;
        }

        while(*(string + i) != ' ' && *(string + i) != '\0')
        {
            ch2 = *(string + i);
            // checks if character(ch2) is between b & y or B & Y.
            if((ch2 >= 'b' && ch2 <= 'y') || (ch2 >= 'B' && ch2 <= 'Y'))
            {
                printf("%c", ch2);
                if(*(string + i + 1) == ' ')
                {
                    printf(" ");
                }
            }
            i++;
        }
    }
    free(string);
}