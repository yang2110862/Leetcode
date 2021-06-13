#include "header.h"

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    };
};
//回溯
class Solution1 {
private:
    unordered_map<Node*, Node*> mp;
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        if (mp.find(head) != mp.end()) {
            return mp[head];
        }
        Node* node = new Node(head->val);
        mp[head] = node;
        node->next = copyRandomList(head->next);
        node->random = copyRandomList(head->random);
        return node;
    }
};
//迭代
class Solution {
private:
    unordered_map<Node*, Node*> mp;
    Node* getCloneNode(Node* node) {
        if (!node) return nullptr;
        if (mp.find(node) != mp.end()) return mp[node];
        Node* newNode = new Node(node->val);
        mp[node] = newNode;
        return newNode;
    }
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node* oldNode = head;
        Node* newNode = new Node(oldNode->val);
        mp[oldNode] = newNode;
        while (oldNode) {
            newNode->next = getCloneNode(oldNode->next);
            newNode->random = getCloneNode(oldNode->random);
            oldNode = oldNode->next;
            newNode = newNode->next;
        }
        return mp[head];
    }
};

//O（1）空间的迭代 在新链表旁边插入旧链表
