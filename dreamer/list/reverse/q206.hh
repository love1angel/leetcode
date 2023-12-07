#pragma once

class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* pre = nullptr;
        while (head) {
            ListNode* tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp;
        }
        return pre;
    }
};
