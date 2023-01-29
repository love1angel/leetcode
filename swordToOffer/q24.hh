//
// Created by Helianthus Xie on 2022/5/8.
//

#ifndef LEETCODE_Q24_HH
#define LEETCODE_Q24_HH

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr)
    {}
};

class Solution {
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *ret = nullptr;
        while (head) {
            auto tmp = head->next;
            head->next = ret;
            ret = head;
            head = tmp;
        }
        return ret;
    }
};

#endif //LEETCODE_Q24_HH
