//all about c++ tuple, which is similar to pair but for 3 elements
#include <iostream>
#include <vector>
#include <tuple>

int main() {
    int array1[] = {1, 2, 3, 4, 5};
    double array2[] = {0.1, 0.2, 0.3, 0.4, 0.5};
    std::string array3[] = {"one", "two", "three", "four", "five"};

    int arraySize = sizeof(array1) / sizeof(array1[0]);

    std::vector<std::tuple<int, double, std::string>> tupleVector;

    for (int i = 0; i < arraySize; ++i) {
        tupleVector.emplace_back(array1[i], array2[i], array3[i]);
    }

    // Accessing the vector of tuples
    for (const auto& tuple : tupleVector) {
        int value1;
        double value2;
        std::string value3;
        std::tie(value1, value2, value3) = tuple;

        std::cout << "Value 1: " << value1 << " | Value 2: " << value2 << " | Value 3: " << value3 << std::endl;
    }

    return 0;
}
