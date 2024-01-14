#include<stdio.h>
#include<stdlib.h>
void main() 
{
    int i, j, rows, cols;
    int** ptr = NULL;

    printf("Enter Rows : \n");
    scanf("%d", &rows);

    printf("Enter Columns : \n");
    scanf("%d", &cols);

    ptr = (int**)malloc(rows * sizeof(int*));

    for(i = 0 ; i < rows ; i++)
    {
        *(ptr + i) = (int*)malloc(cols * sizeof(int)); 
    }

    printf("Enter Array Elements : \n");
    for(i = 0 ; i < rows ; i++)
    {
        for(j = 0 ; j < cols ; j++)
        {
            scanf("%d", (*(ptr + i) + j));
        }
    }

    for(i = 0 ; i < rows ; i++)
    {
        for(j = 0 ; j < cols ; j++)
        {
            printf("%d ", *(*(ptr + i) + j));
        }
        printf("\n");
    }


    for(i = 0 ; i < rows ; i++)
    {
        free(*(ptr + i));
    }
    free(ptr);
    
}