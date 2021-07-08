#include "header.h"
//点菜展示表
class Solution {
private:
    map<int, unordered_map<string, int>> mp;
    set<string> st;
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        for (auto& order : orders) {
            st.insert(order[2]);
            int table = stoi(order[1]);
            ++mp[table][order[2]];
        }
        vector<string> names;
        for (auto& x : st) {
            names.push_back(x);
        }
        vector<vector<string>> ans;
        vector<string> temp;
        temp.push_back("Table");
        for (auto& x : st) temp.push_back(x);
        ans.push_back(temp);
        for (auto& x : mp) {
            temp.clear();
            temp.push_back(to_string(x.first));
            for (auto& y : names) {
                temp.push_back(to_string(x.second[y]));
            }
            ans.push_back(temp);
        }
        return ans;
    }
};