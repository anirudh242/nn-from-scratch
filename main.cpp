#include <iostream>
#include <vector>
#include "Tensor.hpp"

int main() {
    Tensor t({2, 3, 4}); 

    std::cout << "Strides calculated as: {" 
              << t.strides[0] << ", " 
              << t.strides[1] << ", " 
              << t.strides[2] << "}\n";

    t.at({1, 2, 3}) = 99.9;

    std::cout << "Value at {1, 2, 3}: " << t.at({1, 2, 3}) << "\n";

    std::cout << "Value at flat memory index 23: " << t.data[23] << "\n";

    return 0;
}