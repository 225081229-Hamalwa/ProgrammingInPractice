#include <stdio.h>

int main() {

    double revenue = 120500.99;
    double expenses = 902500.95;
    double financialBalance;

    printf("Please Enter Revenue: \n");
    scanf("%lf", &revenue);

    printf("Please Enter Expenses: \n");
    scanf("%lf", &expenses);

    financialBalance = revenue - expenses;

    if (revenue > expenses) {
        printf("There is a surplus.\n");
        printf("The Balance is: N$ %.2f\n", financialBalance);

    } 
    else if (expenses > revenue) {
        printf("There is a deficit.\n");
        printf("The Balance is: N$ -%.2f\n", -financialBalance);

    } 
    else {
        printf("Balance is balanced!\n");
        printf("Balance is: N$ %.2f\n", financialBalance);
    }

    return 0;
}