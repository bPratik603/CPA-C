void f1(void); 
void f2(void); 
extern void print_data(void); 

int main(void)
{
    print_data(); 
    f1(); 
    print_data(); 
    f2(); 
    print_data(); 
    return (0); 
}

void f1(void)
{
    extern int g_num; 
    g_num = 500; 
}

void f2(void)
{
   g_num;   // not declared error 
                // to fix this error 
                    // either write extern int g_num; 
                    // in global scope of test_1.c 
                    // or in local scope of f2() 
                    // exeriment with this ! 
}