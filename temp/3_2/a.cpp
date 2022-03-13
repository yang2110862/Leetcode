#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<int, int> xishu{{0, 7}, {1, 9}, {2, 10}, {3, 5}, {4, 8}, {5, 4},
{6,2}, {7, 1}, {8, 6}, {9, 3}, {10,7}, {11, 9}, {12, 10}, {13, 5}, {14, 8}, {15, 4}, {16, 2}};
unordered_map<int, int> yushu{{1, 0}, {0, 1}, {9, 3}, {8, 4}, {7, 5}, {6, 6}, {5, 7},
{4, 8}, {3, 9}, {2, 10}};
int cnt;
void backtrace(string& card, int index, int ans) {
    if (index == 17) {
        int res = ans % 11;
        int target;
        if (card[index] == 'X') {
            target = 2;
        } else {
            target = yushu[card[index] - '0'];
        }
        if (res == target) {
            cnt++;
        }
        return;
    }
    if (card[index] == '*') {
        for (int i = 0; i < 10; ++i) {
            ans += i * xishu[index];
            backtrace(card, index + 1, ans);
            ans -= i * xishu[index];
        }
    } else {
        ans += (card[index] - '0') * xishu[index];
        backtrace(card, index + 1, ans);
    }
}
int main() {
    int T = 1;
    // cin >> T;
    string card = "34088119480815*663";
    backtrace(card, 0, 0);
    cout << cnt << endl;
    // while (cin >> card) {
    //     backtrace(card, 0, 0);
    //     cout << cnt << endl;
    //     cnt = 0;
    // }
    return 0;
}