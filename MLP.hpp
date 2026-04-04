#pragma once
#include "Layer.hpp"
#include <vector>

class MLP {
    public:
        std::vector<int> layerSizes;
        std::vector<Layer> layers;

        MLP(int nin, std::vector<int> nouts, Activation hidden_act);

        std::vector<V> operator()(std::vector<V> x);

        std::vector<V> parameters();
};
