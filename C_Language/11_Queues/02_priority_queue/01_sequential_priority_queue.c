#include<stdio.h>
#include<stdlib.h>

struct element
{
    int data;
    int priority;
};

struct P_Queue
{
    struct element* arr ; 
    int capacity;
    int size;
};

struct P_Queue* create_queue(void);
int is_full(struct P_Queue* );
void Enqueue(struct P_Queue*);
void display(struct P_Queue*);
int is_empty(struct P_Queue*);
void dequeue(struct P_Queue*);

int main(void)
{
    int choice;
    struct P_Queue* p_queue=NULL;
    p_queue = create_queue();
    do
    {
        puts("1. Enqueue");
        puts("2. display");
        puts("0. Exit");

        puts("Enter your choice :");
        scanf("%d" , &choice);

        switch(choice)
        {
            case 1 : Enqueue(p_queue);
            break;

            case 2 : display(p_queue);
            break;

            case 3: dequeue(p_queue);
            break;

            default : puts("Invalid choice");
        }
    } while(choice != 0);

    return 0;
}

struct P_Queue* create_queue(void)
{
    int data,priority;
    struct P_Queue* p_queue = NULL;

    p_queue = (struct P_Queue*)malloc(sizeof(struct P_Queue));

    if(p_queue == NULL)
    {
        fprintf(stderr , "Error in memory allocation");
        exit(EXIT_FAILURE);
    }

    puts("\nEnter capacity ");
    scanf("%d",&(p_queue->capacity));

    p_queue->arr = (struct element*)malloc(p_queue->capacity * sizeof(struct element));

    if(p_queue->arr == NULL)
    {
        fprintf(stderr, "Error in memory Allocation");
        exit(EXIT_FAILURE);
    }
    p_queue->size = 0;

    return (p_queue);
}

void Enqueue(struct P_Queue* p_queue)
{
    int data , priority, i ;
    struct element temp;

    if(is_full(p_queue))
    {
        puts("\nPriority Queue is Full.");
        return;
    }
    
    puts("Enter Data ");
    scanf("%d" , &data);
    (p_queue->arr[p_queue->size]).data = data;

    puts("Enter Priority :");
    scanf("%d" , &priority);
    (p_queue->arr[p_queue->size]).priority= priority;  // max priority 

    (p_queue->size)++;

    for(i= (p_queue->size-1) ; i > 0 ; i--)
    {
        if((p_queue->arr[i]).priority > (p_queue->arr[i-1]).priority)
        {
            temp = p_queue->arr[i];
            p_queue->arr[i] = p_queue->arr[i-1];
            p_queue->arr[i-1]= temp;
        }
    }
}

int is_full(struct P_Queue* p_queue)
{
    return (p_queue->size == p_queue->capacity);
}

void display(struct P_Queue* p_queue)
{
    int i;
    printf("[Start]->");
    for(i = 0 ; i < p_queue->size ; i++)
    {
        printf("[D:%d|P:%d]->" , (p_queue->arr[i]).data, (p_queue->arr[i]).priority);
    }
    puts("[End]");
}


int is_empty(struct P_Queue* p_queue)
{
    return p_queue->size == 0;
}

void dequeue(struct P_Queue* p_queue)
{
    int i;
    if(is_empty(p_queue))
    {
        fprintf(stderr, "Queue empty\n");
        return;
    }

    for(i = 0 ; i < (p_queue->size-1) ; i++)
    {
        p_queue->arr[i] = p_queue->arr[i+1];
    }
    
    (p_queue->size)--;
}