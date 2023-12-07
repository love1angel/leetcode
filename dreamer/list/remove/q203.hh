#pragma once

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode pre { 0, head };
        ListNode* each = &pre;

        while (each->next) {
            if (each->next->val == val) {
                each->next = each->next->next;
            } else {
                each = each->next;
            }
        }

        return pre.next;
    }
};
