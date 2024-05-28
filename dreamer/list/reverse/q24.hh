class Solution {
public:
    ListNode* swapPairs(ListNode* head)
    {
        if (!head || !head->next)
            return head;
        ListNode *ret { head->next }, *cur { head };

        {
            auto tmp { head->next->next };
            head->next->next = head;
            head->next = tmp;
        }

        while (cur->next) {
            if (cur->next->next) {
                auto tmp { cur->next->next->next };
                cur->next->next->next = cur->next;
                cur->next = cur->next->next;
                cur->next->next->next = tmp;
                cur = cur->next->next;
            } else {
                break;
            }
        }

        return ret;
    }
};
