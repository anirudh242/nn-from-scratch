#pragma once
#include "Value.hpp"
#include <vector>

enum Activation {
    NONE,
    TANH,
    RELU
};

class Neuron {
    public:
        std::vector<V> w;
        V b;
        Activation act;
        
        Neuron(int nin, Activation act = Activation::NONE);
        
        V operator()(std::vector<V> x);

        std::vector<V> parameters();

        void zeroGrad();
};
