#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BRAND_NAME_CHAR                                     100    
#define MAX_SPECIAL_FEATURE_NAME_CHAR                           100
#define MAX_FORM_FACTOR_NAME_CHAR                               100
#define MAX_COLOUR_NAME_CHAR                                    100
#define MAX_FILTER_TYPE_NAME_CHAR                               100
#define MAX_MODEL_NAME_CHAR                                     100

struct Vacuum_Cleaner
{
    char Brand_Name[MAX_BRAND_NAME_CHAR];
    char Special_Feture_Name[MAX_SPECIAL_FEATURE_NAME_CHAR];
    char Form_Factor_Name[MAX_FORM_FACTOR_NAME_CHAR];
    char Colour_Name[MAX_COLOUR_NAME_CHAR];
    char Filter_Type_Name[MAX_FILTER_TYPE_NAME_CHAR];
    char Model_Name[MAX_MODEL_NAME_CHAR];
};

int main(void)
{
      struct Vacuum_Cleaner My_Vacuum_Cleaner;

      strncpy(My_Vacuum_Cleaner.Brand_Name,"AGARO",strlen("AGARO"));
      strncpy(My_Vacuum_Cleaner.Special_Feture_Name,"Wet/Dry,Wheels",strlen("Wet/Dry,Wheels"));
      strncpy(My_Vacuum_Cleaner.Form_Factor_Name,"Cannister",strlen("Cannister"));
      strncpy(My_Vacuum_Cleaner.Colour_Name,"Black",strlen("Black\0"));
      strncpy(My_Vacuum_Cleaner.Filter_Type_Name,"HEPA",strlen("HEPA"));
      strncpy(My_Vacuum_Cleaner.Model_Name,"ACE",strlen("ACE"));

      printf("Brand: %s\n",My_Vacuum_Cleaner.Brand_Name);
      printf("Special Feture: %s\n",My_Vacuum_Cleaner.Special_Feture_Name);
      printf("Colour: %s\n",My_Vacuum_Cleaner.Colour_Name);
      printf("Form Factor: %s\n",My_Vacuum_Cleaner.Form_Factor_Name);
      printf("Colour: %s\n",My_Vacuum_Cleaner.Colour_Name);
      printf("Filter Type: %s\n",My_Vacuum_Cleaner.Filter_Type_Name);
      printf("Model Name: %s\n",My_Vacuum_Cleaner.Model_Name);

      return (0);
}