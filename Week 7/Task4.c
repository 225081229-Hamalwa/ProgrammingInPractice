#include <stdio.h>
#include <string.h>

int main() {

    char original[100];
    char backup[100];

    printf("Enter supplier name: ");
    scanf(" %[\n]", original);

    strcpy(backup, original);

    printf("\nOriginal Supplier: %s\n", original);
    printf("Backup Supplier: %s\n", backup);

    return 0;
}