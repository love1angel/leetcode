import std;

// https://leetcode.cn/problems/reverse-linked-list/description/

class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* new_head { nullptr };
        while (head) {
            const auto tmp = head->next;
            head->next = new_head;
            new_head = head;
            head = tmp;
        }
        return new_head;
    }
};
