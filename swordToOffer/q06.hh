//
// Created by Helianthus Xie on 2022/5/8.
//

#ifndef LEETCODE_Q06_HH
#define LEETCODE_Q06_HH

#include <vector>

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
};

class Solution {
public:
    std::vector<int> reversePrint(ListNode* head)
    {
        std::vector<int> ret {};
        while (head) {
            ret.push_back(head->val);
            head = head->next;
        }

        const int vec_size = ret.size();
        for (int i = 0; i < vec_size / 2; ++i) {
            std::swap(ret[i], ret[vec_size - 1 - i]);
        }

        return ret;
    }
};

#endif //LEETCODE_Q06_HH
