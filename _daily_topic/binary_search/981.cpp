#include "header.h"
//基于时间的键值存储  二分 + hash 找第一个大于value再取左边的值
class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> mp;
public:
    /** Initialize your data structure here. */
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back(make_pair(value, timestamp));
    }
    
    string get(string key, int timestamp) {
        int time = 0;
        string ans;
        auto& vec = mp[key];
        int n = vec.size();
        if (n == 0) return "";
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (vec[mid].second <= timestamp) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (left == 0) return "";
        ans = vec[left - 1].first;
        return ans;
    }
};
