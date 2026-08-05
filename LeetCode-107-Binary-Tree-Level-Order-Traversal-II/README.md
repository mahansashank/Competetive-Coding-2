# LeetCode 107 - Binary Tree Level Order Traversal II

## Problem Statement

Given the `root` of a binary tree, return *the bottom-up level order traversal of its nodes' values*. (i.e., from left to right, level by level from leaf to root).

**LeetCode Link:** https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

---

## Examples

**Example 1:**
```
Input: root = [3,9,20,null,null,15,7]
Output: [[15,7],[9,20],[3]]
```

**Example 2:**
```
Input: root = [1]
Output: [[1]]
```

**Example 3:**
```
Input: root = []
Output: []
```

---

## Approach — BFS with Reversal

We can perform a standard level order traversal using a queue to collect level values from top to bottom, and then reverse the final results array:
1. Conduct standard BFS.
2. Store each level's nodes in a list.
3. Once BFS is finished, reverse the order of levels in the list.

---

## Solution

```cpp
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int> level;
            for (int i = 0; i < sz; ++i) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            result.push_back(level);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
```

---

## Complexity Analysis

| | Complexity |
|---|---|
| **Time** | `O(N)` — Every node is visited once; reversing the 2D array takes time proportional to height/nodes. |
| **Space** | `O(N)` — Queue size plus output space |

---

## Constraints

- The number of nodes in the tree is in the range `[0, 2000]`.
- `-1000 <= Node.val <= 1000`
