#include "header.h"

int main() {
    vector<int> arr{1,2,3,4,5};
    cout << lower_bound(arr.begin(), arr.end(), 3) - arr.begin();
}