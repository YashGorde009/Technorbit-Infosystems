#include<stdio.h>
#include<stdlib.h>
#include<time.h>

enum boolean{FALSE = 0, TRUE = 1} flag;

void input(int*, int);
void display(int*, int, const char*);
void linear_search_iterative(int*, int, int);
int linear_search_recursive(int*, int, int, int);
void merge_sort(int*, int, int);
void merge_procedure(int*, int, int, int);
void binary_search_iterative(int*, int, int, int);
int binary_search_recursive(int*, int, int, int);

void main()
{
    int* arr = NULL; //array(arr)
    int N, num_search, idx; // array_size(N), number_to_be_searched(num_search), index(idx)

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

    merge_sort(arr, 0, (N-1));

    display(arr, N, "Sorted Array Elements Are...");
    
    puts("Enter No.To Be Searched :");
    scanf("%d", &num_search);

    // linear_search_iterative(arr, N, num_search);

    idx = linear_search_recursive(arr, num_search, 0, N);

    // binary_search_iterative(arr, num_search, 0, (N-1));

    // idx = binary_search_recursive(arr, num_search, 0, (N-1));

    if(idx == -1)
    {
        puts("Number Not Found...");
    }
    else
    {
       printf("Number Found At Index : %d\n", idx); 
    }

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

void linear_search_iterative(int* arr, int N, int num_search)
{
    int i;
    flag = FALSE;
    for(i = 0 ; i < N ; i++)
    {
        if(arr[i] == num_search)
        {
            printf("Number Found At Index : %d\n", i);
            flag = TRUE;
            break;

        }
    }
    if(!flag)
    {
        printf("Number Not Found");
    }
}

int linear_search_recursive(int* arr, int num_search, int idx, int N)
{
    if(idx == N)
        return -1;

    if(num_search == arr[idx])
    {
        return idx;
    }
    else
    {
        linear_search_recursive(arr, num_search, idx+1, N);
    }
}

void merge_sort(int* arr, int low, int high)
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

    int* arr1 = NULL; // array_1(arr1)
    int* arr2 = NULL; // array_2(arr2)

    int N1 = q - p + 1; // size_of_array_1(N1)
    int N2 = r - q; // size_of_array_2(N2)

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
    arr1 = NULL;
    free(arr2);
    arr2 = NULL;
}

void binary_search_iterative(int* arr, int num_search, int low, int high)
{
    int mid;

    flag = FALSE;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(arr[mid] == num_search)
        {
            printf("Number Found At Index : %d\n", mid);
            flag = TRUE;
            break;
        }

        if(arr[mid] < num_search)
        {
            low = mid + 1;
        }

        if(arr[mid] > num_search)
        {
            high = mid - 1;
        }
    }
    if(!flag)
    {
        puts("Number Not found");
    }
}

int binary_search_recursive(int* arr, int num_search, int low, int high) // lower_boundary(low), higher_boundary(high)
{
    int mid; 

    if(low <= high)
    {
        mid = (low + high) / 2;

        if(num_search == arr[mid])
        {
            return mid;
        }
        if(num_search < arr[mid])
        {
            return binary_search_recursive(arr, num_search, low, mid-1);
        }
        if(num_search > arr[mid])
        {
            return binary_search_recursive(arr, num_search, mid+1, high);
        }
    }
    return -1;
}