#include <iostream>

#include "SmartArray.h"
#include "SecondSmartArray.h"

int main() {
    std::cout << "Creating myArray and pushing some data...\n";
    SmartArray myArray(10);

    myArray.push(10);
    myArray.push(7);
    myArray.push(12);
    myArray.push(3);

    std::cout << "myArray: "; myArray.print();

    std::cout << "Copying myArray into mySecond array...\n";
    SmartArray mySecondArray = myArray;

    std::cout << "Modifying mySecondArray...\n";
    mySecondArray.pop();
    mySecondArray.push(-1);
    mySecondArray.sortArray();

    std::cout << "myArray: "; myArray.print();
    std::cout << "mySecondArray: "; mySecondArray.print();

    std::cout << "Creating array with rValue...\n";
    SmartArray myThirdArray = SmartArray({1, 2, 3, 4, 5});
    
    std::cout << "Creating a really smart array...\n";
    SecondSmartArray mySecondSmartArray = SecondSmartArray({6, 2, 1, 9, 4, 5});
    mySecondSmartArray.sortArray();
    mySecondSmartArray.print();


    std::cout << "myThirdArray: "; myThirdArray.print();
}