// 8.Write a C program to check whether given strings are Anagram strings or not.
// Input String1: abccd
// Input String2: cbcda
// Output String: Strings are anagram
#include<stdio.h>
#include<stdlib.h>

void main() 
{
   int i, j, size1 = 1, size2 = 1, count1, count2, flag;
   char ch;
   char* string1 = NULL;
   char* string2 = NULL;

   string1 = (char*)malloc(sizeof(char)); 
   string2 = (char*)malloc(sizeof(char)); 

   *(string1 + 0) = '\0';
   *(string2 + 0) = '\0';

    //1st String Input...
    printf("Enter 1st String : \n");

    i = 0;
    do
    {
        scanf("%c", &ch);
        if(ch != '\n')
        {
            size1++;
            string1 = (char*)realloc(string1, size1);
            *(string1 + i) = ch;
            *(string1 + i + 1) = '\0';
            i++;
        }
    }while(ch != '\n');

    //2nd String Input...
    printf("Enter 2nd String : \n");

    i = 0;
    do
    {
        scanf("%c", &ch);
        if(ch != '\n')
        {
            size2++;
            string2 = (char*)realloc(string2, size2);
            *(string2 + i) = ch;
            *(string2 + i + 1) = '\0';
            i++;
        }
    }while(ch != '\n');

    // Anagram logic...
    if(size1 != size2)
    {
        printf("%s and %s are not anagrams", string1, string2);
    }
    else
    {
       i = 0;
       while(*(string1 + i) != '\0') 
       {    
            count1 = 0;
            count2 = 0;

            // Avoidng checking same character again & again
            flag = 0;
            j = i - 1;
            while(j >= 0)
            {
                if(*(string1 + i) == *(string1 + j))
                {
                    flag = 1;
                    break;
                }
                j--;
            }

            if(flag != 1)
            {
                j = 0;
                while(*(string1 + j) != '\0')
                {
                    if(*(string1 + i) == *(string1 + j))
                    {
                        count1++;
                    }
                    j++;
                }

                j = 0;
                while(*(string2 + j) != '\0')
                {
                    if(*(string1 + i) == *(string2 + j))
                    {
                        count2++;
                    }
                    j++;
                }
                if(count1 != count2) 
                {
                    printf("Strings '%s' & '%s' Are Not Anagrams");
                    flag = 1;
                    break;
                }
            }
            i++;
       }
       if(flag != 1)
       {
            printf("Strings '%s' & '%s' Are Anagrams\n", string1, string2);
       }
    }

    free(string1);
    free(string2);
}

