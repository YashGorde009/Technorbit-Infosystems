#include<stdio.h>
#include<stdlib.h>
void main()
{
    int i, j, numElements, currentSum = 0, leastDifference = 2147483647, num1, num2;
    int *arr = NULL, *givenNum = NULL;
    printf("How Many Number To Entered Inside Array : \n");
    scanf("%d", &numElements);
    arr = (int*)malloc(numElements * sizeof(int));
    printf("Enter Array Elements : \n");
    for(i = 0 ; i < numElements ; i++)
    {
        scanf("%d", (arr + i));
    }
    givenNum = (int*)malloc(sizeof(int));
    printf("Give A Number : \n");
    scanf("%d", givenNum);

    for(i = 0 ; i < numElements ; i++)
    {
        for(j = 0 ; j < numElements ; j++)
        {
            currentSum = *(arr + i) + *(arr + j);

            // Check if the current currentSum is greater than the given number
            if(currentSum > *givenNum) 
            {
                // Check if the difference is smaller than the current least difference
                if(leastDifference > (currentSum - *givenNum)) {
                        leastDifference = currentSum - *givenNum;
                        num1 = *(arr + i);
                        num2 = *(arr + j);
                }
            }
            else
            {   // Check if the difference is smaller than the current least difference
                if(leastDifference > (*givenNum - currentSum)) {
                        leastDifference = *givenNum - currentSum;
                        num1 = *(arr + i);
                        num2 = *(arr + j);
                }
            }
        }
    }
    printf("Number1 : %d \nNumber2 : %d\nCloset currentSum : %d\n", num1, num2, num1 + num2);
    free(arr);
    free(givenNum);
}