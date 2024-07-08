#include<stdio.h>
#include<stdlib.h>


#define success              1
#define List_data_not_found  2
#define List_empty           3   
#define List_data_found      4

struct node
{
    int data;
    struct node* next;
};

struct node* get_list(void);
void show(struct node* p_head_node,const char* msg);
void insert_end(struct node* p_head_node,int data);
void insert_start(struct node* p_head_node,int data);

int insert_after(struct node* p_head_node,int e_data,int new_data);
int insert_before(struct node* p_head_node,int e_data,int new_data);

int get_start(struct node* p_head_node,int* p_start_data);
int get_end(struct node* p_head_node,int* p_end_data);

int pop_start(struct node* p_head_node,int* p_start_data);
int pop_end(struct node* p_head_node,int* p_end_data);
int pop_data(struct node* p_head_node,int* p_r_data,int r_data);

int find_data(struct node* p_head_node,int search_data);
unsigned long long int get_lenght(struct node* p_head_node);


void destroy(struct node* p_head_node);

int main(void)
{
    struct node* my_list = NULL;
    int data;
    int start_data = 0;
    int end_data = 0;
    int r_data = 0;
    unsigned long long int count;

   my_list = get_list();
   show(my_list,"Empty list");

   for(data = 25;data<50;data+=5)
   {
    insert_end(my_list,data);
   }

   show(my_list,"After insert end()");

   for(data = 5;data<20;data+=5)
   {
    insert_start(my_list,data);
   }

   show(my_list,"After insert start()");

   data = insert_after(my_list,5,20);
   if(data == List_data_not_found)
   {
      puts("List data not found");
   }
   else
   {
     show(my_list,"After insert after()");
     puts("success");
   }

    data = insert_before(my_list,5,100);
    if(data == List_data_not_found)
    {
        puts("list data not found");
    }
    else
    {
        show(my_list,"After insert before");
        puts("success");
    }

   data = get_start(my_list,&start_data);
   if(data == List_data_not_found)
   {
    puts("List data not found");
   }
   
   else
   {
    show(my_list,"After get_start()");
      printf("started data: %d\n",start_data);
     puts("success");
   }

   
   data = get_end(my_list,&end_data);
if(data == List_data_not_found)
   {
    puts("List data not found");
   }
  
   else
   {
    show(my_list,"After get_end()");
      printf("end data: %d\n",end_data);
     puts("success");
   }

   data = pop_start(my_list,&start_data);
   if(data == List_empty)
   {
    printf("List is empty");
   }
   else
   {
    
     show(my_list,"After pop start");
      printf("pop start is %d\n",start_data);
     puts("success");
   }


   data = pop_end(my_list,&end_data);
   if(data == List_empty)
   {
    printf("List Empty");
   }
   else
   {
    
    show(my_list,"After pop end()");
    printf("pop end is %d\n",end_data);
    puts("success");
   }

   data = pop_data(my_list,&r_data,5);
   if(data == List_empty)
   {
    printf("List Empty");
   }
   else if(data == List_data_not_found)
   {
    printf("List data not found");
   }
   else
   {
     
     show(my_list,"After pop data");
     printf("poped data is %d\n",r_data);
     puts("success");
   }

    

    data = find_data(my_list,100);
    if(data == List_empty)
   {
    printf("List Empty");
   }
   else if(data == List_data_not_found)
   {
    printf("List data not found");
   }
   else
   {
     printf("List datafound \n");
     
     puts("success");
   }
 
   
   count = get_lenght(my_list);
   printf("lenght of list: %llu\n",count);

 destroy(my_list);
    my_list = NULL;
    return(0);
}

struct node* get_list(void)
{
    struct node* p_head_node = NULL;

    p_head_node = (struct node*)malloc(sizeof(struct node));

    p_head_node->data = 0;
    p_head_node->next = NULL;

    return (p_head_node);
}

void insert_end(struct node* p_head_node,int data)
{
    struct node* p_new_node = NULL;
    struct node* p_run = NULL;

    p_new_node = (struct node*)malloc(sizeof(struct node));

    p_new_node->data = data;
    p_new_node->next = NULL;

    p_run = p_head_node;
    while(p_run->next != NULL)
    {
        p_run = p_run->next;
    }

    p_run->next = p_new_node;
}

void insert_start(struct node* p_head_node,int data)
{
    struct node* p_new_node = NULL;

    p_new_node = (struct node*)malloc(sizeof(struct node));

    p_new_node->data = data;
    p_new_node->next = NULL;

    p_new_node->next = p_head_node->next;
    p_head_node->next = p_new_node;
}

int insert_after(struct node* p_head_node,int e_data,int new_data)
{
    struct node* p_new_node = NULL;
    struct node* pe_node = NULL;

    pe_node = p_head_node->next;
    while(pe_node != NULL)
    {
        if(pe_node->data == e_data)
        {
            break;
        }

        pe_node = pe_node->next;
    }

    if(pe_node == NULL)
    {
        return(List_data_not_found);
    }

  p_new_node = (struct node*)malloc(sizeof(struct node));
  
  p_new_node->data = new_data;
  p_new_node->next = NULL;

  p_new_node->next = pe_node->next;
  pe_node->next = p_new_node;

  return(success);
}

int insert_before(struct node* p_head_node,int e_data,int new_data)
{
    struct node* p_new_node = NULL;
    struct node* p_prev_node = NULL;
    struct node* pe_node = NULL;

    p_prev_node = p_head_node;
    pe_node = p_head_node->next;

    while(pe_node != NULL)
    {
    
      
        if(pe_node->data == e_data)
        {
            break;
        }

         p_prev_node = pe_node;
        pe_node = pe_node->next;
    }

    if(pe_node == NULL)
    {
        return(List_data_not_found);
    }

    p_new_node = (struct node*)malloc(sizeof(struct node));

    p_new_node->data = new_data;
    p_new_node->next = NULL;

    p_new_node->next = p_prev_node->next;
    p_prev_node->next = p_new_node;

    return (success);
}

int get_start(struct node* p_head_node,int* p_start_data)
{
    if(p_head_node->next == NULL)
    {
        return(List_empty);
    }

    *p_start_data = p_head_node->next->data;
    return (success);
}

int get_end(struct node* p_head_node,int* p_end_data)
{
   struct node* p_run = NULL;

    if(p_head_node->next == NULL)
    {
        return (List_empty);
    }

   p_run = p_head_node;
   while(p_run->next != NULL)
   {
       p_run = p_run->next;
   }

   *p_end_data = p_run->data;
   return (success);

}

int pop_start(struct node* p_head_node,int* p_start_data)
{
    struct node* p_new_node = NULL;

    if(p_head_node->next == NULL)
    {
        return(List_empty);
    }

    *p_start_data = p_head_node->next->data;

    p_new_node = p_head_node->next;
     p_head_node->next = p_new_node->next;
     free(p_new_node);
     p_new_node = NULL;

   return (success);
}

int pop_end(struct node* p_head_node,int* p_end_data)
{
  struct node* p_run = NULL;
  struct node* p_run_prev = NULL;

  if(p_head_node->next == NULL)
  {
    return(List_empty);
  }

  p_run_prev = p_head_node;
  p_run = p_head_node;

  while(p_run->next != NULL)
  {
    p_run_prev = p_run;
    p_run = p_run->next;
  }

  *p_end_data = p_run->data;

   free(p_run);
  p_run_prev->next = NULL;

  return(success);
}

int pop_data(struct node* p_head_node,int* p_r_data,int r_data)
{
    struct node* p_run = NULL;
    struct node* p_run_prev = NULL;
    struct node* p_new_node = NULL;

    if(p_head_node->next == NULL)
    {
        return(List_empty);
    }

    p_run = p_head_node->next;
    p_run_prev = p_head_node;

    while(p_run != NULL)
    {
        if(p_run->data == r_data)
        {
            break;
        }
        p_run_prev = p_run;
        p_run = p_run->next;
    }

    if(p_run->next == NULL)
    {
        return(List_data_not_found);
    }

   *p_r_data = p_run->data;

   p_new_node = p_run->next;
   p_run_prev->next = p_new_node->next;
    
    free(p_run);

    return(success);
}

int find_data(struct node* p_head_node,int search_data)
{
    struct node* p_run = NULL;

    if(p_head_node->next == NULL)
    {
        return(List_data_not_found);
    }


    p_run = p_head_node->next;
    while(p_run != NULL)
    {
        if(p_run->data == search_data)
        {
            return(List_data_found);
        }
        
        p_run = p_run->next;
    }

    return(List_data_not_found);
}

unsigned long long int get_lenght(struct node* p_head_node)
{
    struct node* p_run = NULL;
    unsigned long long int count = 0;
    p_run = p_head_node->next;
    while(p_run != NULL)
    {
       ++count;
       p_run = p_run->next;
    }

    return (count);
}

void show(struct node* p_head_node,const char* msg)
{
    struct node* p_run = NULL;
    if(msg)
    {
        puts(msg);
    }

    puts("[start]->");
    
    p_run = p_head_node->next;
    while(p_run != NULL)
    {
        printf("arr[%d]->",p_run->data);
        p_run = p_run->next;
    }
    puts("[END]");
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
    p_head_node = NULL;
}