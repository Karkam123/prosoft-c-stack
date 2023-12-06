#include "cstack.h"
#include <stddef.h>
#include <stdio.h>

#define UNUSED(VAR) (void)(VAR)

struct node
{
    const struct node*prev;
    unsigned int size;
    void* data;
};



struct node* stack[10] = {NULL};


hstack_t stack_new(void)
{
    int i;
    for (i=0;i<=10;++i)
    {
        if (stack[i]==NULL)
        {


        }
    }

    return 1;
}

void stack_free(const hstack_t hstack)
{
    UNUSED(hstack);
}

int stack_valid_handler(const hstack_t hstack)
{
    UNUSED(hstack);
    return 1;
}

unsigned int stack_size(const hstack_t hstack)
{
    UNUSED(hstack);
    return 0;
}

void stack_push(const hstack_t hstack, const void* data_in, const unsigned int size)
{
    UNUSED(hstack);
    UNUSED(data_in);
    UNUSED(size);
}

unsigned int stack_pop(const hstack_t hstack, void* data_out, const unsigned int size)
{
    UNUSED(hstack);
    UNUSED(data_out);
    UNUSED(size);
    return 0;
}

