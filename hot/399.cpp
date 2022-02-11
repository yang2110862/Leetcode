#include "header.h"
//除法求值


//union find
class UnionFind {
private:
    vector<int> parent;
    vector<double> value;
public:
    UnionFind(int n) {
        parent.resize(n);
        value.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            value[i] = 1;
        }
    }
    int Find(int child) {
        if (parent[child] != child) {
            int origin = parent[child];
            parent[child] = Find(parent[child]);
            value[child] *= value[origin];
        }
        return parent[child];
    }
    void Union(int a, int b, double v) {
        int x = Find(a);
        int y = Find(b);
        if (x == y) return;
        else {
            parent[x] = y;
            value[x] = value[b] * v / value[a];
        }
    }
    double isConnected(int a, int b) {
        int x = Find(a);
        int y = Find(b);
        if (x != y) return -1;
        else {
            return value[a] / value[b];
        }
    }
};
class Solution {
private:
    unordered_map<string, int> mp;
public:
    vector<double> calcEquation(vector<vector<string>>& equations, 
        vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        UnionFind unionFind(2 * n);
        int index = 0;
        for (int i = 0; i < n; ++i) {
            if (!mp.count(equations[i][0])) mp[equations[i][0]] = index++;
            if (!mp.count(equations[i][1])) mp[equations[i][1]] = index++;
            unionFind.Union(mp[equations[i][0]], mp[equations[i][1]], values[i]);
        }
        vector<double> ans;
        for (const auto& query : queries) {
            if (!mp.count(query[0]) || !mp.count(query[1])) {
                ans.push_back(-1);
                continue;
            }
            int a = mp[query[0]];
            int b = mp[query[1]];
            ans.push_back(unionFind.isConnected(a, b));
        }
        return ans;
    }
};


//bug skip
class Solution1 {
    struct pairhash {
        template <typename T, typename U>
        std::size_t operator()(const std::pair<T, U> &x) const
        {
            return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
        }
    };
private:
    unordered_map<pair<string, string>, double, pairhash> equ;
    unordered_map<pair<string, string>, bool, pairhash> visited;
    double backtrace(string numerator, string denominator) {
        double ans = 1;
        for (const auto& e : equ) {
            if (visited[make_pair(e.first.first, e.first.second)]) continue;
            if (e.first.first == numerator && e.first.second == denominator) {
                return e.second;
            } else if (e.first.first == numerator) {
                double next = backtrace(e.first.second, denominator);
                visited[make_pair(e.first.first, e.first.second)] = true;
                if (next == -1) return -1;
                else return e.second * next;
            } else {
                continue;
            }
        }
        return -1;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, 
        vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        for (int i = 0; i < n; ++i) {
            equ[make_pair(equations[i][0], equations[i][1])] = values[i];
            equ[make_pair(equations[i][1], equations[i][0])] = 1.0 / values[i];
        }
        int num = queries.size();
        vector<double> ans;
        for (int i = 0; i < num; ++i) {
            visited.clear();
            double res = backtrace(queries[i][0], queries[i][1]);
            ans.push_back(res);
        }
        return ans;
    }
};