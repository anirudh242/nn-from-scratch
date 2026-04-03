#pragma once
#include "Value.hpp"
#include <vector>

class Neuron {
    public:
        std::vector<V> w;
        V b;
        
        Neuron(int nin);
        
        V operator()(std::vector<V> x);

        std::vector<V> parameters();
};
