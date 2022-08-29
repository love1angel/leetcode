//
// Created by Helianthus Xie on 2022/5/8.
//

#ifndef LEETCODE_Q06_HH
#define LEETCODE_Q06_HH

class Solution {
public:
    vector<int> reversePrint(ListNode *head)
    {
        std::vector<int> ret;
        while (head) {
            ret.push_back(head->val);
            head = head->next;
        }

        auto size = ret.size();
        for (int i = 0; i < size / 2; ++i) {
            ret[i] ^= ret[size - 1 - i];
            ret[size - 1 - i] ^= ret[i];
            ret[i] ^= ret[size - 1 - i];
        }
        return ret;
    }
};

#endif //LEETCODE_Q06_HH
