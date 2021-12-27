#include "header.h"
// 适龄的朋友
class Solution {
private:
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int n = ages.size();
        int len = ages[n - 1];
        vector<int> lessThan(len + 1);
        for (int i = 0; i < n; ++i) {
            for (int j = ages[i]; j <= len; ++j) {
                lessThan[j]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int lowAge = floor(0.5 * ages[i] + 7);
            int highAge = ages[i];
            if (highAge <= lowAge) continue;
            ans += (lessThan[highAge] - lessThan[lowAge] - 1);
        }
        return ans;
    }
};