#include <stdio.h>
#include <string.h>

int main() {

    char registrations[20][20];
    char searchRegistration[20];
    int i;
    int found = 0;
    
    for(i = 0; i < 20; i++) {
        printf("Enter registration %d: ", i + 1);
        scanf("%s", registrations[i]);
    }

    // Display all registration numbers
    printf("\nVehicle Registration Numbers:\n");

    for(i = 0; i < 20; i++) {
        printf("%d. %s\n", i + 1, registrations[i]);
    }


    printf("\nEnter registration number to search: ");
    scanf("%s", searchRegistration);

    for(i = 0; i < 20; i++) {

        if(strcmp(registrations[i], searchRegistration) == 0) {
            printf("Registration number found at position %d.\n", i + 1);
            found = 1;
            break;
        }
    }

    if(found == 0) {
        printf("Registration number not found.\n");
    }

    return 0;
}