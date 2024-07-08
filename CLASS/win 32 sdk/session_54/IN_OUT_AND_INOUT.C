void f(int* p); 

void caller_1(void)
{
    int n; 
    // जाताना गारबेज     
    // येताना मीनिंगफुल  
    // = आउट परमिटर  
    f(&n); 
}

void caller_2(void)
{
    int n = 10; 
    // जाताना मीनिंगफुल 
    // येताना मीनिंगफुल 
    // = इन - आउट परमिटर 
    f(&n); 
}

void caller_3(void)
{
    int a[5] = {10, 20, 30, 40, 50}; 

    // जाताना मीनिंगफुल 
    // Callee is not changing array 
    // = IN PARAMETER 
    f(a); 
}

void caller_4(void)
{
    int a[5]; 

    // जाताना garbage
    // Callee is changing array 
    // = OUT PARAMETER 
    f(a); 
}

void caller_5(void)
{
    int a[5] = {10, 20, 30, 40, 50,}; 

    // जाताना meaningful
    // Callee is changing array 
    // = IN-OUT PARAMETER 
    f(a); 
}
