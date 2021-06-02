#include "header.h"

int main() {
    vector<int> arr;
    arr.resize(10);
    arr.emplace_back(11);
    cout << arr.size();
    return 0;
}