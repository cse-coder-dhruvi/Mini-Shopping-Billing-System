#include <stdio.h>
#include <stdlib.h>
#include "shop.h"
struct item {
    char name[50];
    float price;
    int quantity;
};  
void addItem() {
    FILE *fp;
    fp = fopen("bill.txt", "a");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    struct item item;
    float amt;
    printf("Enter item name: ");
    scanf("%s", item.name);
    printf("Enter item price: ");
    scanf("%f", &item.price);
    printf("Enter item quantity: ");
    scanf("%d", &item.quantity);
    amt=item.price * item.quantity;
    fprintf(fp, "%s %.2f %d\n", item.name, item.price, item.quantity);
    fclose(fp);
    printf("Item added successfully!\n");
    printf("Amount for this item: %.2f\n", amt);
}   
void viewBill() {
    FILE *fp;
    fp = fopen("bill.txt", "r");
    if (fp == NULL) {
        printf("No items in the bill.\n");
        return;
    }
    struct item item;
    float total = 0;
    printf("\n===  SHOPPING BILL  ===\n");
    printf("Item Name\tPrice\tQuantity\tTotal\n");
    while (fscanf(fp, "%s %f %d", item.name, &item.price, &item.quantity) != EOF) {
        float amt = item.price * item.quantity;
        printf("%s\t\t%.2f\t%d\t\t%.2f\n", item.name, item.price, item.quantity, amt);
        total += amt;
    }
    printf("----------------------------------------\n");
    printf("Total Amount: %.2f\n", total);
    fclose(fp);
}
    