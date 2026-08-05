# LeetCode 103 - Binary Tree Zigzag Level Order Traversal

## Problem Statement

Given the `root` of a binary tree, return *the zigzag level order traversal of its nodes' values*. (i.e., from left to right, then right to left for the next level and alternate between).

**LeetCode Link:** https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

---

## Examples

**Example 1:**
```
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
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

## Approach — BFS with Alternating Direction

We can traverse the tree using a queue (level order traversal) and use a boolean flag `leftToRight` to alternate the ordering direction for each level:
1. Initialize a queue with the root.
2. Maintain `leftToRight` as `true`.
3. For each level, allocate an array/vector of the level's size.
4. Pop each node:
   - If `leftToRight` is true, fill the vector from index `0` to `sz-1`.
   - If `leftToRight` is false, fill the vector from index `sz-1` to `0`.
5. Push children of popped nodes to the queue.
6. Toggle `leftToRight` after finishing the level.

---

## Solution

```cpp
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        while (!q.empty()) {
            int sz = q.size();
            vector<int> level(sz);
            for (int i = 0; i < sz; ++i) {
                TreeNode* node = q.front();
                q.pop();
                int idx = leftToRight ? i : (sz - 1 - i);
                level[idx] = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            result.push_back(level);
            leftToRight = !leftToRight;
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
| **Space** | `O(N)` — Queue size and vector for levels |

---

## Constraints

- The number of nodes in the tree is in the range `[0, 2000]`.
- `-100 <= Node.val <= 100`
