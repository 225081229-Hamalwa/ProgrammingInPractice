#include <stdio.h>
#include <string.h>

int main() {

    char SupplierName[50];
    char Email[50];
    char PhoneNumber[20];
    char Town[50];

    printf("Enter supplier name: ");
    scanf(" %[^\n]", SupplierName);

    printf("Enter email: ");
    scanf("%49s", Email);

    printf("Enter phone number: ");
    scanf("%19s", PhoneNumber);

    printf("Enter town: ");
    scanf("%49s", Town);

    printf("\n--- SUPPLIER DETAILS ---\n");

    printf("Name: %s\n", SupplierName);
    printf("Email: %s\n", Email);
    printf("Phone: %s\n", PhoneNumber);
    printf("Town: %s\n", Town);

    printf("\nSupplier name length: %lu\n", strlen(SupplierName));
    printf("Email length: %lu\n", strlen(Email));
    printf("Town length: %lu\n", strlen(Town));

    return 0;
}