#include <iostream>
#include <vector>
#include <string>
using namespace std;

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

int main(int argc, char* argv[]) {
    Solution test;
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = test.twoSum(numbers, target);
    for (auto x : ans) {
        cout << x << endl;
    }
    return 0;
}