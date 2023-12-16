// I/P : 11 45 44 27 2 51 8 87 13 26 4
// O/P : 11 45 2 27 4 51 8 87 13 26 44
#include<stdio.h>
#define MAX_SIZE 100
int main()
{
    int temp, index, numElements, outerLoop, innerLoop;
    int i_arr[MAX_SIZE], tempArr[MAX_SIZE];
    printf("How Many Elements Do You Want To Enter In Array : \n");
    scanf("%d", &numElements);

    // Inputs In
    for(index = 0; index < numElements; index++)
    {
        scanf("%d", &i_arr[index]);
    }
    
    // Inputs Out
    printf("User Entered Array : \n");
    for(index = 0; index < numElements; index++)
    {
        printf("%d ", i_arr[index]);
    }
    printf("\n");

    for(index = 0; index < numElements; index++)
    {
        if(i_arr[index] % 2 != 0)
        {
            tempArr[index] = 0;
        }
        else
        {
            tempArr[index] = i_arr[index];
        }
    }

    // // Inputs Out
    // for(index = 0; index < numElements; index++)
    // {
    //     printf("%d ", tempArr[index]);
    // } 
    // printf("\n");   

    // Sorting of only non-zero values

    for(outerLoop = 0; outerLoop < numElements; outerLoop++)
    {
        for(innerLoop = outerLoop + 1; innerLoop< numElements; innerLoop++)
        {
            if(tempArr[outerLoop] > tempArr[innerLoop] && tempArr[innerLoop] != 0 && tempArr[outerLoop] != 0)
            {
            // Swapping Of Non Zero Values
            temp = tempArr[outerLoop];
            tempArr[outerLoop] = tempArr[innerLoop]; 
            tempArr[innerLoop]= temp;
            }
        }
    }

    // // Inputs Out
    // for(index = 0; index < numElements; index++)
    // {
    //     printf("%d ", tempArr[index]);
    // }  
    // printf("\n");  

    for(index = 0; index < numElements; index++)
    {
        if(tempArr[index] == 0)
        {
            tempArr[index] = i_arr[index];
        }
    }

    // Inputs Out (Final)

    printf("Sorted Array : \n");

    for(index = 0; index < numElements; index++)
    {
        printf("%d ", tempArr[index]);
    }


    return 0;
}