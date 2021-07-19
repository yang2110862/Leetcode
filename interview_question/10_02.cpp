#include "header.h"

class Solution {
private:
    unordered_set<string> ss;
    unordered_map<string, vector<string>> mp;
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        for (auto& str : strs) {
            string temp = str;
            sort(str.begin(), str.end());
            ss.insert(str);
            mp[str].push_back(temp);
        }
        vector<vector<string>> ans;
        for (auto& s : ss) {
            vector<string> temp;
            for (auto& str : mp[s]) {
                temp.push_back(str);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};