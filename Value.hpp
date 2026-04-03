#pragma once

#include <ostream>
#include <vector>
#include <memory>
#include <functional>

class Value;
using V = std::shared_ptr<Value>;

class Value {
    public:
        double data;
        double grad;
        std::vector<V> prev;
        std::string label;
        std::string op;

        std::function<void()> _backward;
        
        Value(double data, std::string label);
        friend std::ostream& operator<<(std::ostream& os, const V& v);
};

inline V val(double x, std::string l="") {
    return std::make_shared<Value>(x, l);
}

// addition
V operator+(V a, V b);
V operator+(V a, double b);
V operator+(double a, V b);

// multiplication
V operator*(V a, V b);
V operator*(V a, double b);
V operator*(double a, V b);