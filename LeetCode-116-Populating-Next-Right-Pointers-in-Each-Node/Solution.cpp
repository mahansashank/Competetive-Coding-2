#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        Node* curr = root;
        while (curr->left) {
            Node* temp = curr;
            while (temp) {
                temp->left->next = temp->right;
                if (temp->next) {
                    temp->right->next = temp->next->left;
                }
                temp = temp->next;
            }
            curr = curr->left;
        }
        return root;
    }
};

Node* buildTree(const vector<string>& vals) {
    if (vals.empty() || vals[0] == "null") return nullptr;
    Node* root = new Node(stoi(vals[0]));
    queue<Node*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < vals.size()) {
        Node* curr = q.front();
        q.pop();
        if (i < vals.size() && vals[i] != "null") {
            curr->left = new Node(stoi(vals[i]));
            q.push(curr->left);
        }
        i++;
        if (i < vals.size() && vals[i] != "null") {
            curr->right = new Node(stoi(vals[i]));
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

void printConnected(Node* root) {
    Node* level = root;
    while (level) {
        Node* curr = level;
        cout << "[";
        while (curr) {
            cout << curr->val;
            if (curr->next) cout << "->";
            curr = curr->next;
        }
        cout << "#]\n";
        level = level->left;
    }
}

int main() {
    Solution sol;
    Node* root1 = buildTree({"1", "2", "3", "4", "5", "6", "7"});
    Node* res1 = sol.connect(root1);
    cout << "Example 1 (levels with next pointers):\n";
    printConnected(res1);
    return 0;
}
