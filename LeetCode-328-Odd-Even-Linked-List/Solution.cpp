#include <bits/stdc++.h>
using namespace std;

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
        if (!head || !head->next) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;
        return head;
    }
};

ListNode* buildList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* cur = head;
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

    ListNode* head1 = buildList({1, 2, 3, 4, 5});
    cout << "Example 1: ";
    printList(sol.oddEvenList(head1));

    ListNode* head2 = buildList({2, 1, 3, 5, 6, 4, 7});
    cout << "Example 2: ";
    printList(sol.oddEvenList(head2));

    ListNode* head3 = buildList({});
    cout << "Edge (empty): ";
    printList(sol.oddEvenList(head3));

    ListNode* head4 = buildList({42});
    cout << "Edge (single): ";
    printList(sol.oddEvenList(head4));

    return 0;
}
