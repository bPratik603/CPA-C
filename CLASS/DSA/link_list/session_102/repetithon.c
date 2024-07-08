#include<stdio.h>
#include<stdlib.h>

#define success                 1
#define List_data_not_found     2
#define List_data_found         3
#define Empty_list              4



struct node
{
    int data;
    struct node* next;
};

struct node* get_list(void);
void show_list(struct node* p_head_node,const char* msg);
void insert_end(struct node* p_head_node,int data);
void insert_start(struct node* p_head_node,int data);

int insert_after(struct node* p_head_node,int pe_data,int pn_data);
int insert_before(struct node* p_head_node,int pe_data,int pn_data);

int get_start(struct node* p_head_node,int* p_start_data);
int get_end(struct node* p_head_node,int* p_end_data);

int pop_start(struct node* p_head_node,int* p_start_data);
int pop_end(struct node* p_head_node,int* p_end_data);
int pop_data(struct node* p_head_nod,int r_data,int* p_r_data);

unsigned long long int count(struct node* p_head_node);
void destroy_list(struct node* p_head_node);

int main()
{
    struct node* my_list;
    int start_data;
    int end_data;
    int data;
    int r_data;
    unsigned long long int length;

    my_list = get_list();

    show_list(my_list,"Before insert");
 
    for(data=30;data<50;data+=5)
    {
        insert_end(my_list,data);
    }

   show_list(my_list,"After insert end");

   for(data = 5;data<25;data+=5)
   {
    insert_start(my_list,data);
   }

   show_list(my_list,"After insert start");

   data = insert_after(my_list,5,100);
   if(data == List_data_not_found)
   {
    puts("List data not found");
   }
   else
   {
    show_list(my_list,"After insert 100 after 5");
   }

   data = insert_before(my_list,5,20);
   if(data == List_data_not_found)
   {
    puts("list data not found");
   }
   else
   {
      show_list(my_list,"After insert 20 before 5");
   }

   data = get_start(my_list,&start_data);
   if(data == Empty_list)
   {
      puts("Empty list");
   }
   else
   {
      printf("start data is = %d\n",start_data);
   }

   data = get_end(my_list,&end_data);
   if(data == Empty_list)
   {
    puts("empty list");
   }
   else
   {
     printf("end data = %d\n",end_data);
   }

   data = pop_start(my_list,&start_data);
   if(data == Empty_list)
   {
    puts("Empty list");
   }
   else
   {
     show_list(my_list,"After pop start");
     printf("pop start is = %d\n",start_data);
   }

   data = pop_end(my_list,&end_data);
   if(data == Empty_list)
   {
    puts("Empty list");
   }
   else
   {
     show_list(my_list,"After pop end");
     printf("pop end is = %d\n",end_data);
   }

   data = pop_data(my_list,5,&r_data);
    if(data == List_data_not_found)
   {
    puts("List data not found");
   }
   else
   {
     show_list(my_list,"After pop data");
     printf("pop data is = %d\n",r_data);
   }

   length = count(my_list);
   printf("count = %llu\n",length);


    destroy_list(my_list);


}

void destroy_list(struct node* p_head_node)
{
    struct node* p_run;
    struct node* p_run_next;

    p_run = p_head_node->next;
    p_run_next = p_head_node;

    while(p_run != p_head_node)
    {
        p_run_next = p_run->next;
        free(p_run);
        p_run = p_run_next;
    }

    free(p_head_node);
    p_head_node = NULL;
}
unsigned long long int count(struct node* p_head_node)
{
    unsigned long long int count = 0;
   struct node* p_run;

   p_run = p_head_node->next;

    while(p_run!= p_head_node)
    {
        ++count;
        p_run = p_run->next;
    }

    return(count);
}

int pop_data(struct node* p_head_node,int r_data,int* p_r_data)
{
    struct node* p_run;
    struct node* p_run_prev;

    p_run = p_head_node->next;
    p_run_prev = p_head_node;

    while(p_run->next != p_head_node)
    {
        if(p_run->data == r_data)
        {
            break;
        }
        p_run_prev = p_run;
        p_run = p_run->next;
    }

    if(p_run->next == p_head_node)
    {
        return(List_data_not_found);
    }

    *p_r_data = p_run->data;

    p_run_prev->next = p_run->next;

    free(p_run);
    p_run = NULL;

    return(success);
}

int pop_end(struct node* p_head_node,int* p_end_data)
{
    struct node* p_run;
    struct node* p_run_prev;

     p_run = p_head_node->next;
     p_run_prev = p_head_node;

    if(p_run == p_head_node)
    {
        return(Empty_list);
    }

  
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

int pop_start(struct node* p_head_node,int* p_start_data)
{
    struct node* p_run;
   
     p_run = p_head_node->next;
    
     if(p_run == p_head_node)
     {
        return(Empty_list);
     }

     *p_start_data = p_head_node->next->data;

     p_head_node->next = p_run->next;

     free(p_run);
     p_run = NULL;

     return(success);  
}

int get_end(struct node* p_head_node,int* p_end_data)
{
    struct node* p_end_node;

    if(p_head_node->next == p_head_node)
    {
        return(Empty_list);
    }

    p_end_node = p_head_node;
    while(p_end_node->next != p_head_node)
    {
        p_end_node = p_end_node->next;
    }

    *p_end_data = p_end_node->data;

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

int insert_before(struct node* p_head_node,int pe_data,int pn_data)
{
    struct node* p_new_node;
    struct node* p_ext_node;
    struct node* p_ext_node_prev;

    p_ext_node = p_head_node->next;
    p_ext_node_prev = p_head_node;
    
    while(p_ext_node != p_head_node)
    {
        if(p_ext_node->data == pe_data)
        {
            break;
        }
         p_ext_node_prev = p_ext_node;
         p_ext_node = p_ext_node->next;
    }

    if(p_ext_node == p_head_node)
    {
        return(List_data_not_found);
    }

    p_new_node = (struct node*)malloc(sizeof(struct node));

    p_new_node->data = pn_data;

    p_new_node->next = p_ext_node;
    p_ext_node_prev->next = p_new_node;

    return(success);
}

int insert_after(struct node* p_head_node,int pe_data,int pn_data)
{
    struct node* p_new_node;
    struct node* p_run;

    p_run = p_head_node;
    while(p_run->next != p_head_node)
    {
        if(p_run->data == pe_data)
        {
            break;
        }

        p_run=  p_run->next;
    }

    if(p_run->next == p_head_node)
    {
        return(List_data_not_found);
    }

    p_new_node = (struct node*)malloc(sizeof(struct node));

    p_new_node->data = pn_data;

    p_new_node->next = p_run->next;
    p_run->next = p_new_node;

    return(success);
}

void insert_start(struct node* p_head_node,int data)
{
    struct node* p_new_node;
    struct node* p_run;

    p_new_node = (struct node*)malloc(sizeof(struct node));

    p_new_node->data = data;

    

    p_new_node->next = p_head_node->next;
    p_head_node->next = p_new_node;
}

void insert_end(struct node* p_head_node,int data)
{
     struct node* p_end_node;
     struct node* p_new_node;

     p_new_node = (struct node*)malloc(sizeof(struct node));

     p_new_node->data = data;
     
     p_end_node  = p_head_node;
     while(p_end_node->next != p_head_node)
     {
        p_end_node = p_end_node->next;
     }

     p_new_node->next = p_end_node->next;
     p_end_node->next = p_new_node;
}

void show_list(struct node* p_head_node,const char* msg)
{
    struct node* p_run;

    puts(msg);
    puts("[START]->");

    p_run = p_head_node->next;
    while(p_run != p_head_node)
    {
        printf("[%d]->",p_run->data);
        p_run = p_run->next;
    }
    puts("[END]");


}

struct node* get_list(void)
{
    struct node* p_head_node;

    p_head_node = (struct node*)malloc(sizeof(struct node));

    p_head_node->data = 0;
    p_head_node->next = p_head_node;

    return(p_head_node);
}