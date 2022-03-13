#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;
int tuopu(int num, unordered_map<int, int> pre, vector<vector<int>>& cost) {
    int cnt = 0;
    unordered_map<int, int> dis;
    int ans = 0;
    while (true) {
        int flag = 0;
        for (int i = 0; i <= num; ++i) {
            if (pre[i] == 0) {
                flag = 1;
                ++cnt;
                pre[i]--;
                for (int j = 0; j <= num; ++j) {
                    if (j == i) continue;
                    if (cost[i][j] != -1) {
                        dis[j] = max(dis[j], dis[i] + cost[i][j]);
                        ans = max(ans, dis[j]);
                        pre[j]--;
                    }
                }
            }
        }
        if (flag == 0) break;
    }
    if (cnt == num + 1) {
        return ans;
    }
    return -1;
}
int main() {
    int T;
    cin >> T;
    int task;
    while (cin >> task) {
        vector<vector<int>> cost(task + 1, vector<int>(task + 1, -1));
        unordered_map<int, int> pre;
        pre[0] = 0;
        for (int i = 1; i <= task; ++i) {
            int c, preNum;
            cin >> c >> preNum;
            if (preNum != 0) {
                pre[i] = preNum;
                for (int j = 0; j < preNum; ++j) {
                    int pre;
                    cin >> pre;
                    cost[pre][i] = c;
                }
            } else {
                pre[i] = 1;
                cost[0][i] = c;
            }
        }
        cout << tuopu(task, pre, cost) << endl;
    }
    return 0;
}