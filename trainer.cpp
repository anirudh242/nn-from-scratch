#include "trainer.hpp"
#include "Value.hpp"
#include <iostream>

void train(MLP& model, std::vector<std::vector<double>>& xs, std::vector<double>& ys, int epochs, double lr) {
    for (int e = 0; e < epochs; e++) {
        std::vector<V> ypred;
        for (auto& x : xs) {
            std::vector<V> vx;

            for (double xi : x) {
                vx.push_back(val(xi));
            }
            ypred.push_back(model(vx)[0]);
        }

        V loss = val(0.0); 

        // mse loss
        for (int i = 0; i < ypred.size(); i++) {
            V diff = ypred[i] - val(ys[i]);
            loss = loss + diff * diff;
        }

        model.zeroGrad(); 

        backward(loss);

        for (auto p : model.parameters()) {
            p->data -= lr * p->grad;
        }

        std::cout << "epoch " << e << " loss = " << loss->data << std::endl;
    }
}

std::vector<double> predict(MLP& model, std::vector<std::vector<double>>& xs) {
    std::vector<double> predictions;

    for (std::vector<double>& x : xs) {
        std::vector<V> vx;

        for (double xi : x) {
            vx.push_back(val(xi));
        }

        V out = model(vx)[0];
        predictions.push_back(out->data);
    }

    return predictions;
}
