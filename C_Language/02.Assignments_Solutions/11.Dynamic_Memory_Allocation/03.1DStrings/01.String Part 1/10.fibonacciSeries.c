// 10.Write a C program to print all Fibonacci series up to each ASCII code of alphabets in given string.
#include<stdio.h>
#include<stdlib.h>
void main()
{
    int i, j, size = 1, f1, f2, f3, flag;
    char* string, ch;
    string = (char*)malloc(sizeof(char));
    *(string + 0) = '\0';
    printf("Enter String : \n");

    i = 0;
    do{
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

    printf("Fibonacci Series Upto Each Character Ascii Code :\n");

    i = 0;
    while(*(string + i) != '\0')
    {
        // skips spaces
        while(*(string + i) == ' ')
        {
            i++;
        }
     
        // To Avoid Printing Duplicate Characters
        flag = 0;
        j = i - 1;
        while(j >= 0)
        {
            if(*(string + i) == *(string + j))
            {
                flag = 1;
                break;
            }
            j--;
        }

        if(flag == 0)
        {
        f1 = 0;
        f2 = 1;
        printf("Upto '%c' (%d) --> ", *(string + i), *(string + i));
        printf("%d %d ", f1, f2);

        while((f3 = f1 + f2) <= *(string + i))
        {
            printf("%d ", f3);
            f1 = f2;
            f2 = f3;
        }
        printf("\n");
        }

        i++;
    }

    free(string);
}