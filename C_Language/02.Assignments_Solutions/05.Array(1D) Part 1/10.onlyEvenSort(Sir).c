#include<stdio.h>
#define MAX_SIZE 100
int main()
{
    int numElements, index, tempIndex = 0, outerLoop, innerLoop, temp;
    int i_arr[MAX_SIZE], tempArr[MAX_SIZE];
    printf("How Many Elements Do You Want To Enter Into Array : \n");
    scanf("%d", &numElements);
    printf("Enter Array Elements : \n");
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

    // Extracting Only Even Number From i_arr[] into tempArr[]

    for(index = 0; index < numElements; index++)
    {
        if(i_arr[index] % 2 == 0)
        {
            tempArr[tempIndex] = i_arr[index];
            tempIndex++;
        }
    }

    // Sorting tempArr[]

    for(outerLoop = 0; outerLoop < tempIndex; outerLoop++)
    {
        for(innerLoop = outerLoop + 1; innerLoop < tempIndex; innerLoop++)
        {
            if(tempArr[outerLoop] > tempArr[innerLoop])
            {
                temp = tempArr[outerLoop]; 
                tempArr[outerLoop] = tempArr[innerLoop]; 
                tempArr[innerLoop] = temp; 
            }
        }
    }
    
    // Replacing the even elements withing i_arr[] with sorted even Elements of tempArr[]
    tempIndex = 0;
    for(index = 0; index < numElements; index++)
    {
        if(i_arr[index] % 2 == 0)
        {
            i_arr[index] = tempArr[tempIndex];
            tempIndex++;
        }
    }

    // Sorted Inputs Out
    printf("Sorted Array : \n");
    for(index = 0; index < numElements; index++)
    {
        printf("%d ", i_arr[index]);
    }

    return 0;
}