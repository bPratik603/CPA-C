#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_WEIGHT_UNIT_NAME_CHARS                 100
#define MAX_SIZE_UNIT_NAME_CHARS                   100
#define MAX_BRAND_NAME_CHARS                       100
#define MAX_SPECIALITY_NAME_CHARS                  100
#define MAX_DIET_TYPE_NAME_CHARS                   100
#define MAX_PACKAGE_WEIGHT_UNIT_NAME_CHARS         100
#define MAX_ABOUT_THIS_ITOM_NAME_CHARS             100
#define O %
struct Weight_And_Size
{
    int Enter_Weight;
    int Enter_size;
};

struct Package_Weight
{
    float Enter_Package_Weight;
};

struct Per
{
    int Enter_per;
};

struct Anzir_Zaika
{
    char Weight_Unit_Name[MAX_WEIGHT_UNIT_NAME_CHARS];
    char Size_Unit_Name[MAX_SIZE_UNIT_NAME_CHARS];
    char Brand_Name[MAX_BRAND_NAME_CHARS];
    char Speciality_Name[MAX_SPECIALITY_NAME_CHARS];
    char Diet_Type_Name[MAX_DIET_TYPE_NAME_CHARS];
    char Package_Weight_unit_Name[MAX_PACKAGE_WEIGHT_UNIT_NAME_CHARS];
    char About_This_Itom[MAX_ABOUT_THIS_ITOM_NAME_CHARS];

   struct Weight_And_Size Valid_Weight_And_Size;
   struct Package_Weight Valid_Package_Weight;
   struct Per Valid_Per;
};

int main(void)
{
    struct Anzir_Zaika My_Anzir_Zaika;

    strncpy(My_Anzir_Zaika.Weight_Unit_Name,"Grams",strlen("Grams"));
    strncpy(My_Anzir_Zaika.Size_Unit_Name,"g (Packe Of 1)",strlen("g (Packe Of 1)"));
    strncpy(My_Anzir_Zaika.Brand_Name,"Tulsi",strlen("Tulsi"));
    strncpy(My_Anzir_Zaika.Speciality_Name,
    "Sutaible For Diabetics",strlen("Sutailble For Diabetics"));
    strncpy(My_Anzir_Zaika.Package_Weight_unit_Name,"Kilograms",strlen("Kilograms"));
    strncpy(My_Anzir_Zaika.Diet_Type_Name,"Vegetarian",strlen("Vegetarian"));
    strncpy(My_Anzir_Zaika.About_This_Itom,
    "Per Natural Anjeer/Figs From The House Of Tulsi",
    strlen("Per Natural Anjeer/Figs From The House Of Tulsi"));
    
    printf("Enter Weight:\n");
    scanf("%d",
    &My_Anzir_Zaika.Valid_Weight_And_Size.Enter_Weight);
    
    printf("Enter Size:\n");
    scanf("%d",
    &My_Anzir_Zaika.Valid_Weight_And_Size.Enter_size);
    
    printf("Enter Package Weight:\n");
    scanf("%f",
    &My_Anzir_Zaika.Valid_Package_Weight.Enter_Package_Weight);
    
    printf("Enter Per Natural:\n");
    scanf("%d",
    &My_Anzir_Zaika.Valid_Per.Enter_per);

    printf("Weight: %d %s\n",
    My_Anzir_Zaika.Valid_Weight_And_Size.Enter_Weight,
    My_Anzir_Zaika.Package_Weight_unit_Name);
    printf("Size: %d %s\n",
    My_Anzir_Zaika.Valid_Weight_And_Size.Enter_size,
    My_Anzir_Zaika.Size_Unit_Name);
    printf("Brand: %s\n",My_Anzir_Zaika.Brand_Name);
    printf("Speciality: %s\n",My_Anzir_Zaika.Speciality_Name);
    printf("Diet Type: %s\n",My_Anzir_Zaika.Diet_Type_Name);
    printf("Package Weight: %1.f %s\n",
    My_Anzir_Zaika.Valid_Package_Weight.Enter_Package_Weight,
    My_Anzir_Zaika.Package_Weight_unit_Name);
    printf("About This Itom: %d %s\n",
    My_Anzir_Zaika.Valid_Per.Enter_per,
    My_Anzir_Zaika.About_This_Itom);

    return (0);
}