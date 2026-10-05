#include <stdio.h>

int main() {

    char SupplierName[50];
    char Email[50];
    char PhoneNumber[20];
    char Town[50];

    printf("Enter supplier name: ");
    scanf(" %[\n]", SupplierName);

    printf("Enter email: ");
    scanf("%s", Email);

    printf("Enter phone number: ");
    scanf("%s", PhoneNumber);

    printf("Enter town: ");
    scanf("%s", Town);

    printf("\n--- SUPPLIER DETAILS ---\n");

    printf("Name: %s\n", SupplierName);
    printf("Email: %s\n", Email);
    printf("Phone: %s\n", PhoneNumber);
    printf("Town: %s\n", Town);

    return 0;
}