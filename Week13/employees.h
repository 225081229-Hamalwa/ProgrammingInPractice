#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include "records.h"

/* Week 13 - Dynamic employee memory */
void addEmployee(Employee **employees, int *employeeCount, int *capacity);
void displayEmployees(Employee employees[], int employeeCount);
void saveEmployees(Employee employees[], int employeeCount);
void loadEmployees(Employee **employees, int *employeeCount, int *capacity);

/* Week 12 - Pointer functions */
void swapSalaries(double *a, double *b);
void displaySalaries(const double salaries[], int n);
double findHighest(const double salaries[], int n);
void updateSalary(Employee *e, double newSalary);
Employee *findEmployee(Employee list[], int n, int id);

#endif