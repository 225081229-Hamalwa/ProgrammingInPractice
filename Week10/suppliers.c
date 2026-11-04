#include <stdio.h>
#include <string.h>
#include "suppliers.h"

Supplier suppliers[MAX_RECORDS];
int supplierCount = 0;

void addSupplier(void)
{
    if (supplierCount >= MAX_RECORDS)
    {
        printf("Supplier storage is full!\n");
        return;
    }

    Supplier newSupplier;

    printf("\nEnter Supplier ID: ");
    scanf("%d", &newSupplier.supplierID);

    printf("Enter Supplier Name: ");
    scanf(" %49[^\n]", newSupplier.supplierName);

    printf("Enter Town: ");
    scanf(" %49[^\n]", newSupplier.town);

    printf("Enter Phone Number: ");
    scanf(" %19s", newSupplier.phoneNumber);

    suppliers[supplierCount] = newSupplier;
    supplierCount++;

    printf("Supplier added successfully!\n");
}

void displaySuppliers(void)
{
    if (supplierCount == 0)
    {
        printf("\nNo suppliers available.\n");
        return;
    }

    printf("\n--- SUPPLIER LIST ---\n");

    for (int i = 0; i < supplierCount; i++)
    {
        printf("\nSupplier ID: %d\n", suppliers[i].supplierID);
        printf("Supplier Name: %s\n", suppliers[i].supplierName);
        printf("Town: %s\n", suppliers[i].town);
        printf("Phone Number: %s\n", suppliers[i].phoneNumber);
    }
}

void saveSuppliersText(void)
{
    FILE *file = fopen("data/suppliers.txt", "w");

    if (file == NULL)
    {
        printf("Error: Could not open suppliers file for saving.\n");
        return;
    }

    for (int i = 0; i < supplierCount; i++)
    {
        fprintf(file, "%d|%s|%s|%s\n",
                suppliers[i].supplierID,
                suppliers[i].supplierName,
                suppliers[i].town,
                suppliers[i].phoneNumber);
    }

    fclose(file);
    printf("Supplier data saved successfully!\n");
}

void loadSuppliersText(void)
{
    FILE *file = fopen("data/suppliers.txt", "r");

    if (file == NULL)
    {
        printf("No supplier data file found.\n");
        return;
    }

    supplierCount = 0;

    while (supplierCount < MAX_RECORDS &&
           fscanf(file, "%d|%49[^|]|%49[^|]|%19[^\n]\n",
                  &suppliers[supplierCount].supplierID,
                  suppliers[supplierCount].supplierName,
                  suppliers[supplierCount].town,
                  suppliers[supplierCount].phoneNumber) == 4)
    {
        supplierCount++;
    }

    fclose(file);
    printf("%d supplier record(s) loaded successfully!\n", supplierCount);
}