#include <ostream>
#include <vector>
#include <memory>

class Value;
using V = std::shared_ptr<Value>;

class Value {
    public:
        double data;
        std::vector<V> prev;
        
        Value(double data);
        friend std::ostream& operator<<(std::ostream& os, const V& v);
};

inline V val(double x) {
    return std::make_shared<Value>(x);
}

V operator+(V a, V b);
V operator+(V a, double b);
V operator+(double a, V b);
