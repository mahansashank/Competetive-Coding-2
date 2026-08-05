# LeetCode 662 - Maximum Width of Binary Tree

## Problem Statement

Given the `root` of a binary tree, return *the maximum width of the given tree*.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.

**LeetCode Link:** https://leetcode.com/problems/maximum-width-of-binary-tree/

---

## Examples

**Example 1:**
```
Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with width 4 (5,3,null,9).
```

**Example 2:**
```
Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with width 7 (6,null,null,null,null,null,7).
```

**Example 3:**
```
Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width exists in the second level with width 2 (3,2).
```

---

## Approach — Level Indexing

We assign an index to each node in the binary tree similar to the representation in a heap-based array:
- If a parent node has index `i`:
  - Its left child has index `2 * i + 1`.
  - Its right child has index `2 * i + 2`.

To prevent integer overflow on deep trees, at each level we subtract the minimum index of that level (`minIdx`) from all indices in that level. This resets the index of the leftmost node of each level to `0`.

We compute the width of each level as `lastIndex - firstIndex + 1`.

---

## Solution

```cpp
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
```

---

## Complexity Analysis

| | Complexity |
|---|---|
| **Time** | `O(N)` — Every node is visited once |
| **Space** | `O(N)` — Queue size |

---

## Constraints

- The number of nodes in the tree is in the range `[1, 3000]`.
- `-100 <= Node.val <= 100`
