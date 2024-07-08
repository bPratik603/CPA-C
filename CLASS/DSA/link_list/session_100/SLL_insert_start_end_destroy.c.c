#include <stdio.h> 
#include <stdlib.h> 

struct node
{
    int data; 
    struct node* next; 
}; 

struct node* create_list(void); 
void insert_start(struct node* p_head_node, int data); 
void insert_end(struct node* p_head_node, int data); 
void show_list(struct node* p_head_node, const char* msg); 
void destroy_list(struct node* p_head_node); 

int main(void) 
{
    struct node* my_list = NULL; 
    int data; 
    
    my_list = create_list(); 
    show_list(my_list, "Empty list"); /* [START]->[END] */

    for(data = 10; data < 50; data += 10)
        insert_end(my_list, data); 

    show_list(my_list, "After insert_end()"); /* [START]->[10]->[20]->[30]->[40]->[END] */

    for(data = 5; data <= 25; data += 5)
        insert_start(my_list, data);        

    show_list(my_list, "After insert_start()");     /* [START]->[25]->[20]->[15]->[10]->[5]->[10]->[20]->[30]->[40]->[END] */

    destroy_list(my_list); 
    my_list = NULL; 

    exit(EXIT_SUCCESS); 
}

struct node* create_list(void)
{
    struct node* p_head_node = NULL; 

    p_head_node = (struct node*)malloc(sizeof(struct node)); 
    if(p_head_node == NULL)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    p_head_node->data = 0; 
    p_head_node->next = NULL; 

    return (p_head_node); 
}

void insert_start(struct node* p_head_node, int data)
{
    struct node* p_new_node = NULL; 

    p_new_node = (struct node*)malloc(sizeof(struct node)); 
    if(p_new_node == NULL)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    p_new_node->data = data; 
    p_new_node->next = NULL; 

    p_new_node->next = p_head_node->next; 
    p_head_node->next = p_new_node; 
}

void insert_end(struct node* p_head_node, int data)
{
    struct node* p_new_node = NULL; 
    struct node* p_run = NULL; 

    p_new_node = (struct node*)malloc(sizeof(struct node)); 
    if(p_new_node == NULL)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    p_new_node->data = data; 
    p_new_node->next = NULL; 

    p_run = p_head_node; 
    while(p_run->next != NULL)
        p_run = p_run->next; 

    p_run->next = p_new_node; 
}

void show_list(struct node* p_head_node, const char* msg)
{
    struct node* p_run = NULL; 

    if(msg)
        puts(msg); 

    printf("[START]->"); 
    p_run = p_head_node->next; 
    while(p_run != NULL)
    {
        printf("[%d]->", p_run->data); 
        p_run = p_run->next; 
    }

    puts("[END]"); 
}

void destroy_list(struct node* p_head_node)
{
    struct node* p_run = NULL; 
    struct node* p_run_next = NULL; 

    p_run = p_head_node->next; 
    while(p_run != NULL)
    {
        p_run_next = p_run->next; 
        free(p_run); 
        p_run = p_run_next; 
    }

    free(p_head_node); 
}