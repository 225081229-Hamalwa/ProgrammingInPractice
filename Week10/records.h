
#ifndef RECORDS_H
#define RECORDS_H

#define MAX_RECORDS 100

/* Employee Structure */
typedef struct
{
    int employeeID;
    char employeeName[50];
    float basicSalary;
    float housingAllowance;
    float transportAllowance;
    float grossSalary;
} Employee;

/* Supplier Structure */
typedef struct
{
    int supplierID;
    char supplierName[50];
    char town[50];
    char phoneNumber[20];
} Supplier;

/* Asset Structure */
typedef struct
{
    int assetID;
    char assetName[50];
    char department[50];
    float assetValue;
} Asset;

/* Budget Structure */
typedef struct
{
    int budgetID;
    char department[50];
    float allocatedAmount;
    float spentAmount;
} Budget;

/* Project Structure */
typedef struct
{
    int projectID;
    char projectName[50];
    char department[50];
    int endYear;
} Project;

#endif
