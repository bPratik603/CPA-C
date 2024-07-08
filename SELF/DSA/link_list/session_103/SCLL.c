#include<stdio.h>
#include<stdlib.h>

#define success              1
#define Empty_list           2
#define List_data_not_found  3

struct node
{
    int data;
    struct node* next;
};

struct node* get_list(void);
void show(struct node* p_head_node,const char* msg);

void insert_start(struct node* p_head_node,int new_data);
void insert_end(struct node* p_head_node,int new_data);
int  insert_after(struct node* p_head_node,int p_e_data,int p_new_data);
int  insert_before(struct node* p_head_node,int p_e_data,int p_new_data);

int get_start(struct node* p_head_node,int* p_start_data);
int get_end(struct node* p_head_node,int* p_end_data);

int pop_start(struct node* p_head_node,int* p_start_data);
int pop_end(struct node* p_head_node,int* p_end_data);
int pop_data(struct node* p_head_node,int p_e_data);

int get_lenght(struct node* p_head_node);

void destroy_list(my_list);

int main(void)
{
    struct node* my_list = NULL;
    int data;
    int start_data;
    int end_data;
   unsigned long long int lenght;

    my_list = get_list();
    show(my_list,"Empty list");

    for(data = 25;data<50;data+=5)
    {
        insert_start(my_list,data);
    }

    show(my_list,"After insert_start()");

    for(data =5;data<20;data+=5)
    {
        insert_end(my_list,data);
    }

    show(my_list,"After inseret_end()");

   data = insert_after(my_list,5,20);
   if(data == List_data_not_found)
   {
    printf("List data not found\n");
   }
   else
   {
    show(my_list,"After insert_after()");
    printf("insert after data is 20\n");
   }

    data = insert_before(my_list,5,100);
    if(data == List_data_not_found)
   {
    printf("List data not found\n");
   }
   else
   {
    show(my_list,"After insert_before()");
    printf("insert before data is 100\n");
   }

   data = get_start(my_list,&start_data);
   if(data == Empty_list)
   {
    printf("Empyt list\n");
   }
   else
   {
    show(my_list,"After get_start()");
    printf("started data is: %d\n",start_data);
    puts("success");
   }

   data = get_end(my_list,&end_data);
if(data == Empty_list)
   {
    printf("Empyt list\n");
   }
   else
   {
    show(my_list,"After get_end()");
    printf("end data is: %d\n",end_data);
    puts("success");
   }

    data = pop_start(my_list,&start_data);
    if(data == Empty_list)
    {
        puts("Empty list");
    }
    else
    {
        show(my_list,"After pop_start()");
        printf("pop_start data is: %d\n",start_data);
        puts("success");
    }

    data = pop_end(my_list,&end_data);
    if(data == Empty_list)
    {
        puts("Empty list");
    }
    else
    {
        show(my_list,"After pop_end()");
        printf("pop_end data is: %d\n",end_data);
        puts("success");
    }


    data = pop_data(my_list,5);
    if(data == List_data_not_found)
    {
        puts("list data not found");
    }   
     else if(data == Empty_list)
     {
        puts("Empty list");
     }
     else
     {
        show(my_list,"After pop_data()");
        printf("pop data is 5\n");
        puts("success");
     }


    lenght = get_lenght(my_list);
    if(lenght == Empty_list)
    {
        puts("Empty list");
    }
    else
    {
        printf("lenght of list: %lld\n",lenght);
    }

     destroy_list(my_list);
     my_list = NULL;

       return(0);
}

struct node* get_list(void)
{
    struct node* p_head_node = NULL;

    p_head_node = (struct node*)malloc(sizeof(struct node));
    if(p_head_node == NULL)
    {
        puts("Error in allocating memory");
        exit(EXIT_FAILURE);
    }

    p_head_node->data = 0;
    p_head_node->next = p_head_node;

    return(p_head_node);
}

void insert_start(struct node* p_head_node,int new_data)
{
    struct node* p_new_node = NULL;

    p_new_node = (struct node*)malloc(sizeof(struct node));

    p_new_node->data = new_data;

    p_new_node->next = p_head_node->next;
    p_head_node->next = p_new_node;
}

void insert_end(struct node* p_head_node,int new_data)
{
    struct node* p_new_node = NULL;
    struct node* p_end_node = NULL;

   p_end_node = p_head_node;
   while(p_end_node->next != p_head_node)
   {
    p_end_node = p_end_node->next;
   }

   p_new_node = (struct node*)malloc(sizeof(struct node));

   p_new_node->data = new_data;

   p_end_node->next = p_new_node;
   p_new_node->next = p_head_node;
}

int insert_after(struct node* p_head_node,int p_e_data,int p_new_data)
{
    struct node* p_new_node = NULL;
    struct node* p_ext_node = NULL;

    p_ext_node = p_head_node->next;
    while(p_ext_node != p_head_node)
    {
        if(p_ext_node->data == p_e_data)
        {
            break;
        }

        p_ext_node = p_ext_node->next;
    }

    if(p_ext_node == p_head_node)
    {
        return(List_data_not_found);
    }

  p_new_node = (struct node*)malloc(sizeof(struct node));

     p_new_node->data = p_new_data;
   
    p_new_node->next = p_ext_node->next;
    p_ext_node->next = p_new_node;

    return(success);
}

int insert_before(struct node* p_head_node,int p_e_data,int p_new_data)
{
    struct node* p_new_node = NULL;
    struct node* p_ext_prev_node = NULL;
    struct node* p_ext_node = NULL;

    p_ext_prev_node = p_head_node;
    p_ext_node = p_head_node->next;

   while(p_ext_node != p_head_node)
   {
    if(p_ext_node->data == p_e_data)
    {
        break;
    }

    p_ext_prev_node = p_ext_node;
    p_ext_node = p_ext_node->next;
   }

   if(p_ext_node == p_head_node)
   {
    return(List_data_not_found);
   }

   p_new_node = (struct node*)malloc(sizeof(struct node));

   p_new_node->data = p_new_data;

   p_new_node->next = p_ext_node;
   p_ext_prev_node->next = p_new_node;

   return(success);
}

int get_start(struct node* p_head_node,int* p_start_data)
{
    if(p_head_node->next == p_head_node)
    {
        return(Empty_list);
    }

    *p_start_data = p_head_node->next->data;
    return(success);
}

int get_end(struct node* p_head_node,int* p_end_data)
{
    struct node* p_run = NULL;

    if(p_head_node->next == p_head_node)
    {
        return(Empty_list);
    }

    p_run = p_head_node;
    while(p_run->next != p_head_node)
    {
        p_run = p_run->next;
    }

    *p_end_data = p_run->data;

    return(success);
}

int pop_start(struct node* p_head_node,int* p_start_data)
{
    struct node* p_frist_node = NULL;

    if(p_head_node->next == p_head_node)
    {
        return(Empty_list);
    }

    *p_start_data = p_head_node->next->data;

    p_frist_node = p_head_node->next;
   p_head_node->next = p_frist_node->next;

   free(p_frist_node);
   p_frist_node = NULL;

   return(success);

}

int pop_end(struct node* p_head_node,int* p_end_data)
{
    struct node* p_run = NULL;
    struct node* p_run_prev = NULL;

    if(p_head_node->next == p_head_node)
    {
        return(Empty_list);
    }

     p_run_prev = p_head_node;
     p_run = p_head_node->next;

    while(p_run->next != p_head_node)
    {
        p_run_prev = p_run;
        p_run = p_run->next;
    }
     
    *p_end_data = p_run->data;
    
    p_run_prev->next = p_run->next;

    free(p_run);
    p_run = NULL;

    return(success);
}

int pop_data(struct node* p_head_node,int p_e_data)
{
    struct node* p_ext = NULL;
    struct node* p_ext_prev = NULL;

    if(p_head_node->next == p_head_node)
    {
        return(Empty_list);
    }

    p_ext_prev = p_head_node;
    p_ext = p_head_node->next;

    while(p_ext != p_head_node)
    {
        if(p_ext->data == p_e_data)
        {
           break;
        }
        p_ext_prev = p_ext;
        p_ext = p_ext->next;
    }

    if(p_ext == p_head_node)
    {
        return(List_data_not_found);
    }

    p_ext_prev->next = p_ext->next;

    free(p_ext);
    p_ext = NULL;

    return(success);
}

int get_lenght(struct node* p_head_node)
{
    struct node* p_run = 0;
    unsigned long long int count = 0;

    if(p_head_node->next == p_head_node)
    {
        return(Empty_list);
    }

    p_run = p_head_node->next;
    while(p_run != p_head_node)
    {
        ++count;
        p_run = p_run->next;
    }

    return(count);
}

void show(struct node* p_head_node,const char* msg)
{
    struct node* p_run = NULL;
    if(msg)
    {
        puts(msg);
    }

    puts("[START]->");
    p_run = p_head_node->next;
    while(p_run != p_head_node)
    {
        printf("arr[%d]->",p_run->data);
        p_run = p_run->next;
    }

    puts("[END]");

}

void destroy_list(struct node* p_head_node)
{
    struct node* p_run = NULL;
    struct node* p_run_next = NULL;

    p_run_next = p_head_node;
    p_run = p_head_node->next;

    while(p_run != p_head_node)
    {
        p_run_next = p_run->next;
        free(p_run);
        p_run = p_run_next;
    }

   free(p_head_node);
   p_head_node = NULL;
}