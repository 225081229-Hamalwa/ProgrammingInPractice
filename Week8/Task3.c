#include <stdio.h>

float calculateSalary(float basic, float housing, float transport) {

    float grossSalary;

    grossSalary = basic + housing + transport;

    return grossSalary;
}

int main() {

    float basic;
    float housing;
    float transport;
    float grossSalary;

    printf("Enter Basic Salary: ");
    scanf("%f", &basic);

    printf("Enter Housing Allowance: ");
    scanf("%f", &housing);

    printf("Enter Transport Allowance: ");
    scanf("%f", &transport);

    grossSalary = calculateSalary(basic, housing, transport);

    printf("Gross Salary: N$ %.2f\n", grossSalary);

    return 0;
}