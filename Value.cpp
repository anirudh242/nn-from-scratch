#include "Value.hpp"

Value::Value(double data, std::string label) : data(data), label(label), grad(0.0) {
    _backward = [](){}; // for leaf node with no local gradient function
}

std::ostream& operator<<(std::ostream& os, const V& v) {
    os << "Value(data=" << v->data << ", grad=" << v->grad << ")";
    return os;
}

// addition
V operator+(V a, V b) {
    V out = val(a->data + b->data);
    out->prev = {a, b};
    out->op = "+";

    std::function<void()> _backward = [a, b, out] {
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

// backpropogation
void build_topo(V v, std::vector<V>& topo, std::set<Value*>& visited) {
    if (!visited.count(v.get())) {
        visited.insert(v.get());
        for (V child : v->prev) {
            if (!child) continue; 
            build_topo(child, topo, visited);
        }
        topo.push_back(v);
    }
}

void backward(V self) {
    std::vector<V> topo;
    std::set<Value*> visited;
    self->grad = 1.0;
    build_topo(self, topo, visited);

    reverse(topo.begin(), topo.end());
    for (V node : topo) {
        if (node->_backward) node->_backward();
    }
}

// activation functions
V relu(V x) {
    V out = val(std::max(0.0, x->data));
    out->prev = {x};
    out->op = "ReLU";

    out->_backward = [x, out]() {
        x->grad += (x->data > 0.0 ? 1.0 : 0.0) * out->grad;
    };

    return out;
}

V tanh(V x) {
    V out = val(std::tanh(x->data));
    out->prev = {x};
    out->op = "tanx";

    out->_backward = [x, out]() {
        x->grad = (1-out->data*out->data)*out->grad;
    };

    return out;
}
