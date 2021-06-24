#include "header.h"

//穷举
class Solution1 {
private:
    unordered_set<string> owed;
    void backtrack(string temp, string s, vector<string>& ans, vector<bool>& visited) {
        if (temp.size() == s.size()) {
            if (owed.count(temp)) return;
            ans.push_back(temp);
            owed.insert(temp);
            return;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (!visited[i]) {
                visited[i] = true;
                backtrack(temp + s[i], s, ans, visited);
                visited[i] = false;
            }
        }
    }
public:
    vector<string> permutation(string s) {
        int n = s.size();
        vector<bool> visited(n, false);
        vector<string> ans;
        backtrack("", s, ans, visited);
        return ans;
    }
};

//穷举过程中去重

class Solution {
private:
    void backtrack(string temp, string s, vector<string>& ans, vector<bool>& visited) {
        if (temp.size() == s.size()) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (i > 0 && s[i - 1] == s[i] && !visited[i - 1]) continue;
            if (!visited[i]) {
                visited[i] = true;
                backtrack(temp + s[i], s, ans, visited);
                visited[i] = false;
            }
        }
    }
public:
    vector<string> permutation(string s) {
        int n = s.size();
        sort(s.begin(), s.end());
        vector<bool> visited(n, false);
        vector<string> ans;
        backtrack("", s, ans, visited);
        return ans;
    }
};