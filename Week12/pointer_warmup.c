#include <stdio.h>

int main(void)
{
    int salary = 5000;

    int *ptr = &salary;

    printf("Salary: %d\n", salary);
    printf("Address of salary: %p\n", (void *)&salary);
    printf("Pointer value: %p\n", (void *)ptr);
    printf("Value using pointer: %d\n", *ptr);

    return 0;
}