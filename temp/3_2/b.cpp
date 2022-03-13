#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;
int minMinus;
void dfs(int beg, bool flag, int sum, int target, vector<vector<bool>>& visited,
    vector<vector<int>>& dis) {
    if (sum >= minMinus) return;
    if (beg == target) {
        minMinus = min(sum, minMinus);
        return;
    }
    for (int i = 1; i <= target; ++i) {
        if (i == beg) continue;
        if (visited[beg][i] || visited[i][beg]) continue;
        if (dis[beg][i] == 2) {
            visited[beg][i] = visited[i][beg] = true;
            if (flag == 1) {
                dfs(i, 1, sum + 1, target, visited, dis);
            } else {
                dfs(i, 1, sum, target, visited, dis);
            }
            visited[beg][i] = visited[i][beg] = false;
        } else if (dis[beg][i] == 1) {
            visited[beg][i] = visited[i][beg] = true;
            dfs(i, 0, sum + 1, target, visited, dis);
            visited[beg][i] = visited[i][beg] = false;
        }
        
    }
}
int main() {
    int T;
    cin >> T;
    int N, M1, M2;
    while (cin >> N >> M1 >> M2) {
        minMinus = INT_MAX;
        vector<vector<int>> dis(N + 1, vector<int>(N + 1, 0)); //0表示不可行，1表示有道路，2表示有传送门
        vector<vector<bool>> visited(N + 1, vector<bool>(N + 1, false));
        for (int i = 0; i < M1; ++i) {
            int x, y;
            cin >> x >> y;
            dis[x][y] = dis[y][x] = 1;
        }
        for (int i = 0; i < M2; ++i) {
            int x, y;
            cin >> x >> y;
            dis[x][y] = dis[y][x] = 2;
        }
        dfs(1, 0, 0, N, visited, dis);
        cout << minMinus << endl;
    }
    return 0;
}