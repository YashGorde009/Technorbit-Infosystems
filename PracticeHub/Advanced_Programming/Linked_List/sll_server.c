#include<stdio.h>
#include<stdlib.h>
#include "sll.h"

sll_t* create_list(void)
{
    return (get_node(0));
}

node_t* get_node(data_t new_data)
{
    node_t* new_node = NULL;

    new_node = (node_t*)xmalloc(sizeof(node_t));
    new_node -> data = new_data;
    new_node -> next = NULL;

    return (new_node);
}

void* xmalloc(size_t size_in_bytes)
{
    void* ptr = NULL;

    ptr = malloc(size_in_bytes);

    if(ptr == NULL)
    {
        fprintf(stderr, "Error in memory allocation");
        exit(EXIT_FAILURE);
    }

    return (ptr);
}

void show_list(sll_t* p_list, const char* msg)
{
    node_t* run = NULL;
    if(msg != NULL)
        puts(msg);

    run = p_list->next;

    printf("[start]->");
    while(run != NULL)
    {
        printf("[%d]->", run -> data);
        run = run->next;
    }
    puts("[End]->");
}

status_t insert_start(sll_t* p_list, data_t new_data)
{
    node_t* new_node = NULL;

    new_node = get_node(new_data);
    new_node->next = p_list->next;
    p_list->next = new_node;

    return (SUCCESS);
}

status_t insert_end(sll_t* p_list, data_t new_data)
{
    node_t* run = NULL;

    run = p_list->next;
    
    while(run->next != NULL)
    {
        run = run->next;
    }
    run->next = get_node(new_data);

    return (SUCCESS);
}

status_t insert_after(sll_t* p_list, data_t e_data, data_t new_data)
{
    node_t* run = NULL;
    node_t* new_node = NULL;

    run = p_list->next;

    while(run != NULL)   
    {
        if(run->data == e_data)
        {
            new_node = get_node(new_data);
            new_node->next = run->next;
            run->next = new_node;

            return (SUCCESS);
        }
        run = run->next;
    }
    
    return (LIST_DATA_NOT_FOUND);
}

status_t insert_before(sll_t* p_list, data_t e_data, data_t new_data)
{
    node_t* run = NULL;
    node_t* run_before = NULL;
    node_t* new_node = NULL;

    run = p_list->next;
    run_before = p_list;

    while(run != NULL)
    {
        if(run->data == e_data)
        {
            new_node = get_node(new_data);
            new_node->next = run; // run(run_before->next)
            run_before->next = new_node;

            return (SUCCESS);
        }
        run_before = run;
        run = run->next;
    }

    return (LIST_DATA_NOT_FOUND);
}


status_t get_start(sll_t* p_list, data_t* p_start_data)
{
    if(p_list->next == NULL)
        return (LIST_EMPTY);

    *p_start_data = p_list->next->data;
    return (SUCCESS);
}

status_t get_end(sll_t* p_list, data_t* p_end_data)
{
    node_t* run = NULL;

    if(p_list->next == NULL)
        return (LIST_EMPTY);

    run = p_list->next;
    while(run->next != NULL)
    {
        run = run->next;
    }
    *p_end_data = run->data;
    return (SUCCESS);
}


// assignment_part

// 1

status_t remove_start(sll_t* p_list)
{
    node_t* temp = NULL;

    if(p_list->next == NULL)
        return (LIST_EMPTY);

    temp = p_list->next;
    p_list->next = temp->next;

    free(temp);
    temp = NULL;

    return (SUCCESS);
}

// 2

status_t remove_end(sll_t* p_list)
{
    node_t* run = NULL;
    node_t* run_before = NULL;

    if(p_list->next == NULL)
        return (LIST_EMPTY);

    run = p_list->next;
    run_before = p_list;

    while(run->next != NULL)
    {
        run_before = run;
        run = run->next;
    }
    run_before->next = NULL;
    free(run);
    run = NULL;

    return (SUCCESS);
}

// 3

status_t remove_data(sll_t* p_list, data_t r_data)
{
    node_t* run = NULL;
    node_t* run_before = NULL;

    if(p_list->next == NULL)
        return (LIST_EMPTY);

    run = p_list->next;
    run_before = p_list;

    while(run != NULL)
    {
        if(run->data == r_data)
        {
            run_before->next = run->next;
            free(run);
            run = NULL;

            return (SUCCESS);
        }
        run_before = run;
        run = run->next;
    }

    return (LIST_DATA_NOT_FOUND);
}

// 4

status_t pop_start(sll_t* p_list, data_t* p_start_data)
{
    node_t* temp = NULL;

    if(p_list->next == NULL)
        return (LIST_EMPTY);

    *p_start_data = p_list->next->data;
    temp = p_list->next;
    p_list->next = temp->next;
    free(temp);
    temp = NULL;

    return (SUCCESS);
}

// 5

status_t pop_end(sll_t* p_list, data_t* p_end_data)
{
    node_t* run = NULL;
    node_t* run_before = NULL;

    if(p_list->next == NULL)
        return (LIST_EMPTY);

    run = p_list->next;
    run_before = p_list;

    while(run->next != NULL)
    {
        run_before = run;
        run = run->next;
    }
    *p_end_data = run->data;
    run_before->next = NULL;
    free(run);
    run = NULL;

    return (SUCCESS);
}

// 6

status_t clear_list(sll_t* p_list)
{
    node_t* run = NULL;

    if(p_list->next == NULL)
        return (LIST_EMPTY);

    run = p_list->next;

    while(run != NULL)
    {
        run->data = 0;
        run = run->next;
    }

    return (SUCCESS);
}

// 7

status_t is_list_empty(sll_t* p_list)
{
    if(p_list->next == NULL)
        return (LIST_EMPTY);

    return (SUCCESS);
}

// 8

status_t find(sll_t* p_list, data_t f_data)
{
    node_t* run = NULL;

    run = p_list->next;

    while(run != NULL)
    {
        if(run->data == f_data)
        {
            return (TRUE);
        }
        run = run->next;
    }
    return (FALSE);
}

// 9

len_t get_list_length(sll_t* p_list)
{
    counter_t count = 0;
    node_t* run = NULL;

    if(p_list->next == NULL)
        return (LIST_EMPTY);

    run = p_list->next;
    while(run != NULL)
    {
        count++;
        run = run->next;
    }

    return (count);
}

// 10

status_t destroy_list(sll_t** p_list)
{
    node_t* run = NULL;
    node_t* run_after = NULL;

    if((*p_list)->next == NULL)
        return (LIST_EMPTY);

    run = (*p_list)->next;
    run_after = run->next;

    while(run_after != NULL)
    {
        free(run);
        run = NULL;
        run = run_after->next;
        free(run_after);
        run_after = NULL;

        run_after = run->next;
    }
    (*p_list)->next = NULL;

    return (SUCCESS);
}

// assignment_part
