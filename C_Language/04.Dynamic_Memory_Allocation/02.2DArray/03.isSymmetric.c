#include<stdio.h>
#include<stdlib.h>
void main()
{
    int i, j, rows, cols, flag = 0;
    int** matrix = NULL;

    printf("For Matrix : \n");
    printf("Enter No. Of Rows : \n");
    scanf("%d", &rows);
    printf("Enter No. Of Columns : \n");
    scanf("%d", &cols);

    if(rows == cols)
    {
        matrix = (int**)malloc(rows * sizeof(int*));
        for(i = 0 ; i < rows ; i++)
        {
           *(matrix + i) = (int*)malloc(cols * sizeof(int)); 
        }

        printf("Enter %d Elements For Matrix :\n");
        for(i = 0 ; i < rows ; i++)
        {
            for(j = 0 ; j < cols ; j++)
            {
                scanf("%d", (*(matrix + i) + j));
            }
        }

        // Check For Symmetry
        for(i = 0 ; i < rows ; i++)
        {
            for(j = 0 ; j < cols ; j++)
            {
                if(i < j)
                {
                    if(*(*(matrix + i) + j) != *(*(matrix + j) + i))
                    {
                        printf("No, It's Not An Symmetric Matrix.\n");
                        flag = 1;
                        break; // This Breaks Innermost Loop

                    }
                }
            }
            if(flag == 1)
            {
                break; // This Breaks Outermost Loop
            }
        }
        if(flag == 0)
        {
            printf("Yes, It's An Symmetric Matrix.\n");
        }

    }
    else 
    {
        printf("No, It's Not An Symmetric Matrix.\n");
        printf("For a matrix to be symmetric, it should have the same number of rows and columns.");
    }

    for(i = 0 ; i < rows ; i++)
    {
        free(*(matrix + i)); 
    }
    free(matrix);
}