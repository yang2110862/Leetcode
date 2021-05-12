#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
//重点预防int溢出
class Solution {
public:
    bool judgeSquareSum(int c) {
        int high = sqrt(c);
        int low = 0;
        while (low <= high) {
            unsigned int sum = pow(high, 2) + pow(low, 2); //重点
            if(sum == c) {
                return true;
            } else if (sum > c) {
                high--;
            } else {
                low++;
            }
        }
        return false;
    }
};

int main(int argc, char* argv[]) {
    Solution test;
    int c = 2147482647;
    bool ans = test.judgeSquareSum(c);
    cout << ans;
    return 0;
}