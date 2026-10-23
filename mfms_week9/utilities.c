#include <stdio.h>
#include "utilities.h"

void displayWelcome(void) {
    printf("Welcome to the Municipal Financial Management System\n");
}

void displayMenu(void) {
    printf("\n==================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT\n");
    printf("==================================\n");
    printf("1. Calculate VAT\n");
    printf("2. Calculate Salary\n");
    printf("3. Calculate Budget\n");
    printf("4. Reports\n");
    printf("5. Exit\n");
    printf("Enter choice: ");
}