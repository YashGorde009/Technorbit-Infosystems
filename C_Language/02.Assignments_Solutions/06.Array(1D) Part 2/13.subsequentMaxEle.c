// 13.Write a C program to create an array of n elements using static memory allocation to find 2 subsequent elements whose sum is maximum.
#include<stdio.h>
void main() 
{
    int index, numElements, maximum = -2147483648;
    int i_arr[100];
    printf("How Many Array Elements Do You Want To Enter : \n");
    scanf("%d", &numElements);

    if(numElements <= 1)
    {
        printf("Insufficient Array Elements...\n");
    }
    else
    {
    printf("Enter Array Elements : \n");
    // Inputs In
    for(index = 0 ; index < numElements ; index++)
    {
        scanf("%d", &i_arr[index]);
    }

    // Looking for maximum Sum 
    for(index = 0 ; index < numElements - 1 ; index++)
    {
        if(i_arr[index] + i_arr[index + 1] > maximum)
        {
            maximum = i_arr[index] + i_arr[index + 1];
        }
    }

    // Looking for the subsequent elements whos sum comes to be maximum
    for(index = 0 ; index < numElements - 1 ; index++)
    {
        if(i_arr[index] + i_arr[index + 1] == maximum)
        {
            printf("Element 1 : %d\nElement 2 : %d\nmaximum : %d\n", i_arr[index], i_arr[index + 1], i_arr[index] + i_arr[index + 1]);
        }
    }
    }
}