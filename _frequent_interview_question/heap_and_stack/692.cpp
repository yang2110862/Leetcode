#include "header.h"

//hash + sort
class Solution1 {
private:
unordered_map<string, int> mp;
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        for (auto& word : words) ++mp[word];
        vector<string> ans;
        for (auto& word : mp) ans.emplace_back(word.first);
        sort(ans.begin(), ans.end(), [&](string& a, string& b) {
            return mp[a] == mp[b] ? a < b : mp[a] > mp[b];
        });
        ans.erase(ans.begin() + k, ans.end());
        return ans;
    }
};

//priority_queue(heap)
class Solution {
private:
    unordered_map<string, int> mp;
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        for (auto& word : words) ++mp[word];
        auto cmp = [](pair<string, int>& a, pair<string, int>& b) {
            return a.second == b.second ? a.first < b.first : a.second > b.second;
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> q(cmp);
        for (auto& word : mp) {
            q.push(word);
            if (q.size() > k) q.pop();
        }
        vector<string> ans(k);
        // while (!q.empty()) {
        //     ans.push_back(q.top().first);
        //     q.pop();
        // }
        // reverse(ans.begin(), ans.end());
        for (int i = k - 1; i >= 0; --i) {
            ans[i] = q.top().first;
            q.pop();
        }
        return ans;
    }
};