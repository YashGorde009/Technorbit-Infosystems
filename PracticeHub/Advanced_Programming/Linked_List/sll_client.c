#include<stdio.h>
#include<stdlib.h>
#include "sll.h"

void main() 
{
    status_t status;
    sll_t* p_list = NULL;

    p_list = create_list();
    show_list(p_list, "After create list");

    status = insert_start(p_list, 10);
    show_list(p_list, "After insert start");
    status = insert_end(p_list, 20);
    show_list(p_list, "After insert start");
    status = insert_start(p_list, 30);
    show_list(p_list, "After insert start");
    status = insert_start(p_list, 40);
    show_list(p_list, "After insert start");
    status = insert_start(p_list, 50);
    show_list(p_list, "After insert start");
    status = insert_start(p_list, 60);
    show_list(p_list, "After insert start");
    status = insert_end(p_list, 70);
    show_list(p_list, "After insert end");
}