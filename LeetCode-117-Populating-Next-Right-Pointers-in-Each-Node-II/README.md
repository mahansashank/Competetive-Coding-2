# LeetCode 117 - Populating Next Right Pointers in Each Node II

## Problem Statement

Given a binary tree (not necessarily perfect). Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to `NULL`.

Initially, all next pointers are set to `NULL`.

**LeetCode Link:** https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

---

## Examples

**Example 1:**
```
Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
```

**Example 2:**
```
Input: root = []
Output: []
```

---

## Approach — Dummy Node Level Traversal

Since the tree is not a perfect binary tree, we can use a dummy node to act as the head of the next level's list as we traverse the current level:
1. For the current level, initialize a `dummy` node. Let `tail = &dummy`.
2. As we traverse the nodes of the current level using their `next` pointers:
   - If a node has a left child, connect `tail->next = node->left` and advance `tail`.
   - If a node has a right child, connect `tail->next = node->right` and advance `tail`.
3. After completing the current level, move to the next level's head: `curr = dummy.next`.
4. Repeat until all levels are connected.

---

## Solution

```cpp
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        Node* curr = root;
        while (curr) {
            Node dummy(0);
            Node* tail = &dummy;
            while (curr) {
                if (curr->left) {
                    tail->next = curr->left;
                    tail = tail->next;
                }
                if (curr->right) {
                    tail->next = curr->right;
                    tail = tail->next;
                }
                curr = curr->next;
            }
            curr = dummy.next;
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
| **Space** | `O(1)` — Only constant extra space is used |

---

## Constraints

- The number of nodes in the tree is in the range `[0, 6000]`.
- `-100 <= Node.val <= 100`
