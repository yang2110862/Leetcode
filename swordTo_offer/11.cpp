#include "header.h"

class Solution1 {
public:
    int minArray(vector<int>& numbers) {
        sort(numbers.begin(), numbers.end());
        return numbers[0];
    }
};

//binary
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int n = numbers.size();
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (numbers[mid] > numbers[right]) {
                left = mid + 1;
            } else if (numbers[mid] < numbers[right]){
                right = mid;    
            } else {
                right = right - 1;
            }
        }
        return numbers[left];
    }
};