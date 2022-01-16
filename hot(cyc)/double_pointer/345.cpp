#include "header.h"
class Solution {
private:
    set<char> dict = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
public:
    string reverseVowels(string s) {
        int low = 0;
        int high = s.size() - 1;
        while (low < high) {
            while (dict.find(s[low]) == dict.end() && low < high) {      //以防进入无限循环
                low++;
            }
            while (dict.find(s[high]) == dict.end() && low < high) {
                high--;
            }
            if (low < high) {
                swap(s[low], s[high]);
                low++;
                high--;
            }
        }
        return s;
    }
};