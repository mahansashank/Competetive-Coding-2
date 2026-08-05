# LeetCode 637 - Average of Levels in Binary Tree

## Problem Statement

Given the `root` of a binary tree, return *the average value of the nodes on each level in the form of an array*. Answers within `10^-5` of the actual answer will be accepted.

**LeetCode Link:** https://leetcode.com/problems/average-of-levels-in-binary-tree/

---

## Examples

**Example 1:**
```
Input: root = [3,9,20,null,null,15,7]
Output: [3.00000,14.50000,11.00000]
Explanation: The average value of nodes on level 0 is 3, on level 1 is (9 + 20) / 2 = 14.5, and on level 2 is (15 + 7) / 2 = 11.
```

**Example 2:**
```
Input: root = [3,9,20,15,7]
Output: [3.00000,14.50000,11.00000]
```

---

## Approach — BFS Level Average

We perform BFS to traverse the tree level by level:
1. Standard queue BFS.
2. For each level, track the running sum of all nodes in that level.
3. Compute the average as `sum / sz` (where `sz` is the count of nodes in the level).
4. Add the average to the result array.

---

## Solution

```cpp
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if (!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            double sum = 0;
            for (int i = 0; i < sz; ++i) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            result.push_back(sum / sz);
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
| **Space** | `O(N)` — Queue size |

---

## Constraints

- The number of nodes in the tree is in the range `[1, 10^4]`.
- `-2^31 <= Node.val <= 2^31 - 1`
