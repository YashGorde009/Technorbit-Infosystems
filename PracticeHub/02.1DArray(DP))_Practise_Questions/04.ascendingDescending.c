#include<stdio.h>
#include<stdlib.h>
void main() 
{
    int i, j, numElements, temp;
    int *ptr = NULL;
    printf("How Many Elements To Be Entered : \n");
    scanf("%d", &numElements);
    ptr = (int*)malloc(numElements * sizeof(int));
    printf("Enter %d Elements : \n", numElements);

    for(i = 0 ; i < numElements ; i++)
    {
        scanf("%d", (ptr + i));
    }
    printf("Before : \n");
    for(i = 0 ; i < numElements ; i++)
    {
        printf("%d  ", *(ptr + i));
    }

    for(i = 0 ; i < numElements/2 ; i++)
    {
        for(j = i + 1 ; j < numElements/2 ; j++)
        {
            if(*(ptr + i) > *(ptr + j))
            {
                temp = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = temp;
            }
        }
    }

    for(i = numElements/2 ; i < numElements ; i++)
    {
        for(j = i + 1 ; j < numElements ; j++)
        {
            if(*(ptr + i) < *(ptr + j))
            {
                temp = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = temp;
            }
        }
    }
    printf("\n");
    printf("After : \n");
    for(i = 0 ; i < numElements ; i++)
    {
        printf("%d  ", *(ptr + i));
    }

    free(ptr);

}