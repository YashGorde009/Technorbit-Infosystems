#include<stdio.h>
#include<stdlib.h>
#include<time.h>

enum boolean{FALSE = 0, TRUE = 1};

void input(int*, int);
void display(int*, int N, const char*);
void bubble_sort(int*, int N);
void swap(int*, int*);

void main() 
{
    int* arr;
    int N;
    time_t start_time, end_time, delta_time;

    puts("Enter Size of Array : ");
    scanf("%d", &N);

    if(N < 0)
    {
        puts("Invalid Input Array Size...");
        exit(EXIT_FAILURE);
    }

    arr = (int*)malloc(N * sizeof(int));

    if(arr == NULL)
    {
        puts("Memory Allocation Error...");
        exit(EXIT_FAILURE);
    }

    input(arr, N);

    display(arr, N, "Before Sorting...");

    start_time = time(0);

    bubble_sort(arr, N);

    end_time = time(0);

    delta_time = end_time - start_time;

    printf("Total elapsed time is = %ld\n", delta_time);
    
    display(arr, N, "After Sorting...");

    free(arr);
    arr = NULL;
}

void input(int* arr, int N)
{
    int i;

   srand(time(0)); 

   for(i = 0 ; i < N ; i++)
   {
        arr[i] = rand();
   }
}

void display(int* arr, int N, const char* msg)
{
    int i;

    if(msg != NULL)
        puts(msg);

    for(i = 0; i < N ; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void bubble_sort(int* arr, int N)
{
    int itr, i; // No. Of Iteration(itr), iterator(i)

    enum boolean flag;

    for(itr = 1 ; itr < N ; itr++)
    {
        flag = FALSE;

        for(i = 0 ; i < N-itr ; i++)
        {
            if(arr[i] > arr[i+1])
            {
                swap(&arr[i], &arr[i+1]); 
                flag = TRUE;
            }
        }

        if(!flag)
        {
            break;
        }
    }
}

void swap(int* num1, int* num2)
{
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}