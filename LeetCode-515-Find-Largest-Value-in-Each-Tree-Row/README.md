# LeetCode 515 - Find Largest Value in Each Tree Row

## Problem Statement

Given the `root` of a binary tree, return *an array of the largest value in each row of the tree (0-indexed)*.

**LeetCode Link:** https://leetcode.com/problems/find-largest-value-in-each-tree-row/

---

## Examples

**Example 1:**
```
Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]
```

**Example 2:**
```
Input: root = [1,2,3]
Output: [1,3]
```

---

## Approach — BFS Level Maximum

We perform standard BFS (level-order traversal). For each level, we keep track of the maximum value of nodes visited and add it to our result list.
1. Perform queue-based BFS.
2. Initialize `maxVal = INT_MIN` at the start of each level.
3. Traverse all nodes in the level, updates `maxVal = max(maxVal, node->val)`.
4. Store `maxVal` in the result array.

---

## Solution

```cpp
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            int maxVal = INT_MIN;
            for (int i = 0; i < sz; ++i) {
                TreeNode* node = q.front();
                q.pop();
                maxVal = max(maxVal, node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            result.push_back(maxVal);
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

- The number of nodes in the tree is in the range `[0, 10^4]`.
- `-2^31 <= Node.val <= 2^31 - 1`
