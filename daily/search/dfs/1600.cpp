#include "header.h"

class ThroneInheritance {
private:
    unordered_map<string, vector<string>> edges;
    unordered_set<string> dead;
    string king;
    void preorder(string& name, vector<string>& ans) {
        if (!dead.count(name)) ans.push_back(name);
        if (edges.count(name)) {
            for (auto& childName : edges[name]) preorder(childName, ans);
        }
    }
public:
    ThroneInheritance(string kingName) : king(kingName){}
    
    void birth(string parentName, string childName) {
        edges[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        preorder(king, ans);
        return ans;
    }
};