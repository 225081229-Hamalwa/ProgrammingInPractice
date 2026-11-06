#include <stdio.h>
#include <string.h>
#include "suppliers.h"

void addSupplier(Supplier suppliers[], int *supplierCount)
{
    if (*supplierCount >= MAX_RECORDS)
    {
        printf("\nSupplier array is full!\n");
        return;
    }

    printf("\n--- ADD SUPPLIER ---\n");

    printf("Enter Supplier ID: ");
    scanf("%d", &suppliers[*supplierCount].id);

    printf("Enter Supplier Name: ");
    scanf(" %39[^\n]", suppliers[*supplierCount].name);

    printf("Enter Email: ");
    scanf(" %39[^\n]", suppliers[*supplierCount].email);

    printf("Enter Phone: ");
    scanf(" %14[^\n]", suppliers[*supplierCount].phone);

    printf("Enter Town: ");
    scanf(" %19[^\n]", suppliers[*supplierCount].town);

    (*supplierCount)++;

    printf("\nSupplier added successfully!\n");
}

void displaySuppliers(Supplier suppliers[], int supplierCount)
{
    if (supplierCount == 0)
    {
        printf("\nNo suppliers registered.\n");
        return;
    }

    printf("\n========== SUPPLIER RECORDS ==========\n");

    for (int i = 0; i < supplierCount; i++)
    {
        printf("\nSupplier %d\n", i + 1);
        printf("ID: %d\n", suppliers[i].id);
        printf("Name: %s\n", suppliers[i].name);
        printf("Email: %s\n", suppliers[i].email);
        printf("Phone: %s\n", suppliers[i].phone);
        printf("Town: %s\n", suppliers[i].town);
    }

    printf("\n======================================\n");
}
void searchSuppliersByTown(Supplier suppliers[], int supplierCount)
{
    if (supplierCount == 0)
    {
        printf("\nNo suppliers available to search.\n");
        return;
    }

    char searchTown[20];
    int found = 0;

    printf("\nEnter town to search: ");
    scanf(" %19[^\n]", searchTown);

    printf("\n========== SEARCH RESULTS ==========\n");

    for (int i = 0; i < supplierCount; i++)
    {
        if (strcmp(suppliers[i].town, searchTown) == 0)
        {
            printf("\nSupplier ID: %d\n", suppliers[i].id);
            printf("Name: %s\n", suppliers[i].name);
            printf("Email: %s\n", suppliers[i].email);
            printf("Phone: %s\n", suppliers[i].phone);
            printf("Town: %s\n", suppliers[i].town);

            found++;
        }
    }

    if (found == 0)
    {
        printf("\nNo suppliers found in %s.\n", searchTown);
    }
    else
    {
        printf("\nTotal suppliers found: %d\n", found);
    }

    printf("====================================\n");
}