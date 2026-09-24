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