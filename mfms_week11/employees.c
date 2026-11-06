#include <stdio.h>
#include "employees.h"

void addEmployee(Employee employees[], int *employeeCount)
{
    if (*employeeCount >= MAX_RECORDS)
    {
        printf("\nEmployee array is full!\n");
        return;
    }

    printf("\n--- ADD EMPLOYEE ---\n");

    printf("Enter Employee ID: ");
    scanf("%d", &employees[*employeeCount].id);

    printf("Enter Employee Name: ");
    scanf(" %29[^\n]", employees[*employeeCount].name);

    printf("Enter Department: ");
    scanf(" %19[^\n]", employees[*employeeCount].department);

    printf("Enter Salary: ");
    scanf("%lf", &employees[*employeeCount].salary);

    (*employeeCount)++;

    printf("\nEmployee added successfully!\n");
}

void displayEmployees(Employee employees[], int employeeCount)
{
    if (employeeCount == 0)
    {
        printf("\nNo employees registered.\n");
        return;
    }

    printf("\n========== EMPLOYEE RECORDS ==========\n");

    for (int i = 0; i < employeeCount; i++)
    {
        printf("\nEmployee %d\n", i + 1);
        printf("ID: %d\n", employees[i].id);
        printf("Name: %s\n", employees[i].name);
        printf("Department: %s\n", employees[i].department);
        printf("Salary: N$ %.2lf\n", employees[i].salary);
    }

    printf("\n======================================\n");
}

void saveEmployees(Employee employees[], int employeeCount)
{
    FILE *file = fopen("employees.dat", "wb");

    if (file == NULL)
    {
        printf("\nError: Could not open employees.dat for writing.\n");
        return;
    }

    size_t recordsWritten = fwrite(
        employees, sizeof(Employee), employeeCount, file
    );

    fclose(file);

    if (recordsWritten == (size_t)employeeCount)
    {
        printf("\nEmployee records saved successfully!\n");
    }
    else
    {
        printf("\nError saving employee records.\n");
    }
}

void loadEmployees(Employee employees[], int *employeeCount)
{
    FILE *file = fopen("employees.dat", "rb");

    if (file == NULL)
    {
        printf("\nNo saved employee file found.\n");
        return;
    }

    *employeeCount = (int)fread(
        employees, sizeof(Employee), MAX_RECORDS, file
    );

    fclose(file);

    printf("\nEmployee records loaded successfully!\n");
}