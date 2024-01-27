#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TRUE 1

void input(int*, int);
void display(int*, int, const char*);
void merge_sort(int*, int, int);
void merge_procedure(int*, int, int, int);

void main() 
{
    int* arr = NULL; //array(arr)
    int N; //array_size(N)
    time_t start_time, end_time, delta_time;

    puts("Enter Array Size : ");
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

    display(arr, N, "Before Merge_Sort...");

    start_time = time(0);

    merge_sort(arr, 0, (N-1));

    end_time = time(0);

    delta_time = end_time - start_time;

    printf("Total Time Elapsed : %ld\n", delta_time);

    display(arr, N, "After Merge_Sort...");

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
        printf("%d  ", arr[i]);

    puts("");
}

void merge_sort(int* arr, int low, int high) // lower_boundary(low) higher_boundery(high)
{
    int mid; 

    if(low < high)
    {
        mid = (low + high) / 2;

        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge_procedure(arr, low, mid, high);
    }
}

void merge_procedure(int* arr, int p, int q, int r)
{
    int i, j, k;
    int N1 = q - p + 1; // length_of_array1(N1)
    int N2 = r - q; // length_of_array2(N2)

    int* arr1 = (int*)malloc(N1 * sizeof(int));
    
    if(arr1 == NULL)
    {
        puts("Memory Allocation Error...");
        exit(EXIT_FAILURE);
    }

    int* arr2 = (int*)malloc(N2 * sizeof(int));
    
    if(arr2 == NULL)
    {
        puts("Memory Allocation Error...");
        exit(EXIT_FAILURE);
    }

    for(i = 0 ; i < N1 ; i++)
    {
        arr1[i] = arr[p+i];
    }

    for(j = 0 ; j < N2 ; j++)
    {
        arr2[j] = arr[q+1+j];
    }

    i = 0;
    j = 0;
    k = 0;

    while(TRUE)
    {
        if(arr1[i] < arr2[j])
        {
            arr[p+k] = arr1[i];
            i++;
            k++;
            if(i == N1)
            {
                while(j < N2)
                {
                    arr[p+k] = arr2[j];
                    j++;
                    k++;
                }
                break;
            }
        }
        else
        {
            arr[p+k] = arr2[j];
            j++;
            k++;
            if(j == N2)
            {
                while(i < N1)
                {
                    arr[p+k] = arr1[i];
                    i++;
                    k++;
                }
                break;
            }
        }
    }
    free(arr1);
    arr1 = NULL;
    free(arr2);
    arr2 = NULL;
}

