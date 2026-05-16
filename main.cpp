#include <iostream>
#include <vector>
#include "Tensor.hpp"

int main() {
    Tensor b({3});
    b.at({0}) = 1.1;
    b.at({1}) = 2.2;
    b.at({2}) = 3.3;

    Tensor B_matrix = b.broadcastTo({4, 3});

    std::cout << "Broadcasted Strides: {" 
              << B_matrix.strides[0] << ", " 
              << B_matrix.strides[1] << "}\n";

    std::cout << "Row 0, Col 1: " << B_matrix.at({0, 1}) << "\n";
    std::cout << "Row 3, Col 1: " << B_matrix.at({3, 1}) << "\n";

    return 0;
}