int get_int_1(void); 
int get_int_1(void); 
int get_int_1(void); 
int get_int_1(void); 
int get_int_1(void); 

void get_int_2(int* p_n); 
void get_int_2(int* p_n); 
void get_int_2(int* p_n); 
void get_int_2(int* p_n); 
void get_int_2(int* p_n); 

int main(void)
{
    int ret1, ret2, ret3, ret4, ret5; 
    int n1, n2, n3, n4, n5; 

    ret1 = get_int_1(); 
    ret2 = get_int_1(); 
    ret3 = get_int_1(); 
    ret4 = get_int_1(); 
    ret5 = get_int_1(); 

    get_int_2(&n1); 
    get_int_2(&n2); 
    get_int_2(&n3); 
    get_int_2(&n4); 
    get_int_2(&n5); 
}

int get_int_1(void)
{
    return 10; 
}

int get_int_1(void)
{
    return 15; 
}

int get_int_1(void)
{
    return 20; 
}

int get_int_1(void)
{
    return 25; 
}

int get_int_1(void)
{
    return 30; 
}

void get_int_2(int* p_n)
{
    *p_n = 10; 
}

void get_int_2(int* p_n)
{
    *p_n = 20; 
}

void get_int_2(int* p_n)
{
    *p_n = 30; 
}

void get_int_2(int* p_n)
{
    *p_n = 40; 
}

void get_int_2(int* p_n)
{
    *p_n = 50; 
}