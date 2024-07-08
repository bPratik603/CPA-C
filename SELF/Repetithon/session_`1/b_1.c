#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

void test_1(void);
void test_2(void);
void test_3(void);

int main(void)
{
    test_1();
    test_2();
    test_3();

   return (0);
}

void test_1()
{
    puts("test_1");
    puts("------------------------------prog: 1------------------------------");
    char* p_char = NULL;

    p_char = (char*)malloc(sizeof(char));

    if(p_char == NULL)
    {
        puts("Error in allocating memory");
        exit(EXIT_FAILURE);
    }

    *p_char = 'A';
    printf("*p_char = %c\n",*p_char);

    free(p_char);
    p_char  = NULL;


puts("------------------------------prog: 2------------------------------");
    
   short* p_short = NULL;
   
   p_short = (short*)malloc(sizeof(short));
   if(p_short == NULL)
   {
    puts("Error in allocating memory");
    exit(EXIT_FAILURE);
   }

   *p_short = 1234;
   printf("*p_short = %hd\n",*p_short);
   
   free(p_short);
   p_short = NULL;

puts("------------------------------prog: 3------------------------------");

    float* p_float = NULL;

    p_float = (float*)malloc(sizeof(float));
    if(p_float == NULL)
    {
        puts("Error in allcating memory");
        exit(EXIT_FAILURE);
    }

    *p_float = 12.234;
    printf("*p_float = %.2f\n",*p_float);

    free(p_float);
    p_float = NULL;

puts("------------------------------prog: 4------------------------------");

   struct Date
   {
    int day;
    int month;
    int year;
   };

   struct Date* p_Date = NULL;

   p_Date = (struct Date*)malloc(sizeof(struct Date));

   if(p_Date == NULL)
   {
    puts("Error in allocating memory");
    exit(EXIT_FAILURE);
   }

   p_Date->day = 1;
   p_Date->month = 2;
   p_Date->year = 2022;

   printf("*p_Date = %d-%d-%d\n\n",p_Date->day,p_Date->month, p_Date->year);

   free(p_Date);
   p_Date = NULL;
   

}

void test_2(void)
{
    puts("test_2");
    puts("------------------------------prog: 1------------------------------");

 int* pInt = NULL;

 pInt = (int*)malloc(sizeof(int));
 
 if(pInt == NULL)
 {
    puts("Error in allocating memory");
    exit(EXIT_FAILURE);
 }

*pInt = 123455;
printf("*pInt = %d\n",*pInt);

free(pInt);
pInt = 0;

puts("------------------------------prog: 2------------------------------");

   typedef double DOUBLE;

   DOUBLE* p_double = NULL;
    
    p_double = (DOUBLE*)malloc(sizeof(DOUBLE));
   if(p_double == NULL)
   {
    puts("Error in allocating memory");
    exit(EXIT_FAILURE);
   }

   *p_double = 6.28;
   printf("*p_double = %.2lf\n",*p_double);

   free(p_double);
   p_double = NULL;

puts("------------------------------prog: 3------------------------------");

   UINT* puInt = NULL;

   puInt = (UINT*)malloc(sizeof(UINT));
   if(puInt == NULL)
   {
    puts("Error in allocating memroy");
    exit(EXIT_FAILURE);
   } 

   *puInt = 1341234;
   printf("*puInt = %u\n",*puInt);

   free(puInt);
   puInt = NULL;

puts("------------------------------prog: 4------------------------------");

   typedef struct tagNode
   {
    INT iData;
    struct tagNode* prevLink;
    struct tagNode* nextLink;

   }NODE, *PNODE;

   PNODE pNode = (PNODE)malloc(sizeof(NODE));
   if(pNode == NULL)
   {
    puts("Error in allocating memory");
    exit(EXIT_FAILURE);
   }

   pNode->iData = 1000;
   pNode->prevLink = pNode;
   pNode->nextLink = pNode;

  // printf("tagNode = %d-%d-%d\n",pNode->iData,pNode->prevLink,pNode->nextLink);

   free(pNode);
   pNode = 0;
}

void test_3(void)
{
    puts("test_3");
    puts("------------------------------prog: 1------------------------------");

   size_t N  = 8;
   size_t i;

   int* p_arr = NULL;
   p_arr = (int*)malloc(N * sizeof(int));
   
   if(p_arr == NULL)
   {
    puts("Error in allcoating memory");
    exit(EXIT_FAILURE);
   }

  for(i = 0;i<N;++i)
  {
    p_arr[i] = (i + 1) * 100;
  }

  for(i = 0;i<N;++i)
  {
    printf("*p_arr[%llu] = %d\n",i,p_arr[i]);
  }

  free(p_arr);
  p_arr = NULL;

puts("------------------------------prog: 2------------------------------");

float* p_float = NULL;
p_float = (float*)malloc(N * sizeof(float));

if(p_float == NULL)
{
    puts("Error in allocating memory");
    exit(EXIT_FAILURE);
}

  for(i = 0;i<N;++i)
  {
    *(p_float + i) = (i + 1) * 1.11;
  }

for(i = 0;i<N;++i)
{
  printf("*(p_float + %llu) = %.2f\n",i,*(p_float + i));
}

free(p_float);
p_float = NULL;

puts("------------------------------prog: 3------------------------------");

    struct Date
    {
        int day;
        int month;
        int year;
    };

   struct Date* p_Date = NULL;
   p_Date = (struct Date*)malloc(N * sizeof(struct Date));
   if(p_Date == NULL)
   {
    puts("error in allocating memory");
    exit(EXIT_FAILURE);
   }

   for(i =0;i<N;++i)
   {
    p_Date[i].day = 21 + i;
    p_Date[i].month = 10 - i;
    p_Date[i].year = 1990 + i;
   }

   for(i = 0;i<N;++i)
   {
    printf("Date(%llu) = %d-%d-%d\n",i,p_Date[i].day,p_Date[i].month,p_Date[i].year);
   }

   free(p_Date);
   p_Date = 0;
}