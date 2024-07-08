#include<stdio.h>
#include<stdlib.h>

#define success                1
#define List_data_not_found    2
#define List_Empty             3

struct node
{
    int data;
    struct node* prev;
    struct node* next;
};

struct node* get_list(void);
void show(struct node* p_head_node,const char* msg);

void insert_start(struct node* p_head_node,int new_data);
void insert_end(struct node* p_head_node,int new_data);

int insert_after(struct node* p_head_node,int p_ext_data,int p_new_data);
int insert_before(struct node* p_head_node,int p_ext_data,int p_new_data);

int get_start(struct node* p_head_node,int* p_start_data);
int get_end(struct node* p_head_node,int* p_end_data);

int pop_start(struct node* p_head_node,int* p_start_data);
int pop_end(struct node* p_head_node,int* p_end_data);
int remove_data(struct node* p_head_node,int p_r_data);

unsigned long long int count(struct node* p_head_node);
void destroy_list(struct node* p_head_node);

int main(void)
{
   struct node* my_list = NULL;
   int data;
   int start_data;
   int end_data;
   unsigned long long int lenght = 0;

   my_list = get_list();
   show(my_list,"Emtpy list");

   for(data = 25;data<50;data+=5)
   {
    insert_start(my_list,data);
   }
    
    show(my_list,"After insert_start()");

    for(data  = 5;data<20;data+=5)
    {
        insert_end(my_list,data);
    }

    show(my_list,"After insert_end()");

   data = insert_after(my_list,25 ,100);
   if(data == List_data_not_found)
   {
    puts("List data not found");
   }
   else
   {
       show(my_list,"After insert_after()");
       printf("after iserted data is: 100\n");
       puts("success");
   }

     data = insert_before(my_list,5,20);
     if(data == List_data_not_found)
     {
        puts("List data not found");
     }
     else
     {
        show(my_list,"After insert_before()");
        printf("insert before data is: 20\n");
        puts("success");
     }

    data = get_start(my_list,&start_data);
    if(data == List_Empty)
    {
        puts("list empty");
    }
    else
    {
        show(my_list,"After get_start");
        printf("started data is: %d\n",start_data);
        puts("success");
    }

    data = get_end(my_list,&end_data);
if(data == List_Empty)
    {
        puts("list empty");
    }
    else
    {
        show(my_list,"After get_end");
        printf("end data is: %d\n",end_data);
        puts("success");
    }


    data = pop_start(my_list,&start_data);
    if(data == List_Empty)
    {
        puts("list empty");
    }
    else
    {
        show(my_list,"After pop_start");
        printf("pop_start data is: %d\n",start_data);
        puts("success");
    }

  data = pop_end(my_list,&end_data);
  if(data == List_Empty)
    {
        puts("list empty");
    }
    else
    {
        show(my_list,"After end_start");
        printf("pop_end data is: %d\n",end_data);
        puts("success");
    }

    data = remove_data(my_list,5);
    if(data == List_Empty)
    {
        puts("list empty");
    }
    else if(data == List_data_not_found)
    {
        puts("list data not found");
    }
    
    else 
    {
        show(my_list,"After remove data");
        printf("remove data is: 5\n");
        puts("success");
    }

   lenght = count(my_list);

   printf("lenght is: %llu\n",lenght);

   destroy_list(my_list);

   return(0);
}

struct node* get_list(void)
{
    struct node* p_head_node = NULL;

    p_head_node = (struct node*)malloc(sizeof(struct node));

    p_head_node->data = 0;
    p_head_node->prev = NULL;
    p_head_node->next = NULL;

    return(p_head_node);
}

void insert_start(struct node* p_head_node,int new_data)
{
    struct node* p_new_node = NULL;

    p_new_node = (struct node*)malloc(sizeof(struct node));

    p_new_node->data = new_data;
    p_new_node->prev = NULL;
    p_new_node->next = NULL;

    p_new_node->next = p_head_node->next;
    p_new_node->prev = p_head_node;
    if(p_head_node->next != NULL)
    {
        p_head_node->next->prev = p_new_node;
    }

    p_head_node->next = p_new_node;
}

void insert_end(struct node* p_head_node,int new_data)
{
    struct node* p_new_node = NULL;
    struct node* p_run = NULL;

    p_run = p_head_node;
    while(p_run->next != NULL)
    {
        p_run = p_run->next;
    }

    p_new_node = (struct node*)malloc(sizeof(struct node));

    p_new_node->data = new_data;
    p_new_node->next = NULL;
    p_new_node->prev = NULL;

    p_new_node->next = p_run->next;
    p_new_node->prev = p_run;
    p_run->next = p_new_node;
}

int insert_after(struct node* p_head_node,int p_ext_data,int p_new_data)
{
    struct node* p_new_node = NULL;
    struct node* p_ext_node = NULL;

    p_ext_node = p_head_node->next;
    while(p_ext_node != NULL)
    {
         if(p_ext_node->data == p_ext_data)
         {
            break;
         }
         p_ext_node = p_ext_node->next;
    }

    if(p_ext_node == NULL)
    {
        return(List_data_not_found);
    }

   p_new_node = (struct node*)malloc(sizeof(struct node));

   p_new_node->data = p_new_data;
   p_new_node->next = NULL;
   p_new_node->prev = NULL;

   p_new_node->next = p_ext_node->next;
   p_new_node->prev = p_ext_node;
   if(p_ext_node->next != NULL)
   {
    p_ext_node->next->prev = p_new_node;
   }

   p_ext_node->next = p_new_node;

   return(success);

}

int insert_before(struct node* p_head_node,int p_ext_data,int p_new_data)
{
    struct node* p_new_node = NULL;
    struct node* p_ext_node = NULL;

    p_ext_node = p_head_node->next;
    while(p_ext_node != NULL)
    {
        if(p_ext_node->data == p_ext_data)
        {
            break;
        }

        p_ext_node = p_ext_node->next;
    }

    if(p_ext_node == NULL)
    {
        return(List_data_not_found);
    }

    p_new_node = (struct node*)malloc(sizeof(struct node));

    p_new_node->data = p_new_data;
    p_new_node->next = NULL;
    p_new_node->prev = NULL;

    p_new_node->next = p_ext_node;
    p_new_node->prev = p_ext_node->prev;
    p_ext_node->prev->next = p_new_node;
    p_ext_node->prev = p_new_node;

   return (success);
}

int get_start(struct node* p_head_node,int* p_start_data)
{
    if(p_head_node->next == NULL && p_head_node->prev == NULL)
    {
        return(List_Empty);
    }

    *p_start_data = p_head_node->next->data;
    return(success);
}

int get_end(struct node* p_head_node,int* p_end_data)
{
    if(p_head_node->next == NULL && p_head_node->prev == NULL)
    {
        return(List_Empty);
    }
    
    struct node* p_run = NULL;

    p_run = p_head_node;
    while(p_run->next != NULL)
    {
        p_run = p_run->next;
    }

    *p_end_data = p_run->data;
    return(success);
}

int pop_start(struct node* p_head_node,int* p_start_data)
{
    struct node* p_start_node = NULL;

    if(p_head_node->next == NULL && p_head_node->prev == NULL)
    {
        return(List_Empty);
    }

     *p_start_data = p_head_node->next->data;

    p_start_node = p_head_node->next;
    p_start_node->prev->next = p_start_node->next;
    if(p_start_node->next != NULL)
    {
        p_start_node->next->prev = p_start_node->prev;
    }

    free(p_start_node);
    p_start_node = NULL;

    return(success);
}

int pop_end(struct node* p_head_node,int* p_end_data)
{
    struct node* p_run = NULL;

    if(p_head_node->next == NULL && p_head_node->prev == NULL)
    {
        return(List_Empty);
    }

    p_run = p_head_node;
    while(p_run->next != NULL)
    {
        p_run = p_run->next;
    }

    *p_end_data = p_run->data;

    p_run->prev->next = NULL;
    free(p_run);
    p_run = NULL;

    return(success);
}

int remove_data(struct node* p_head_node,int p_r_data)
{
    if(p_head_node->next == NULL && p_head_node->prev == NULL)
    {
        return(List_Empty);
    }

    struct node* p_run = NULL;

    p_run = p_head_node;
    while(p_run->next != NULL)
    { 
        if(p_run->data == p_r_data)
        {
            break;
        }
       p_run = p_run->next;
    }

    if(p_run->next == NULL)
    {
        return(List_data_not_found);
    }

   p_run->prev->next = p_run->next;
   if(p_run->next != NULL)
   {
    p_run->next->prev = p_run->prev;
   }

   free(p_run);
   p_run = NULL;

   return(success);
}

unsigned long long int count(struct node* p_head_node)
{
    unsigned long long int L = 0;
    struct node* p_run = NULL;

    p_run = p_head_node->next;
    while(p_run != NULL)
    {
        ++L;
        p_run  = p_run->next;
    }

    return(L);

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
    while(p_run != NULL)
    {
        printf("arr[%d]->",p_run->data);
        p_run = p_run->next;
    }

    puts("[END]");

}

void destroy_list(struct node* p_head_node)
{
    struct node* p_run = NULL;
    struct node* p_run_next  = NULL;

    p_run_next = p_head_node;
    p_run = p_head_node->next;

    while(p_run != NULL)
    {
        p_run_next = p_run->next;
        free(p_run);
        p_run = p_run_next;
    }

    free(p_head_node);
    p_head_node = NULL;
}