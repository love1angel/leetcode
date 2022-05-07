//
// Created by Helianthus Xie on 2022/5/8.
//

class CQueue {
public:
    CQueue()
    {

    }

    void appendTail(int value)
    {
        m_add_stack.push(value);
    }

    int deleteHead()
    {
        int ret = -1;
        if (m_del_stack.empty()) {
            if (m_add_stack.empty())
                return ret;
            do {
                m_del_stack.push(m_add_stack.top());
                m_add_stack.pop();
            } while (!m_add_stack.empty());
        }
        ret = m_del_stack.top();
        m_del_stack.pop();
        return ret;
    }

private:
    std::stack<int> m_add_stack, m_del_stack;
};
