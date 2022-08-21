//
// Created by Helianthus Xie on 2022/5/8.
//

#ifndef LEETCODE_Q09_HH
#define LEETCODE_Q09_HH


class CQueue {
public:
    CQueue() = default;

    void appendTail(int value)
    {
        m_add_stack.push(value);
    }

    int deleteHead()
    {
        if (m_del_stack.empty()) {
            while (!m_add_stack.empty()) {
                m_del_stack.push(m_add_stack.top());
                m_add_stack.pop();
            }
        }

        int ret = -1;
        if (!m_del_stack.empty()) {
            ret = m_del_stack.top();
            m_del_stack.pop();
        }
        return ret;
    }

private:
    std::stack<int> m_add_stack, m_del_stack;
};

#endif // LEETCODE_Q09_HH
