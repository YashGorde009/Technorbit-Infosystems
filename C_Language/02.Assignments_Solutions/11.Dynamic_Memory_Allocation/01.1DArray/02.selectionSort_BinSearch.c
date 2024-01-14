#include<stdio.h>
#include<stdlib.h>
void main() 
{
    int i, j, numElements, temp, lower = 0, middle, higher, flag = 0;
    int *database = NULL, *rollSearch = NULL;

    printf("How Many Rolls Calls To Be Entered : \n");
    scanf("%d", &numElements);

    database = (int*)malloc(numElements*sizeof(int));

    printf("Enter %d Rolls Calls : \n", numElements);

    for(i = 0 ; i < numElements ; i++) 
    {
        scanf("%d", (database + i));
    }

    // Sorting(selection Sort)
    for(i = 0 ; i < numElements ; i++)
    {
        for(j = i + 1 ; j < numElements ; j++)
        {
            if(*(database + i) > *(database + j)) 
            {
                temp = *(database + i);
                *(database + i) = *(database + j);
                *(database + j) = temp;
            }
        }
    }

    printf("SR.No\tRoll Calls\n");

    for(i = 0 ; i < numElements ; i++) 
    {
        printf("%d\t%d\n", (i+1), *(database + i));
    }

    printf("Roll Call To Be Searched : \n");
    rollSearch = (int*)malloc(sizeof(int));
    scanf("%d", rollSearch);

    //Binary Search 

    higher = numElements - 1;
    while(lower <= higher) 
    {
        middle = (lower + higher) / 2;

        if(*rollSearch == *(database + middle))
        {
            printf("%d Exist In Database At SR.No %d\n", *rollSearch, middle + 1);
            flag = 1;
            break;
        }
        else if(*rollSearch > *(database + middle)) 
        {
            lower = middle + 1;
        }
        else
        {
            higher = middle - 1;
        }
    }
    if(flag == 0) 
    {
        printf("%d Does Not Exist In SEIT Database\n");
    }
    free(database);
    free(rollSearch);
}