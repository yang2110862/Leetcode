#include "header.h"

class Solution {
private:
    unordered_set<char> vowel{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
public:
    string reverseVowels(string s) {
        vector<int> vowels;
        for (auto c : s) {
            if (vowel.count(c)) vowels.push_back(c);
        }
        int num = vowels.size();
        for (auto& c : s) {
            if (vowel.count(c)) c = vowels[--num];
        }
        return s;
    }
};