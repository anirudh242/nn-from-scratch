#include "Value.hpp"

Value::Value(double data) : data(data) {}

std::ostream& operator<<(std::ostream& os, const V& v) {
    os << "Value(data=" << v->data << ")";
    return os;
}

// addition
V operator+(V a, V b) {
    auto out = val(a->data + b->data);
    out->prev = {a, b};

    return out;
}

V operator+(V a, double b) {
    return a + val(b);
}

V operator+(double a, V b) {
    return val(a) + b;
}
