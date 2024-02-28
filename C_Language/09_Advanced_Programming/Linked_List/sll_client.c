#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "sll.h"

void main() 
{
    status_t status;
    sll_t* p_list = NULL;
    data_t data, p_start_data, p_end_data;
    len_t length;

    p_list = create_list();
    show_list(p_list, "After create list");

    status = insert_start(p_list, 10);
    assert(status == SUCCESS);
    show_list(p_list, "After insert start");

    status = insert_end(p_list, 20);
    assert(status == SUCCESS);
    show_list(p_list, "After insert start");

    status = insert_start(p_list, 30);
    assert(status == SUCCESS);
    show_list(p_list, "After insert start");

    status = insert_start(p_list, 40);
    assert(status == SUCCESS);
    show_list(p_list, "After insert start");
    
    status = insert_start(p_list, 50);
    assert(status == SUCCESS);
    show_list(p_list, "After insert start");

    status = insert_start(p_list, 60);
    assert(status == SUCCESS);
    show_list(p_list, "After insert start");

    status = insert_end(p_list, 70);
    assert(status == SUCCESS);
    show_list(p_list, "After insert end");

    status = insert_after(p_list, 30, -5000);
    assert(status == SUCCESS);
    show_list(p_list, "After insert after");

    status = insert_before(p_list, 60, -9000);
    assert(status == SUCCESS);
    show_list(p_list, "After insert before");

    status = get_start(p_list, &data);
    assert(status == SUCCESS);
    printf("Start data = [%d]\n", data);

    status = get_end(p_list, &data);
    assert(status == SUCCESS);
    printf("End data = [%d]\n", data);

    
    // assignment_part

    // 1

    status = remove_start(p_list);
    assert(status == SUCCESS);
    show_list(p_list, "After remove start");

    // 2

    status = remove_end(p_list);
    assert(status == SUCCESS);
    show_list(p_list, "After remove end");

    // 3

    status = remove_data(p_list, -5000);
    assert(status == SUCCESS);
    show_list(p_list, "After remove data");

    // 4

    status = pop_start(p_list, &p_start_data);
    assert(status == SUCCESS);
    printf("Popped start data = [%d]\n", p_start_data);

    // 5

    status = pop_end(p_list, &p_end_data);
    assert(status == SUCCESS);
    printf("Popped end data = [%d]\n", p_end_data);

    // 6

    status = is_list_empty(p_list);
    assert(status == SUCCESS);
    

    // 7

    status = find(p_list, 30);
    assert(status == TRUE);

    // 8

    length = get_list_length(p_list);
    printf("List length : %d\n", length);

    // 6

    status = clear_list(p_list);
    assert(status == SUCCESS);
    show_list(p_list, "After clear list");

    // 10

    status = destroy_list(&p_list);
    assert(status == SUCCESS); 
    
    // assignment_part
}