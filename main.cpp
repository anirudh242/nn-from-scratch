#include <iostream>
#include "Value.hpp"
#include "graph.hpp"
#include "MLP.hpp"

int main() {
    // V a = val(2.0, "a");
    // V b = val(3.0, "b");
    // V c = a + b; c->label = "c";
    // V d = c + 5; d->label = "d";
    // V e = d * 2; e->label = "e";
    // V f = e * d; f->label = "f";
    // V g = relu(f);

    // backward(g);
    // draw_dot(g);

    // for (auto i : c->prev) cout << i << endl;
    // cout << d << endl
    // cout << e << endl;
    // cout << f << endl; 

    // auto x1 = val(2.0, "x1");
    // auto x2 = val(0.0, "x2");
    // auto w1 = val(-3.0, "w1");
    // auto w2 = val(1.0, "w2");
    // auto x1w1 = x1*w1; x1w1->label="x1w1";
    // auto x2w2 = x2*w2; x2w2->label="x2w2";
    // auto b = val(6.8813735870195432, "b");
    // auto x1w1x2w2 = x1w1 + x2w2; x1w1x2w2->label = "x2w1+x2w2";
    // auto n = x1w1x2w2 + b; n->label = "n";
    // auto y = tanh(n);
    // backward(y);
    // draw_dot(y);

    MLP model(2, {4, 4, 1}, Activation::TANH);

    // std::vector<std::vector<double>> xs = {
    //     {2.0, 3.0},
    //     {3.0, -1.0},
    //     {0.5, 1.0},
    //     {1.0, 1.0}
    // };
    // std::vector<double> ys = {1.0, -1.0, -1.0, 1.0};

    std::vector<std::vector<double>> xs = {
        {0,0},
        {0,1},
        {1,0},
        {1,1}
    };

    std::vector<double> ys = {0, 1, 1, 0};

    double lr = 0.01;

    for (int e = 0; e < 500; e++) {
        std::vector<V> ypred;
        for (std::vector<double>& x : xs) {
            std::vector<V> vx;
            for (double xi : x) {
                vx.push_back(val(xi));
            }
            V pred = model(vx)[0];
            ypred.push_back(pred);
        }

        V loss = val(0.0);
        for (int i = 0; i < ypred.size(); i++) {
            V diff = ypred[i] - val(ys[i]);
            loss = loss + diff * diff;
        }

        for (auto p : model.parameters()) {
            p->grad = 0;
        }

        backward(loss);

        for (auto p : model.parameters()) {
            p->data -= lr * p->grad;
        }

        if (e == 99) draw_dot(loss);

        std::cout << "epoch " << e << " loss = " << loss->data << std::endl;
    }

    std::cout << "Model predictions: " << std::endl;
    for (auto& x : xs) {
        std::vector<V> vx;
        for (double xi : x) {
            vx.push_back(val(xi));
        }

        V pred = model(vx)[0];
        std::cout << pred->data << std::endl;
    }


    return 0;
}