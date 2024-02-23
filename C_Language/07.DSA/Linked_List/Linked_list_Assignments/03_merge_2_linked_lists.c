// 3. Write a C program to merge two linked lists into one.
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node
{
    int data;
    struct node* next;
};

void create_linked_list(struct node**);
struct node* create_node();
void display_linked_list(struct node*, const char*);
void merge_2_linked_list(struct node**, struct node**, int, int);


void main() 
{
    int i, length1, length2, position1, position2;
    struct node* first_node1 = NULL; // first_node of first linked list
    struct node* first_node2 = NULL;// first_node of second linked list

    puts("Enter Length Of Linked List 1...");
    scanf("%d", &length1);

    srand(time(0));

    for(i = 1 ; i <= length1 ; i++)
    {
        create_linked_list(&first_node1);
    }
    
    display_linked_list(first_node1, "Linked List 1 Is...");

    puts("Enter Length Of Linked List 2...");
    scanf("%d", &length2);

    for(i = 1 ; i <= length2 ; i++)
    {
        create_linked_list(&first_node2);
    }

    display_linked_list(first_node2, "Linked List 2 Is...");

    merge_2_linked_list(&first_node1, &first_node2, length1, length2);

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

    new_node -> data = rand();
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

void merge_2_linked_list(struct node** head1, struct node** head2, int length1, int length2)
{
    int i;
    struct node* trav_node = *head1;

    if(*head1 == NULL)
    {
        *head1 = *head2;
        display_linked_list(*head1, "After Merge...");
        return;
    }

    if(*head2 == NULL)
    {
        display_linked_list(*head1, "After Merge...");
        return;
    } 

    for(i = 1 ; i < length1 ; i++)
    {
        trav_node = trav_node -> next;
    }

    trav_node -> next = *head2;

    display_linked_list(*head1, "After Merge...");
}


