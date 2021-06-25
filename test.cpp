#include "header.h"
#include <ctime>
int main() {
    pair<int, int> p = {3, 4};
    auto [x, y] = p;
    x = 6;
    y = x;
    int* z = &x;
    ++x;
    cout << *z;
}