#include "Neuron.hpp"
#include <random>

Neuron::Neuron(int nin, Activation act) : act(act) {
    static std::mt19937 gen(std::random_device{}());
    static std::uniform_real_distribution<double> rands(-1, 1);

    for (int i = 0; i < nin; i++) {
        this->w.push_back(val(rands(gen)));
    }
    this->b = val(rands(gen));
}

V Neuron::operator()(std::vector<V> x) {
    V out = b;

    for (int i = 0; i < w.size(); i++) {
        out = out + w[i] * x[i]; // y = xiwi + b
    }
   
    switch (act) {
        case Activation::TANH:
            return tanh(out) ;
        case Activation::RELU:
            return relu(out);
        case Activation::NONE:
            return out;
        default:
            return out;
    }
}


std::vector<V> Neuron::parameters() {
    std::vector<V> params = this->w;
    params.push_back(this->b);

    return params;
}

void Neuron::zeroGrad() {
    for (V& wi : w) {
        wi->grad = 0.0;
    }
    b->grad = 0.0;
}
