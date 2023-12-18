#include<stdio.h>
#include<stdlib.h>
void main() 
{
    int i, numElements, num1, num2, sum = 0, maxSum = -2147483648;
    int *arr = NULL;
    printf("How Many Elements Would You Like To Input?\n");
    scanf("%d", &numElements);
    arr = (int*)malloc(numElements * sizeof(int));
    printf("Input Array Elements : \n");
    for(i = 0 ; i < numElements ; i++)
    {
        scanf("%d", (arr + i));
    }

    for(i = 0 ; i < numElements ; i++)
    { 
        if(i == (numElements - 1)) 
        {
            break;
        }

        sum = *(arr + i) + *(arr + i + 1);

        if(sum > maxSum) {
            maxSum = sum;
            num1 = i;
            num2 = i + 1;
        }
    }

    printf("%d and %d with maximum sum %d\n", *(arr + num1), *(arr + num2) , maxSum);
    free(arr);
}