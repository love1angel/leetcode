#pragma once

class Solution {
public:
    ListNode* swapPairs(ListNode* head)
    {
        ListNode A[2] { { 0, &A[1] }, { 0, head } };
        ListNode* pairs = &A[0];
        while (pairs->next->next && pairs->next->next->next) {
            // 不能用引用，链路前面的先不动
            auto first = pairs->next->next, second = pairs->next->next->next;
            auto tmp = second->next;
            second->next = first;
            first->next = tmp;
            pairs->next->next = second;
            pairs = pairs->next->next;
        }
        return A[1].next;
    }
};
