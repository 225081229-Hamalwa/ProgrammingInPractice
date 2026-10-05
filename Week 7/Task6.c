#include <stdio.h>
#include <string.h>

int main() {

    char SupplierName[100] = "";
    char Email[50] = "";
    char Phone[30] = "";
    char Town[50] = "";
    char SearchName[100];

    int choice;

    do {

        printf("\n--- MFMS SUPPLIER MANAGEMENT ---\n");
        printf("1. Add Supplier\n");
        printf("2. Display Supplier\n");
        printf("3. Search Supplier\n");
        printf("4. Show Name Length\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {

            printf("\n--- ADD SUPPLIER ---\n");

            printf("Enter supplier name: ");
            scanf(" %[\n]", SupplierName);

            printf("Enter email: ");
            scanf("%s", Email);

            printf("Enter phone number: ");
            scanf("%s", Phone);

            printf("Enter town: ");
            scanf(" %[\n]", Town);

            printf("Supplier added successfully.\n");
        }

        else if (choice == 2) {

            printf("\n--- SUPPLIER DETAILS ---\n");

            printf("Name: %s\n", SupplierName);
            printf("Email: %s\n", Email);
            printf("Phone: %s\n", Phone);
            printf("Town: %s\n", Town);
        }

        else if (choice == 3) {

            printf("\nEnter supplier name to search: ");
            scanf(" %[\n]", SearchName);

            if (strcmp(SearchName, SupplierName) == 0) {
                printf("Supplier found.\n");
            }
            else {
                printf("Supplier not found.\n");
            }
        }

        else if (choice == 4) {

            printf("\nSupplier name length: %lu\n",
                   strlen(SupplierName));
        }

        else if (choice == 5) {

            printf("\nExiting Supplier Management System...\n");
        }

        else {

            printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}