#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BRAND_NAME_CHARS                             100
#define MAX_HAIR_TYPE_NAME_CHARS                         100
#define MAX_PRODUCTS_BENIFITS_FRONT_NAME_CHARS           100
#define MAX_PRODUCTS_BENIFITS_BACK_NAME_CHARS            100
#define MAX_LIQUID_VOLUME_NAME_CHARS                     100
#define MAX_RECOMMENDED_UESR_FOR_PRODUCT_NAME_CHARS      100 
#define MAX_NET_QUNTITY_NAME_CHARS                       100

struct Product_Benefits
{
    int Enter_Hours;
};

struct Liquid_Volume
{
    int Enter_Volume;
};

struct Net_Quntity
{
    int Enter_Quntity;
};

struct Shampoo
{
    char Brand_Name[MAX_BRAND_NAME_CHARS];
    char Haire_Type_Name[MAX_HAIR_TYPE_NAME_CHARS];
    char Product_Benefits_Front_Name[MAX_PRODUCTS_BENIFITS_FRONT_NAME_CHARS];
    char Product_Benefits_Back_Name[MAX_PRODUCTS_BENIFITS_BACK_NAME_CHARS];
    char  Liquid_Volume_Unit_Name[MAX_LIQUID_VOLUME_NAME_CHARS];
    char  Recommended_Uses_For_Product_Name[MAX_RECOMMENDED_UESR_FOR_PRODUCT_NAME_CHARS];
    char  Net_Quntity[MAX_NET_QUNTITY_NAME_CHARS];

    struct Product_Benefits Valid_Product_Benefits;
    struct Liquid_Volume Valid_Liquid_Volume;
    struct Net_Quntity Valid_Net_Quntity;

};

int main(void)
{
    struct Shampoo My_shampoo;

    strncpy(My_shampoo.Brand_Name,
    "L'oreal Professional",strlen("L'oreal Professional"));
    strncpy(My_shampoo.Haire_Type_Name,"All Frizzy",strlen("All Frizzy"));
    strncpy(My_shampoo.Product_Benefits_Front_Name,
    "Product Upto",strlen("Product Upto"));
    strncpy(My_shampoo.Product_Benefits_Back_Name,
    "Hours Of Frizz Control",strlen("Hours Of Frizz Control"));
    strncpy(My_shampoo.Liquid_Volume_Unit_Name,"Milliliters",strlen("Milliliters"));
    strncpy(My_shampoo.Recommended_Uses_For_Product_Name,
    "Frizz Manegment",strlen("Frizz Manegment"));
    strncpy(My_shampoo.Net_Quntity,"Count",strlen("Count"));

    My_shampoo.Valid_Product_Benefits.Enter_Hours = 96;
    My_shampoo.Valid_Liquid_Volume.Enter_Volume = 300;
    My_shampoo.Valid_Net_Quntity.Enter_Quntity = 1;

    printf("Brand: %s\n",My_shampoo.Brand_Name);
    printf("Hair Type: %s\n",My_shampoo.Haire_Type_Name);
    printf("Products Benefits: %s %d %s\n",
    My_shampoo.Product_Benefits_Front_Name,
    My_shampoo.Valid_Product_Benefits.Enter_Hours,
    My_shampoo.Product_Benefits_Back_Name);
    printf("Liquid Volume: %d %s\n",
    My_shampoo.Valid_Liquid_Volume.Enter_Volume,
    My_shampoo.Liquid_Volume_Unit_Name);
    printf("Recommended Uses For Product: %s\n",
    My_shampoo.Recommended_Uses_For_Product_Name);
    printf("Net Quntity: %d %s\n",
    My_shampoo.Valid_Net_Quntity.Enter_Quntity,
    My_shampoo.Net_Quntity);

    return (0);
}