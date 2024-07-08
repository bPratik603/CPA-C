#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BRAND_NAME_CHAR                               100
#define MAX_STYLE_NAME_CHAR                               100
#define MAX_SIZE_NAME_CHAR                                100
#define MAX_SIZE_NAME_BACK_CHAR                           100
#define MAX_NET_QUANTITY_CHAR                             100
#define MAX_INCLUDED_COMPONENTS_CHAR                      100
#define MAX_SCENT_CHAR                                    100

struct Style
{
    int Style_Count;
};

struct Size
{
    int Size_Count;
    int Size_Back_Count;
};

struct Net_Quntity
{
    int Net_Quntity_Count;
};

struct pads
{
    char Brand_Name[MAX_BRAND_NAME_CHAR];
    char Style_Name[MAX_STYLE_NAME_CHAR];
    char Size_Name[MAX_SIZE_NAME_CHAR];
    char Size_Name_Back[MAX_SIZE_NAME_BACK_CHAR];
    char Net_Quantity_Name[MAX_NET_QUANTITY_CHAR];
    char Included_Components_Name[MAX_INCLUDED_COMPONENTS_CHAR];
    char Scent_Name[MAX_SCENT_CHAR];

    struct Style Style_Number;
    struct Size Size_Number;
    struct Net_Quntity Net_Quantity_Number;
};

int main(void)
{
    struct pads My_Pads;

    strncpy(My_Pads.Brand_Name,"Whisper",strlen("Whisper"));

    strncpy(My_Pads.Style_Name,"Counts\0",strlen("Counts\0"));

    strncpy(My_Pads.Size_Name,"Counts\0",strlen("Counts\0"));

    strncpy(My_Pads.Size_Name_Back,"(Pack Of)",strlen("(Pack Of)"));

    strncpy(My_Pads.Net_Quantity_Name,"Count",strlen("Count"));

    strncpy(My_Pads.Included_Components_Name,"Sanitary Napkins/Pads",strlen("Sanitary Napkins/Pads"));

    strncpy(My_Pads.Scent_Name,"Scented",strlen("Scented"));

    My_Pads.Style_Number.Style_Count = 44;
    My_Pads.Size_Number.Size_Count = 44;
    My_Pads.Size_Number.Size_Back_Count = 1;
    My_Pads.Net_Quantity_Number.Net_Quntity_Count = 44;

    printf("Brand= %s\n",
    My_Pads.Brand_Name);
    printf("Style= %d %s\n",My_Pads.Style_Number.Style_Count,My_Pads.Style_Name);
    printf("Size= %d %s %s %d\n",
    My_Pads.Size_Number.Size_Count,My_Pads.Size_Name,My_Pads.Size_Name_Back,My_Pads.Size_Number.Size_Back_Count);
    printf("Net Quntity= %d %s\n",
    My_Pads.Net_Quantity_Number.Net_Quntity_Count,
    My_Pads.Net_Quantity_Name);
    printf("Included Components= %s\n",My_Pads.Included_Components_Name);
    printf("Scent= %s\n",My_Pads.Scent_Name);

    return (0);
}