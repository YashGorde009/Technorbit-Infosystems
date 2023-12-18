// 12.Write a C program to create an array of n elements using dynamic memory allocation to Find Union & Intersection of 2 arrays.
#include<stdio.h>
#include<stdlib.h>
int main() 
{
    int i, j, k, numElements1, numElements2, unionCount = 0, intersectionCount = 0, totalElements, flag, minEleCount;
    int *i_arr1 = NULL, *i_arr2 = NULL, *unionArr = NULL, *intersectionArr = NULL, *tempArr = NULL;
    
    // Array 1
    printf("How Many Elements Do You Want To Enter In Array 1 : \n"); 
    scanf("%d", &numElements1);   
    i_arr1 = (int*)malloc(numElements1 * sizeof(int));
    printf("Enter Array1 Elements : \n");
    for(i = 0 ; i < numElements1 ; i++) 
    {
        scanf("%d", (i_arr1 + i));
    }

    // Array 2
    printf("How Many Elements Do You Want To Enter In Array 2 : \n"); 
    scanf("%d", &numElements2);   
    i_arr2 = (int*)malloc(numElements2 * sizeof(int));
    printf("Enter Array2 Elements : \n");
    for(i = 0 ; i < numElements2 ; i++) 
    {
        scanf("%d", (i_arr2 + i));
    }

    // Temporary Array 
    totalElements = numElements1 + numElements2; 
    tempArr = (int*)malloc(totalElements * sizeof(int));
    for(i = 0 ; i < numElements1 ; i++)
    {
        *(tempArr + i) = *(i_arr1 + i);
        if(i == (numElements1 - 1)) 
        {   
            k = 0;
            for(j = numElements1 ; j < totalElements ; j++)
            {
                *(tempArr + j) = *(i_arr2 + k);
                k++;
            }
        }
    }

    // Union Array 
    unionArr = (int*)malloc(totalElements * sizeof(int));
    unionCount = 0;
    for(i = 0 ; i < totalElements ; i++)
    {   
        flag = 0;
        j = i - 1;
        while(j >= 0) 
        {
            if(*(tempArr + i) == *(tempArr + j))
            {
                flag = 1;
                break;
            }
            j--;
        }
        if(flag == 0) 
        {
            *(unionArr + unionCount) = *(tempArr + i);
            unionCount++;
        }
    }

    printf("Union Array : \n");
    for(i = 0 ; i < unionCount ; i++) 
    {
        printf("%d ", *(unionArr + i));
    }
    free(unionArr);
    free(tempArr);
    // Intersection Array
    minEleCount = (numElements1 > numElements2) ? numElements2 : numElements1;
    intersectionArr = (int*)malloc(minEleCount * sizeof(int));
    intersectionCount = 0;
    for(i = 0 ; i < numElements1 ; i++)
    {
        flag = 0;
        j = i - 1;
        while(j >= 0) 
        {
            if(*(i_arr1 + i) == *(i_arr1 + j)) 
            {
                flag = 1;
                break;
            }
            j--;
        }
        if(flag == 0) 
        {
            flag = 0;
            for(k = 0 ; k < numElements2 ; k++)
            {
                if(*(i_arr1 + i) == *(i_arr2 + k))
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 1) 
            {
                *(intersectionArr + intersectionCount) = *(i_arr1 + i);
                intersectionCount++;
            }
        }
    }

    printf("\nIntersection Array : \n");
    for(i = 0 ; i < intersectionCount; i++) 
    {
        printf("%d ", *(intersectionArr + i));
    }
    free(intersectionArr);

    return 0;
}