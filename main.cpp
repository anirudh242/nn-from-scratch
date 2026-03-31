#include <iostream>
#include "Value.hpp"
using namespace std;

int main() {
    V a = val(2.0);
    V b = val(3.0);
    V c = a + b;
    V d = c + 5;

    for (auto i : c->prev) cout << i << endl;
    cout << d << endl;

    return 0;
}