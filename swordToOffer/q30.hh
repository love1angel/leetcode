//
// Created by Helianthus Xie on 2022/5/8.
//

#ifndef LEETCODE_Q30_HH
#define LEETCODE_Q30_HH

#include <stack>

class MinStack {
public:
    MinStack() = default;

    void push(int x)
    {
        if (m_stack.empty() || m_min_stack.top() >= x)
            m_min_stack.push(x);
        m_stack.push(x);
    }

    void pop()
    {
        if (m_stack.empty())
            return;
        if (m_stack.top() == m_min_stack.top())
            m_min_stack.pop();
        m_stack.pop();
    }

    int top()
    {
        return m_stack.top();
    }

    int min()
    {
        return m_min_stack.top();
    }

private:
    std::stack<int> m_stack, m_min_stack;
};

#endif // LEETCODE_Q30_HH
