#include <stdio.h>
#include "employees.h"

float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}

int searchEmployee(int id, int ids[], int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        if (ids[i] == id)
        {
            return i;
        }
    }

    return -1;
}

void saveEmployeesText(void)
{
    FILE *file;
    int employeeIDs[] = {101, 102, 103};
    float salaries[] = {8500.00f, 9200.00f, 7800.00f};
    int i;

    file = fopen("data/employees.txt", "w");

    if (file == NULL)
    {
        printf("Error opening employee file for writing.\n");
        return;
    }

    for (i = 0; i < 3; i++)
    {
        fprintf(file, "%d %.2f\n", employeeIDs[i], salaries[i]);
    }

    fclose(file);
    printf("Employee data saved successfully.\n");
}

void loadEmployeesText(void)
{
    FILE *file;
    int employeeID;
    float salary;

    file = fopen("data/employees.txt", "r");

    if (file == NULL)
    {
        printf("Error opening employee file for reading.\n");
        return;
    }

    printf("\n--- SAVED EMPLOYEE RECORDS ---\n");

    while (fscanf(file, "%d %f", &employeeID, &salary) == 2)
    {
        printf("Employee ID: %d | Salary: N$ %.2f\n",
               employeeID, salary);
    }

    fclose(file);
}