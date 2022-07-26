//
// Created by Helianthus Xie on 2022/7/26.
//

#ifndef LEETCODE_Q22_HH
#define LEETCODE_Q22_HH

class Solution {
public:
    ListNode *getKthFromEnd(ListNode *head, int k)
    {
        auto fast = head, slow = head;

        int i = 0;
        while (i < k && fast) {
            fast = fast->next;
            ++i;
        }
        if (i != k)
            return head;

        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};

#endif //LEETCODE_Q22_HH
