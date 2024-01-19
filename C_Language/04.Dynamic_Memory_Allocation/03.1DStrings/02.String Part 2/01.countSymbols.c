// 1.Write a C program which accept sentence from user and print number of small letters, capital letters, Spaces and digits from that sentence.
#include<stdio.h>
#include<stdlib.h>
void main() 
{
    int i, size = 1, smallCount = 0, capitalCount = 0, spaceCount = 0, digitCount = 0;
    char* string, ch1, ch2;
    string = (char*)malloc(sizeof(char));
    *(string + 0) =  '\0';
    printf("Enter String : \n");

    i = 0;
    do
    {   
        scanf("%c", &ch1);
        if(ch1 != '\n')
        {
            size++;
            string = (char*)realloc(string , size);
            *(string + i) = ch1;
            *(string + i + 1) = '\0';
            i++;
        }
    }while(ch1 != '\n');

    i = 0;
    while(*(string + i) != '\0')
    {
        ch2 = *(string + i);

        if(ch2 >= 'a' && ch2 <= 'z')
        {
            smallCount++;
        }
        else if(ch2 >= 'A' && ch2 <= 'Z')
        {
            capitalCount++;
        }
        else if(ch2 >= '0' && ch2 <= '9')
        {
            digitCount++;
        }
        else if(ch2 == ' ')
        {
            spaceCount++;
        }
        i++;
    } 
    printf("Small : %d Capital : %d Digit : %d : Space : %d\n", smallCount, capitalCount, digitCount, spaceCount);  
    free(string);
}
