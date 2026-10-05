#include <stdio.h>
#include <string.h>

int main() {

    char Supplier1[] = "ABC Office Supplies";
    char Supplier2[] = "Namibia Stationery";
    char SearchName[100];

    printf("Enter supplier name to search: ");
    scanf(" %[\n]", SearchName);

    if (strcmp(SearchName, Supplier1) == 0) {
        printf("Supplier found.\n");
    }
    else if (strcmp(SearchName, Supplier2) == 0) {
        printf("Supplier found.\n");
    }
    else {
        printf("Supplier not found.\n");
    }

    return 0;
}