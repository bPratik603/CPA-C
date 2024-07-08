#include<stdio.h>
#include<stdlib.h>

// 1
void merge(int* a,int p,int q,int r)
{
    int N1 = q-p+1;
    int N2 = r-q;

    int* a1  = NULL;
    int* a2 =  NULL;
  
    int k,k1,k2;

    a1 = (int*)malloc(N1 * sizeof(int));
    a1 = (int*)malloc(N2 * sizeof(int));

    for(k=0;k<N1;++k)
    {
        a1[k] = a[p+k];
    }

    for(k=0;k<N2;++k)
    {
        a2[k] = a[q+1+k];
    }

    k=0;
    k1=0;
    k2=0;

    while(1)
    {
        if(a1[k1] <= a1[k2])
        {
            a[p+k] = a1[k1];
            ++k;
            ++k1;
            if(k1 == N1)
            {
                while(k2 < N2)
                {
                    a[p+k] = a2[k2];
                    ++k;
                    ++k2;
                }
                break;
            }
        }
        else
        {
            a[p+k] = a2[k2];
            ++k;
            ++k2;
            if(k2 == N2)
            {
                while(k1 < N1)
                {
                    a[p+k] = a1[k1];
                    ++k;
                    ++k1;
                }
                break;
            }
        }
    }
}

// 2
 void merge(int* a,int p,int q,int r)
 {
    int N1 = q-p+1;
    int N2 = r-q;

    int* a1 = NULL;
    int* a2 = NULL;

    int k,k1,k2;

    a1 = (int*)malloc(N1 * sizeof(int));
    a2 = (int*)malloc(N2 * sizeof(int));

    for(k=0;k<N1;++k)
    {
        a1[k] = a[p+k];
    }

    for(k=0;k<N2;++k)
    {
        a2[k] = a[q+1+k];
    }

    k=0;
    k1 =0;
    k2 =0;

    while(1)
    {
        if(a1[k1] <= a2[k2])
        {
            a[p+k] = a1[k1];
            ++k;
            ++k1;

            if(k1 == N1)
            {
                while(k2 < N2)
                {
                a[p+k] = a2[k2];
                ++k;
                ++k2;
                }
                break;
            }
        }
        else
        {
           a[p+k] = a2[k2];
           ++k;
           ++k2;
           if(k2 == N2)
           {
            while(k1 < N1)
            {
                a[p+k] = a1[k1];
                ++k;
                ++k1;
            }
            break;
           }
        }
    }
 }


 // 3
void merge(int* a,int p,int q ,int r)
{
    int N1 = q-p+1;
    int N2 = r-q;

    int* a1 = (int*)malloc(N1 * sizeof(int));
    int* a2 = (int*)malloc(N2 * sizeof(int));

    int k,k1,k2;

    for(k=0;k<N1;++k)
    {
        a1[k] = a[p+k];
    }

    for(k=0;k<N2;++k)
    {
        a2[k2] = a[q+1+k];
    }

    k=0;
    k1=0;
    k2=0;

    while(1)
    {
        if(a1[k1] <= a2[k2])
        {
            a[p+k] = a1[k1];
            ++k;
            ++k1;
            if(k1 == N1)
            {
                while(k2 < N2)
                {
                   a[p+k] = a2[k2];
                   ++k;
                   ++k2;
                }
                break;
            }
        }
        else
        {
              a[p+k] =a2[k2];
              ++k;
              ++k2;
              if(k2 == N2)
              {
                while(k1 < N1)
                {
                    a[p+k] = a1[k1];
                    ++k;
                    ++k1;
                }
                break;
              }
        }
    }
}

// 4
void merge(int* a,int p,int q,int r)
{
    int N1 = q-p+1;
    int N2 = r-q;

    int* a1 = (int*)malloc(N1 * sizeof(int));
    int* a2= (int*)malloc(N2 * sizeof(int));

    int k,k1,k2;

    for(k=0;k<N1;++k)
    {
        a1[k] = a[p+k];
    }

    for(k=0;k<N2;++k)
    {
        a2[k2] = a[q+1+k];
    }

    k=0;
    k1=0;
    k2=0;
    while(1)
    {
        if(a1[k1] <= a2[k2])
        {
            a[p+k] = a1[k1];
            ++k;
            ++k1;
            if(k1 == N1)
            {
                while(k2 < N2)
                {
                  a[p+k] = a2[k2];
                  ++k;
                  ++k2;
                } 
                break;
            }
        } 
        else
        {
           a[p+k] = a2[k2];
           ++k;
           ++k2;
           if(k2 == N2)
           {
            while(k1 < N1)
            {
                a[p+k] = a1[k1];
                ++k;
                ++k1;
            }
            break;
           }
        }
    }

}
// 5
void merge(int* a,int p,int q,int r)
{
    int N1 = q-p+1;
    int N2 = r-q;

    int* a1 = (int*)malloc(N1 * sizeof(int));
    int* a2= (int*)malloc(N2 * sizeof(int));

    int k,k1,k2;

    for(k=0;k<N1;++k)
    {
        a1[k] = a[p+k];
    }

    for(k=0;k<N1;++k)
    {
        a2[k] = a[q+1+k];
    }
    k=0;
    k1=0;
    k2=0;

    while(1)
    {
        if(a1[k1] <= a2[k2])
        {
            a[p+k]  = a1[k1];
            ++k;
            ++k1;
        
           if(k1 == N1)
           {
            while(k2 < N2)
            {
                a[p+k] = a2[k2];
                ++k;
                ++k2;
            }
            break;
           }
        }
        else{

            a[p+k] = a2[k2];
            ++k;
            ++k2;
            if(k2 == N2)
            {
                while(k1 < N1)
                {
                    a[p+k] = a1[k1];
                    ++k;
                    ++k1;
                }
                break;
            }
        }

    }
}