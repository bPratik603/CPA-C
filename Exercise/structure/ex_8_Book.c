#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PUBLISHER_NAME_CHAR                        100   
#define MAX_PUBLISHER_BACK_NAME_CHAR                   100
#define MAX_LANGUAGE_NAME_CHAR                         100
#define MAX_PAPERBACK_NAME_CHAR                        100
#define MAX_READING_AGE_FRONT_NAME_CAHR                100
#define MAX_READING_AGE_BACK_NAME_CHAR                 100
#define MAX_DIMENSIONS_UNIT_NAME_CHAR                  100
#define MAX_COUNTRY_OF_ORIGIN_NAME_CHAR                 100


struct Publisher
{
   int day;
   int year;
};

struct PaperBack
{
    int Page_Number;
};

struct Isbn_10
{
    long long Number;
};

struct Isbn_13
{
    long long Number;
};

struct Reading_Age
{
    int Age;
};

struct Item_Weight
{
    int Weight;
};

struct Dimensions
{
    float Lx;
    float Wx;
    float H;
};

struct Book
{
    char Publisher_Name[MAX_PUBLISHER_NAME_CHAR];
    char Publisher_Back_Name[MAX_PUBLISHER_BACK_NAME_CHAR];
    char Language_Name[MAX_LANGUAGE_NAME_CHAR];
    char PaperBack_Name[MAX_PAPERBACK_NAME_CHAR];
    char Reading_Age_Front_Name[MAX_READING_AGE_FRONT_NAME_CAHR];
    char Reading_Age_Back_Name[MAX_READING_AGE_BACK_NAME_CHAR];
    char Dimensions_Unit_Name[MAX_DIMENSIONS_UNIT_NAME_CHAR];
    char Country_Of_Origin_Name[MAX_COUNTRY_OF_ORIGIN_NAME_CHAR];
    
   struct Publisher Publisher_Number;
   struct PaperBack PaperBacke_Number;
   struct Isbn_10 Isbn_10_Number;
   struct Isbn_13 isbn_13_Number;
   struct Reading_Age Reading_Age_Number;
   struct Item_Weight Item_Weight_Number;
   struct Dimensions Dimensions_Number;

};

int main(void)
{
    struct Book My_Book;

    strncpy(My_Book.Publisher_Name,
    "Random House Business Books",strlen("Random House Business Books"));

    strncpy(My_Book.Publisher_Back_Name,"October",strlen("October"));

    strncpy(My_Book.Language_Name,"English",strlen("English"));

    strncpy(My_Book.PaperBack_Name,"Pages",strlen("Pages"));

    strncpy(My_Book.Reading_Age_Front_Name,
    "Customer Suggested Age:",strlen("Customer Suggested Age:"));

    strncpy(My_Book.Reading_Age_Back_Name,
    "Years and Up\0",strlen("Years and Up\0"));

    strncpy(My_Book.Dimensions_Unit_Name,"cm",strlen("cm"));

    strncpy(My_Book.Country_Of_Origin_Name,"United Kingdom",strlen("United Kingdom"));

    My_Book.Publisher_Number.day = 30;
    My_Book.Publisher_Number.year = 2018;
    My_Book.PaperBacke_Number.Page_Number = 288;
    My_Book.Isbn_10_Number.Number = 1847941834;
    My_Book.isbn_13_Number.Number = 9781847941831;
    My_Book.Reading_Age_Number.Age = 13;
    My_Book.Item_Weight_Number.Weight = 390;
    My_Book.Dimensions_Number.Lx = 15.3;
    My_Book.Dimensions_Number.Wx = 2.3;
    My_Book.Dimensions_Number.H = 23.4;

    printf("Publisher: %s (%d %s %d)\n",
    My_Book.Publisher_Name,
    My_Book.Publisher_Number.day,
    My_Book.Publisher_Back_Name,
    My_Book.Publisher_Number.year);

    printf("Language: %s\n",My_Book.Language_Name);
    printf("PaperBack: %d %s\n",
    My_Book.PaperBacke_Number.Page_Number,
    My_Book.PaperBack_Name);

    printf("ISBN-10: %lld\n",My_Book.Isbn_10_Number.Number);
    printf("ISBN-13: %lld\n",My_Book.isbn_13_Number.Number);
    printf("Reading Age: %s %d %s\n",
    My_Book.Reading_Age_Front_Name,
    My_Book.Reading_Age_Number.Age,
    My_Book.Reading_Age_Back_Name);
    
    printf("Item Weight: %d\n",My_Book.Item_Weight_Number.Weight);
    printf("Dimensions: %f*%f*%f\n",
    My_Book.Dimensions_Number.Lx,
    My_Book.Dimensions_Number.Wx,
    My_Book.Dimensions_Number.H,
    My_Book.Dimensions_Unit_Name);

    printf("Country of Origin Name: %s\n",My_Book.Country_Of_Origin_Name);

    return (0);
}