#include<stdio.h>
#include<stdlib.h>
void main() 
{
    int index, delPosition, numElements, temp;
    int *array = NULL;

    printf("How Many Element Do You Want To Enter : \n");
    scanf("%d", &numElements);
    array = (int*)malloc(numElements * sizeof(int));
    
    printf("Enter Array Elements : \n");

    for(index = 0 ; index < numElements ; index++)
    {
        scanf("%d", (array + index));
    }

    printf("Before Deletion : \n");

    for(index = 0 ; index < numElements ; index++)
    {
        printf("%d  ", *(array + index));
    }

    printf("\nEnter Position To Be Deleted *(0-%d) : \n", numElements - 1);
    scanf("%d", &delPosition);

    for(index = delPosition ; index < numElements ; index++)
    {
        *(array + index) = *(array + index + 1);
    }

    printf("After Deletion : \n");

    for(index = 0 ; index < numElements - 1 ; index++)
    {
        printf("%d  ", *(array + index));
    }

    free(array);
   
}