#include "header.h"
#include <ctime>
int main() {
    auto cmp1 = [](int a,int b) {
        return a < b;
    };
    priority_queue<int, vector<int>, decltype(cmp1)> q(cmp1);
    q.push(1);
    q.push(3);
    q.pop();
    cout << q.top();
}