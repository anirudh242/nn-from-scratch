#pragma once
#include <vector>

class Tensor {
public:
    std::vector<double> data;
    std::vector<int> shape;
    std::vector<int> strides;

    Tensor(const std::vector<int>& shape);

    double& at(const std::vector<int>& indices);
};