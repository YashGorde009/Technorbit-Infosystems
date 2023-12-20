#include<stdio.h>
#include<stdlib.h>
void main() 
{
    int i, j, k, rows1, cols1, rows2, cols2, sum;
    int** matrixA = NULL, **matrixB = NULL, **productABMatrix = NULL;

    printf("For Matrix A : \n");
    printf("Enter No. Of Rows : \n");
    scanf("%d", &rows1);
    printf("Enter No. Of Columns : \n");
    scanf("%d", &cols1);

    printf("For Matrix B : \n");
    printf("Enter No. Of Rows : \n");
    scanf("%d", &rows2);
    printf("Enter No. Of Columns : \n");
    scanf("%d", &cols2);

    if(cols1 == rows2)
    {
        matrixA = (int**)malloc(rows1 * sizeof(int*));
        matrixB = (int**)malloc(rows2 * sizeof(int*));
        productABMatrix = (int**)malloc(rows1 * sizeof(int*));

        for(i = 0 ; i < rows1; i++)
        {
            *(matrixA + i) = (int*)malloc(cols1 * sizeof(int));
        }

        for(i = 0 ; i < rows2; i++)
        {
            *(matrixB + i) = (int*)malloc(cols2 * sizeof(int));
        }

        for(i = 0 ; i < rows1; i++)
        {
            *(productABMatrix + i) = (int*)malloc(cols2 * sizeof(int));
        }

        printf("Input Matrix A %d Elements : \n", rows1*cols1);
        for(i = 0 ; i < rows1 ; i++)
        {
            for(j = 0 ; j < cols1 ; j++)
            {
                scanf("%d", (*(matrixA + i) + j));
            }
        }

        printf("Input Matrix B %d Elements : \n", rows2*cols2);
        for(i = 0 ; i < rows2 ; i++)
        {
            for(j = 0 ; j < cols2; j++)
            {
                scanf("%d", (*(matrixB + i) + j));
            }
        }

        for(i = 0 ; i < rows1 ; i++)
        {
            for(j = 0 ; j < cols2 ; j++)
            {   
                sum = 0;
                for(k = 0 ; k < cols1 ; k++)
                {
                    sum += *(*(matrixA + i) + k) * *(*(matrixB + k) + j);
                }
                *(*(productABMatrix + i) + j) = sum;
            }
        }

        printf("Multiplication Of Matrix A & Matrix B : \n");
        for(i = 0 ; i < rows1 ; i++)
        {
            for(j = 0 ; j < cols2 ; j++)
            {
                printf("%d ", *(*(productABMatrix + i) + j));
            }
            printf("\n");
        }

    }
    else
    {
        printf("For multiplication of two matrices,the number of columns in the first matrix should be equal to the number of rows in the second matrix.");
    }

    for(i = 0 ; i < rows1; i++)
    {
        free(*(matrixA + i));
    }
    free(matrixA);

    for(i = 0 ; i < rows2; i++)
    {
        free(*(matrixB + i));
    }
    free(matrixB);
    
    for(i = 0 ; i < rows1; i++)
    {
        free(*(productABMatrix + i));
    }
    free(productABMatrix);
    
}