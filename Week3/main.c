#include<stdio.h>

int main(){
float BasicSalary = 0;
float HousingAllowance = 0;
float TransportAllowance = 0;
float Tax = 0;
float GrossSalary;
float NetSalary;

printf("Enter Basic Salary: ");
scanf("%f", &BasicSalary);

printf("Enter HousingAllowance: ");
scanf("%f", &HousingAllowance);

printf("Enter TransportAllowance: ");
scanf("%f", &TransportAllowance);

printf("Enter Tax: ");
scanf("%f", &Tax);

GrossSalary = BasicSalary + HousingAllowance + TransportAllowance;

NetSalary = GrossSalary - Tax;

printf("The Gross Salary is :N$ %.2f\n", GrossSalary);
printf("The Net Salary is :N$ %.2f\n", NetSalary);

return 0;

}