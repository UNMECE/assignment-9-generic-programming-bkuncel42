#ifndef GENERIC_ARRAY_H
#define GENERIC_ARRAY_H

#include <iostream>
#include <limits>

template<typename T>
class GenericArray {
private:
    T* data;
    int length;

public:
    // Constructor
    GenericArray() {
        data = nullptr;
        length = 0;
    }

    // Destructor
    ~GenericArray() {
        delete[] data;
    }

    // Add element to the array
    void addElement(T value) {
        T* newData = new T[length + 1];
        for (int i = 0; i < length; ++i) {
            newData[i] = data[i];
        }
        newData[length] = value;
        delete[] data;
        data = newData;
        ++length;
    }

    // Return value at index
    T at(int index) const {
        if (index < 0 || index >= length) {
            std::cerr << "Index out of bounds\n";
            return T(); // Return default-constructed value
        }
        return data[index];
    }

    // Return size
    int size() const {
        return length;
    }

    // Return sum of elements
    T sum() const {
        T total = 0;
        for (int i = 0; i < length; ++i) {
            total += data[i];
        }
        return total;
    }

    // Return max value
    T max() const {
        if (length == 0) {
            std::cerr << "Array is empty\n";
            return T();
        }
        T maxVal = std::numeric_limits<T>::lowest();
        for (int i = 0; i < length; ++i) {
            if (data[i] > maxVal) maxVal = data[i];
        }
        return maxVal;
    }

    // Return min value
    T min() const {
        if (length == 0) {
            std::cerr << "Array is empty\n";
            return T();
        }
        T minVal = std::numeric_limits<T>::max();
        for (int i = 0; i < length; ++i) {
            if (data[i] < minVal) minVal = data[i];
        }
        return minVal;
    }

    // Return a slice from begin to end (inclusive)
    T* slice(int begin, int end) const {
        if (begin < 0 || end >= length || begin > end) {
            std::cerr << "Invalid slice bounds\n";
            return nullptr;
        }

        int newSize = end - begin + 1;
        T* sliceArray = new T[newSize];
        for (int i = 0; i < newSize; ++i) {
            sliceArray[i] = data[begin + i];
        }
        return sliceArray;
    }
};

#endif // GENERIC_ARRAY_H
