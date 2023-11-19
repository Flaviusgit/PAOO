#include <iostream>
#include "SmartArray.h"

int main() {
    std::cout << "Cream firstArr si incarcam data \n";
    SmartArray firstArr(10);

    firstArr.push(10);
    firstArr.push(7);
    firstArr.push(12);
    firstArr.push(3);

    std::cout << "firstArr: "; 
    firstArr.print();

    std::cout << "Copiem firstArr in secondArr\n";
    SmartArray secondArr(firstArr);

    std::cout << "Modificam secondArr\n";
    secondArr.pop();
    secondArr.push(-1);
    secondArr.sortArray();

    std::cout << "firstArr: "; firstArr.print();
    std::cout << "secondArr: "; secondArr.print();

    std::cout << "Cream array cu rValue\n";
    SmartArray thirdArr(SmartArray({1, 2, 3, 4, 5}));

    std::cout << "thirdArr: "; thirdArr.print();

    SmartArray fourthArr(std::move(thirdArr));

    std::cout << "fourthArr: "; fourthArr.print();
}