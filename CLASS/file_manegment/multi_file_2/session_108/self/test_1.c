void f1(void);
void f2(void);
extern print_test(void);

int main(void)
{
    print_test();
    f1();
    print_test();
    f2();
    print_test();
}

void f1(void)
{
    extern int g_num;
    g_num = 500;
}

void f2(void)
{
    extern int g_num;
    g_num = 1000;
}