#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node
{
    int data;
    int priority;
    struct node* next;
};

void create_queue(struct node**, int);
void display(struct node*);
void dequeue(struct node**);
void peek(struct node*);

int main(void)
{
    int choice, size;
    struct node* front = NULL;

    puts("Enter size of queue :");
    scanf("%d", &size);
    create_queue(&front, size);

    do
    {
        puts("1. Display");
        puts("2. Dequeue");
        puts("3. Peek");
        puts("0. Exit");

        puts("Enter your choice");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1 : display(front);
                     break;

            case 2 : dequeue(&front);
                     break;

            case 3 : peek(front);
                     break;

            default : puts("Invalid choice");
        }
    } while(choice != 0);

    return 0;
}

void create_queue(struct node** head, int size)
{
    int i, data, priority;
    struct node* run = NULL;
    struct node* run_before = NULL;

    srand(time(0));

    for(i = 1 ; i <= size ; i++)
    {
        struct node* new_node = NULL;
        new_node = (struct node*)malloc(sizeof(struct node));

        if(new_node == NULL)
        {
            fprintf(stderr, "Error in memory allocation\n");
            exit(EXIT_FAILURE);
        }

        new_node->data = rand() % 100;
        new_node->priority = rand() % 100;
        new_node->next = NULL;

        if(*head == NULL)
        {
            *head = new_node;
        }
        else if(*head == NULL || (*head)->priority > new_node->priority)
        {
            new_node->next = *head;
            *head = new_node;
        }
        else
        {
            run = *head;

            while((run != NULL) && (run->priority <= new_node->priority))
            {
                run_before = run;
                run = run->next;
            }
            new_node->next = run;
            run_before->next = new_node;
        }
    }
}

void display(struct node* head)
{
    struct node* run = head;

    if(head == NULL)
    {
        fprintf(stderr, "Queue empty\n");
        return;
    }

    printf("[Start]-> ");
    while(run != NULL)
    {
        printf("[D:%d|P:%d] -> ", run->data, run->priority);
        run = run->next;
    }
    puts("[End]");
}

void dequeue(struct node** head)
{
    struct node* temp = NULL;
    if(*head == NULL)
    {
        fprintf(stderr, "Queue empty\n");
        return;
    }

    printf("Dequeue element : [D:%d|P:%d]\n", (*head)->data, (*head)->priority);

    temp = *head;
    *head= (*head)->next;
    free(temp);
}

void peek(struct node* head)
{
    if(head == NULL)
    {
        fprintf(stderr, "Queue empty\n");
        return;
    }
    printf("Peek element : [D:%d|P:%d]\n", head->data, head->priority);
}