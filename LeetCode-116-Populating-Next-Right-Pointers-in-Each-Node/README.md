# LeetCode 116 - Populating Next Right Pointers in Each Node

## Problem Statement

You are given a **perfect binary tree** where all leaves are on the same level, and every parent has two children. Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to `NULL`.

Initially, all next pointers are set to `NULL`.

**LeetCode Link:** https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

---

## Examples

**Example 1:**
```
Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
```

**Example 2:**
```
Input: root = []
Output: []
```

---

## Approach — Level-by-Level Connections

Since the tree is a perfect binary tree, we can establish links for level `L + 1` while iterating through level `L` using the already populated next pointers:
1. Start at the leftmost node of a level.
2. For each node `temp` at the current level:
   - Connect its left child to its right child: `temp->left->next = temp->right`.
   - If `temp->next` exists, connect its right child to `temp->next->left`: `temp->right->next = temp->next->left`.
3. Move `temp` to `temp->next`.
4. Once a level is finished, move to the leftmost node of the next level (`curr = curr->left`).

---

## Solution

```cpp
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        Node* curr = root;
        while (curr->left) {
            Node* temp = curr;
            while (temp) {
                temp->left->next = temp->right;
                if (temp->next) {
                    temp->right->next = temp->next->left;
                }
                temp = temp->next;
            }
            curr = curr->left;
        }
        return root;
    }
};
```

---

## Complexity Analysis

| | Complexity |
|---|---|
| **Time** | `O(N)` — Every node is visited once |
| **Space** | `O(1)` — Only a constant number of pointers used |

---

## Constraints

- The number of nodes in the tree is in the range `[0, 2^12 - 1]`.
- `-1000 <= Node.val <= 1000`
