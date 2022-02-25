#include "header.h"
// 846.一手顺子

// 一遍遍历hand，只遍历group里的第一个元素即可。如要把group里的每个元素都遍历，则问题会便复杂，时间复杂度会上去。
// 所以遍历group的第一个元素，剩下的元素用hash解决
class Solution {
private:
    unordered_map<int, int> cnt;
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        sort(hand.begin(), hand.end());
        for (int i = 0; i < n; ++i) {
            cnt[hand[i]]++;
        }
        for (int i = 0; i < n; ++i) {
            if (!cnt[hand[i]]) continue;
            for (int j = 0; j < groupSize; ++j) {
                int num = hand[i] + j;
                if (!cnt[num]) return false;
                else cnt[num]--;
            }
        }
        return true;
    }
};