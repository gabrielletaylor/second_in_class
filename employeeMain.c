// gcc employeeMain.c employeeTable.c employeeOne.c
// gcc employeeMain.c employeeTable.c employeeTwo.c
#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(void) {
   // defined in employeeOne.c or employeeTwo.c
   PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
   PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind);
   PtrToEmployee searchEmployeeByPhoneNumber(const Employee table[], int sizeTable, char * numberToFind);
   PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);

   // defined in employeeTable.c
   extern Employee EmployeeTable[];
   extern const int EmployeeTableEntries;

   PtrToEmployee matchPtr; // declaration
   matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);

   // example not found
   if (matchPtr != NULL)
      printf("\nEmployee ID 1045 is in record %ld\n", matchPtr - EmployeeTable);
   else
      printf("\nEmployee ID 1045 is NOT found in the record\n");

   // example found
   matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
   if (matchPtr != NULL)
      printf("Employee Tony Bobcat is in record %ld\n", matchPtr - EmployeeTable);
   else
      printf("Employee Tony Bobcat is NOT found in the record\n");

   // example phone number found
   matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "909-555-2134");
   if (matchPtr != NULL)
      printf("Employee phone number 909-555-2134 is in record %ld\n", matchPtr - EmployeeTable);
   else
      printf("Employee phone number 909-555-2134 is NOT found in the record\n");
   // example phone number not found
   matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "909-680-0253");
   if (matchPtr != NULL)
      printf("Employee phone number 909-680-0253 is in record %ld\n", matchPtr - EmployeeTable);
   else
      printf("Employee phone number 909-680-0253 is NOT found in the record\n");

   // example salary found
   matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 6.34);
   if (matchPtr != NULL)
      printf("Employee salary 6.34 is in record %ld\n", matchPtr - EmployeeTable);
   else
      printf("Employee salary 6.34 is NOT found in the record\n");
   // example salary not found
   matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 3.33);
   if (matchPtr != NULL)
      printf("Employee salary 3.33 is in record %ld\n\n", matchPtr - EmployeeTable);
   else
      printf("Employee salary 3.33 is NOT found in the record\n\n");

   return EXIT_SUCCESS;
}