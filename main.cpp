#include <iostream>
#include "Value.hpp"
#include "graph.hpp"
#include "MLP.hpp"
#include "trainer.hpp"

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

    // std::vector<std::vector<double>> xs = {
    //     {2.0, 3.0},
    //     {3.0, -1.0},
    //     {0.5, 1.0},
    //     {1.0, 1.0}
    // };
    // std::vector<double> ys = {1.0, -1.0, -1.0, 1.0};

    MLP model(2, {4, 4, 1}, Activation::TANH);

    std::vector<std::vector<double>> xs = {
        {0,0},
        {0,1},
        {1,0},
        {1,1}
    };

    std::vector<double> ys = {0, 1, 1, 0};

    train(model, xs, ys, 500, 0.01);

    std::vector<double> predictions = predict(model, xs);

    std::cout << "Model predictions: " << std::endl;
    for (double p : predictions) {
        std::cout << p << std::endl;
    }

    return 0;
}