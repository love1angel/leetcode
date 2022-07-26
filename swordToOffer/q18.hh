//
// Created by Helianthus Xie on 2022/7/26.
//

#ifndef LEETCODE_Q18_HH
#define LEETCODE_Q18_HH

class Solution {
public:
    ListNode *deleteNode(ListNode *head, int val)
    {
        ListNode temp(0);
        temp.next = head;
        head = &temp;
        while (head->next) {
            if (head->next->val == val) {
                head->next = head->next->next;
                break;
            }
            head = head->next;
        }
        return temp.next;
    }
};

#endif //LEETCODE_Q18_HH
