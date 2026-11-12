
#include <stdio.h>

/* Function to swap two salaries using pointers */
void swapSalaries(double *salary1, double *salary2)
{
    double temp;

    temp = *salary1;
    *salary1 = *salary2;
    *salary2 = temp;
}

int main(void)
{
    double salary1 = 15000;
    double salary2 = 22000;

    printf("Before swapping:\n");
    printf("Employee 1 Salary: N$ %.2lf\n", salary1);
    printf("Employee 2 Salary: N$ %.2lf\n", salary2);

    swapSalaries(&salary1, &salary2);

    printf("\nAfter swapping:\n");
    printf("Employee 1 Salary: N$ %.2lf\n", salary1);
    printf("Employee 2 Salary: N$ %.2lf\n", salary2);

    return 0;
}
