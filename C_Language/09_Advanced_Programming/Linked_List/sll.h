#ifndef _SLL_H
#define _SLL_H

#include<stdio.h>
#define FALSE					0
#define TRUE					1
#define SUCCESS 				2
#define LIST_EMPTY          	3
#define LIST_DATA_NOT_FOUND 	4

struct node 
{
	int data;
	struct node* next;
};

typedef int data_t;
typedef int status_t;
typedef struct node node_t;
typedef node_t sll_t;

// assignment_part

typedef int len_t;

// assignment_part


sll_t* create_list(void);
node_t* get_node(data_t new_data);
void* xmalloc(size_t size_in_bytes);
void show_list(sll_t* p_list, const char* msg);
status_t insert_start(sll_t* p_list, data_t new_data);
status_t insert_end(sll_t* p_list, data_t new_data);
status_t insert_after(sll_t* p_list, data_t e_data, data_t new_data);
status_t insert_before(sll_t* p_list, data_t e_data, data_t new_data);
status_t get_start(sll_t* p_list, data_t* p_start_data);
status_t get_end(sll_t* p_list, data_t* p_end_data);

// assignment_part

// 1
status_t remove_start(sll_t* p_list);

// 2
status_t remove_end(sll_t* p_list);

// 3
status_t remove_data(sll_t* p_list, data_t r_data);

// 4
status_t pop_start(sll_t* p_list, data_t* p_start_data);

// 5
status_t pop_end(sll_t* p_list, data_t* p_end_data);

// 6
status_t is_list_empty(sll_t* p_list);

// 7
status_t find(sll_t* p_list, data_t f_data);

// 8
len_t get_list_length(sll_t* p_list);

// 9
status_t clear_list(sll_t* p_list);

// 10
status_t destroy_list(sll_t** pp_list);

// // assignment_part


#endif