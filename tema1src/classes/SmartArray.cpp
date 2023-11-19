#include <cstdlib>
#include <iostream>
#include <vector>

#include "SmartArray.h"

SmartArray::SmartArray(int totalSize) {
    std::cout << "Apelam constructorul\n";

    array = (int*)malloc(totalSize * sizeof(int));
    if(!array) {
        std::cout << "Eroare de alocare.Iesire\n";
        exit(1);
    }

    avMemory = totalSize;
}

SmartArray::SmartArray(std::vector<int> initialData) {
    std::cout << "Apelam constructorul cu memorie default\n";

    int totalSize = initialData.size();

    array = (int*)malloc(totalSize * sizeof(int));
    if(!array) {
        std::cout << "Eroare de alocare.Iesire\n";
        exit(1);
    }

    avMemory = totalSize;

    for(int& x: initialData) {
        array[n++] = x;
    }
}

SmartArray::~SmartArray() {
    std::cout << "Eliberam memorie din array \n";
    free(array);
}

SmartArray::SmartArray(const SmartArray& arrayToCopy) {
    std::cout << "Apelam constructorul\n";

    n = arrayToCopy.n;
    avMemory = arrayToCopy.avMemory;

    array = (int*)malloc(avMemory * sizeof(int));
    if(!array) {
        std::cout << "Problema cu copierea array-ului \n";
        exit(1);
    }

    for(int i=0; i<n; i++) {
        array[i] = arrayToCopy.array[i];
    }
}

SmartArray::SmartArray(SmartArray&& arrayToMove) {
    std::cout << "Apelam move constructor\n";

    n = arrayToMove.n;
    avMemory = arrayToMove.avMemory;
    array = arrayToMove.array;

    arrayToMove.array = NULL;
}

void SmartArray::push(int x) {
    if(n + 1 < avMemory) {
        array[n++] = x;
        return;
    }

    // Double memory space
    array = (int*)realloc(array, 2 * avMemory * sizeof(int));
    if(!array) {
        std::cout << "Fara memorie. Ieșire\n";
        exit(1);
    };

    avMemory *= 2;
    array[n++] = x;
    return;
}

void SmartArray::pop() {
    if(n > 0) {
        n--;
        return;
    }

    std::cout << "Array e deja gol\n";
    return;
}

void SmartArray::sortArray() {
    if(!n) {
        std::cout << "Array e gol\n";
        return;
    }

    int sortat = 0;
    while(!sortat) {
        sortat = 1;

        for(int i=1; i<n; i++) {
            if(array[i-1] > array[i]) {
                sortat = 0;

                int aux = array[i-1];
                array[i-1] = array[i];
                array[i] = aux;
            }
        }
    }

    std::cout << "Array sortat cu succes.\n";
    return;
}

void SmartArray::print() {
    std::cout << "[";

    for(int i=0; i<n; i++) {
        std::cout << array[i] << " ";
    }

    std::cout << "\b]\n";
}