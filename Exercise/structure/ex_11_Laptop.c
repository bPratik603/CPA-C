#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BRAND_NAME_CHAR                                 100
#define MAX_SERIES_FRONT_NAME_CHAR                          100
#define MAX_SERIES_BACK_NAME_CHAR                           100
#define MAX_SREEN_SIZE_NAME_CHAR                            100
#define MAX_COLOUR_NAME_CHAR                                100
#define MAX_CPU_MODEL_NAME_CHAR                             100
#define MAX_RAM_MEMORY_INSTALLED_SIZE_UNIT_NAME_CHAR        100
#define MAX_OPERATING_SYSTEM_FRONT_NAME_CHAR                100
#define MAX_OPERATING_SYSTEM_BACK_NAME_CHAR                 100
#define MAX_SPECIAL_FEATURE_NAME_CHAR                       100
#define MAX_GRAPHICS_AND_DESCRIPTION_NAME_CHAR              100
#define MAX_GRAPHICS_COPROCESSOR_NAME_CHAR                  100

struct Series
{
    int Number;
};

struct Screen_Size
{
    int size;
};

struct Cpu_Model
{
    int Model_no;
};

struct Ram_Memory_Installed_Size
{
    int size;
};

struct Operating_System
{
    int version;
};

struct Graphics_Processor
{
    int version;
};

struct Laptop
{
   char  Brand_Name[MAX_BRAND_NAME_CHAR];
   char  Series_Front_Name[MAX_SERIES_FRONT_NAME_CHAR];
   char  Series_Back_Name[MAX_SERIES_BACK_NAME_CHAR];
   char  Screen_Size_Name[MAX_SREEN_SIZE_NAME_CHAR];
   char  Colour_Name[MAX_COLOUR_NAME_CHAR];
   char  Cpu_Model_Name[MAX_CPU_MODEL_NAME_CHAR];
   char  Ram_Memory_Installed_Size_Unit_Name[MAX_RAM_MEMORY_INSTALLED_SIZE_UNIT_NAME_CHAR];
   char  operating_system_Front_Name[MAX_OPERATING_SYSTEM_FRONT_NAME_CHAR];
   char  operating_ststem_Back_Name[MAX_OPERATING_SYSTEM_BACK_NAME_CHAR];
   char  Special_Feature_Name[MAX_SPECIAL_FEATURE_NAME_CHAR];
   char  Graphics_And_Description_Name[MAX_GRAPHICS_AND_DESCRIPTION_NAME_CHAR];
   char  Graphics_Coprocessor_Name[MAX_GRAPHICS_COPROCESSOR_NAME_CHAR];

  struct Series Series_Number;
  struct Screen_Size Screen_Size_Number;
  struct Cpu_Model Cpu_Model_Number;
  struct Ram_Memory_Installed_Size Ram_Memory_Installed_Size_Number;
  struct Operating_System Operating_System_Number;
  struct Graphics_Processor Graphics_Processor_Number;
   
};

int main(void)
{
    struct Laptop My_Laptop;

    strncpy(My_Laptop.Brand_Name,"MSI",strlen("MSI"));
    strncpy(My_Laptop.Series_Front_Name,"Katana_GF",strlen("Katana_GF"));
    strncpy(My_Laptop.Series_Back_Name,"E",strlen("E"));
    strncpy(My_Laptop.Screen_Size_Name,"cm",strlen("sm"));
    strncpy(My_Laptop.Colour_Name,"Black",strlen("Black"));
    strncpy(My_Laptop.Cpu_Model_Name,"Intel_Core_i",strlen("Intel_Core_i"));
    strncpy(My_Laptop.Cpu_Model_Name,"Intel_Core",strlen("Intel_Core"));
    strncpy(My_Laptop.Ram_Memory_Installed_Size_Unit_Name,"GB",strlen("GB"));
    strncpy(My_Laptop.operating_system_Front_Name,"Windows",strlen("Windows"));
    strncpy(My_Laptop.operating_ststem_Back_Name,"Home",strlen("Home"));
    strncpy(My_Laptop.Special_Feature_Name,"HD_Audio,Backlit_keybored,Anti_Glare_Coating_Dedicated",
    strlen("HD_Audio,Backlit_keybored,Anti_Glare_Coating_Dedicated"));
    strncpy(My_Laptop.Graphics_And_Description_Name,"Dedicated",strlen("Dedicated"));
    strncpy(My_Laptop.Graphics_Coprocessor_Name,"NVIDIA_Geforce_RTX",strlen("NVIDIA_Geforce_RTX"));

    My_Laptop.Screen_Size_Number.size = 66110;
    My_Laptop.Screen_Size_Number.size = 40;
    My_Laptop.Cpu_Model_Number.Model_no = 7;
    My_Laptop.Ram_Memory_Installed_Size_Number.size = 16;
    My_Laptop.Operating_System_Number.version = 11;
    My_Laptop.Graphics_Processor_Number.version = 3060;

  printf("Brand: %s\n",My_Laptop.Brand_Name);
  printf("Series: %s %d %s\n",
  My_Laptop.Series_Front_Name,
  My_Laptop.Series_Number.Number,
  My_Laptop.Series_Back_Name);
  printf("Screen_Size: %d %s\n",
  My_Laptop.Screen_Size_Number.size,
  My_Laptop.Screen_Size_Name);
  printf("Colour: %s\n",My_Laptop.Colour_Name);
  printf("CPU_Model: %s %d\n",
  My_Laptop.Cpu_Model_Name,
  My_Laptop.Cpu_Model_Number.Model_no);
  printf("Ram_Memory_Installed_Size: %d%s\n",
  My_Laptop.Ram_Memory_Installed_Size_Number.size,
  My_Laptop.Ram_Memory_Installed_Size_Unit_Name);
  printf("Operating_System: %s %d %s\n",
  My_Laptop.operating_system_Front_Name,
  My_Laptop.Operating_System_Number.version,
  My_Laptop.operating_ststem_Back_Name);
  printf("Special_Feture: %s\n",My_Laptop.Special_Feature_Name);
  printf("Graphics_Card_Descriptioin: %s\n",My_Laptop.Graphics_And_Description_Name);
  printf("Graphics_Coprocessor: %s %d\n",
  My_Laptop.Graphics_Coprocessor_Name,
  My_Laptop.Graphics_Processor_Number.version);

  return (0);
}