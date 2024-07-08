struct list_head{
    struct list_head* prev; 
    struct list_head* next; 
}; 

/* struct list_head v = {&v, &v}; */ 

#define INIT_HEAD(v)    struct list_head v = {&v, &v}; 

int main(void)
{
    INIT_HEAD(task_list_head); 
    INIT_HEAD(lru_head); 

    return 0; 
}

#define OFFSET_OF(type, mem)
#define CONTAINER_OF(addr, type, mem)   