#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[30];
    double salary;
} Employee;

int main(void)
{
    int capacity = 2;
    int count = 0;
    int i;

    Employee *employees = NULL;
    Employee *bigger;
    Employee e;

    employees = malloc(capacity * sizeof(Employee));

if (employees == NULL)
{
    printf("Out of memory!\n");
    return 1;
}

    /* TODO 1: Allocate memory using malloc() */

    printf("Employee ID (0 to stop): ");
    scanf("%d", &e.id);

    while (e.id != 0)
    {
        printf("Name (one word): ");
        scanf("%29s", e.name);

        printf("Salary: ");
        scanf("%lf", &e.salary);

       if (count == capacity)
{
    capacity = capacity * 2;

    bigger = realloc(employees, capacity * sizeof(Employee));

    if (bigger == NULL)
    {
        printf("Out of memory!\n");
        free(employees);
        return 1;
    }

    employees = bigger;
}

       employees[count] = e;
count++;

        printf("Employee ID (0 to stop): ");
        scanf("%d", &e.id);
    }

    printf("\n========== EMPLOYEE RECORDS ==========\n");

for (i = 0; i < count; i++)
{
    printf("\nEmployee %d\n", i + 1);
    printf("ID: %d\n", employees[i].id);
    printf("Name: %s\n", employees[i].name);
    printf("Salary: N$ %.2lf\n", employees[i].salary);
}

printf("\nEmployees: %d | Capacity: %d\n", count, capacity);

    free(employees);
employees = NULL;

    return 0;
}