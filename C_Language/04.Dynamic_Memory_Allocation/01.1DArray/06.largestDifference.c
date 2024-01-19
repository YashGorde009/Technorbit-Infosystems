#include<stdio.h>
#include<stdlib.h>
void main() {
    int index, numElements, min = 2147483647, max = -2147483648;
    int *ptr = NULL;

    printf("How Many Elements To Be Entered : \n");
    scanf("%d", &numElements);
    ptr= (int*)malloc(numElements * sizeof(int));
    printf("Enter %d Elements : \n", numElements);

    for(index = 0 ; index < numElements ; index++)
    {
        scanf("%d", (ptr + index));
    }

    for(index = 0 ; index < numElements ; index++)
    {
        if(max < *(ptr + index))
        {
            max = *(ptr + index);
        }
        if(min > *(ptr + index))
        {
            min = *(ptr + index);
        }
    }
    free(ptr);
    printf("Maximum: %d Mininum : %d Difference : %d\n",max, min, max - min);

}