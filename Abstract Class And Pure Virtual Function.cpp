#include <iostream>
#include <string>
using namespace std;

// Abstract class with pure virtual functions
class Employee {
protected:
    int empId;
    string name;
    float baseSalary;

public:
    Employee() {
        empId = 0;
        name = "Unknown";
        baseSalary = 0;
    }

    Employee(int id, string n, float salary) {
        empId = id;
        name = n;
        baseSalary = salary;
    }
    
    // Pure virtual functions - making this an abstract class
    virtual float calculateSalary() = 0;
    virtual void displayInfo() = 0;

    // Regular member function
    void setBaseSalary(float salary) {
        this->baseSalary = salary; // Using 'this' pointer
    }

    // Demonstrating 'this' pointer
    Employee& setEmpId(int id) {
        this->empId = id;
        return *this; // Returning reference to current object for chaining
    }

    Employee& setName(string n) {
        this->name = n;
        return *this;
    }
  
    virtual ~Employee() {}
};
  
// derived class - PermanentEmployee
class PermanentEmployee : public Employee {
private:
    float bonus;
    float allowances;
  
public:
    PermanentEmployee() : Employee() {
        bonus = 0;
        allowances = 0;
    }
     
    PermanentEmployee(int id, string n, float salary, float b, float a)
        : Employee(id, n, salary) {
        bonus = b;
        allowances = a;
    }

    // Implementation of pure virtual functions
    float calculateSalary() override {
        return baseSalary + bonus + allowances;
    }

    void displayInfo() override {
        cout << "--- Permanent Employee ---" << endl;
        cout << "ID: " << empId << endl;
        cout << "Name: " << name << endl;
        cout << "Base Salary: " << baseSalary << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "Allowances: " << allowances << endl;
        cout << "Total Salary: " << calculateSalary() << endl;
    }
};                    

// derived class - ContractEmployee
class ContractEmployee : public Employee {
private:
    int contractDuration; // in months
    float hourlyRate;
    int hoursWorked;
  
public:
    ContractEmployee() : Employee() {
        contractDuration = 0;
        hourlyRate = 0;
        hoursWorked = 0;
    }
     
    ContractEmployee(int id, string n, float salary, int duration, float rate, int hours)
        : Employee(id, n, salary) {
        contractDuration = duration;
        hourlyRate = rate;
        hoursWorked = hours;
    }

    float calculateSalary() override {
        return hourlyRate * hoursWorked;
    }
     
    void displayInfo() override {
        cout << "--- Contract Employee ---" << endl;
        cout << "ID: " << empId << endl;
        cout << "Name: " << name << endl;
        cout << "Base Salary (Monthly): " << baseSalary << endl;
        cout << "Contract Duration: " << contractDuration << " months" << endl;
        cout << "Hourly Rate: " << hourlyRate << endl;
        cout << "Hours Worked: " << hoursWorked << endl;
        cout << "Total Salary: " << calculateSalary() << endl;
    }
};

// Demonstrate Pointers to objects 
void DemonstratePointeroperation() {
    cout << "\n======== Pointers to Objects ========" << endl;
  
    // Creating objects
    PermanentEmployee emp1(101, "john doe", 50000, 10000, 5000);
    ContractEmployee emp2(102, "jane smith", 0, 6, 200, 160);
  
    // Pointer to object
    PermanentEmployee *ptr1 = &emp1;
    ContractEmployee *ptr2 = &emp2;

    cout << "Using pointer to object:" << endl;
    ptr1->displayInfo();
    cout << endl;
    ptr2->displayInfo();

    // Array of pointers to Employee (polymorphism)
    cout << "\nArray of pointers to Employees:" << endl;

    Employee *employees[2];

    employees[0] = new PermanentEmployee(103, "Bob Johnson", 60000, 15000, 7000);
    employees[1] = new ContractEmployee(104, "Alice Brown", 0, 3, 250, 150);

    for (int i = 0; i < 2; i++) {
        employees[i]->displayInfo();
        cout << endl;
        delete employees[i];
    }
}

// demonstrating chaining using 'this' pointer
void demonstrateThisPointer() {
    cout << "\n===== 'this' pointer and method chaining =====" << endl;
  
    PermanentEmployee emp;
    emp.setEmpId(105)
       .setName("Charlie Wilson")
       .setBaseSalary(45000);
    // add bonus and allowances
    emp = PermanentEmployee(105, "Charlie Wilson", 45000, 8000, 3000);
    emp.displayInfo();
}
     
int main() {
    cout << "----- Abstract Class and Pure Virtual Functions -----" << endl;

    // Cannot instantiate abstract class
    // Employee e; // Error: cannot declare variable of abstract type

    PermanentEmployee perm(1001, "David Miller", 55000, 12000, 6000);
    ContractEmployee contract(1002, "Sarah Davis", 0, 4, 180, 160);

    perm.displayInfo();
    cout << endl;
    contract.displayInfo();

    // Call additional demonstration functions
    DemonstratePointeroperation();
    demonstrateThisPointer();

    return 0;
}



























































