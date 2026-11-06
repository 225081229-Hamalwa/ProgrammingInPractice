#include <stdio.h>
#include "budget.h"

void addBudget(Budget budgets[], int *budgetCount)
{
    if (*budgetCount >= MAX_RECORDS)
    {
        printf("\nBudget array is full!\n");
        return;
    }

    printf("\n--- ADD BUDGET ---\n");

    printf("Enter Department: ");
    scanf(" %19[^\n]", budgets[*budgetCount].department);

    printf("Enter Allocated Budget: ");
    scanf("%lf", &budgets[*budgetCount].allocated);

    printf("Enter Amount Spent: ");
    scanf("%lf", &budgets[*budgetCount].spent);

    (*budgetCount)++;

    printf("\nBudget added successfully!\n");
}

void displayBudgets(Budget budgets[], int budgetCount)
{
    if (budgetCount == 0)
    {
        printf("\nNo budgets registered.\n");
        return;
    }

    printf("\n========== BUDGET RECORDS ==========\n");

    for (int i = 0; i < budgetCount; i++)
    {
        double remaining = budgets[i].allocated - budgets[i].spent;

        printf("\nBudget %d\n", i + 1);
        printf("Department: %s\n", budgets[i].department);
        printf("Allocated Budget: N$ %.2lf\n", budgets[i].allocated);
        printf("Amount Spent: N$ %.2lf\n", budgets[i].spent);
        printf("Remaining Budget: N$ %.2lf\n", remaining);

        if (budgets[i].spent > budgets[i].allocated)
        {
            printf("WARNING: Department has exceeded its budget!\n");
        }
    }

    printf("\n====================================\n");
}

double calculateVAT(double amount)
{
    return amount * 0.15;
}

double calculateBudget(double revenue, double expenses)
{
    return revenue - expenses;
}