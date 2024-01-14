//  For two matrices to be added,the number of rows and columns must be equal.
#include<stdio.h>
#include<stdlib.h>
void main() 
{
    int i, j, rows, cols, sum;
    int** mat1 = NULL, **mat2 = NULL, **sumMat = NULL;

    printf("For Matrix A & B: \n");
    printf("Input No. Of Rows : \n");
    scanf("%d", &rows);
    printf("Input No. Of Columns : \n");
    scanf("%d", &cols);

    mat1 = (int**)malloc(rows * sizeof(int*));
    mat2 = (int**)malloc(rows * sizeof(int*));
    sumMat = (int**)malloc(rows * sizeof(int*));

    for(i = 0 ; i < rows ; i++)
    {
        *(mat1 + i) = (int*)malloc(cols * sizeof(int));
        *(mat2 + i)= (int*)malloc(cols * sizeof(int));
        *(sumMat + i) = (int*)malloc(cols * sizeof(int));
    }

    printf("Input Elements Of Matrix 1 : \n");
    for(i = 0 ; i < rows ; i++)
    {
        for(j = 0 ; j < cols ; j++)
        {
            scanf("%d", *(mat1 + i) + j);
        }
    }

    printf("Input Elements Of Matrix 2 : \n");
    for(i = 0 ; i < rows ; i++)
    {
        for(j = 0 ; j < cols ; j++)
        {
            scanf("%d", *(mat2 + i) + j);
        }
    }

    for(i = 0 ; i < rows ; i++)
    {
        for(j = 0 ; j < cols ; j++)
        {
            *(*(sumMat + i) + j) = (*(*(mat1 + i) + j)) + (*(*(mat2 + i) + j));
        }
        
    }
    printf("Addition Of Matrix 1 & Matrix 2  : \n");
    for(i = 0 ; i < rows ; i++)
    {
        for(j = 0 ; j < cols ; j++)
        {
            printf("%d ", *(*(sumMat + i) + j));
        }
        printf("\n");
    }

    for(i = 0 ; i < rows ; i++)
    {
        free(*(mat1 + i));
        free(*(mat2 + i));
        free(*(sumMat + i));
    }
    free(mat1);
    free(mat2);
    free(sumMat);
}
