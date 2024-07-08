#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BRAND_NAME_CHAR                          100
#define MAX_COLOUR_NAME_CHAR                         100
#define MAX_MATERIAL_NAME_CHAR                       100
#define MAX_BLADE_MATERIAL_NAME_CHAR                 100
#define MAX_PRODUCT_DIMENSIONS_UNIT_NAME_CAHR        100


struct Number_Of_Speed
{
    int Speed;
};

struct Product_Dimensions
{
    float dx;
    float wx;
    float h;
};

struct Mixer_Grinder
{
    char Brand_Name[MAX_BRAND_NAME_CHAR];
    char Colour_Name[MAX_COLOUR_NAME_CHAR];
    char Material_Name[MAX_MATERIAL_NAME_CHAR];
    char Blade_Material_Name[MAX_BLADE_MATERIAL_NAME_CHAR];
    char product_Dimensions_Unit_Name[MAX_PRODUCT_DIMENSIONS_UNIT_NAME_CAHR];

    struct Number_Of_Speed Number_Of_Speed_Number;
    struct Product_Dimensions Product_Dimensions_Number; 
};

int main(void)
{
    struct Mixer_Grinder My_Mixer_Grinder;

    strncpy(My_Mixer_Grinder.Brand_Name,"Life_Long",strlen("Life_Lond"));
    strncpy(My_Mixer_Grinder.Colour_Name,"Black",strlen("Black"));
    strncpy(My_Mixer_Grinder.Material_Name,"Stainless_Steel",strlen("Stainless_Steel"));
    strncpy(My_Mixer_Grinder.Blade_Material_Name,"Stainless_Steel",
    strlen("Stainless_Steel\0"));
    strncpy(My_Mixer_Grinder.product_Dimensions_Unit_Name,"cm",strlen("cm"));

    My_Mixer_Grinder.Number_Of_Speed_Number.Speed = 3;
    My_Mixer_Grinder.Product_Dimensions_Number.dx = 23.3;
    My_Mixer_Grinder.Product_Dimensions_Number.wx = 35.1;
    My_Mixer_Grinder.Product_Dimensions_Number.h = 20;

   printf("Brand: %s\n",My_Mixer_Grinder.Brand_Name);
   printf("Colour: %s\n",My_Mixer_Grinder.Colour_Name);
   printf("Material: %s\n",My_Mixer_Grinder.Material_Name);
   printf("Blade_Material %s\n",My_Mixer_Grinder.Blade_Material_Name);
   printf("Number of Speeds: %d\n",My_Mixer_Grinder.Number_Of_Speed_Number.Speed);
   printf("Product Dimensions: %.fDx*%.fWx*%2.fH\n",
   My_Mixer_Grinder.Product_Dimensions_Number.dx,
   My_Mixer_Grinder.Product_Dimensions_Number.wx,
   My_Mixer_Grinder.Product_Dimensions_Number.h,
   My_Mixer_Grinder.product_Dimensions_Unit_Name);
}