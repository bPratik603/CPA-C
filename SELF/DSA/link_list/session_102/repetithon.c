#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* prev;
    struct node* next;
};

//1
unsigned long long int count(struct node* p_head_node)
{
    unsigned long long int L = 0;
    struct node* p_run = NULL;

    p_run = p_head_node->next;
    while(p_run != NULL)
    {
        ++L;
        p_run = p_run->next;
    }

    return(L);
}

//2
unsigned long long int count(struct node* p_head_node)
{
    unsigned long long int L = 0;
    struct node* p_run = NULL;

    p_run = p_head_node->next;
    while(p_run != NULL)
    {
        ++L;
        p_run = p_run->next;
    }

    return(L);
}