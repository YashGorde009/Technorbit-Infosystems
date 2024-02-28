#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int *arr;
    int capacity;
    int front;
    int rear;
};

struct Queue* create_queue();

int main(void) 
{
    struct Queue* queue = NULL;

    queue = create_queue();
    return 0;
}


struct Queue* create_queue()
{
    struct Queue* queue = NULL;
    queue = (struct Queue*)malloc(sizeof(struct Queue));

    if(queue == NULL)
    {
        fprintf(stderr, "Error in memory allocation");
        exit(EXIT_FAILURE);
    }

    puts("Enter capacity :");
    scanf("%d", &(queue->capacity));

    queue->arr = (int*)malloc((queue->capacity) * sizeof(int));

    if(queue->arr == NULL)
    {
        fprintf(stderr, "Error in memory allocation");
        exit(EXIT_FAILURE);
    }

    queue->front = -1;
    queue->rear = -1;

    return queue;
}

