// 2. Write a C program to search for a given element in a given linked list.
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
int recursive_linear_search(struct node*, int, int);

void main() 
{
    int i, length, num_search, position;
    struct node* first_node = NULL;

    puts("Enter Length Of Linked List...");
    scanf("%d", &length);

    srand(time(0));

    for(i = 1 ; i <= length ; i++)
    {
        create_linked_list(&first_node);
    }

    display_linked_list(first_node, "Linked List Is...");

    puts("Enter Element To Be Searched :");
    scanf("%d", &num_search);

    position = recursive_linear_search(first_node, num_search, 1);

    if(position == -1)
    {
        printf("%d Doesn't Exists Inside Linked List...\n", num_search);
    }
    else
    {
        printf("%d Found At %dth Node\n", num_search, position);
    }

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

int recursive_linear_search(struct node* head, int num_search, int position)
{
    if(head != NULL)
    {
        if(head -> data == num_search)
        {
            return position;
        }
        return recursive_linear_search((head -> next), num_search, (position+1));
    }
    return -1;
}

