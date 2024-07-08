// 1 
int partition(int* a, int p, int r)
{
    int i; 
    int j; 
    int pivot; 
    int tmp; 

    pivot = a[r]; 
    i = p - 1; 

    for(j = p; j < r; ++j)
    {
        if(a[j] <= pivot)
        {
            i = i + 1; 
            tmp = a[i]; 
            a[i] = a[j]; 
            a[j] = tmp; 
        }
    }

    tmp = a[r]; 
    a[r] = a[i+1]; 
    a[i+1] = tmp; 

    return (i+1); 
}

// 2 
int partition(int* a, int p, int r)
{
    int i; 
    int j; 
    int pivot; 
    int tmp; 

    pivot = a[r]; 
    i = p - 1; 

    for(j = p; j < r; ++j)
    {
        if(a[j] <= pivot)
        {
            i = i + 1;
            tmp = a[i];  
            a[i] = a[j]; 
            a[j] = tmp; 
        }
    }

    tmp = a[r]; 
    a[r] = a[i+1]; 
    a[i+1] = tmp; 

    return (i+1); 
}

// 3 
int partition(int* a, int p, int r)
{
    int i; 
    int j; 
    int pivot; 
    int tmp; 

    pivot = a[r]; 
    i = p - 1; 

    for(j = p; j < r; ++j)
    {
        if(a[j] <= pivot)
        {
            i = i + 1; 
            tmp = a[i]; 
            a[i] = a[j]; 
            a[j] = tmp; 
        }
    }

    tmp = a[r]; 
    a[r] = a[i+1]; 
    a[i+1] = tmp; 

    return (i+1); 
}

 // 4 
int partition(int* a, int p, int r)
{
    int i; 
    int j; 
    int pivot; 
    int tmp; 

    pivot = a[r]; 
    i = p - 1; 

    for(j = p; j < r; ++j)
    {
        if(a[j] <= pivot)
        {
            i = i + 1; 
            tmp = a[i]; 
            a[i] = a[j]; 
            a[j] = tmp; 
        }
    }

    tmp = a[r]; 
    a[r] = a[i+1]; 
    a[i+1]  = tmp; 

    return (i+1); 
}

// 5 
int partition(int* a, int p, int r)
{
    int i; 
    int j; 
    int tmp; 
    int pivot; 

    pivot = a[r]; 
    i = p - 1; 

    for(j = p; j < r; ++j)
    {
        if(a[j] <= pivot)
        {
            i = i + 1; 
            tmp = a[i]; 
            a[i] = a[j]; 
            a[j] = tmp; 
        }
    }

    tmp = a[r]; 
    a[r] = a[i+1]; 
    a[i+1] = tmp; 

    return (i+1); 
}