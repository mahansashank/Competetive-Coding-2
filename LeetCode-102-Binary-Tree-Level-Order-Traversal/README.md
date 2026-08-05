# LeetCode 102 - Binary Tree Level Order Traversal

## Problem Statement

Given the `root` of a binary tree, return *the level order traversal of its nodes' values*. (i.e., from left to right, level by level).

**LeetCode Link:** https://leetcode.com/problems/binary-tree-level-order-traversal/

---

## Examples

**Example 1:**
```
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
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

## Approach — Breadth-First Search (BFS)

We use a queue to traverse the tree level by level:
1. Initialize a queue and push the root node.
2. While the queue is not empty, get the size of the queue (which represents the number of nodes at the current level).
3. Pop each node of the current level, record its value, and push its children (left and right) to the queue if they exist.
4. Add the current level list to the result.

---

## Solution

```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
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
        return result;
    }
};
```

---

## Complexity Analysis

| | Complexity |
|---|---|
| **Time** | `O(N)` — Every node is visited exactly once |
| **Space** | `O(N)` — Maximum size of the queue (at most the width of the tree) |

---

## Constraints

- The number of nodes in the tree is in the range `[0, 2000]`.
- `-1000 <= Node.val <= 1000`
