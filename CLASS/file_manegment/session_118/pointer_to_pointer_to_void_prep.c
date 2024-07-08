void f(void** pp)
{

}

int main(void)
{
    void** pp = NULL; 
    
    f(pp); /* First Degree Moronic*/
}

pthread_join(pthread_t thread_id, void** ret_val); 

int main(void)
{
    pthread_t thread_id; 
    void** pp;  

    pthread_create(&thread_id, NULL, thread_function, NULL); 
    pthread_join(thread_id, pp); /* First Degree Moronic Code*/

    return (0); 
}
// 1) ISSUE 
// 2) ISSUE R&D. 
/////////////////////////////////////////////////////////////////////////////




