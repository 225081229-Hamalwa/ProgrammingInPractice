#include <stdio.h>

int searchEmployee(int id, int ids[], int size) {

    int i;

    for (i = 0; i < size; i++) {

        if (ids[i] == id) {
            return i;
        }
    }

    return -1;
}

int main() {

    int employeeIDs[] = {101, 102, 103, 104, 105};
    int id;
    int position;

    printf("Enter employee ID: ");
    scanf("%d", &id);

    position = searchEmployee(id, employeeIDs, 5);

    if (position != -1) {
        printf("Employee found at position %d.\n", position);
    }
    else {
        printf("Employee not found.\n");
    }

    return 0;
}