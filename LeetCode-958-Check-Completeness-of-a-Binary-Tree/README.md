# LeetCode 958 - Check Completeness of a Binary Tree

## Problem Statement

Given the `root` of a binary tree, determine if it is a *complete binary tree*.

In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2^h nodes inclusive at the last level h.

**LeetCode Link:** https://leetcode.com/problems/check-completeness-of-a-binary-tree/

---

## Examples

**Example 1:**
```
Input: root = [1,2,3,4,5,6]
Output: true
Explanation: Every level before the last is full (node 1, then nodes 2 and 3), and all nodes in the last level (4, 5, 6) are as far left as possible.
```

**Example 2:**
```
Input: root = [1,2,3,4,5,null,7]
Output: false
Explanation: The node with value 7 isn't as far left as possible.
```

---

## Approach — BFS Null Node Tracking

In a complete binary tree, if we traverse the nodes level by level (using BFS) and represent null nodes in our queue, we should never see a non-null node after we have already seen a null node.
1. Perform standard BFS, pushing both non-null and null nodes onto the queue.
2. Maintain a boolean flag `seenNull` initialized to `false`.
3. Pop a node:
   - If the node is `null`, set `seenNull = true`.
   - If the node is not `null`:
     - If `seenNull` is already `true`, return `false` because we found a non-null node after a null node.
     - Otherwise, push its left and right children to the queue (even if they are null).
4. If the loop completes successfully, return `true`.

---

## Solution

```cpp
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        bool seenNull = false;
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (!curr) {
                seenNull = true;
            } else {
                if (seenNull) return false;
                q.push(curr->left);
                q.push(curr->right);
            }
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
| **Space** | `O(N)` — Queue size (includes null markers) |

---

## Constraints

- The number of nodes in the tree is in the range `[1, 100]`.
- `1 <= Node.val <= 1000`
