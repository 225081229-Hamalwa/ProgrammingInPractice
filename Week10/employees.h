#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include "records.h"

void addEmployee(void);
void displayEmployees(void);

float calculateSalary(float basic, float housing, float transport);
int searchEmployee(int id, int ids[], int size);

void saveEmployeesText(void);
void loadEmployeesText(void);

void saveEmployeesBinary(void);
void loadEmployeesBinary(void);

#endif