#include "header.h"

//二叉树的序列化与反序列化


class Codec {
private:
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // inorder(root);
        // return ans;
        queue<TreeNode*> q;
        if (root == nullptr) return "";
        q.push(root);
        string ans;
        ans += to_string(root->val);
        ans += ',';
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                TreeNode* temp = q.front();
                q.pop();
                if (temp->left) {
                    q.push(temp->left);
                    // ans.push_back(temp->left->val + '0');
                    ans += to_string(temp->left->val);
                    ans += ',';
                } else {
                    // ans.push_back(' ');
                    ans += "null";
                    ans += ',';
                }
                if (temp->right) {
                    q.push(temp->right);
                    // ans.push_back(temp->right->val + '0');
                    ans += to_string(temp->right->val);
                    ans += ',';
                } else {
                    ans += "null";
                    ans += ',';
                }
            }
        }
        return ans.substr(0, ans.size() - 1);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> datas;
        if (data.empty()) return nullptr;
        string str;
        for (auto c : data) {
            if (c == ',') {
                datas.push_back(str);
                str.clear();
            } else {
                str += c;
            }
        }
        if (!str.empty()) datas.push_back(str);
        queue<TreeNode*> q;
        int n = datas.size();
        TreeNode* head = new TreeNode(stoi(datas[0]));
        q.push(head);
        int index = 1;
        while (!q.empty() && index < n) {
            TreeNode* temp = q.front();
            q.pop();
            if (index < n && datas[index] != "null") {
                TreeNode* left = new TreeNode(stoi(datas[index]));
                temp->left = left;
                q.push(left);
            }
            ++index;
            if (index < n && datas[index] != "null") {
                TreeNode* right = new TreeNode(stoi(datas[index]));
                temp->right = right;
                q.push(right);
            }
            ++index;
        }
        return head;
    }
};

int main() {
    Codec test;
    TreeNode* head = new TreeNode(-1000);
    // head->left = new TreeNode(2);
    head->right = new TreeNode(-1000);
    // head->right->left = new TreeNode(4);
    string ans = test.serialize(head);
    TreeNode* p = test.deserialize(ans);
    cout << ans;
}