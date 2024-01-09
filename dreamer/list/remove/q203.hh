#pragma once

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode** pp = &head;
        ListNode* entry = head;
        while (entry) {
            if (entry->val == val) {
                *pp = entry->next;
            } else {
                pp = &entry->next;
            }
            entry = entry->next;
        }
        return head;
    }
};
