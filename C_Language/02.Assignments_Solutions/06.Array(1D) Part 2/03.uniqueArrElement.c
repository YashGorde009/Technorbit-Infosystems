// 3. Write a C program to create an array of n elements using static memory allocation to print all unique elements in an array.
#include<stdio.h>
void main()
{
    int numElements, index, outerLoop, innerLoop, flag;
    int i_arr[100];
    printf("How Many Element Do You Want To Enter : \n");
    scanf("%d", &numElements);

    printf("Enter Array Elements : \n");
    
    // Inputs In
    for(index = 0 ; index < numElements ; index++)
    {
        scanf("%d", &i_arr[index]); 
    }


    //Checking each element whether it is repeated inside array
    for(outerLoop = 0 ; outerLoop < numElements ; outerLoop++)
    {   
        flag = 0;
        for(innerLoop = 0 ; innerLoop < numElements ; innerLoop++)
        {
            if(i_arr[outerLoop] == i_arr[innerLoop] && outerLoop != innerLoop)
            {
                flag++;
                break;
            }
        }
        if(flag == 0)
        {
            // Unique Ele... Printed
            printf("%d is Unique\n", i_arr[outerLoop]);
        }
    }
}