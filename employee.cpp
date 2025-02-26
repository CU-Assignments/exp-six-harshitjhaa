#include <iostream>
#include <vector>
#include <algorithm>

class Employee {
public:
    std::string name;
    int age;
    double salary;

    Employee(std::string n, int a, double s) : name(n), age(a), salary(s) {}

    void display() const {
        std::cout << name << ", " << age << ", " << salary << std::endl;
    }
};

int main() {
    std::vector<Employee> employees = {
        {"Alice", 30, 60000},
        {"Bob", 25, 50000},
        {"Charlie", 35, 70000},
        {"David", 28, 55000}
    };

    // Sorting by name (alphabetically)
    std::sort(employees.begin(), employees.end(), [](const Employee &a, const Employee &b) {
        return a.name < b.name;
    });
    std::cout << "Sorted by Name:\n";
    for (const auto &emp : employees) emp.display();

    // Sorting by age (ascending order)
    std::sort(employees.begin(), employees.end(), [](const Employee &a, const Employee &b) {
        return a.age < b.age;
    });
    std::cout << "Sorted by Age:\n";
    for (const auto &emp : employees) emp.display();

    // Sorting by salary (descending order)
    std::sort(employees.begin(), employees.end(), [](const Employee &a, const Employee &b) {
        return a.salary > b.salary;
    });
    std::cout << "Sorted by Salary:\n";
    for (const auto &emp : employees) emp.display();

    return 0;
}
