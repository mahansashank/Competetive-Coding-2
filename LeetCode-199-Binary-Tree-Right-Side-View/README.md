# LeetCode 199 - Binary Tree Right Side View

## Problem Statement

Given the `root` of a binary tree, imagine yourself standing on the **right side** of it, return *the values of the nodes you can see ordered from top to bottom*.

**LeetCode Link:** https://leetcode.com/problems/binary-tree-right-side-view/

---

## Examples

**Example 1:**
```
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
```

**Example 2:**
```
Input: root = [1,null,3]
Output: [1,3]
```

**Example 3:**
```
Input: root = []
Output: []
```

---

## Approach — BFS Last Node of Level

We can perform a level-order traversal. For each level, the last node processed (at index `sz - 1` in BFS iteration) is the node visible from the right side.
1. Use BFS with a queue.
2. For each level, loop from `0` to `sz - 1`.
3. If `i == sz - 1`, add the node's value to the result.
4. Push left and right children to the queue.

---

## Solution

```cpp
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (i == sz - 1) {
                    result.push_back(node->val);
                }
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return result;
    }
};
```

---

## Complexity Analysis

| | Complexity |
|---|---|
| **Time** | `O(N)` — Every node is visited once |
| **Space** | `O(D)` — Queue size where `D` is the max tree diameter/width |

---

## Constraints

- The number of nodes in the tree is in the range `[0, 100]`.
- `-100 <= Node.val <= 100`
