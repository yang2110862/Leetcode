#include "header.h"

// 字母异位词分组


class Solution {
private:
    unordered_map<string, vector<string>> mp;
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        for (auto s : strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto it : mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};