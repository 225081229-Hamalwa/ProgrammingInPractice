#include <stdio.h>
#include "employees.h"

int main(void)
{
    int choice;

    do
    {
        printf("\n===== MFMS MENU =====\n");
        printf("1. Save Employee Data\n");
        printf("2. Load Employee Data\n");
        printf("3. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input.\n");
            return 1;
        }

        switch (choice)
        {
            case 1:
                saveEmployeesText();
                break;

            case 2:
                loadEmployeesText();
                break;

            case 3:
                printf("Exiting MFMS...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 3);

    return 0;
}