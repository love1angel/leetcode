class Solution {
public:
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode *entry { head }, **pp_node { &head };

        while (entry) {
            if (entry->val == val)
                *pp_node = entry->next;
            else
                pp_node = &entry->next;
            entry = entry->next;
        }

        return head;
    }
};
