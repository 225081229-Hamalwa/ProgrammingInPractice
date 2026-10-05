#include <stdio.h>
#include <string.h>

int main() {

    char SupplierName[100];
    char Town[50];
    char Description[200];

    printf("Enter supplier name: ");
    scanf(" %[\n]", SupplierName);

    printf("Enter town: ");
    scanf(" %[\n]", Town);

    strcpy(Description, SupplierName);

    strcat(Description, " operates in ");
    strcat(Description, Town);
    strcat(Description, ".");

    printf("\nSupplier Description:\n");
    printf("%s\n", Description);

    return 0;
}