#include "header.h"

class Solution {
private:
    unordered_map<string, int> mp;
public:
    string countOfAtoms(string formula) {
        int n = formula.size();
        vector<string> atom;
        int coe = 1;
        for (int i = 0; i < n; ++i) {
            if (formula[i] == '(') {
                for (int j = i + 1; j < n; ++j) {
                    if (formula[j] == ')') coe = formula[j + 1];
                }
            }
            if (formula[i] == ')') coe = 1;
            if (formula[i] >= 'A' && formula[i] <= 'Z') {
                string temp;
                string mul;
                temp += formula[i];
                while (++i) {
                    if (i >= n) break;
                    if (formula[i] >= 'a' && formula[i] <= 'z') temp += formula[i];
                    else {
                        if (formula[i] < '0' || formula[i] > '9') {
                            mul = 1;
                            mp[temp] = stoi(mul) * coe;
                            atom.push_back(temp);
                            break;
                        }
                        mul += formula[i];
                        while (++i) {
                            if (formula[i] >= '0' && formula[i] <= '9') mul += formula[i];
                            else {
                                --i;
                                break;
                            }
                        }
                        mp[temp] = stoi(mul) * coe;
                        atom.push_back(temp);
                        break;
                    }
                }
            }
        }
        sort(atom.begin(), atom.end());
        string ans;
        for (auto x : atom) {
            ans += x;
            ans += to_string(mp[x]);
        }
        return ans;
    }
};

int main() {
    string formula = "H2O";
    Solution test;
    auto x = test.countOfAtoms(formula);
}