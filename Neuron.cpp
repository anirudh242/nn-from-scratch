#include "Neuron.hpp"
#include <random>

Neuron::Neuron(int nin) {
    static std::mt19937 gen(std::random_device{}());
    static std::uniform_real_distribution<double> rands(-1, 1);

    for (int i = 0; i < nin; i++) {
        this->w.push_back(val(rands(gen)));
    }
    this->b = val(rands(gen));
}

V Neuron::operator()(std::vector<V> x) {
    V activation = b;

    for (int i = 0; i < w.size(); i++) {
        activation = activation + w[i] * x[i]; // y = xiwi + b
    }
    
    return tanh(activation);
}


std::vector<V> Neuron::parameters() {
    std::vector<V> params = this->w;
    params.push_back(this->b);

    return params;
}

