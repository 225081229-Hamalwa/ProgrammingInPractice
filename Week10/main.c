
#include <stdio.h>

#include "employees.h"
#include "suppliers.h"
#include "assets.h"
#include "budget.h"
#include "projects.h"

/* Employee Management Menu */
void employeeMenu(void)
{
    int choice;

    do
    {
        printf("\n===== EMPLOYEE MANAGEMENT =====\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Save Employee Data\n");
        printf("4. Load Employee Data\n");
        printf("5. Save Employee Data (Binary)\n");
        printf("6. Load Employee Data (Binary)\n");
        printf("7. Back to Main Menu\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: saveEmployeesText(); break;
            case 4: loadEmployeesText(); break;
            case 5: saveEmployeesBinary(); break;
            case 6: loadEmployeesBinary(); break;
            case 7: break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 7);
}

/* Supplier Management Menu */
void supplierMenu(void)
{
    int choice;

    do
    {
        printf("\n===== SUPPLIER MANAGEMENT =====\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Save Supplier Data\n");
        printf("4. Load Supplier Data\n");
        printf("5. Back to Main Menu\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1: addSupplier(); break;
            case 2: displaySuppliers(); break;
            case 3: saveSuppliersText(); break;
            case 4: loadSuppliersText(); break;
            case 5: break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 5);
}

/* Asset Management Menu */
void assetMenu(void)
{
    int choice;

    do
    {
        printf("\n===== ASSET MANAGEMENT =====\n");
        printf("1. Add Asset\n");
        printf("2. Display Assets\n");
        printf("3. Save Asset Data\n");
        printf("4. Load Asset Data\n");
        printf("5. Back to Main Menu\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1: addAsset(); break;
            case 2: displayAssets(); break;
            case 3: saveAssetsText(); break;
            case 4: loadAssetsText(); break;
            case 5: break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 5);
}

/* Budget Management Menu */
void budgetMenu(void)
{
    int choice;

    do
    {
        printf("\n===== BUDGET MANAGEMENT =====\n");
        printf("1. Add Budget\n");
        printf("2. Display Budgets\n");
        printf("3. Save Budget Data\n");
        printf("4. Load Budget Data\n");
        printf("5. Back to Main Menu\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1: addBudget(); break;
            case 2: displayBudgets(); break;
            case 3: saveBudgetsText(); break;
            case 4: loadBudgetsText(); break;
            case 5: break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 5);
}

/* Project Management Menu */
void projectMenu(void)
{
    int choice;

    do
    {
        printf("\n===== PROJECT MANAGEMENT =====\n");
        printf("1. Add Project\n");
        printf("2. Display Projects\n");
        printf("3. Save Project Data\n");
        printf("4. Load Project Data\n");
        printf("5. Back to Main Menu\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1: addProject(); break;
            case 2: displayProjects(); break;
            case 3: saveProjectsText(); break;
            case 4: loadProjectsText(); break;
            case 5: break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 5);
}

/* Main Menu */
int main(void)
{
    int choice;

    do
    {
        printf("\n============================================\n");
        printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
        printf("============================================\n");

        printf("1. Employee Management\n");
        printf("2. Supplier Management\n");
        printf("3. Asset Management\n");
        printf("4. Budget Management\n");
        printf("5. Project Management\n");
        printf("6. Exit\n");

        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input!\n");
            return 1;
        }

        switch (choice)
        {
            case 1: employeeMenu(); break;
            case 2: supplierMenu(); break;
            case 3: assetMenu(); break;
            case 4: budgetMenu(); break;
            case 5: projectMenu(); break;
            case 6:
                printf("Thank you for using MFMS!\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 6);

    return 0;
}
