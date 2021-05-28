#include "header.h"

class Solution1 {  //枚举
public:
    int countPrimes(int n) {
        int res = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime(i)) ++res;
        }
        return res;
    }
private:
    bool isPrime(int x) {
        for (int i = 2; i * i <= x; ++i) {
            if (x % i == 0) return false;
        }
        return true;
    }
};

class Solution {
public:
    int countPrimes(int n) {
        vector<int> isPrime(n, 1);
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                ++ans;
                if ((long long)i * i < n) {         //注意先转换为long long再×，不要先×再long long
                    for (int j = i * i; j < n; j += i) { 
                        isPrime[j] = 0;
                    }
                } 
            }
        }
        return ans;
    }
};