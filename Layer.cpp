#include "Layer.hpp"

Layer::Layer(int nin, int nout, Activation act) {
    for (int i = 0; i < nout; i++) {
        this->neurons.push_back(Neuron(nin, act));
    }
}

std::vector<V> Layer::operator()(std::vector<V> x) {
    std::vector<V> outs;

    for (Neuron& neuron : this->neurons) {
        outs.push_back(neuron(x));
    }

    return outs;
}

std::vector<V> Layer::parameters() {
    std::vector<V> params;
    for (Neuron& neuron : this->neurons) {
        for (V p : neuron.parameters()) {
            params.push_back(p);
        }
    }
    return params;
}

void Layer::zeroGrad() {
    for (Neuron& neuron : this->neurons) {
        neuron.zeroGrad();
    }
}
