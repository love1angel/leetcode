//
// Created by Helianthus Xie on 2022/5/8.
//

#ifndef LEETCODE_Q24_HH
#define LEETCODE_Q24_HH

class Solution {
public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head || !head->next) return head;
        ListNode *cur = head;
        do {
            auto tmp = cur->next->next;
            cur->next->next = head;
            head = cur->next;
            cur->next = tmp;
        } while (cur->next);
        return head;
    }
};

#if 0
class Solution {
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *pre = nullptr;
        while (head) {
            auto temp = head->next;
            head->next = pre;
            pre = head;
            head = temp;
        }
        return pre;
    }
};
#endif

#if 0
class Solution {
public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head || !head->next) return head;
        auto temp = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return temp;
    }
};
#endif

#endif //LEETCODE_Q24_HH
