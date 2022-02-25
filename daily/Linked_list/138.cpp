#include "header.h"
// 复制带随机指针的链表
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution1 {
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

class Solution {
private:
    unordered_map<Node*, Node*> mp;
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        if (mp.count(head)) return mp[head];
        Node* newHead = new Node(head->val);
        mp[head] = newHead;
        newHead->next = copyRandomList(head->next);
        newHead->random = copyRandomList(head->random);
        return newHead;
    }
};