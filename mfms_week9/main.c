#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "utilities.h"
#include "reports.h"

int main(void) {
    int choice;
    float amount, vat;
    float basic, housing, transport, grossSalary;
    float revenue, expenses, balance;

    displayWelcome();

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter amount: N$ ");
                scanf("%f", &amount);

                vat = calculateVAT(amount);
                printf("VAT: N$ %.2f\n", vat);
                break;

            case 2:
                printf("Enter basic salary: N$ ");
                scanf("%f", &basic);

                printf("Enter housing allowance: N$ ");
                scanf("%f", &housing);

                printf("Enter transport allowance: N$ ");
                scanf("%f", &transport);

                grossSalary = calculateSalary(basic, housing, transport);
                printf("Gross salary: N$ %.2f\n", grossSalary);
                break;

            case 3:
                printf("Enter revenue: N$ ");
                scanf("%f", &revenue);

                printf("Enter expenses: N$ ");
                scanf("%f", &expenses);

                balance = calculateBudget(revenue, expenses);
                printf("Budget balance: N$ %.2f\n", balance);

                if (balance > 0) {
                    printf("SURPLUS\n");
                } else if (balance < 0) {
                    printf("DEFICIT\n");
                } else {
                    printf("BALANCED\n");
                }
                break;

            case 4:
                displayReports();
                break;

            case 5:
                printf("Exiting MFMS...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 5);

    return 0;
}