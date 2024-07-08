#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_DIAMETER_UNIT_NAME_CHARS         100
#define MAX_COLOUR_NAME_CHARS                100
#define MAX_MATERIAL_TYPE_NAME_CHARS         100
#define MAX_MODEL_NAME_CHARS                 100
#define MAX_COUNTRY_OF_ORIGIN_NAME_CHARS     100
#define MAX_ABOUT_THIS_ITOM_CHARS            100
#define MAX_DESCRIPTION_CHARS                100
#define MAX_MANUFACTURER_NAME_CHARS          100
#define MAX_PACKER_NAME_CHARS                100
#define MAX_IMPORTER_NAME_CHARS              100
#define MAX_ITOM_DIMENSIONS_UNIT_NAME_CHARS  100
#define MAX_NET_QUANTITY_COUNT_CHARS         100
#define MAX_GENERIC_NAME_CHARS               100

struct Diameter
{
   int Diameter_mm;
};

struct Dimension
{
   int Lx;
   int Wx;
   int H;
};

struct Quntity
{
    float Number;
};
struct Watch
{
   char Diameter_Unit_Name[MAX_DIAMETER_UNIT_NAME_CHARS];
   char Colour_Name[MAX_COLOUR_NAME_CHARS];
   char Material_Type_Name[MAX_MATERIAL_TYPE_NAME_CHARS];
   char Model_Name[MAX_MODEL_NAME_CHARS];
   char Country_Of_Origin_Name[MAX_COUNTRY_OF_ORIGIN_NAME_CHARS];
   char About_This_Itom[MAX_ABOUT_THIS_ITOM_CHARS];
   char Description[MAX_DESCRIPTION_CHARS];
   char Manufacturer_Name[MAX_MANUFACTURER_NAME_CHARS];
   char Packer_Name[MAX_PACKER_NAME_CHARS];
   char Importer_Name[MAX_IMPORTER_NAME_CHARS];
   char Itom_Dimention_Unit_Name[MAX_ITOM_DIMENSIONS_UNIT_NAME_CHARS];
   char Net_Quantity_Count[MAX_NET_QUANTITY_COUNT_CHARS];
   char Generic_Name[MAX_GENERIC_NAME_CHARS];

   struct Diameter Diameter_Numbers;
   struct Dimension Dimension_Numbers;
   struct Quntity Quntity_Number;

};

int mian(void)
{
   struct Watch My_Watch;

   strncpy(My_Watch.Diameter_Unit_Name,
   "Milimeter",strlen("Milimeter")); 
   
   strncpy(My_Watch.Colour_Name,
   "Black",strlen("Black"));
   
   strncpy(My_Watch.Material_Type_Name,
   "Leather",strlen("Leather"));
   
   strncpy(My_Watch.Model_Name,
   "Janata",strlen("Janata"));
   
   strncpy(My_Watch.Country_Of_Origin_Name,
   "India",strlen("India"));
   
   strncpy(My_Watch.About_This_Itom,
   "Mechanical Movement;Genuine Leather Belt",
   strlen("Mechanical Movement;Genuine Leather Belt"));
   
   strncpy(My_Watch.Description,
   "Janata Premium Collection",
   strlen("Janata Premium Collection"));
   
   strncpy(My_Watch.Manufacturer_Name,
   "HMT",strlen("HMT"));
   
   strncpy(My_Watch.Packer_Name,
   "Navnath Enterprises - Mumbai",strlen("Navnath Enterprises - Mumbai"));
   
   strncpy(My_Watch.Importer_Name,
   "Discover Diamonds",strlen("Discover Diamonds"));
   
   strncpy(My_Watch.Itom_Dimention_Unit_Name,
   "Milimeter",strlen("Milimeter"));
 
   strncpy(My_Watch.Net_Quantity_Count,
   "Count",strlen("Count"));

   strncpy(My_Watch.Generic_Name,
   "Certified Pre-owned Watch",strlen("Certified Pre-owned Watch"));

   My_Watch.Diameter_Numbers.Diameter_mm = 35;
   My_Watch.Dimension_Numbers.Lx = 44;
   My_Watch.Dimension_Numbers.Wx = 35;
   My_Watch.Dimension_Numbers.H = 10;
   My_Watch.Quntity_Number.Number = 1.00;

   printf("Case Diameter: %d %s",
   My_Watch.Diameter_Numbers.Diameter_mm,
   My_Watch.Diameter_Unit_Name);
 
  printf("Band Colour: %s",
  My_Watch.Colour_Name);

  printf("Band Material Name: %s",
  My_Watch.Material_Type_Name);

  printf("Model Name: %s",
   My_Watch.Model_Name);

  printf("Country Of Origin: %s",
  My_Watch.Country_Of_Origin_Name);

  printf("About This Itom: %s",
  My_Watch.About_This_Itom );

  printf("Description: %s",
  My_Watch.Description);

  printf("Manufacture: %s",
  My_Watch.Manufacturer_Name);

  printf("Packer: %s",
  My_Watch.Packer_Name);

  printf("Importer: %s",
  My_Watch.Importer_Name);

  printf("Itom Dimension LxWxH: %d*%d*%d %s",
  My_Watch.Dimension_Numbers.Lx,
  My_Watch.Dimension_Numbers.Wx,
  My_Watch.Dimension_Numbers.H,
  My_Watch.Itom_Dimention_Unit_Name );

  printf("Net Quntity: %f %s",
  My_Watch.Quntity_Number.Number,
  My_Watch.Net_Quantity_Count);

  printf("Generic Name: %s",
  My_Watch.Generic_Name);

 return (0);
}