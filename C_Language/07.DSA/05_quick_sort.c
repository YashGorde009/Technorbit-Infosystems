#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void input(int*, int);
void display(int*, int, const char*);
void quick_sort(int*, int, int);
int partition(int*, int, int);

void main() 
{
    int* arr = NULL; // array(arr)
    int N; // array_size(N)

    puts("Enter Size Of Array : ");
    scanf("%d", &N);

    if(N < 0)
    {
        puts("Invalid Array Size...");
        exit(EXIT_FAILURE);
    }

    arr = (int*)malloc(N * sizeof(int));

    if(arr == NULL)
    {
        puts("Memory Allocation Error...");
        exit(EXIT_FAILURE);
    }

    input(arr, N);

    display(arr, N, "Before Quick Sort...");

    quick_sort(arr, 0, N-1);

    display(arr, N, "After Quick Sort...");

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

void display(int* arr, int N, const char* msg) // message(msg)
{
    int i;
    if(msg != NULL)
        puts(msg);

    for(i = 0 ; i < N ; i++)
    {
        printf("%d  ", arr[i]);
    }
    puts("");
}

void quick_sort(int* arr, int p, int r)
{
    int q;
    if(p < r)
    {
        q = partition(arr, p, r);
        quick_sort(arr, p, q-1);
        quick_sort(arr, q+1, r);
    }
}

int partition(int* arr, int p, int r)
{
    int i = p - 1;
    int pivot = arr[r];
    int j, temp;

    for(j = p ; j < r ; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j]; // swapping
            arr[j] = temp;  
        }

    }
    temp = arr[i+1];
    arr[i+1] = arr[r]; // swapping
    arr[r] = temp;

    return (i + 1);
}