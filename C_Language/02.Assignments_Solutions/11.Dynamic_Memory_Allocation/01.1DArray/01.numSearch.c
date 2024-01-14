#include<stdio.h>
#include<stdlib.h>
void main()
{
    int index, numElements, flag = 0;
    int *pointer = NULL, *numSearch = NULL;

    printf("How Many Elements Do You Want To Enter : \n");
    scanf("%d", &numElements);

    pointer = (int*)malloc(numElements * sizeof(int));

    printf("Enter Elements : \n");
    for(index = 0 ; index < numElements ; index++)
    {
        scanf("%d", (pointer + index));
    }
    numSearch = (int*)malloc(sizeof(int));
    printf("Enter Number To Be Searched : \n");
    scanf("%d", numSearch);

    for(index = 0 ; index < numElements ; index++)
    {
        if(*numSearch == *(pointer + index))
        {
            printf("%d found at index %d\n", *numSearch, index);
            flag = 1;
            break;
        }
    }
    if(flag == 0) 
    {
        printf("%d not found\n", *numSearch);
    }
    free(pointer);
    free(numSearch);
}