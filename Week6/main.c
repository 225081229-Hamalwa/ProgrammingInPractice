#include <stdio.h>

int main() {

    float Salaries[50];
    float Average = 0.00;
    float total = 0.00;
    float highSalary = 0.00;
    float lowestSalary = 0.00;
    float searchSalary;
    int i;

    for (i = 0; i < 50; i++) {

        printf("Enter Employee Salary: N$ ");
        scanf("%f", &Salaries[i]);

        printf("Employee %d: N$ %.2f\n", i + 1, Salaries[i]);

        total = total + Salaries[i];
    }

    Average = total / 50;

    highSalary = Salaries[0];
    lowestSalary = Salaries[0];

    for (i = 0; i < 50; i++) {

        if (highSalary < Salaries[i]) {
            highSalary = Salaries[i];
        }

        if (lowestSalary > Salaries[i]) {
            lowestSalary = Salaries[i];
        }
    }

    printf("The Average Salary is: N$ %.2f\n", Average);
    printf("The Highest Salary is: N$ %.2f\n", highSalary);
    printf("The Lowest Salary is: N$ %.2f\n", lowestSalary);

    int found = 0;

    printf("Enter salary to search: N$ ");
    scanf("%f", &searchSalary);

    for (i = 0; i < 50; i++) {

        if (searchSalary == Salaries[i]) {
            printf("Salary Found at Employee %d\n", i + 1);
            found = 1;
        }
    }

    if (found == 0) {
        printf("Salary Not Found\n");
    }

    return 0;
}

#include <stdio.h>

int main() {

float budget[10];
float totalBudget = 0.00;
float average = 0.00;
float lowestBudget, highestBudget;
int i;

for(i=0; i<10; i++){
printf("Enter Department Budget: N$");
scanf("%f", &budget[i]);

printf("Department %d: N$ %.2f\n", i + 1, budget[i]);

 totalBudget = totalBudget + budget[i];
 }
 
 average = totalBudget / 10;
 
float temp;

for(i = 0; i < 9; i++) {
    for(int j = i + 1; j < 10; j++) {

        if(budget[i] > budget[j]) {
            temp = budget[i];
            budget[i] = budget[j];
            budget[j] = temp;
        }
    }
}


printf("\nBudgets from Lowest to Highest:\n");

for(i = 0; i < 10; i++) {
    printf("N$ %.2f\n", budget[i]);
}

    return 0;
}