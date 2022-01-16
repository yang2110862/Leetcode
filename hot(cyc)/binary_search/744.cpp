#include "header.h"

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int low = 0, high = letters.size();
        while (low < high) {
            int m = low + (high - low) / 2;
            if (letters[m] > target) {
                high = m;
            } else {
                low = m + 1;
            }
        }
        if (low == n) return letters[0];
        return letters[low];
    }
};