#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        bool seenNull = false;
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (!curr) {
                seenNull = true;
            } else {
                if (seenNull) return false;
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return true;
    }
};

TreeNode* buildTree(const vector<string>& vals) {
    if (vals.empty() || vals[0] == "null") return nullptr;
    TreeNode* root = new TreeNode(stoi(vals[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < vals.size()) {
        TreeNode* curr = q.front();
        q.pop();
        if (i < vals.size() && vals[i] != "null") {
            curr->left = new TreeNode(stoi(vals[i]));
            q.push(curr->left);
        }
        i++;
        if (i < vals.size() && vals[i] != "null") {
            curr->right = new TreeNode(stoi(vals[i]));
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

int main() {
    Solution sol;
    TreeNode* root1 = buildTree({"1", "2", "3", "4", "5", "6"});
    bool res1 = sol.isCompleteTree(root1);
    cout << "Example 1:\n";
    cout << (res1 ? "true" : "false") << "\n";
    return 0;
}
