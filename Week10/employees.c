
#include <stdio.h>
#include "employees.h"

Employee employees[MAX_RECORDS];
int employeeCount = 0;

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

void addEmployee(void)
{
    if (employeeCount >= MAX_RECORDS)
    {
        printf("Employee list is full!\n");
        return;
    }

    printf("\n--- ADD EMPLOYEE ---\n");

    printf("Enter Employee ID: ");
    scanf("%d", &employees[employeeCount].employeeID);

    printf("Enter Employee Name: ");
    scanf(" %49[^\n]", employees[employeeCount].employeeName);

    printf("Enter Basic Salary: ");
    scanf("%f", &employees[employeeCount].basicSalary);

    printf("Enter Housing Allowance: ");
    scanf("%f", &employees[employeeCount].housingAllowance);

    printf("Enter Transport Allowance: ");
    scanf("%f", &employees[employeeCount].transportAllowance);

    employees[employeeCount].grossSalary =
        calculateSalary(
            employees[employeeCount].basicSalary,
            employees[employeeCount].housingAllowance,
            employees[employeeCount].transportAllowance
        );

    employeeCount++;

    printf("\nEmployee added successfully!\n");
}

void displayEmployees(void)
{
    int i;

    if (employeeCount == 0)
    {
        printf("\nNo employees registered.\n");
        return;
    }

    printf("\n--- EMPLOYEE RECORDS ---\n");

    for (i = 0; i < employeeCount; i++)
    {
        printf("\nEmployee ID: %d\n", employees[i].employeeID);
        printf("Name: %s\n", employees[i].employeeName);
        printf("Basic Salary: N$ %.2f\n", employees[i].basicSalary);
        printf("Housing Allowance: N$ %.2f\n", employees[i].housingAllowance);
        printf("Transport Allowance: N$ %.2f\n", employees[i].transportAllowance);
        printf("Gross Salary: N$ %.2f\n", employees[i].grossSalary);
    }
}

void saveEmployeesText(void)
{
    FILE *file;
    int i;

    file = fopen("data/employees.txt", "w");

    if (file == NULL)
    {
        printf("Error opening employee file for writing.\n");
        return;
    }

    for (i = 0; i < employeeCount; i++)
    {
        fprintf(file, "%d %s %.2f %.2f %.2f %.2f\n",
                employees[i].employeeID,
                employees[i].employeeName,
                employees[i].basicSalary,
                employees[i].housingAllowance,
                employees[i].transportAllowance,
                employees[i].grossSalary);
    }

    fclose(file);
    printf("Employee data saved successfully.\n");
}

void loadEmployeesText(void)
{
    FILE *file;

    file = fopen("data/employees.txt", "r");

    if (file == NULL)
    {
        printf("No saved employee file found.\n");
        return;
    }

    employeeCount = 0;

    while (employeeCount < MAX_RECORDS &&
           fscanf(file, "%d %49s %f %f %f %f",
                  &employees[employeeCount].employeeID,
                  employees[employeeCount].employeeName,
                  &employees[employeeCount].basicSalary,
                  &employees[employeeCount].housingAllowance,
                  &employees[employeeCount].transportAllowance,
                  &employees[employeeCount].grossSalary) == 6)
    {
        employeeCount++;
    }

    fclose(file);

    printf("%d employee record(s) loaded successfully.\n", employeeCount);
}

void saveEmployeesBinary(void)
{
    FILE *file;

    file = fopen("data/employees.dat", "wb");

    if (file == NULL)
    {
        printf("Error opening binary file for writing.\n");
        return;
    }

    size_t recordsWritten = fwrite(
        employees,
        sizeof(Employee),
        employeeCount,
        file
    );

    fclose(file);

    if (recordsWritten == (size_t)employeeCount)
    {
        printf("Employee data saved in binary format successfully.\n");
    }
    else
    {
        printf("Error writing employee records.\n");
    }
}

void loadEmployeesBinary(void)
{
    FILE *file;

    file = fopen("data/employees.dat", "rb");

    if (file == NULL)
    {
        printf("Error opening binary file for reading.\n");
        return;
    }

    employeeCount = (int)fread(
        employees,
        sizeof(Employee),
        MAX_RECORDS,
        file
    );

    fclose(file);

    printf("%d employee record(s) loaded from binary file.\n",
           employeeCount);
}

