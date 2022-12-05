//
// Created by Helianthus Xie on 2022/7/17.
//

#ifndef LEETCODE_Q35_HH
#define LEETCODE_Q35_HH

#include <unordered_map>

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;

        if (!m_map.contains(head)) {
            auto new_node = new Node(head->val);
            m_map[head] = new_node;
            new_node->next = copyRandomList(head->next);
            new_node->random = copyRandomList(head->random);
            return new_node;
        }

        return m_map[head];
    }

private:
    std::unordered_map<Node *, Node *> m_map;
};

#endif //LEETCODE_Q35_HH
