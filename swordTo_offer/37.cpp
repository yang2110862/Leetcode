#include "header.h"

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    // TreeNode(): val
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
private:
    void creatTree(istringstream& in, TreeNode* root) {
        string temp;
        if (in >> temp) {
            if (temp != "null") root->left = new TreeNode(stoi(temp));
            else root->left = nullptr;
        }
        if (in >> temp) {
            if (temp != "null") root->right = new TreeNode(stoi(temp));
            else root->right = nullptr;
        }
    }
public:

    string serialize(TreeNode* root) {
        string ret;
        if (root == nullptr) {
            ret += "null";
            return ret;
        }
        queue<TreeNode*> q;  //可以加入空指针的
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                auto loc = q.front();
                q.pop();
                if (loc) {
                    ret += ',';
                    ret += to_string(loc->val);
                    q.push(loc->left);  
                    q.push(loc->right);
                } else {
                    ret += ',';
                    ret += "null";
                }
            }
        }
        return ret.substr(1, ret.size() - 1);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        for (int i = 0; i < data.size(); ++i) {
            if (data[i] == ',') data[i] = ' ';
        }
        istringstream in(data);
        string s;
        in >> s;
        if (s == "null") return nullptr;

        TreeNode* root = new TreeNode(stoi(s));
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                auto loc = q.front();
                q.pop();
                creatTree(in, loc);
                if (loc->left) q.push(loc->left);
                if (loc->right) q.push(loc->right);
            }
        }
        return root;
    }
};

int main() {
    Codec test;
    string data = "1,2,3,null,null,4,5";
    auto x = test.deserialize(data);
    cout << test.serialize(x);
}
