#include<stdio.h>
#include<stdlib.h>
#include<time.h>

enum boolean{FALSE = 0, TRUE = 1} flag;

void input(int*, int);
void display(int*, int, const char*);
void selection_sort(int*, int);
void bubble_sort(int*, int);
void insertion_sort(int*, int);
void merge_sort(int*, int, int);
void merge_procedure(int*, int, int, int);
void quick_sort(int*, int, int);
int partition(int*, int, int);
void swap(int*, int*);

void main()
{
    int* arr = NULL; //array(arr)
    int N; // array_size(N)
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

    display(arr, N, "Before Sorting...");

    start_time = time(0);

    // selection_sort(arr, N);

    // bubble_sort(arr, N);

    // insertion_sort(arr, N);

    // merge_sort(arr, 0, (N-1));

    quick_sort(arr, 0, (N-1));

    end_time = time(0);
    
    delta_time = end_time - start_time;

    display(arr, N, "After Sorting...");
    
    printf("Total Time Elapsed : %ld\n", delta_time);

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

void display(int* arr, int N, const char* msg) //message(msg)
{
    int i;

    if(msg != NULL)
        puts(msg);

    for(i = 0 ; i < N ; i++)
        printf("%d  ", arr[i]);

    puts("");
}

void selection_sort(int* arr, int N)
{
    int i, j;

    for(i = 0 ; i < N ; i++)
    {
        flag = FALSE;
        for(j = (i+1) ; j < N ; j++)
        {
            if(arr[i] > arr[j])
            {
                swap(&arr[i], &arr[j]);
                flag = TRUE;
            }
        }
        if(!flag)
        {
            break;
        }
    }
}

void bubble_sort(int* arr, int N)
{
    int itr, i; // no._of_iterations(itr), iterator(i)
    for(itr = 1 ; itr < N ; itr++)
    {
        flag = FALSE;
        for(i = 0 ; i < (N-itr) ; i++)
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

void insertion_sort(int* arr, int N)
{
    int i, empty, key;
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
}

void merge_sort(int* arr, int low, int high) //lower_boundary(low), higher_boundary(high)
{
    int mid;
    if(low < high)
    {
        mid = (low + high) / 2;

        merge_sort(arr, low, mid);
        merge_sort(arr, (mid+1), high);
        merge_procedure(arr, low, mid, high);
    }
}

void merge_procedure(int* arr, int p, int q, int r)
{
    int i, j, k;

    int* arr1 = NULL; //array_1(arr1)
    int* arr2 = NULL; //array_2(arr2)

    int N1 = q - p + 1; // size_of_array1(N1);
    int N2 = r - q; // size_of_array2(N2);

    arr1 = (int*)malloc(N1 * sizeof(int));
    if(arr1 == NULL)
    {
        puts("Memory Allocation Error...");
        exit(EXIT_FAILURE);
    }

    arr2 = (int*)malloc(N2 * sizeof(int));
    if(arr2 == NULL)
    {
        puts("Memory Allocation Error...");
        exit(EXIT_FAILURE);
    }

    for(i = 0 ; i < N1 ; i++)
    {
        arr1[i] = arr[p+i];
    }

    for(i = 0 ; i < N2 ; i++)
    {
        arr2[i] = arr[q+1+i];
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
    arr2 = NULL;
    free(arr2);
    arr1 = NULL;
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
    int j, temp; // temporary(temp)
    
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

    return (i+1);
}

void swap(int* num1, int* num2)
{
    int temp;
    temp = *num1; 
    *num1 = *num2;
    *num2 = temp;
}