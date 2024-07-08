#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BRAND_NAME_CHAR                          100
#define MAX_CAPACITY_NAME_CAHR                       100
#define MAX_SPECIAL_FEATURE_FRONT_NAME_CHAR          100
#define MAX_SPECIAL_FEATURE_BACK_NAME_CHAR           100
#define MAX_ENERGY_STAR_NAME_CHAR                    100
#define MAX_COLOUR_NAME_CHAR                         100
#define MAX_VOLTAGE_UNIT_NAME_CHAR                   100
#define MAX_PRODUCT_DIMENSION_UNIT_NAME_CHAR         100
#define MAX_NOISE_LEVEL_UNIT_NAME_CHAR               100

struct Capacity
{
    int num;
};

struct Special_Feature
{
    int front;
    int back;
};

struct Energy_Star
{
    int num;
};

struct Seasonal_Energy_Efficiency_Ratio
{
   float num;
};

struct Voltage
{
    int num;
};

struct Dimensions
{
    int Dx;
    int Wx;
    int H;
};

struct Noise_Level
{
    int num;
};

struct Number_Of_Speed
{
    int num;
};

struct AC
{
    char  Brand_Name[MAX_BRAND_NAME_CHAR];
    char  Capacity_Name[MAX_CAPACITY_NAME_CAHR];
    char  Special_Feature_Front_Name[MAX_SPECIAL_FEATURE_FRONT_NAME_CHAR];
    char  Special_Feature_Back_Name[MAX_SPECIAL_FEATURE_BACK_NAME_CHAR];
    char  Energy_Star_Name[MAX_ENERGY_STAR_NAME_CHAR];
    char  Colour_Name[MAX_COLOUR_NAME_CHAR];
    char  Voltage_Unit_Name[MAX_VOLTAGE_UNIT_NAME_CHAR];
    char  Product_Dimension_Unit_Name[MAX_PRODUCT_DIMENSION_UNIT_NAME_CHAR];
    char  Noise_Level_Unit_Name[MAX_NOISE_LEVEL_UNIT_NAME_CHAR];

   struct Capacity Capacity_Number;
   struct Special_Feature Special_Feature_Number;
   struct Energy_Star Energy_Star_Number;
   struct Seasonal_Energy_Efficiency_Ratio Seasonal_Energy_Efficiency_Ratio_Number;
   struct Voltage Voltage_Number;
   struct Dimensions Dimensions_Number;
   struct Noise_Level Noise_Level_Number;
   struct Number_Of_Speed Number_Of_Speed_Number;

};

int main(void)
{
    struct AC My_AC;

    strncpy(My_AC.Brand_Name,"Godrej",strlen("Godrej"));
    strncpy(My_AC.Capacity_Name,"Tons",strlen("Tons"));
    strncpy(My_AC.Special_Feature_Front_Name,"-in-",strlen("-in-"));
    strncpy(My_AC.Special_Feature_Back_Name,
    "Technology with inverter compressor",strlen("Technology with inverter compressor"));
    strncpy(My_AC.Energy_Star_Name,"Star",strlen("Star"));
    strncpy(My_AC.Colour_Name,"White",strlen("white"));
    strncpy(My_AC.Voltage_Unit_Name,"Volts",strlen("Volts"));
    strncpy(My_AC.Product_Dimension_Unit_Name,"Centimeters",strlen("Centimeters"));
    strncpy(My_AC.Noise_Level_Unit_Name,"db",strlen("db"));
    
    My_AC.Capacity_Number.num = 1;
    My_AC.Special_Feature_Number.front = 5;
    My_AC.Special_Feature_Number.back = 1;
    My_AC.Energy_Star_Number.num = 3;
    My_AC.Voltage_Number.num = 230;
    My_AC.Dimensions_Number.Dx = 21;
    My_AC.Dimensions_Number.Wx = 84;
    My_AC.Dimensions_Number.H = 289;
    My_AC.Noise_Level_Number.num = 37;
    My_AC.Number_Of_Speed_Number.num = 6;

    printf("Brand: %s\n",My_AC.Brand_Name);
    printf("Capacity: %d %s\n",
    My_AC.Capacity_Number.num,
    My_AC.Capacity_Name);
    printf("Special Feature: %d%s%d %s\n",
    My_AC.Special_Feature_Number.front,
    My_AC.Special_Feature_Front_Name,
    My_AC.Special_Feature_Number.back,
    My_AC.Special_Feature_Back_Name);
    printf("Energy Star: %d %s\n",
    My_AC.Energy_Star_Number.num,
    My_AC.Energy_Star_Name);
    printf("Seasonal Energy Efficiency Raio(SEER): %f\n",
    My_AC.Seasonal_Energy_Efficiency_Ratio_Number.num);
    printf("Colour: %s\n",My_AC.Colour_Name);
    printf("Voltage: %d %s",
    My_AC.Voltage_Number.num,
    My_AC.Voltage_Unit_Name);
    printf("Product Dimensions: %dDx*%dWx*%dH %s\n",
    My_AC.Dimensions_Number.Dx,
    My_AC.Dimensions_Number.Wx,
    My_AC.Dimensions_Number.H,
    My_AC.Product_Dimension_Unit_Name);
    printf("Noise Level: %d %s\n",
    My_AC.Noise_Level_Number.num,
    My_AC.Noise_Level_Unit_Name);
    printf("Number of speeds: %d\n",My_AC.Number_Of_Speed_Number.num);

    return (0);
}