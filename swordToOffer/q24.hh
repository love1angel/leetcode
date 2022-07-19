//
// Created by Helianthus Xie on 2022/5/8.
//

#ifndef LEETCODE_Q24_HH
#define LEETCODE_Q24_HH

class Solution {
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *pre = nullptr;
        while (head) {
            auto tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp;
        }
        return pre;
    }
};

#endif //LEETCODE_Q24_HH
