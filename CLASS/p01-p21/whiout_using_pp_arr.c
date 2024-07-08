void release_array_2(int*** ppp_arr, int N)
{
    int i; 
    
    for(i = 0; i < N; ++i)
    {
        free((*ppp_arr)[i]); 
        (*ppp_arr)[i] = 0; 
    }

    free(*ppp_arr); 
    *ppp_arr = 0; 
}
