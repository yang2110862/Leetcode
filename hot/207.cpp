#include "header.h"

//课程表

class Solution {
private:
    vector<vector<int>> edges;
    unordered_map<int, int> inDegree;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        for (const auto prerequisite : prerequisites) {
            edges[prerequisite[0]].push_back(prerequisite[1]);
            edges[prerequisite[1]].push_back(prerequisite[0]);
            inDegree[prerequisite[1]]++;
        }
        queue<int> topology;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) topology.push(i);
        }
        vector<int> res;
        while (!topology.empty()) {
            int len = topology.size();
            for (int i = 0; i < len; ++i) {
                int inNum = topology.front();
                topology.pop();
                res.push_back(inNum);
                for (const auto num : edges[inNum]) {
                    inDegree[num]--;
                    if (inDegree[num] == 0) topology.push(num);
                }
            }
        }
        if (res.size() == numCourses) return true;
        else return false;
    }
};