#include "header.h"

class Solution {
private:
    vector<vector<int>> arrs;
    void backtrack (vector<int>& arr, vector<bool>& visited, int n) {
        if (arr.size() == n) {
            arrs.push_back(arr);
        }
        for (int i = 1; i <= n; ++i) {
            if (visited[i]) continue;
            arr.push_back(i);
            visited[i] = true;
            backtrack(arr, visited, n);
            arr.pop_back();
            visited[i] = false;
        }
    }
    int comupteMod(int n) {
        if (n == 0) return 1;
        int ans = n;
        while(n) {
            if (n == 1) break;
            ans *= --n;
        }
        return ans;
    }
public:
    string getPermutation(int n, int k) {
        vector<bool> visited(n + 1, false);
        vector<int> arr;
        int mod = comupteMod(n - 1);
        int first = (k - 1) / mod + 1;
        arr.push_back(first);
        visited[first] = true;
        backtrack(arr, visited, n);
        string ans;
        for (auto num : arrs[k - 1 - (first - 1) * mod]) {
            ans += to_string(num);
        }
        return ans;
    }
};