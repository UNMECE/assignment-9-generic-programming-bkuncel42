#include <iostream>
#include "generic_array.h"

int main() {
    GenericArray<int> int_array;
    int_array.addElement(10);
    int_array.addElement(20);
    int_array.addElement(5);
    int_array.addElement(40);
    int_array.addElement(15);
    int_array.addElement(25);

    std::cout << "Size of array is " << int_array.size() << std::endl;
    std::cout << "Sum of the array is " << int_array.sum() << std::endl;
    std::cout << "Maximum of array is " << int_array.max() << std::endl;
    std::cout << "Minimum of array is " << int_array.min() << std::endl;

    int* sliced_array = int_array.slice(2, 4);
    if (sliced_array) {
        std::cout << "Sliced array (2 to 4): ";
        for (int i = 0; i <= 4 - 2; ++i) {
            std::cout << sliced_array[i] << " ";
        }
        std::cout << std::endl;
        delete[] sliced_array;
    }

    return 0;
}
