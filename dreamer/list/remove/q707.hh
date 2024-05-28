class MyLinkedList {
    struct Node {
        Node(int val, Node* next)
            : m_val { val }
            , m_next { next }
        {
        }
        int m_val;
        Node* m_next;
    };

public:
    MyLinkedList() = default;

    ~MyLinkedList() noexcept
    {
        while (m_head) {
            auto tmp { m_head->m_next };
            delete m_head;
            m_head = tmp;
        }
    }

    int get(int index)
    {
        Node* entry { m_head };
        while (entry && index > 0) {
            entry = entry->m_next;
            --index;
        }
        if (!entry || index > 0)
            return -1;
        return entry->m_val;
    }

    void addAtHead(int val)
    {
        if (m_head == nullptr)
            m_head = new Node(val, nullptr);
        else
            m_head = new Node(val, m_head);
    }

    void addAtTail(int val)
    {
        if (!m_head) {
            m_head = new Node(val, nullptr);
            return;
        }

        Node *fast { m_head->m_next }, *slow { m_head };
        while (fast) {
            slow = slow->m_next;
            fast = fast->m_next;
        }

        slow->m_next = new Node(val, nullptr);
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0)
            return;
        if (index == 0) {
            this->addAtHead(val);
            return;
        }

        Node* entry { m_head };
        while (entry && index > 1) {
            entry = entry->m_next;
            --index;
        }
        if (!entry || index > 1)
            return;

        entry->m_next = new Node(val, entry->m_next);
    }

    void deleteAtIndex(int index)
    {
        if (index < 0)
            return;
        if (index == 0) {
            auto tmp { m_head->m_next };
            delete m_head;
            m_head = tmp;
            return;
        }

        Node* entry { m_head };
        while (entry && index > 1) {
            entry = entry->m_next;
            --index;
        }
        if (!entry || !entry->m_next || index > 1)
            return;

        auto tmp { entry->m_next->m_next };
        delete entry->m_next;
        entry->m_next = tmp;
    }

private:
    Node* m_head = nullptr;
};
