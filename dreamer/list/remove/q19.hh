class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode node { 0, head };

        ListNode *fast { &node }, *slow { &node };
        while (n >= 0) {
            fast = fast->next;
            --n;
        }

        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return node.next;
    }
};
