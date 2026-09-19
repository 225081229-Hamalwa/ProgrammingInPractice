#include <stdio.h>
#include <stdbool.h>

int main() {

char SupplierName[50];
float SupplierPrice = 0.00;
float Budget = 100000.00;
bool isRegistered = true;
bool isDocumentsComplent = true;

printf("Enter Supplier Name:\n");
scanf("%49s", SupplierName);

printf("Enter Supplier Price:\n");
scanf("%f", &SupplierPrice);

printf("Enter Budget:\n");
scanf("%f", &Budget);

printf("Is The Supplier Registered?(1 = Yes, 0 = No)\n");
scanf("%d", &isRegistered);

printf("Is The Supplier Documents Complete?(1 = Yes, 0 = No)\n");
scanf("%d", &isDocumentsComplent);

if(SupplierPrice <= Budget){
   if(isRegistered == true){
       if(isDocumentsComplent == true){
       printf("Supplier Is Qualified\n");
       } else{
             printf("Supplier Is Not Qualified\n");
             }
            }
       else{
         printf("Supplier Is Not Qualified\n");
           }
         }
    else{
        printf("Supplier Is Not Qualified\n");
      }

  return 0;
}