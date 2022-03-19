#include "header.h"

#include <fstream>
#include <algorithm>
#include <string>
int main() {
    priority_queue<int, vector<int>, less<int>> q;
    q.push(9);
    q.push(8);
    q.push(4);
    cout << q.top();
};