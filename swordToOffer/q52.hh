//
// Created by Helianthus Xie on 2022/7/27.
//

#ifndef LEETCODE_Q52_HH
#define LEETCODE_Q52_HH

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == nullptr || headB == nullptr)
            return nullptr;

        ListNode *p_A = headA, *p_B = headB;
        while (p_A != p_B) {
            p_A = p_A == nullptr ? headB : p_A->next;
            p_B = p_B == nullptr ? headA : p_B->next;
        }
        return p_A;
    }
};

#endif //LEETCODE_Q52_HH
