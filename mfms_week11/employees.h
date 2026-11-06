#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include "records.h"

void addEmployee(Employee employees[], int *employeeCount);

void displayEmployees(Employee employees[], int employeeCount);

void saveEmployees(Employee employees[], int employeeCount);

void loadEmployees(Employee employees[], int *employeeCount);

#endif