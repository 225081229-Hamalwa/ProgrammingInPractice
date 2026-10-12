#include <stdio.h>

float calculateVAT(float amount) {

    float VAT;

    VAT = amount * 0.15;

    return VAT;
}

int main() {

    float amount;
    float VAT;

    printf("Enter amount: ");
    scanf("%f", &amount);

    VAT = calculateVAT(amount);

    printf("VAT: %.2f\n", VAT);

    return 0;
}