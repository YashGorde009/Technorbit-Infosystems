// 12.Write a C program to create an array of n elements using static memory allocation to Find Union & Intersection of 2 arrays.
#include<stdio.h>
void main() 
{
    int i, j, Arr1Elements, Arr2Elements, intersectionCount;
    int i_arr1[100], i_arr2[100], unionArr[200],  intersectionArr[100];

    printf("How Many Element Do You Want To Enter In Array1 : \n");
    scanf("%d", &Arr1Elements);

    // Array1 Inputs In
    printf("Enter Array1 Elements : \n");
    for(i = 0 ; i < Arr1Elements ; i++)
    {
        scanf("%d", &i_arr1[i]);
    }

    printf("\nHow Many Element Do You Want To Enter In Array 2 : \n");
    scanf("%d", &Arr2Elements);

    // Array2 Inputs In
    printf("Enter Array2 Elements : \n");
    for(i = 0 ; i < Arr2Elements ; i++)
    {
        scanf("%d", &i_arr2[i]);
    }


    // Union Array
    for(i = 0 ; i < Arr1Elements ; i++)
    {
        unionArr[i] = i_arr1[i];
        if(i == Arr1Elements - 1)
        {
            for(j = Arr1Elements; j < Arr1Elements + Arr2Elements ; j++)
            {
                unionArr[j] = i_arr2[j - Arr1Elements];
            }
        }
    }

    // Printing UnionArr 
    printf("Union Array Elements : \n");
    for(i = 0 ; i < Arr1Elements + Arr2Elements ; i++)
    {
        printf("%d ", unionArr[i]);
    }    

    // Intersection Array 
    intersectionCount = 0;
    for(i = 0 ; i < Arr1Elements ; i++)
    {
        for(j = 0 ; j < Arr2Elements ; j++)
        {
            if(i_arr1[i] == i_arr2[j])
            {
                intersectionArr[intersectionCount] = i_arr1[i];
                intersectionCount++;
            }
        }
    }

    // printing intersection Array 
    printf("\nIntersection Array Elements : \n");
    for(i = 0 ; i < intersectionCount ; i++)
    {
        printf("%d ", intersectionArr[i]);
    }      
}