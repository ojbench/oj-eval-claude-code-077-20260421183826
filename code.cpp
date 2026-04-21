#include <iostream>
#include "CrossArray.hpp"

int main() {
    // Basic test to ensure it compiles and runs.
    // The actual testing will be done by the OJ calling the class methods.
    sjtu::CrossArray ca(2);
    int arr1[] = {1, 2, 3};
    ca.InsertArrays(arr1, 3);
    int arr2[] = {4, 5};
    ca.InsertArrays(arr2, 2);

    std::cout << "At(0, 0): " << ca.At(0, 0) << std::endl;
    std::cout << "At(1, 1): " << ca.At(1, 1) << std::endl;

    int arr3[] = {6};
    ca.AppendArrays(arr3, 0, 1);
    std::cout << "At(0, 3): " << ca.At(0, 3) << std::endl;

    ca.DoubleCrossLength();
    int arr4[] = {7, 8, 9, 10};
    ca.InsertArrays(arr4, 4);
    std::cout << "At(2, 2): " << ca.At(2, 2) << std::endl;

    sjtu::CrossArray ca2 = ca;
    std::cout << "ca2 At(2, 2): " << ca2.At(2, 2) << std::endl;

    return 0;
}
