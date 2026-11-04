
#include <stdio.h>
#include "budget.h"
#include "records.h"

Budget budgets[MAX_RECORDS];
int budgetCount = 0;

void addBudget(void)
{
    if (budgetCount >= MAX_RECORDS)
    {
        printf("Budget storage is full!\n");
        return;
    }

    Budget newBudget;

    printf("\nEnter Budget ID: ");
    scanf("%d", &newBudget.budgetID);

    printf("Enter Department: ");
    scanf(" %49[^\n]", newBudget.department);

    printf("Enter Allocated Amount: ");
    scanf("%f", &newBudget.allocatedAmount);

    printf("Enter Spent Amount: ");
    scanf("%f", &newBudget.spentAmount);

    budgets[budgetCount] = newBudget;
    budgetCount++;

    printf("Budget added successfully!\n");
}

void displayBudgets(void)
{
    if (budgetCount == 0)
    {
        printf("\nNo budget records available.\n");
        return;
    }

    printf("\n--- DEPARTMENTAL BUDGETS ---\n");

    for (int i = 0; i < budgetCount; i++)
    {
        printf("\nBudget ID: %d\n", budgets[i].budgetID);
        printf("Department: %s\n", budgets[i].department);
        printf("Allocated Amount: N$ %.2f\n", budgets[i].allocatedAmount);
        printf("Spent Amount: N$ %.2f\n", budgets[i].spentAmount);
        printf("Remaining Budget: N$ %.2f\n",
               calculateBudget(budgets[i].allocatedAmount,
                               budgets[i].spentAmount));
    }
}

void saveBudgetsText(void)
{
    FILE *file = fopen("data/budgets.txt", "w");

    if (file == NULL)
    {
        printf("Error: Could not open budgets file for saving.\n");
        return;
    }

    for (int i = 0; i < budgetCount; i++)
    {
        fprintf(file, "%d|%s|%.2f|%.2f\n",
                budgets[i].budgetID,
                budgets[i].department,
                budgets[i].allocatedAmount,
                budgets[i].spentAmount);
    }

    fclose(file);
    printf("Budget data saved successfully!\n");
}

void loadBudgetsText(void)
{
    FILE *file = fopen("data/budgets.txt", "r");

    if (file == NULL)
    {
        printf("No budget data file found.\n");
        return;
    }

    budgetCount = 0;

    while (budgetCount < MAX_RECORDS &&
           fscanf(file, "%d|%49[^|]|%f|%f\n",
                  &budgets[budgetCount].budgetID,
                  budgets[budgetCount].department,
                  &budgets[budgetCount].allocatedAmount,
                  &budgets[budgetCount].spentAmount) == 4)
    {
        budgetCount++;
    }

    fclose(file);
    printf("%d budget record(s) loaded successfully!\n", budgetCount);
}

float calculateVAT(float amount)
{
    return amount * 0.15f;
}

float calculateBudget(float revenue, float expenses)
{
    return revenue - expenses;
}
