#ifndef BUDGET_H
#define BUDGET_H

#include "records.h"

void addBudget(void);
void displayBudgets(void);

void saveBudgetsText(void);
void loadBudgetsText(void);

float calculateVAT(float amount);
float calculateBudget(float revenue, float expenses);

#endif