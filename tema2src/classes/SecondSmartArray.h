#pragma once

#include <vector>
#include "SmartArray.h"

class SecondSmartArray : public SmartArray {
    private:
        int partition(int arr[], int start, int end);
        void quickSort(int arr[], int start, int end);
    public:
        SecondSmartArray(std::vector<int> initialData = {});
        void sortArray();
        void print();
};