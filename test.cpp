#include "header.h"
//二叉树的垂序遍历

class Test {
private:
    static constexpr int RED = 1;
public:
    void hehe() {
        int red = RED;
        vector<int> arr(10, red);
        cout << arr[0];
    }
};
int main() {
    // constexpr int RED = 1;
    // vector<int> arr(10,RED);
    // cout << arr[0]
    Test test;
    test.hehe();
}