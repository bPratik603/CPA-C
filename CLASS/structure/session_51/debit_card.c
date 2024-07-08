#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#define MAX_HOLDER_NAME_CHARS 128 
#define MAX_VENDOR_NAME_CHARS 64 

struct Date 
{
    unsigned char day, month; 
    int year; 
}; 

struct DebitCard
{
    char holder_name[MAX_HOLDER_NAME_CHARS]; 
    unsigned long long card_number; 
    unsigned short card_cvv; 
    struct Date card_valid_thru_date; 
    struct Date card_expirey_date; 
    char card_vendor[MAX_VENDOR_NAME_CHARS]; 
}; 

int main(void)
{
    struct DebitCard my_debit_card; 
    unsigned long long name_length; 

    name_length = strlen("Yogeshwar Shukla"); 
    strncpy(my_debit_card.holder_name, "Yogeshwar Shukla", name_length); 

    strncpy(my_debit_card.card_vendor, 
            "MasterCard", 
            strlen("MasterCard")
        ); 

    
    my_debit_card.card_number = 1111222233334444; 
    my_debit_card.card_cvv = 999; 
    my_debit_card.card_valid_thru_date.day = 1; 
    my_debit_card.card_valid_thru_date.month = 5; 
    my_debit_card.card_valid_thru_date.year = 2020; 
    my_debit_card.card_expirey_date.day = 1; 
    my_debit_card.card_expirey_date.month = 5; 
    my_debit_card.card_expirey_date.year = 2025; 

    printf("Card Name:%s\n", my_debit_card.holder_name); 
    printf("Card Number:%llu\n", my_debit_card.card_number); 
    printf("Card CVV:%hu\n", my_debit_card.card_cvv); 
    printf("Valid Thru Date:%hhu/%hhu/%d\n", 
            my_debit_card.card_valid_thru_date.day, 
            my_debit_card.card_valid_thru_date.month, 
            my_debit_card.card_valid_thru_date.year
        ); 
    printf("Expirey Date:%hhu/%hhu/%d\n", 
            my_debit_card.card_expirey_date.day, 
            my_debit_card.card_expirey_date.month, 
            my_debit_card.card_expirey_date.year
        ); 
    printf("Card Vendor:%s\n", my_debit_card.card_vendor); 
    
    return (0); 
}

/* 

    char A[8]; 

    A = &A[0] = char* 

    my_debit_card.holder_name == 
    &my_debitcard.holder_name[0]

*/


