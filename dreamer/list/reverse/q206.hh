class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* ret { nullptr };
        while (head) {
            auto tmp { head->next };
            head->next = ret;
            ret = head;
            head = tmp;
        }
        return ret;
    }
};
