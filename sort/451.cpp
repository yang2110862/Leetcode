#include "header.h"
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> hashTable;
        int mostFre = 0;
        for (auto x : s) {
            mostFre = max(mostFre, ++hashTable[x]);
        }
        vector<vector<char>> buckets(mostFre + 1);
        for (auto x : hashTable) {
            buckets[x.second].push_back(x.first);
        }
        string ans;
        for (int i = mostFre; i > 0; --i) {
            for (auto x : buckets[i]) {
                int j = i + 1;
                while (--j) {
                    ans += x;
                }
            }
        }
        return ans;
    }
};