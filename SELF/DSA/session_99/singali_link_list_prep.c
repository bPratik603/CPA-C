#include<stdio.h>
#include<stdlib.h>


struct node
{
    int data;
    struct node* next;
};


int main(void)
{
    struct node* p_node;
    struct node* p_run;

    p_node = (struct node*)malloc(sizeof(struct node));
    if(p_node == NULL)
    {
        puts("Error in allocating memory");
        exit(EXIT_FAILURE);
    }

    p_node->data = 10;
    p_node->next = NULL;

    p_node->next = (struct node*)malloc(sizeof(struct node));
    if(p_node == NULL)
    {
        puts("Error in allocating memory");
        exit(EXIT_FAILURE);
    }

    p_node->next->data = 20;
    p_node->next->next = NULL;

    p_node->next->next = (struct node*)malloc(sizeof(struct node));
    if(p_node->next->next == NULL)
    {
        puts("Error  in allocating memory");
        exit(EXIT_FAILURE);
    }

    p_node->next->next->data = 30;
    p_node->next->next->next = NULL;

    p_run = p_node;
    while(p_run != NULL)
    {
        printf("%d\n",p_run->data);
        p_run = p_run->next;
    }

    return (0);
}