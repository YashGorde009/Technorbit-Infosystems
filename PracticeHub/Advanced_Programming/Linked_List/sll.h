#ifndef _SLL_H
#define _SLL_H

#include<stdio.h>
#define SUCCESS 1

struct node 
{
	int data;
	struct node* next;
};

typedef int data_t;
typedef int status_t;
typedef int len_t;
typedef struct node node_t;
typedef node_t sll_t;

sll_t* create_list(void);
node_t* get_node(data_t new_data);
void* xmalloc(size_t size_in_bytes);
void show_list(sll_t* p_list, const char* msg);
status_t insert_start(sll_t* p_list, data_t new_data);
status_t insert_end(sll_t* p_list, data_t new_data);

#endif