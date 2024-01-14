// 4.Write a C program which accept two strings from user and compare only first N 
// characters of two strings. If both strings are equal till first N characters then return 
// 0 otherwise return difference between first mismatch character.
// Eg:
// Input String1: Ramayan 
// Input String2: Ramanacharya 
// Input of N: 4
// Output: Both strings are equal.

#include<stdio.h>
#include<stdlib.h>

void main() 
{
    int i, size1 = 1, size2 = 1, flag = 0, nChar;
    char ch;
    char* string1 = NULL;
    char* string2 = NULL;

    string1 = (char*)malloc(sizeof(char));
    *(string1 + 0) = '\0';

    printf("Enter 1st String : \n");
    
    i = 0;
    do
    {
        scanf("%c", &ch);
        if(ch != '\n')
        {
            if(ch >= 'A' && ch <= 'Z')
            {
                ch += 32; // to lowercase
            }
            size1++;
            string1 = (char*)realloc(string1, size1);
            *(string1 + i) = ch;
            *(string1 + i + 1) = '\0';
            i++;
        }
    }while(ch != '\n');

    string2 = (char*)malloc(sizeof(char));
    *(string2 + 0) = '\0';

    printf("Enter 2nd String : \n");
    
    i = 0;
    do
    {
        scanf("%c", &ch);
        if(ch != '\n')
        {
            if(ch >= 'A' && ch <= 'Z')
            {
                ch += 32; // to lowercase
            }
            size2++;
            string2 = (char*)realloc(string2, size2);
            *(string2 + i) = ch;
            *(string2 + i + 1) = '\0';
            i++;
        }
    }while(ch != '\n');

    printf("How Many Character Do You Want To Compare : \n");
    scanf("%d", &nChar);

    nChar -= 1; // bcoz idx begin from zero
    
    i = 0;
    while(i <= nChar)
    {
        if(*(string1 + i) != *(string2 + i))
        {
            printf("Mismatch Character '%c' & '%c' with difference %d\n", *(string1 + i), *(string2 + i), (*(string1 + i) - *(string2 + i)));
            flag = 1;
            break;
        }
        i++;
    }
    if(flag != 1)
    {
        printf("Both Strings Are Equal\n");
    }
}