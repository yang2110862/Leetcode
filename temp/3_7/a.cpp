#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    int calDPDScore(string dpdInfo) {
        int ans = 0;
        int continuous = 0;
        int n = dpdInfo.size();
        for (int i = 0; i < n; ++i) {
            if (dpdInfo[i] == 'N') {
                if (continuous == 0) continue;
                else {
                    if (continuous > 0 && continuous <= 3) {
                        ans = min(-10, ans);
                    } else if (continuous <= 7) {
                        ans = min(-15, ans);
                    } else {
                        ans = min(-25, ans);
                    }
                }
                continuous = 0;
            } else {
                continuous++;
            }
        }
        if (continuous == 0) return ans;
        else {
            if (continuous > 0 && continuous <= 3) {
                ans = min(-10, ans);
            } else if (continuous <= 7) {
                ans = min(-15, ans);
            } else {
                ans = min(-25, ans);
            }
        }
        return ans;
    }
};
