/**
 * LeetCode 328 - Odd Even Linked List
 *
 * Approach: Two-pointer regrouping (O(n) time, O(1) space)
 *
 * We maintain two separate chains — one for odd-indexed nodes and one for
 * even-indexed nodes — by re-linking pointers as we traverse the list once.
 * At the end we attach the even chain to the tail of the odd chain.
 */

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // Edge case: empty list or single node
        if (!head || !head->next) return head;

        ListNode* odd  = head;           // pointer to current odd-indexed node
        ListNode* even = head->next;     // pointer to current even-indexed node
        ListNode* evenHead = even;       // save the head of the even chain

        while (even && even->next) {
            odd->next  = even->next;     // link odd node to the next odd node
            odd        = odd->next;      // advance odd pointer

            even->next = odd->next;      // link even node to the next even node
            even       = even->next;     // advance even pointer
        }

        odd->next = evenHead;            // attach even chain after odd chain
        return head;
    }
};

// ---------------------------------------------------------------------------
// Helper utilities for local testing
// ---------------------------------------------------------------------------

ListNode* buildList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* cur  = head;
    for (int i = 1; i < (int)vals.size(); ++i) {
        cur->next = new ListNode(vals[i]);
        cur = cur->next;
    }
    return head;
}

void printList(ListNode* head) {
    cout << "[";
    while (head) {
        cout << head->val;
        if (head->next) cout << ",";
        head = head->next;
    }
    cout << "]\n";
}

int main() {
    Solution sol;

    // Example 1: [1,2,3,4,5] → [1,3,5,2,4]
    ListNode* head1 = buildList({1, 2, 3, 4, 5});
    cout << "Example 1: ";
    printList(sol.oddEvenList(head1));   // Expected: [1,3,5,2,4]

    // Example 2: [2,1,3,5,6,4,7] → [2,3,6,7,1,5,4]
    ListNode* head2 = buildList({2, 1, 3, 5, 6, 4, 7});
    cout << "Example 2: ";
    printList(sol.oddEvenList(head2));   // Expected: [2,3,6,7,1,5,4]

    // Edge case: empty list
    ListNode* head3 = buildList({});
    cout << "Edge (empty): ";
    printList(sol.oddEvenList(head3));   // Expected: []

    // Edge case: single node
    ListNode* head4 = buildList({42});
    cout << "Edge (single): ";
    printList(sol.oddEvenList(head4));   // Expected: [42]

    return 0;
}
