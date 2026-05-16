#include "Tensor.hpp"
#include <string>
#include <stdexcept>

Tensor::Tensor(const std::vector<int>& s) : shape(s) {
    int dataSize = 1;
    for (int i : shape) {
        dataSize *= i;  
    }
    data.assign(dataSize, 0.0);

    strides.resize(shape.size());
    int currStride = 1;
    for (int i = shape.size() - 1; i >= 0; i--) {
        strides[i] = currStride;
        currStride *= shape[i];
    }
}

double& Tensor::at(const std::vector<int>& indices) {
    if (indices.size() != shape.size()) {
        throw std::invalid_argument("No. of indices does not match rank");
    }
    
    int flatIndex = 0;
    for (int i = 0; i < indices.size(); i++) {
        if (indices[i] < 0 || indices[i] >= shape[i]) {
            throw std::out_of_range("Index out of bounds for dimension: " + std::to_string(i));
        }

        flatIndex += indices[i] * strides[i];
    }

    return data[flatIndex];
}