// 1. Write a C program to sort a given linked list in ascending order.
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

enum boolean{FALSE = 0, TRUE = 1}flag;

struct node
{
    int data;
    struct node* next;
};

void create_linked_list(struct node**);
struct node* create_node();
void display_linked_list(struct node*, const char*);
void selection_sort(struct node*, int);

void main() 
{
    int i, length;
    struct node* first_node = NULL;

    puts("Enter Length Of Linked List...");
    scanf("%d", &length);

    srand(time(0));

    for(i = 1 ; i <= length ; i++)
    {
        create_linked_list(&first_node);
    }
    
    display_linked_list(first_node, "Before Linked List Is...");

    selection_sort(first_node, length);

    display_linked_list(first_node, "After Linked List Is...");


    exit(EXIT_SUCCESS);
}

void create_linked_list(struct node** head)
{
    struct node* new_node = NULL;
    struct node* trav_node = *head;

    new_node = create_node();

    if(*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        while(trav_node -> next != NULL)
        {
            trav_node = trav_node -> next;
        }
        trav_node -> next = new_node;
    }
}

struct node* create_node()
{
    struct node* new_node = NULL;
    new_node = (struct node*)malloc(sizeof(struct node));

    if(new_node == NULL)
    {
        puts("Error In Memory Allocation...");
        exit(EXIT_FAILURE);
    }

    new_node -> data = rand() % 10;
    new_node -> next = NULL;

    return new_node;
}

void display_linked_list(struct node* head, const char* msg) // msg(message)
{
    if(msg != NULL)
        puts(msg);

    if(head == NULL)
    {
        puts("Linked List Is Empty...");
        return;
    }
    while(head != NULL)
    {
        printf("%d => ", head -> data);
        head = head -> next;
    }
    puts("NULL");
}

void selection_sort(struct node* head, int length)
{
    int i, j, temp;
    struct node* trav_node1 = head;
    struct node* trav_node2 = head;

    for(i = 1 ; i < length ; i++)
    {
        flag = FALSE;
        trav_node2 = trav_node1->next;

        for(j = i+1 ; trav_node2 != NULL ; j++)
        {
            if((trav_node1 -> data) > (trav_node2 -> data))
            {
                temp = trav_node1 -> data;
                trav_node1 -> data = trav_node2 -> data;
                trav_node2 -> data = temp;
                flag = TRUE;
            }
            trav_node2 = trav_node2->next;
        }
        if(!flag)
        {
            break;
        }
        trav_node1 = trav_node1 -> next;
    }
}


