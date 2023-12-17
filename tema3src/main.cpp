#include "StudentService.h"
#include <vector>
#include <memory>

int main() {
    const int numStudents = 5;
    std::vector<std::unique_ptr<std::thread>> studentThreads;

    
    std::vector<std::string> studentNames = {"Flavius", "Carpean", "Gheorghe", "Marius", "Mihai"};

    
    Attendance studentService;

    
    for (int i = 0; i < numStudents; ++i) {
        studentThreads.push_back(std::make_unique<std::thread>(&Attendance::writeNameOnAttendanceSheet, &studentService, i + 1, studentNames[i]));
    }
    
    for (auto& thread : studentThreads) {
        thread->join();
    }

    studentService.displayAttendanceSheet();
    
    return 0;
}