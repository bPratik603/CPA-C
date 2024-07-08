#include <stdio.h> 
#include <stdlib.h> 
#include "sort.h"

void cpa_sort(void *arr, int N, int nmem, int(*compare)(const void*, const void*))
{
    int i, j;   /* Index variables -> Insertion sort*/
    void* key = NULL; 

    /* 
        Create a temporary variable of data type of array 
        Though data type name of array element type is known 
        the size of array element type is known. Therefore, we 
        can allocate an instance of array element type using 
        dynamic memory allocation function malloc() -> as 
        it requires only size of data type instance and not its 
        actual name to allocate an instance of the same. 
    */

    key = malloc(nmem); 
    if(key == NULL)
    {
        puts("Error in allocating memory");
        exit(EXIT_FAILURE); 
    }

    for(j=1; j<N; ++j)
    {
        /* key = arr[j] */ 
        memcpy(key, ((char*)arr) + j * nmem, nmem); 
        i = j - 1; 
        /* while(i > -1 && arr[i] > key)*/
        while(i > -1 && compare(((char*)arr) + i * nmem, key) > 0)
        {
            /* arr[i+1] = arr[i]; */
            memcpy(
                ((char*)arr) + (i+1) * nmem, 
                ((char*)arr) + i * nmem, 
                nmem
            ); 
            i = i - 1; 
        }

        /* arr[i+1] = key*/
        memcpy(
            ((char*)arr) + (i+1) * nmem, 
            key, 
            nmem
        ); 
    }
    
    free(key); 
    key = NULL; 
}

/* 
    struct student arr[5]; 

    arr[3]      arr[0] 

    arr[3].roll = arr[0].roll; 
    arr[3].marks = arr[0].marks; 
    arr[3].attnd = arr[0].attnd; 

    memcpy(
        &arr[3], 
        &arr[0], 
        sizeof(struct student)
    ); 
*/