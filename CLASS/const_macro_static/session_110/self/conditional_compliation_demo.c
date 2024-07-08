#define define_var(T,Name)     T Name

#define define_node(type)       struct node{\
                                 type data;\
                                 struct node_type* prev;\
                                 struct node_type* next;\
                                 };

int main()
{
    define_var(int,date);
    define_var(float,f);
    define_var(char,c);

    define_node(int);
    define_node(float);
}
