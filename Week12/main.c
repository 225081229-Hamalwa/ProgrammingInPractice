
#include <stdio.h>
#include "records.h"
#include "employees.h"
#include "suppliers.h"
#include "assets.h"
#include "budget.h"
#include "projects.h"

int main(void)
{
    Employee employees[MAX_RECORDS];
    int employeeCount = 0;

    Supplier suppliers[MAX_RECORDS];
    int supplierCount = 0;

    Asset assets[MAX_RECORDS];
    int assetCount = 0;

    Budget budgets[MAX_RECORDS];
    int budgetCount = 0;

    Project projects[MAX_RECORDS];
    int projectCount = 0;

    int choice;

    /* Load saved employees */
    loadEmployees(employees, &employeeCount);

    do
    {
        printf("\n========================================\n");
        printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
        printf("========================================\n");

        printf("\nCURRENT RECORD COUNTS\n");
        printf("----------------------------------------\n");
        printf("Employees:  %d\n", employeeCount);
        printf("Suppliers:  %d\n", supplierCount);
        printf("Assets:     %d\n", assetCount);
        printf("Budgets:    %d\n", budgetCount);
        printf("Projects:   %d\n", projectCount);
        printf("----------------------------------------\n");

        printf("\nMAIN MENU\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Add Supplier\n");
        printf("4. Display Suppliers\n");
        printf("5. Search Suppliers by Town\n");
        printf("6. Add Asset\n");
        printf("7. Display Assets\n");
        printf("8. Search Assets by Minimum Value\n");
        printf("9. Add Budget\n");
        printf("10. Display Budgets\n");
        printf("11. Add Project\n");
        printf("12. Display Projects\n");
        printf("13. Search Projects by Ending Year\n");

/* Week 12 - Pointer Operations */
printf("14. Display Employee Salaries\n");
printf("15. Find Highest Salary\n");
printf("16. Swap Employee Salaries\n");
printf("17. Search and Update Employee Salary\n");

printf("0. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addEmployee(employees, &employeeCount);
                saveEmployees(employees, employeeCount);
                break;

            case 2:
                displayEmployees(employees, employeeCount);
                break;

            case 3:
                addSupplier(suppliers, &supplierCount);
                break;

            case 4:
                displaySuppliers(suppliers, supplierCount);
                break;

            case 5:
                searchSuppliersByTown(suppliers, supplierCount);
                break;

            case 6:
                addAsset(assets, &assetCount);
                break;

            case 7:
                displayAssets(assets, assetCount);
                break;

            case 8:
            {
                double minimumValue;

                printf("Enter minimum asset value: ");
                scanf("%lf", &minimumValue);

                displayAssetsAboveValue(assets, assetCount, minimumValue);
                break;
            }

            case 9:
                addBudget(budgets, &budgetCount);
                break;

            case 10:
                displayBudgets(budgets, budgetCount);
                break;

            case 11:
                addProject(projects, &projectCount);
                break;

            case 12:
                displayProjects(projects, projectCount);
                break;

            case 13:
            {
                int year;

                printf("Enter ending year to search: ");
                scanf("%d", &year);

                displayProjectsByEndYear(projects, projectCount, year);
                break;
            }

                        /* WEEK 12 - POINTER OPERATIONS */

            case 14:
            {
                double salaries[MAX_RECORDS];

                for (int i = 0; i < employeeCount; i++)
                {
                    salaries[i] = employees[i].salary;
                }

                displaySalaries(salaries, employeeCount);
                break;
            }

            case 15:
            {
                double salaries[MAX_RECORDS];

                for (int i = 0; i < employeeCount; i++)
                {
                    salaries[i] = employees[i].salary;
                }

                if (employeeCount > 0)
                {
                    printf("\nHighest Salary: N$ %.2lf\n",
                           findHighest(salaries, employeeCount));
                }
                else
                {
                    printf("\nNo employee records available.\n");
                }

                break;
            }

            case 16:
            {
                int id1, id2;

                printf("Enter first employee ID: ");
                scanf("%d", &id1);

                printf("Enter second employee ID: ");
                scanf("%d", &id2);

                Employee *emp1 = findEmployee(employees, employeeCount, id1);
                Employee *emp2 = findEmployee(employees, employeeCount, id2);

                if (emp1 != NULL && emp2 != NULL)
                {
                    swapSalaries(&emp1->salary, &emp2->salary);

                    saveEmployees(employees, employeeCount);

                    printf("\nSalaries swapped successfully!\n");
                }
                else
                {
                    printf("\nOne or both employee IDs were not found.\n");
                }

                break;
            }

            case 17:
            {
                int id;
                double newSalary;

                printf("Enter employee ID: ");
                scanf("%d", &id);

                Employee *emp = findEmployee(employees, employeeCount, id);

                if (emp != NULL)
                {
                    printf("Employee: %s\n", emp->name);
                    printf("Current Salary: N$ %.2lf\n", emp->salary);

                    printf("Enter new salary: N$ ");
                    scanf("%lf", &newSalary);

                    if (newSalary >= 0)
                    {
                        updateSalary(emp, newSalary);

                        saveEmployees(employees, employeeCount);

                        printf("\nSalary updated successfully!\n");
                    }
                    else
                    {
                        printf("\nSalary cannot be negative.\n");
                    }
                }
                else
                {
                    printf("\nEmployee not found.\n");
                }

                break;
            }

            case 0:
                printf("\nExiting MFMS. Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}
