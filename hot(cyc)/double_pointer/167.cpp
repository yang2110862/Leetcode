#include "header.h"
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int num = numbers.size();
        int i = 0, j = num - 1;
        while(i < j) {
            int sum = numbers[i] + numbers[j];
            if(sum == target) {
                return {i + 1, j + 1};
            } else if (sum > target) {
                j--;
            } else {
                i++;
            }
        }
        return {-1, -1};
    }
};