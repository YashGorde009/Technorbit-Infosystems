#ifndef _ARRAY_H
#define _ARRAY_H

typedef int data_t;
typedef int status_t;
typedef long long s_size_t;
typedef s_size_t index_t;
typedef struct array array_t;

struct array
{
    data_t* arr;
    s_size_t N;
};

array_t* create_array(s_size_t N);

#endif