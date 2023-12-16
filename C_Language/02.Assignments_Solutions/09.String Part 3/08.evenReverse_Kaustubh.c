#include<stdio.h>
int main()
{
    char str[100];
    printf("Enter a string =");
    fgets(str , sizeof(str) , stdin);
    int i , j , count =0 , k;
    i=0;
    while(str[i]!= '\n')
    {
        count =0 ;
        while(str[i] != ' ' && str[i] !='\n')
        {
            i++ ; 
            count ++;
        }
        j = i-1 ;
        k = i - count;
        if(count % 2 == 0)
        {
            while(count!= 0)
            {
                printf("%c" , str[j]);
                j--;
                count--;
                
            }
        }
        else{
            while(count!=0)
            {
                printf("%c" , str[k]);
                k++;
                count--;
            }
        }

        while(str[i] == ' ')
        {
            printf(" ");
            i++;
        }


    }
    return 0;
}

       