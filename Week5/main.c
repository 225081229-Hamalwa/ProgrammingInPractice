#include <stdio.h>

int main() {

float employeeSalary = 0.00;
float totalSalary = 0.00;
float averageSalary = 0.00;
float highestSalary = 0.00;
float lowestSalary = 0.00;

for (int i = 1; i < 51; i++) {

  printf("Enter Employee Salary: ");
  scanf("%f", &employeeSalary);
  
  totalSalary = totalSalary + employeeSalary;
  
  averageSalary = totalSalary/50;
  
  if(i==1){
     highestSalary = employeeSalary;
     lowestSalary = employeeSalary;
  }
  
  if(employeeSalary > highestSalary){
   highestSalary = employeeSalary;
    }
    
    if(employeeSalary < lowestSalary){
     lowestSalary = employeeSalary;
      }
      
   
   printf("Total Salary : N$ %.2f\n", totalSalary);
    printf("Average Salary : N$ %.2f\n", averageSalary);
     printf("Highest Salary : N$ %.2f\n", highestSalary);
      printf("Lowest Salary : N$ %.2f\n", lowestSalary);
     
  }
  return 0;
}