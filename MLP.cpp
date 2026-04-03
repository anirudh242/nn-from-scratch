#include "MLP.hpp"
#include <vector>

MLP::MLP(int nin, std::vector<int> nouts) {
    this->layerSizes = {nin};
    this->layerSizes.insert(layerSizes.end(), nouts.begin(), nouts.end());

    for (int i = 0; i < layerSizes.size() - 1; i++) {
        layers.push_back(Layer(layerSizes[i], layerSizes[i+1]));
    }
}

std::vector<V> MLP::operator()(std::vector<V> x) {
    for (Layer& layer : this->layers) {
        x = layer(x);
    }

    return x;
}

std::vector<V> MLP::parameters() {
    std::vector<V> params;
    for (Layer& layer : this->layers) {
        for (V p : layer.parameters()) {
            params.push_back(p);
        }
    }
    return params;
}