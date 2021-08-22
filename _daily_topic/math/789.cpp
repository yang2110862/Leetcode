#include "header.h"

//逃脱阻碍者

class Solution {
private:
    int manhattandistance(vector<int>& a, vector<int>& b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        vector<int> beg{0, 0};
        int comp = manhattandistance(beg, target);
        for (auto& ghost : ghosts) {
            int temp = manhattandistance(ghost, target);
            if (temp <= comp) return false;
        }
        return true;
    }
};