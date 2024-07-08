struct node
{
    int data;
    struct node* next;
};

void destroy(struct node* p_head_node)
{
    struct node* p_run = NULL;
    struct node* p_run_next = NULL;

    p_run = p_head_node->next;
    p_run_next = p_head_node;

    while(p_run != NULL)
    {
        p_run_next = p_run->next;
        free(p_run);
        p_run = p_run_next;
    }

    free(p_head_node);
    p_head_node = NULL;
}

void destroy(struct node* p_head_node)
{
    struct node* p_run = NULL;
    struct node* p_run_next = NULL;

    p_run = p_head_node->next;
    p_run_next = p_head_node;

    while(p_run != NULL)
    {
        p_run_next = p_run->next;
        free(p_run);
        p_run = p_run_next;
    }

    free(p_head_node);
    
}