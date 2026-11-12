#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#include "records.h"

void addSupplier(Supplier suppliers[], int *supplierCount);

void displaySuppliers(Supplier suppliers[], int supplierCount);
void searchSuppliersByTown(Supplier suppliers[], int supplierCount);
#endif