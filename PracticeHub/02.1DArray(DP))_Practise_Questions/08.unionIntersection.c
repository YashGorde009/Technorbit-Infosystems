#include<stdio.h>
#include<stdlib.h>
void main() 
{
    int i, j, k, n1, n2, min, unionCount = 0, intersectionCount = 0, flag;
    int *array1 = NULL, *array2 = NULL, *unionArray = NULL, *intersectionArray = NULL;
    // Array 1
    printf("Total Element Count for Array1 : \n");
    scanf("%d", &n1);
    array1 = (int*)malloc(n1 * sizeof(int));
    printf("Input %d Array1 Elements : \n", n1);
    for(i = 0 ; i < n1 ; i++) 
    {
        scanf("%d", (array1 + i));
    }
    // Array 2
    printf("Total Element Count for Array2 : \n");
    scanf("%d", &n2);
    array2 = (int*)malloc(n2 * sizeof(int));
    printf("Input %d Array2 Elements : \n", n2);
    for(i = 0 ; i < n2 ; i++) 
    {
        scanf("%d", (array2 + i));
    }


    // Intersection Array
    min = (n1 > n2) ? n2 : n1;
    intersectionArray = (int*)malloc(min * sizeof(int));
    for(i = 0 ; i < n1 ; i++) 
    {
        for(j = 0; j < n2 ; j++)
        {
            if(*(array1 + i) == *(array2 + j)) 
            {
                *(intersectionArray + intersectionCount) = *(array1 + i);
                intersectionCount++;
            }
        }
    }

    printf("Intersection Array : \n");
    for(i = 0 ; i < intersectionCount ; i++)
    {
        printf("%d ", *(intersectionArray + i));
    }

    // Union Array 
    unionArray = (int*)malloc((n1 + n2) * sizeof(int));
    for(i = 0 ; i < n1 ; i++)
    {
        *(unionArray + i) = *(array1 + i);

        if(i == (n1 - 1)) 
        {
            unionCount = n1;

            for(j = 0 ; j < n2 ; j++)
            {   
                flag = 0; 
                for(k = 0 ; k < intersectionCount ; k++)
                {
                    if(*(array2 + j) == *(intersectionArray + k)) {
                        flag = 1;
                    }
                }
                if(flag == 0) 
                {
                    *(unionArray + unionCount) = *(array2 + j);
                    unionCount++;
                    
                }
            }
        }
    }
    
    printf("\nUnion Array : \n");
    for(i = 0 ; i < unionCount ; i++)
    {
        printf("%d ", *(unionArray + i));
    }

    free(array1);
    free(array2);
    free(intersectionArray);
    free(unionArray);
}