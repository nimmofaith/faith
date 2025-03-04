#include <iostream>
#include <vector>
using namespace std;

// Base Class: Employee
class Employee {
protected:
    string name;
    int employeeID;
    double salary;

public:
    virtual void inputDetails() {
        cout << "Enter Name: ";
        cin >> ws;
        getline(cin, name);
        cout << "Enter Employee ID: ";
        cin >> employeeID;
        cout << "Enter Salary: ";
        cin >> salary;
    }

    virtual void displayDetails() {
        cout << "\nEmployee Details:" << endl;
        cout << "Name: " << name << endl;
        cout << "Employee ID: " << employeeID << endl;
        cout << "Salary: $" << salary << endl;
    }

    int getEmployeeID() { return employeeID; }
    virtual ~Employee() {}
};

// Derived Class: Manager
class Manager : public Employee {
private:
    string department;
    double bonus;

public:
    void inputDetails() override {
        Employee::inputDetails();
        cout << "Enter Department: ";
        cin >> ws;
        getline(cin, department);
        cout << "Enter Bonus: ";
        cin >> bonus;
    }

    void displayDetails() override {
        Employee::displayDetails();
        cout << "Department: " << department << endl;
        cout << "Bonus: ksh" << bonus << endl;
    }
};

// Derived Class: Engineer
class Engineer : public Employee {
private:
    string specialization;
    string projectAssigned;

public:
    void inputDetails() override {
        Employee::inputDetails();
        cout << "Enter Specialization: ";
        cin >> ws;
        getline(cin, specialization);
        cout << "Enter Project Assigned: ";
        getline(cin, projectAssigned);
    }

    void displayDetails() override {
        Employee::displayDetails();
        cout << "Specialization: " << specialization << endl;
        cout << "Project Assigned: " << projectAssigned << endl;
    }
};

// Employee Management System Class
class EmployeeManagementSystem {
private:
    vector<Employee*> employees;

public:
    void addEmployee(Employee* emp) {
        employees.push_back(emp);
    }

    void displayAllEmployees() {
        cout << "\nAll Employee Records:" << endl;
        for (Employee* emp : employees) {
            emp->displayDetails();
        }
    }

    void searchEmployeeByID(int id) {
        for (Employee* emp : employees) {
            if (emp->getEmployeeID() == id) {
                cout << "\nEmployee Found:" << endl;
                emp->displayDetails();
                return;
            }
        }
        cout << "\nEmployee with ID " << id << " not found." << endl;
    }

    ~EmployeeManagementSystem() {
        for (Employee* emp : employees)
            delete emp;
    }
};

// Main Function
int main() {
    EmployeeManagementSystem ems;

    Manager* mgr = new Manager();
    cout << "\nEnter Manager Details:" << endl;
    mgr->inputDetails();
    ems.addEmployee(mgr);

    Engineer* eng = new Engineer();
    cout << "\nEnter Engineer Details:" << endl;
    eng->inputDetails();
    ems.addEmployee(eng);

    ems.displayAllEmployees();

    int searchID;
    cout << "\nEnter Employee ID to search: ";
    cin >> searchID;
    ems.searchEmployeeByID(searchID);

    return 0;
}
