//
// Created by Helianthus Xie on 2022/7/17.
//

#ifndef LEETCODE_Q35_HH
#define LEETCODE_Q35_HH

class Solution {
public:
    Node *copyRandomList(Node *head)
    {
        if (!head) return nullptr;
        if (!m_map.contains(head)) {
            Node *ret = new Node(head->val);
            m_map[head] = ret;
            ret->next = copyRandomList(head->next);
            ret->random = copyRandomList(head->random);
        }

        return m_map[head];
    }

private:
    std::unordered_map<Node *, Node *> m_map;
};

#endif //LEETCODE_Q35_HH
