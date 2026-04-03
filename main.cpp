#include <iostream>
#include "Value.hpp"
#include "graph.hpp"
using namespace std;

int main() {
    V a = val(2.0, "a");
    V b = val(3.0, "b");
    V c = a + b; c->label = "c";
    V d = c + 5; d->label = "d";
    V e = d * 2; e->label = "e";
    V f = e * d; f->label = "f";

    backward(f);
    draw_dot(f);

    for (auto i : c->prev) cout << i << endl;
    cout << d << endl;
    cout << e << endl;
    cout << f << endl; 

    return 0;
}