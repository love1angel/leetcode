#pragma once

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode sentry { 0, head };
        ListNode *slow = &sentry, *quick = &sentry;
        while (n >= 0) {
            quick = quick->next;
            --n;
        }

        while (quick) {
            slow = slow->next;
            quick = quick->next;
        }

        slow->next = slow->next->next;

        return sentry.next;
    }
};
