#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BRAND_NAME_CHARS                                 100
#define MAX_MODEL_NAME_CHARS                                 100
#define MAX_COLOUR_NAME_CHARS                                100
#define MAX_FORM_FACTOR_NAME_CHARS                           100
#define MAX_CONNECTOR_TYPE_NAME_CHARS                        100
#define MAX_WIRLESS_COMMUNICATION_TECHNOLOGY_NAME_CHARS      100
#define MAX_SPECIAL_FEATURE_NAME_CHARS                       100
#define MAX_AGE_RANGE_NAME_CHARS                             100

struct Model
{
    int Model_Name_Number;
};

struct Connector
{
    float Connector_Type_Number;
};

struct Buds
{
    char Brand_Name[MAX_BRAND_NAME_CHARS];
    char Model_Name[MAX_MODEL_NAME_CHARS];
    char Colour_Name[MAX_COLOUR_NAME_CHARS];
    char Form_Factor_Name[MAX_FORM_FACTOR_NAME_CHARS];
    char Connector_Type_Name[MAX_CONNECTOR_TYPE_NAME_CHARS];
    char Wireless_Cmmunication_Technology_Name[MAX_WIRLESS_COMMUNICATION_TECHNOLOGY_NAME_CHARS];
    char Special_Feature[MAX_SPECIAL_FEATURE_NAME_CHARS];
    char Age_Range[MAX_AGE_RANGE_NAME_CHARS];

    struct Model Valid_Model;
    struct Connector Valid_Connector;
};
int main(void)
{
      struct Buds My_Buds;

      strncpy(My_Buds.Brand_Name,"Boat",strlen("Boat"));
      strncpy(My_Buds.Model_Name,"Airdops",strlen("Airdops"));
      strncpy(My_Buds.Colour_Name,"Bold Black",strlen("Bold Black"));
      strncpy(My_Buds.Form_Factor_Name,"In Ear",strlen("In Ear"));
      strncpy(My_Buds.Connector_Type_Name,"Bluetooth",strlen("Bluetooth"));
      strncpy(My_Buds.Special_Feature,
      "Sweatproof,Microphone Include One Touch Voice Assistant",
      strlen("Sweatproof,Microphone Include One Touch Voice Assistant"));
      strncpy(My_Buds.Age_Range,"Adult",strlen("Adult"));

      My_Buds.Valid_Model.Model_Name_Number= 141;
      My_Buds.Valid_Connector.Connector_Type_Number = 5.1;

      printf("Brand: %s\n",My_Buds.Brand_Name);
      printf("Model Name: %s%d\n",My_Buds.Model_Name,My_Buds.Valid_Model.Model_Name_Number);
      printf("Colour: %s\n",My_Buds.Colour_Name);
      printf("Form Factor: %s\n",My_Buds.Form_Factor_Name);
      printf("Connector Type: %s%f\n",My_Buds.Connector_Type_Name,My_Buds.Valid_Connector.Connector_Type_Number);
      printf("wirless Communication Technology: %s\n",My_Buds.Connector_Type_Name);
      printf("Special Feature: %s\n",My_Buds.Special_Feature);
      printf("Age Range: %s\n",My_Buds.Age_Range);

      return (0);
}