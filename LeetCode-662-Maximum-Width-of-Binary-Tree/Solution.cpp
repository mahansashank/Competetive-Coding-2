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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        unsigned long long maxWidth = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int sz = q.size();
            unsigned long long minIdx = q.front().second;
            unsigned long long first = 0, last = 0;
            for (int i = 0; i < sz; ++i) {
                auto [node, idx] = q.front();
                q.pop();
                unsigned long long currIdx = idx - minIdx;
                if (i == 0) first = currIdx;
                if (i == sz - 1) last = currIdx;
                if (node->left) q.push({node->left, currIdx * 2 + 1});
                if (node->right) q.push({node->right, currIdx * 2 + 2});
            }
            maxWidth = max(maxWidth, last - first + 1);
        }
        return maxWidth;
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
    TreeNode* root1 = buildTree({"1", "3", "2", "5", "3", "null", "9"});
    int res1 = sol.widthOfBinaryTree(root1);
    cout << "Example 1:\n";
    cout << res1 << "\n";
    return 0;
}
