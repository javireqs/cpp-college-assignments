/* 
Javier Hernandez Requena
July 27, 2022
CS 110 B - C++ Programming Fundamentals
Assignement 4 - Employee Training Roster
This program allows a small business to keep track of which employees have completed their training.
Allows user to add and search through a list of Employee ID's
*/


#include <iostream>
#include <string>
#include <algorithm>
#include <array>

using namespace std;

// function to add employee at specified index
void addEmployee(int employees[], int emp_index, int employeeID)
{
  employees[emp_index] = employeeID;
}

// function to perform linear search for employee
bool searchEmployee(int employees[], int searchkey, int size)
{
  sort(employees, employees + size);

  for (int i = 0; i < size; i++)
  {
    if (employees[i] == searchkey)
    {
      return true;
    }
  }
  return false;
}

// main function
int main()
{
  const int SIZE = 10;
  int employees[SIZE];
  int choice;
  int employeeID;
  int searchkey;
  int emp_index = 0;

  do
  {
    cout << "\n\nPlease enter an option ( -1 to Exit ):\n";
    cout << "1. Add Employee ID to Training Roster\n";
    cout << "2. Search Employee ID in Training Roster\n\n";
    cin >> choice;

    if (choice == 1)
    {
      do
      {
        if (emp_index <= SIZE-1)
        {
          cout << "\nPlease enter an Employee ID to add:\n\n";
          cin >> employeeID;
          addEmployee(employees, emp_index, employeeID);
          emp_index += 1;
        }
        else if (emp_index >= SIZE-1)
        {
          cout << "\n\n\nSorry, the roster is full.\n\n";
          break;
        }
      } while (employeeID != -1);
      
    }
    else if (choice == 2)
    {
      cout << "\nPlease enter the Employee ID to search for:\n\n";
      cin >> searchkey;
      bool result = searchEmployee(employees, searchkey, SIZE);
      if (result == true)
      {
        cout << "\n\nEmployee " << searchkey << " has completed their training.\n\n";
      }
      else
      {
        cout << "\n\nEmployee " << searchkey << " has NOT completed their training.\n\n";
      }
    }
    else
    {
      cout << "\n\nSorry that's an invalid choice!\n\n";
    }
  } while (choice != -1);
}
