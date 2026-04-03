#pragma once
#include "Neuron.hpp"
#include <vector>

class Layer {
    public:
        std::vector<Neuron> neurons;
        Layer(int nins, int nout);

        std::vector<V> operator()(std::vector<V> x);
        
        std::vector<V> parameters();
};
