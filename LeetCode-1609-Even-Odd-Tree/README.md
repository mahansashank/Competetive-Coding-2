# LeetCode 1609 - Even Odd Tree

## Problem Statement

A binary tree is named **Even-Odd** if it meets the following conditions:
- The root of the binary tree is at level index `0`, its children are at level index `1`, their children are at level index `2`, etc.
- For every **even-indexed** level, all nodes at the level have **odd** integer values in **strictly increasing** order (from left to right).
- For every **odd-indexed** level, all nodes at the level have **even** integer values in **strictly decreasing** order (from left to right).

Given the root of a binary tree, return `true` if the binary tree is **Even-Odd**, otherwise return `false`.

**LeetCode Link:** https://leetcode.com/problems/even-odd-tree/

---

## Examples

**Example 1:**
```
Input: root = [1,10,4,3,null,7,9,12,8,6,null,null,2]
Output: true
Explanation: The node values on each level are:
- Level 0: [1] (odd integers, strictly increasing)
- Level 1: [10,4] (even integers, strictly decreasing)
- Level 2: [3,7,9] (odd integers, strictly increasing)
- Level 3: [12,8,6,2] (even integers, strictly decreasing)
Since all levels satisfy the conditions, the tree is Even-Odd.
```

**Example 2:**
```
Input: root = [5,4,2,3,3,7]
Output: false
Explanation: The node values on each level are:
- Level 0: [5]
- Level 1: [4,2]
- Level 2: [3,3,7] (node values 3 and 3 are not strictly increasing)
```

**Example 3:**
```
Input: root = [5,9,1,3,5,7]
Output: false
Explanation: Node values on Level 1 are [9,1] (strictly decreasing, but 9 and 1 are odd, which violates the requirement for even integers on odd levels).
```

---

## Approach — Level-by-Level Validation

We perform standard BFS (level-order traversal) and track the current level's index (`levelIdx`).
For each node in the level:
- If `levelIdx` is even (0, 2, 4, ...):
  - Values must be **odd**.
  - Values must be **strictly increasing**. We use a `prevVal` initialized to `INT_MIN`.
- If `levelIdx` is odd (1, 3, 5, ...):
  - Values must be **even**.
  - Values must be **strictly decreasing**. We use a `prevVal` initialized to `INT_MAX`.

If any condition is violated, we immediately return `false`. Otherwise, if BFS completes, return `true`.

---

## Solution

```cpp
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
```

---

## Complexity Analysis

| | Complexity |
|---|---|
| **Time** | `O(N)` — Every node is visited once |
| **Space** | `O(N)` — Queue size |

---

## Constraints

- The number of nodes in the tree is in the range `[1, 10^5]`.
- `1 <= Node.val <= 10^6`
