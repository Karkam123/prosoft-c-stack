#include "cstack.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

struct node
{
    struct node* prev;
    unsigned int size;
    void* data;
};

struct node* ptr[SIZE] = {NULL};

hstack_t stack_new(void)
{
    hstack_t handler = 0;
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->size = 0;
    new->data = NULL;
    new->prev = NULL;

    for(size_t i = 0; i != SIZE; i++)
    {
        if (ptr[i] == NULL)
        {
            handler = i;
            ptr[handler] = new;
            if (ptr[handler] != 0)
            {
                return handler;
            }
        }
    }
    return -1;
}

void stack_free(const hstack_t hstack)
{
    if (stack_valid_handler(hstack) == 0)
    {
        struct node* old = ptr[hstack];
        struct node* tmp;
        while(old!=NULL)
        {
            tmp = old->prev;
            if (old->data != NULL)
            {
                free(old->data);
            }
            free(old);
            old=tmp;
        }
        ptr[hstack]=NULL;
    }
}

int stack_valid_handler(const hstack_t stack)
{
    if(stack>=0 && stack<SIZE && ptr[stack]!= NULL)
    {
        return 0;
    }
    return 1;
}

unsigned int stack_size(const hstack_t stack)
{
    if (stack_valid_handler(stack)==0)
    {
        struct node* stack_tmp = ptr[stack];
        return stack_tmp -> size;
    }
    return 0;
}

void stack_push(const hstack_t hstack, const void* data_in, const unsigned int size)
{
    struct node* stack_now= NULL;
    if (stack_valid_handler(hstack)==0)
    {
        stack_now=ptr[hstack];
        if (stack_now->size!=0 && data_in != NULL && size != 0)
        {
            struct node* new_node=(struct node*)malloc(sizeof(struct node));
            new_node->data=malloc(size);
            memcpy(new_node->data, data_in,size);
            new_node->size=(stack_now->size)+1;
            new_node->prev=stack_now;
            ptr[hstack]=new_node;

        }else
        {
            if (data_in != NULL && size != 0)
            {
                stack_now->size++;
                stack_now->data=malloc(size);
                memcpy(stack_now->data, data_in,size);
            }
        }

    }
}

unsigned int stack_pop(const hstack_t hstack, void* data_out, const unsigned int size)
{
    if (stack_valid_handler(hstack) == 0)
    {
        struct node* tmp = ptr[hstack];
        if (tmp->data != NULL)
        {
            memcpy(data_out, tmp->data, size);
            free(tmp->data);
            ptr[hstack]=tmp->prev;
            free(tmp);
            return size;
        }
    }
    return 0;
}

