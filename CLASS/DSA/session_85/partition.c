int partition(int* a, int p, int r)
{
    int i, j, pivot, tmp; 

    pivot = a[r]; 
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

void quick_sort(int* a, int p, int r)
{
    int q; 

    if(p < r)
    {
        q = partition(a, p, r); 
        quick_sort(a, p, q); 
        quick_sort(a, q+1, r); 
    }
}

int main(void)
{
    int a[10] = {values}; 

    show_array(a, SIZE, "Before sort():"); 
    quick_sort(a, 0, 9); 
    show_array(a, SIZE, "After sort():"); 

    return (0); 
}





