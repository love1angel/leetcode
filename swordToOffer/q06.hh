//
// Created by Helianthus Xie on 2022/5/8.
//

#ifndef LEETCODE_Q06_HH
#define LEETCODE_Q06_HH

class Solution {
public:
    vector<int> reversePrint(ListNode *head)
    {
        if (!head) return {};
        std::vector<int> temp;
        auto ret = std::move(reversePrint(head->next));
        ret.push_back(head->val);
        return ret;
    }
};

#endif //LEETCODE_Q06_HH
