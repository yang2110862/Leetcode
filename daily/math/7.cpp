#include "header.h"
#include "climits"
//数学推导第19行很重要。
class Solution {
private:
    int removeZero(int x) {
        while (x % 10 == 0) {
            x /= 10;
        }
        return x;
    }
public:
    int reverse(int x) {
        if (x == 0) return 0;
        int sum = 0;
        x = removeZero(x);
        while (x) {
            int num = x % 10;
            if (sum > INT_MAX / 10 || sum < INT_MIN / 10) return 0;
            sum = sum * 10 + num;
            x /= 10;
        }
        return sum;
    }
};

int main() {
    Solution test;
    int x = 1534236469;
    cout << test.reverse(x);
}