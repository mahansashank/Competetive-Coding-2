# LeetCode 328 - Odd Even Linked List

## Problem Statement

Given the head of a singly linked list, group all the nodes with **odd indices** together followed by the nodes with **even indices**, and return the reordered list.

- The **first node** is considered odd, the **second node** even, and so on.
- The relative order inside both the even and odd groups must remain as it was in the input.

**LeetCode Link:** https://leetcode.com/problems/odd-even-linked-list/

---

## Examples

**Example 1:**
```
Input:  head = [1, 2, 3, 4, 5]
Output: [1, 3, 5, 2, 4]
```

**Example 2:**
```
Input:  head = [2, 1, 3, 5, 6, 4, 7]
Output: [2, 3, 6, 7, 1, 5, 4]
```

---

## Approach — Two-Pointer Regrouping

We maintain **two separate chains** as we do a single pass:

- `odd`  → tracks the tail of the odd-indexed sub-list.
- `even` → tracks the tail of the even-indexed sub-list.
- `evenHead` → saves the head of the even chain so we can splice it at the end.

At every iteration we re-link:
```
odd.next  = even.next   (skip over the current even node)
even.next = odd.next    (skip over the newly linked odd node)
```
After the loop, we attach `evenHead` to `odd.next`.

### Steps:
1. Return early if `head` is `null` or has only one node.
2. Initialise `odd = head`, `even = head->next`, `evenHead = even`.
3. While `even` and `even->next` exist:
   - `odd->next = even->next` → advance odd chain.
   - `odd = odd->next`
   - `even->next = odd->next` → advance even chain.
   - `even = even->next`
4. Set `odd->next = evenHead` to join the two chains.
5. Return `head`.

---

## Solution

```cpp
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* odd     = head;
        ListNode* even    = head->next;
        ListNode* evenHead = even;

        while (even && even->next) {
            odd->next  = even->next;
            odd        = odd->next;

            even->next = odd->next;
            even       = even->next;
        }

        odd->next = evenHead;
        return head;
    }
};
```

---

## Complexity Analysis

| | Complexity |
|---|---|
| **Time** | `O(n)` — Single pass through the list |
| **Space** | `O(1)` — Only a constant number of pointers used |

---

## Constraints

- The number of nodes in the linked list is in the range `[0, 10^4]`.
- `-10^6 <= Node.val <= 10^6`
