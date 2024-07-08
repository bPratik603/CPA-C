#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE_ABOVE_CHARS             100
#define MAX_SIZE_YEAR                    100
#define MAX_SPORTS_NAME_CHARS            100
#define MAX_BRAND_NAME_CHARS             100
#define MAX_MATERIAL_NAME_CHARS          100
#define MAX_COLOUR_NAME_CHARS            100
#define MAX_HANDLE_MATERIAL_NAME_CHARS   100
#define MAX_DESCRIPTION_CHARS            100


struct Size
{
    int age;
};

struct Criket_Bat
{
   char Size_Above[MAX_SIZE_ABOVE_CHARS];
   char Size_Year[MAX_SIZE_YEAR];
   char Sports_Name[MAX_SPORTS_NAME_CHARS];
   char Brand_Name[MAX_BRAND_NAME_CHARS];
   char Material_Name[MAX_MATERIAL_NAME_CHARS];
   char Colour_Name[MAX_COLOUR_NAME_CHARS];
   char Handle_Material_Name[MAX_HANDLE_MATERIAL_NAME_CHARS];
   char Description[MAX_DESCRIPTION_CHARS];

   struct Size Enter_Age;
};

int main(void)
{
    struct Criket_Bat My_Criket_Bat;

    strncpy(My_Criket_Bat.Size_Above,"Above",strlen("Above"));
    strncpy(My_Criket_Bat.Size_Year,"Years",strlen("Years"));
    strncpy(My_Criket_Bat.Sports_Name,"Criket ",strlen("Criket "));
    strncpy(My_Criket_Bat.Brand_Name,"XSTROX ",strlen("XSTROX "));
    strncpy(My_Criket_Bat.Material_Name,"Popular Willow",strlen("Popular Willow"));
    strncpy(My_Criket_Bat.Colour_Name,"Natural ",strlen("Natural "));
    strncpy(My_Criket_Bat.Handle_Material_Name,"Wood ",strlen("Wood "));
    strncpy(My_Criket_Bat.Description,
    "Light weight with full control, Can Play with soft tennis ball",
    strlen("Light weight with full control, Can Play with soft tennis ball"));

    My_Criket_Bat.Enter_Age.age = 15;

    printf("Size:            %s %d %s\n",
     My_Criket_Bat.Size_Above,
     My_Criket_Bat.Enter_Age.age,
     My_Criket_Bat.Size_Year);

    printf("Sports:          %s \n",My_Criket_Bat.Sports_Name);
    printf("Brand:           %s \n", My_Criket_Bat.Brand_Name);
    printf("Material:        %s \n",My_Criket_Bat.Material_Name);
    printf("Colour:          %s \n",My_Criket_Bat.Colour_Name);
    printf("Handle Material: %s \n",My_Criket_Bat.Handle_Material_Name);
    printf("Description:     %s \n",My_Criket_Bat.Description);
    return (0);
}