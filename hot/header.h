#ifndef HEADER_FILE_H
#define HEADER_FILE_H

#include <iostream>
#include <map>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <cfloat>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <sstream>
using namespace std;

struct ListNode {    
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#endif