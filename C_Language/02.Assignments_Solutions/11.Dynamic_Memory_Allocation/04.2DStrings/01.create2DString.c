#include<stdio.h>
#include<stdlib.h>
void main() 
{
    int i, j, k, stringSize, rows, cols;
    char*** cityNames = NULL, ch, buffer;

    printf("For String Matrix : \n");
    printf("Enter No. of Rows : \n");
    scanf("%d", &rows);

    printf("Enter No. of Columns : \n");
    scanf("%d", &cols);

    scanf("%c", &buffer); // to consumes '\n'

    cityNames  = (char***)malloc(rows * sizeof(char**));

    for(i = 0 ; i < rows ; i++)
    {
        *(cityNames + i) = (char**)malloc(cols * sizeof(char*));
    }


    for(i = 0 ; i < rows ; i++)
    {
        for(j = 0 ; j < cols ; j++)
        {
            stringSize = 1;
            *(*(cityNames + i) + j) = (char*)malloc(sizeof(char));
            *(*(*(cityNames + i) + j) + 0) = '\0';
            printf("Enter City Name : \n");
            k = 0;
            do 
            {
                scanf("%c", &ch);
                if(ch != '\n')
                {
                    stringSize++;
                    *(*(cityNames + i) + j) = (char*)realloc(*(*(cityNames + i) + j), stringSize);
                    *(*(*(cityNames + i) + j) + k) = ch;
                    *(*(*(cityNames + i) + j) + k + 1) = '\0';
                    k++;
                }
            }while(ch != '\n');
        }
    }

    printf("City Matrix Is : \n");
    for(i = 0 ; i < rows ; i++)   
    {
        for(j = 0 ; j < cols ; j++)
        {
            printf("%s\t", *(*(cityNames + i) + j));
        }
        printf("\n");
    }

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            free(*(*(cityNames + i) + j));
        }
        free(*(cityNames + i));
    }
    free(cityNames);
}