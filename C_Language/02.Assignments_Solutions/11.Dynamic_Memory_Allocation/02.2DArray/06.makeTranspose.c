#include<stdio.h>
#include<stdlib.h>
void main() 
{
    int i, j, rows, cols;
    int** matrix = NULL, ** transMatrix = NULL;

    printf("For Matrix : \n");
    printf("Enter No. Of Rows : \n");
    scanf("%d", &rows);
    printf("Enter No. Of Columns : \n");
    scanf("%d", &cols);

    matrix = (int**)malloc(rows * sizeof(int*));
    transMatrix = (int**)malloc(cols * sizeof(int*));

    for(i = 0 ; i < rows ; i++)
    {
        *(matrix + i) = (int*)malloc(cols * sizeof(int));
    }

    for(i = 0 ; i < cols ; i++)
    {
        *(transMatrix + i) = (int*)malloc(rows * sizeof(int));
    }

    printf("Enter %d Element Matrix : \n", rows*cols);
    for(i = 0 ; i < rows ; i++)
    {
        for(j = 0 ; j < cols ; j++)
        {
            scanf("%d", (*(matrix + i) + j));
        }
    }

    for(i = 0 ; i < rows ; i++)
    {
        for(j = 0 ; j < cols ; j++)
        {
            *(*(transMatrix + j) + i) = *(*(matrix + i) + j);
        }
    }

    printf("Original Matrix \n");
    for(i = 0 ; i < rows ; i++)
    {
        for(j = 0 ; j < cols ; j++)
        {
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }

    printf("\nTranspose Matrix\n");
    for(i = 0 ; i < cols ; i++)
    {
        for(j = 0 ; j < rows ; j++)
        {
            printf("%d ", *(*(transMatrix + i) + j));
        }
        printf("\n");
    }
    
    for(i = 0 ; i < rows ; i++)
    {
        free(*(matrix + i));
    }
    free(matrix);
    for(i = 0 ; i < cols ; i++)
    {
        free(*(transMatrix + i));
    }
    free(transMatrix);
}