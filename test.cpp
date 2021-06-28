#include "header.h"
#include <ctime>
int main() {
    unordered_set<int> s{1,2,3};
    for (auto x : s) {
        cout << x;
    }
}