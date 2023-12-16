// 8.Write a C program to check whether given strings are Anagram strings or not
#include<stdio.h>
void main() 
{
    int i, j, str1Length = 0, str2Length = 0, str1CharCount, str2CharCount, flag = 0;
    char str1[100], str2[100];

    printf("Enter String1 : \n");
    fgets(str1, sizeof(str1), stdin);

    printf("Enter String2 : \n");
    fgets(str2, sizeof(str2), stdin);

    i = 0;
    while(str1[i] != '\n') 
    {
        str1Length++;
        i++;
    }

    i = 0;
    while(str2[i] != '\n') 
    {
        str2Length++;
        i++;
    }

    if(str1Length != str2Length)
    {
        printf("Not Anagram1\n", str1, str2);
    }
    else{
        i = 0;
        while(str1[i] != '\n') 
        {
            str1CharCount = 0;
            j = 0;
            while(str1[j] != '\n')
            {
                if(str1[i] == str1[j])
                {
                str1CharCount++;
                }
                j++;
            }

            str2CharCount = 0;
            j = 0;
            while(str2[j] != '\n')
            {
                if(str1[i] == str1[j])
                {
                str2CharCount++;
                }
                j++;
            }
            if(str1CharCount != str2CharCount)
            {
                flag = 1;
                printf("Not Anagram2\n");
                break;
            }
            i++;
        }
    }
    if(flag == 0)
    {
        printf("Both Strings Are Anagram\n");
    }
}