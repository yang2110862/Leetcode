#include "header.h"

//任务调度器

class Solution {
private:
    unordered_map<char, int> cnt;
public:
    int leastInterval(vector<char>& tasks, int n) {
        for (auto task : tasks) {
            ++cnt[task];
        }
        int maxExec = max_element(cnt.begin(), cnt.end(), [](const auto& u, const auto& v) {
            return u.second < v.second;
        })->second;
        int maxCount = accumulate(cnt.begin(), cnt.end(), 0, [=](int acc, const auto& u) {
            return acc + (u.second == maxExec);
        });
        return max((maxExec - 1) * (n + 1) + maxCount, static_cast<int>(tasks.size()));
    }
};