#include "Value.hpp"

Value::Value(double data, std::string label) : data(data), label(label), grad(0.0) {}

std::ostream& operator<<(std::ostream& os, const V& v) {
    os << "Value(data=" << v->data << ", grad=" << v->grad << ")";
    return os;
}

// addition
V operator+(V a, V b) {
    V out = val(a->data + b->data);
    out->prev = {a, b};
    out->op = "+";

    std::function<void()> _backward = [&] {
        a->grad += out->grad;
        b->grad += out->grad;
    };

    out->_backward = _backward;

    return out;
}

V operator+(V a, double b) {
    return a + val(b);
}

V operator+(double a, V b) {
    return val(a) + b;
}

// multiplication
V operator*(V a, V b) {
    V out = val(a->data * b->data);
    out->prev = {a, b};
    out->op = "*";

    std::function<void()> _backward = [a, b, out] {
        a->grad += b->data * out->grad;
        b->grad += a->data * out->grad;
    };

    out->_backward = _backward;

    return out;
}

V operator*(V a, double b) {
    return a * val(b);
}

V operator*(double a, V b) {
    return val(a) * b;
}
