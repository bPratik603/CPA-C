#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BRAND_NAME_CHARS                          100

#define MAX_MODEL_NAME_FRONT_CHARS                    100
#define MAX_MODEL_NAME_BACK_CHARS                     100

#define MAX_NETWORK_SERVICE_PROVIDER_NAME_CHARS       100

#define MAX_OS_FRONT_CHARS                            100
#define MAX_OS_BACK_CHARS                             100

#define MAX_CELLUAR_TECHNOLOGY_NAME_CHARS             100
#define MAX_MEMORY_STORAJ_CAPACITY_CHARS              100
#define MAX_CONNECTIVITY_TECHNOLOGY_NAME_CHARS        100
#define MAX_COLOUR_NAME_CHARS                         100
#define MAX_SCREEN_SIZE_CHARS                         100
#define MAX_WIRELESS_NETWORK_TECHNOLOGY_NAME_CHARS    100

struct Os
{
    int Android_Version;
    int Os_Version;
};

struct Cellular
{
    int Genaration;
};

struct Storaj
{
    int Storaj_Capacity;
};

struct Size
{
    float Screen_Size;
};

struct Mobile
{
   char Brand_Name[MAX_BRAND_NAME_CHARS];
   char Model_Front_Name[MAX_MODEL_NAME_FRONT_CHARS];
   char Model_Back_Name[MAX_MODEL_NAME_BACK_CHARS];
   char Nerwork_Service_provider_Name[MAX_NETWORK_SERVICE_PROVIDER_NAME_CHARS];
   char Os_Front_Name[MAX_OS_FRONT_CHARS];
   char Os_Back_Name[MAX_OS_BACK_CHARS];
   char Cellular_Technology_Unit_Name[MAX_CELLUAR_TECHNOLOGY_NAME_CHARS];
   char Memory_Storaj_Capacity_Unit_Name[MAX_MEMORY_STORAJ_CAPACITY_CHARS];
   char Connectivity_Technology_Name[MAX_CONNECTIVITY_TECHNOLOGY_NAME_CHARS];
   char Colour_Name[MAX_COLOUR_NAME_CHARS];
   char Screen_size_Unit_Name[MAX_SCREEN_SIZE_CHARS];
   char Wireless_Network_Technology_Name[MAX_WIRELESS_NETWORK_TECHNOLOGY_NAME_CHARS];

    struct Size Valid_Sreen_size;
    struct Storaj Valid_Storaj_Capacity;
    struct Cellular Valid_Genaration;
    struct Os Valid_Os;
};


int main(void)
{
     struct Mobile My_Mobile;

     strncpy(My_Mobile.Brand_Name,"IQOO",strlen("IQOO"));
     
     strncpy(My_Mobile.Model_Front_Name,
     "IQOO Z6 Pro ",strlen("IQOO Z6 Pro "));
     strncpy(My_Mobile.Model_Back_Name,
     "G By Vivo",strlen("G By Vivo"));
     
     strncpy(My_Mobile.Nerwork_Service_provider_Name,
     "Unlocked For All Carriers",strlen("Unlocked For All Carriers"));    
     
     strncpy(My_Mobile.Os_Front_Name,
     "Function OS ",strlen("Function OS"));
     strncpy(My_Mobile.Os_Back_Name,
     "Based On Android",strlen("Based On Android"));

     strncpy(My_Mobile.Cellular_Technology_Unit_Name,"G",strlen("G"));

     strncpy(My_Mobile.Memory_Storaj_Capacity_Unit_Name,
     "GB",strlen("GB"));

     strncpy(My_Mobile.Connectivity_Technology_Name,
     "USB,Type-c,Bluetooth,Wifi",strlen("USB,Type-c,Bluetooth,Wifi"));
     strncpy(My_Mobile.Colour_Name,"Legion Sky",strlen("Legion Sky"));

     strncpy(My_Mobile.Screen_size_Unit_Name,"inches",strlen("inches"));

     strncpy(My_Mobile.Wireless_Network_Technology_Name,
     "Wi-fi",strlen("Wi-fi"));

   My_Mobile.Valid_Genaration.Genaration= 5;
   My_Mobile.Valid_Os.Os_Version = 12;
   My_Mobile.Valid_Os.Android_Version = 12;
   My_Mobile.Valid_Storaj_Capacity.Storaj_Capacity = 128;
   My_Mobile.Valid_Sreen_size.Screen_Size = 6.44;

   printf("Brand: %s\n\n",My_Mobile.Brand_Name);
   printf("Model Name: %s %d%s\n\n",
   My_Mobile.Model_Front_Name,
   My_Mobile.Valid_Genaration.Genaration,
   My_Mobile.Model_Back_Name);
   printf("Network Service Provider: %s\n\n",My_Mobile.Nerwork_Service_provider_Name);
   printf("Os: %s %d %s %d\n\n",
   My_Mobile.Os_Front_Name,
   My_Mobile.Valid_Os.Os_Version,
   My_Mobile.Os_Back_Name,
   My_Mobile.Valid_Os.Android_Version);
   printf("Cellular Technology: %d%s\n\n",
   My_Mobile.Valid_Genaration.Genaration,
   My_Mobile.Cellular_Technology_Unit_Name);
   printf("Memory Storaj Capacity: %d %s\n\n",
   My_Mobile.Valid_Storaj_Capacity.Storaj_Capacity,
   My_Mobile.Memory_Storaj_Capacity_Unit_Name);
   printf("Connectivity Technology: %s\n\n",My_Mobile.Connectivity_Technology_Name);
   printf("Colour: %s\n",My_Mobile.Colour_Name);
   printf("Screen Size: %f %s\n\n",
    My_Mobile.Valid_Sreen_size.Screen_Size,
    My_Mobile.Screen_size_Unit_Name);
    printf("Wireless NetWork Technology: %s\n\n",My_Mobile.Wireless_Network_Technology_Name);

    return (0);
}