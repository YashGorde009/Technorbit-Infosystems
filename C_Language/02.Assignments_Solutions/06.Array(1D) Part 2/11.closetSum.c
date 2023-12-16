// 11. Write a C program to create an array of n elements using static memory allocation to Find the two Elements such that their Sum is Closest to given number
#include<stdio.h>
void main()
{
    int index, numElements, givenNum, i, j, flag = 0, temp;
    int i_arr[100];

    printf("How Many Elements Do You Want To Enter In Array : \n");
    scanf("%d", &numElements);

    printf("Enter Array Elements : \n");

    // Inputs In
    for(index = 0 ; index < numElements ; index++)
    {
        scanf("%d", &i_arr[index]);
    }

    printf("\nEnter givenNum : \n");
    scanf("%d", &givenNum);
    
    temp = givenNum;

    givenNum -= 1;

    // checking for the closet sum for the givenNum
    while(givenNum >= 0)
    {
        for(i = 0 ; i < numElements ; i++)
        {
            for(j = i + 1 ; j < numElements ; j++)
            {
                if(i_arr[i] + i_arr[j] == givenNum)
                {
                    // Enters inside only if match found
                    printf("%d & %d with closet sum %d to %d\n",i_arr[i], i_arr[j], i_arr[i] + i_arr[j], temp);
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
            {
                break;
            }
        }
        if(flag == 1)
        {
            break;
        }
        givenNum--;
    }
}

