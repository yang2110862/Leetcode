#include "header.h"

class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double, vector<double>, less<double>> q;
        double sum = 0;
        for (auto num : nums) {
            sum += num;
            q.push(1.0 * num);
        }
        double target = sum / 2;
        int cnt = 0;
        double temp = 0;
        while (true) {
            if (temp >= target) {
                return cnt;
            }
            temp += q.top() / 2;
            cnt++;
            q.push(q.top() / 2);
            q.pop();
        }
        return 0;
    }
};