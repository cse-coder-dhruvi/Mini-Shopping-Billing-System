#include<stdio.h>
#include<stdlib.h>
#include "shop.h"
int main() {
   int choice;
   do{
    printf("\n=== MINI SHPPING BILLING SYSTEM ===\n");
    printf("1. Add Item\n");
    printf("2. View bill\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
     
    switch(choice){
        case 1:
            addItem();
            break;
        case 2:
            viewBill();
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid optional!  try again.\n");
    }
   } while(choice != 3);
    return 0;
}