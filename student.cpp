#include <iostream>
#include <vector>
#include <algorithm>

class Student {
public:
    std::string name;
    double marks;

    Student(std::string n, double m) : name(n), marks(m) {}
};

int main() {
    std::vector<Student> students = {
        {"Alice", 85.5},
        {"Bob", 72.0},
        {"Charlie", 90.0},
        {"David", 65.5},
        {"Eve", 78.0}
    };

    // Filtering students scoring above 75% and sorting by marks in descending order
    std::vector<Student> filtered_students;
    std::copy_if(students.begin(), students.end(), std::back_inserter(filtered_students), [](const Student &s) {
        return s.marks > 75.0;
    });
    
    std::sort(filtered_students.begin(), filtered_students.end(), [](const Student &a, const Student &b) {
        return a.marks > b.marks;
    });
    
    // Displaying student names
    std::cout << "Students scoring above 75%, sorted by marks:\n";
    for (const auto &student : filtered_students) {
        std::cout << student.name << "\n";
    }
    
    return 0;
}