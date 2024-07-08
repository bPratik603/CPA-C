/* 
    Proof that local static variable gets allocated only once 
    and non-static local variable is allocated per call. 
*/

void test_fun(void); 
void other_fun(void); 

int main(void)
{
    puts("1:test_fun() call 1 from main()"); 
    test_fun();     

    other_fun(); 

    return (0); 
}

void test_fun(void)
{
    int n; 
    static int yogeshwar; 
    static int m; 
    

    printf("&n = %p\n", &n); 
    printf("&m = %p\n", &m); 
    printf("&yogeshwar=%p\n", &yogeshwar); 
}

void other_fun()
{
    int a[5]; 
    double d[10]; 

    puts("test_fun() call 2 from other_fun()"); 
    test_fun(); 
}