// 5. Write a C program to replace the n1 node with the n2 node from same linked list.
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
void replace_n1_n2_nodes(struct node**, int);


void main() 
{
    int i, length, position1, position2;
    struct node* first_node = NULL;

    puts("Enter Length Of Linked List...");
    scanf("%d", &length);

    srand(time(0));

    for(i = 1 ; i <= length ; i++)
    {
        create_linked_list(&first_node);
    }

    display_linked_list(first_node, "Before Linked List Is...");

    replace_n1_n2_nodes(&first_node, length);

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

void replace_n1_n2_nodes(struct node** head, int length)
{
    int i, pos1, pos2; // pos1(position1), pos2(position2)
    struct node* trav_node1 = *head;
    struct node* trav_node2 = *head;
    struct node* temp_node1 = NULL;
    struct node* temp_node2 = NULL;

    if(*head == NULL)
    {
        puts("Linked List Is Empty...");
        return;
    }

    puts("Enter Position 1 : ");
    scanf("%d", &pos1);
    puts("Enter Position 2 : ");
    scanf("%d", &pos2);

    if(pos1 == pos2)
    {
        return;
    }
    else if(pos1 < 1 || pos2 <= 1 || pos1 > length || pos2 > length)
    {
        puts("Invalid Positions...");
        replace_n1_n2_nodes(head, length);
    }
    else if(pos1 == 1)
    {   
        temp_node1 = *head;

        for(i = 1 ; i < (pos2 - 1) ; i++)
        {
            trav_node1 = trav_node1 -> next;
        }

        temp_node2 = trav_node1 -> next;

        *head = temp_node2;
        (*head) -> next = temp_node1 -> next;
        trav_node1 -> next = temp_node1;                // FIXME 
        trav_node1 -> next -> next = temp_node2 -> next;
        
    }
    else
    {
        for(i = 1 ; i < (pos1-1) ; i++)
        {
            trav_node1 = trav_node1 -> next;
        }
        temp_node1 = trav_node1 -> next;

        for(i = 1 ; i < (pos2-1) ; i++)
        {
            trav_node2 = trav_node2 -> next;
        }
        temp_node2 = trav_node2 -> next;

        trav_node1 -> next = trav_node2 -> next;
        trav_node1 -> next -> next = temp_node1 -> next; // FIXME
        trav_node2 -> next = temp_node1;
        trav_node2 -> next -> next = temp_node2 -> next;        
    }

}

