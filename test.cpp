#include "header.h"
//二叉树的垂序遍历


int main() {
    vector<int> arr{1,2,3};
    int x = upper_bound(arr.begin(), arr.end(), 2) - arr.begin();
    cout << x;
}