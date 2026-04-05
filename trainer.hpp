#pragma once
#include "MLP.hpp"
#include <vector>

void train(MLP& model, std::vector<std::vector<double>>& xs, std::vector<double>& ys, int epochs, double lr);

std::vector<double> predict(MLP& model, std::vector<std::vector<double>>& xs);
