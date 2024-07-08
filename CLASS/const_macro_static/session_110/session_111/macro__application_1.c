/* 
    Application of macro. 
    As seen in macro_1.c, macro definition and replacement of macro 
    parameters by their arguments happen at compile time. 

    But pre-processed expression may not be evaluable at compile time. 

    Avoiding repetition cannot be the sole reason, as function can be used 
    for the same. 

    Application 1 of macro: 
        Writing single definition for multiple data types but at the cost 
        of type safety. 

    e.g. If you want to write a code which will find max of numbers then 
    you can model it as a function if you dont want to repeat it! 

    But the function must be repeated for every data type for which 
    max amongst 2 logic is needed. 

    int max_int(int a, int b)
    {
        if(a > b)
            return (a); 
        return (b); 
    }

    max_int(34534535.2342342, 'Z')

    char max_char(char a, char b)
    {
        if(a > b)
            return (a); 
        return (b); 
    }

    double max_double(double a, double b)
    {
        if(a > b)
            return (a); 
        return (b); 
    }

    #define MAX(a, b)   ((a) > (b) ? (a) : (b))

    MAX(1, 2)
    MAX('a', 'M')
    MAX(1.1f, 5.6f)
    MAX(2345354.342, 356436345345.35)

    MAX(MADHURI, KATRINA)

     ((a) > (b) ? (a) : (b))

    MAX(%*&^*&^*, ()*&^*&^*&^)

    MAX(1.1, "Hello")



*/