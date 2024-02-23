#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void input(int*, int);
void display(int*, int N, const char*);
void insertion_sort(int*, int);

void main()
{
    int* arr = NULL;
    int N;
    time_t start_time, end_time, delta_time;

    puts("Enter Size Of Array : ");
    scanf("%d", &N);

    if(N < 0)
    {
        puts("Invalid Input Array Size");
        exit(EXIT_FAILURE);
    }

    arr = (int*)malloc(N * sizeof(int));

    if(arr == NULL)
    {
        puts("Memory Allocation Error");
        exit(EXIT_FAILURE);
    }

    input(arr, N);

    display(arr, N, "Before Sorting...");

    start_time = time(0);

    insertion_sort(arr, N);

    end_time = time(0);

    delta_time = end_time - start_time;

    printf("Total Elapsed Time : %ld\n", delta_time);
    
    display(arr, N, "After Sorting...");

    free(arr);
    arr = NULL;
    
    exit(EXIT_SUCCESS);
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

    for(i = 0 ; i < N ; i++)
    {
        printf("%d ", arr[i]);
    }
}

void insertion_sort(int* arr, int N)
{
    int i, key, empty;

    for(i = 0 ; i < N ; i++)
    {
        key = arr[i];
        empty = i;
        while(empty > 0 && arr[empty-1] > key)
        {
            arr[empty] = arr[empty-1];
            empty--;
        }
        arr[empty] = key;
    }
    printf("\n");
}

