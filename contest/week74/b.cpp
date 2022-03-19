#include "header.h"

class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        int n = text.size();
        vector<int> a(n + 2);
        vector<int> b(n + 2);
        for (int i = 1; i <= n; ++i) {
            if (text[i - 1] == pattern[0]) {
                a[i] = a[i - 1] + 1;
            } else {
                a[i] = a[i - 1];
            }
        }        
        for (int i = n; i >= 1; --i) {
            if (text[i - 1] == pattern[1]) {
                b[i] = b[i + 1] + 1;
            } else {
                b[i] = b[i + 1];
            }
        }
        long ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (text[i - 1] == pattern[0]) {
                ans += b[i + 1];
            }
            
        }
        ans += max(a[n], b[1]);
        return ans;
    }
};