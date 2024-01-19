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

    matrix = (int**)malloc(rows * sizeof(int*));

    for(i = 0 ; i < rows ; i++)
    {
        *(matrix + i) = (int*)malloc(cols * sizeof(int));
    }

    printf("Enter %d Elements For Matrix : \n", rows*cols);  

    for(i = 0 ; i < rows ; i++)
    {
        for(j = 0 ; j < cols ; j++)
        {
            scanf("%d", *(matrix + i) + j);
        }
    }

    for(i = 0 ; i < rows ; i++)
    {
        for(j = 0 ; j < cols ; j++)
        {
           if(i == j)
           {
                if(*(*(matrix + i) + j) != 1)
                {
                    printf("Not, It's Not An Identify Matrix\n");
                    flag = 1;
                    break;
                }
           } 
           else // i < j or i > j
           {
                if(*(*(matrix + i) + j) != 0)
                {
                    printf("Not, It's Not An Identify Matrix\n");
                    flag = 1;
                    break;  
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
        printf("Yes, It's An Identity Matrix\n");
    }
    for(i = 0 ; i < rows ; i++)
    {
        free(*(matrix + i));
    }
    free(matrix);
}