#include "header.h"
#include <cstring>
//二叉树的垂序遍历

class P {
public:
    virtual void f(int i) {
        cout << i;
    }
};
class Q : public P {
public:
    virtual void f(int i) {
        cout << (2 * i);
    }
};
int main() {
    P* X = new P();
    Q* Y = new Q();
    P* Z = new Q();
    ((Q*)X)->f(1);
    ((P*)Y)->f(1);
    Z->f(1);
}