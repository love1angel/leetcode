//
// Created by Helianthus Xie on 2022/7/27.
//

#ifndef LEETCODE_Q25_HH
#define LEETCODE_Q25_HH

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode ret(0), *cur = &ret;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 != nullptr ? l1 : l2;
        return ret.next;
    }
};

#endif //LEETCODE_Q25_HH
