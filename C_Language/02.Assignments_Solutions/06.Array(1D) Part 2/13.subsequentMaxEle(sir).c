// 13.Write a C program to create an array of n elements using static memory allocation to find 2 subsequent elements whose sum is maximum.
#include<stdio.h>
void main()
{
    int i, numElements, currentNum, nextNum, maxSum = -2147483648;
    int i_arr[100];
    printf("How Many Elements Do You Want To Enter Insdie Array : \n");
    scanf("%d", &numElements);

    printf("Enter Array Elements : \n");
    for(i = 0 ; i < numElements ; i++)
    {
        scanf("%d", &i_arr[i]);
    }

    // check subsequent element with maximum sum
    for(i = 0 ; i < numElements - 1 ; i++)
    {
        if((i_arr[i] + i_arr[i + 1]) > maxSum) 
        {
             // Update maxSum and the currentNum & nextNum elements
            maxSum = i_arr[i] + i_arr[i + 1];
            currentNum = i_arr[i];
            nextNum = i_arr[i + 1];
        }
    }
    printf("Element 1 : %d\n", currentNum);
    printf("Element 2 : %d\n", nextNum);
    printf("Maximum Sum : %d\n", maxSum);
}