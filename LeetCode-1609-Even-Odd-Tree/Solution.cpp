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
    bool isEvenOddTree(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        int levelIdx = 0;
        while (!q.empty()) {
            int sz = q.size();
            int prevVal = levelIdx % 2 == 0 ? INT_MIN : INT_MAX;
            for (int i = 0; i < sz; ++i) {
                TreeNode* node = q.front();
                q.pop();
                int val = node->val;
                if (levelIdx % 2 == 0) {
                    if (val % 2 == 0 || val <= prevVal) return false;
                } else {
                    if (val % 2 != 0 || val >= prevVal) return false;
                }
                prevVal = val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            levelIdx++;
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
    TreeNode* root1 = buildTree({"1", "10", "4", "3", "null", "7", "9", "12", "8", "6", "null", "null", "2"});
    bool res1 = sol.isEvenOddTree(root1);
    cout << "Example 1:\n";
    cout << (res1 ? "true" : "false") << "\n";
    return 0;
}
