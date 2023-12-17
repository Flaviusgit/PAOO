#pragma once

#include <iostream>
#include <thread>
#include <mutex>
#include <memory>
#include <vector>
#include <cstdlib>
#include <ctime>

class Attendance {
    public:
        Attendance();
        void displayAttendanceSheet() const;

        void writeNameOnAttendanceSheet(int id, const std::string& name);

    private:
        std::mutex attendanceMutex;
        std::vector<std::string> attendanceSheet;

        int getRandomDuration(int minDuration, int maxDuration) const;
};