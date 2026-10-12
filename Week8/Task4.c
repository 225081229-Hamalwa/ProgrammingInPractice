#include <stdio.h>

float calculateBudget(float revenue, float expenses) {

    float balance;

    balance = revenue - expenses;

    return balance;
}

int main() {

    float revenue;
    float expenses;
    float balance;

    printf("Enter Revenue: N$ ");
    scanf("%f", &revenue);

    printf("Enter Expenses: N$ ");
    scanf("%f", &expenses);

    balance = calculateBudget(revenue, expenses);

    printf("Budget Balance: N$ %.2f\n", balance);

    if (balance > 0) {
        printf("SURPLUS\n");
    }
    else if (balance < 0) {
        printf("DEFICIT\n");
    }
    else {
        printf("BALANCED\n");
    }

    return 0;
}