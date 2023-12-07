#pragma once

class MyLinkedList {

    struct Node {
        Node(int v, Node* n)
            : val(v)
            , next(n)
        {
        }
        int val;
        Node* next;
    };

public:
    MyLinkedList() = default;

    int get(int index)
    {
        if (index < 0) {
            return -1;
        }

        Node* each = head.next;
        while (each && index) {
            each = each->next;
            --index;
        }
        if (!each) {
            return -1;
        }
        return each->val;
    }

    void addAtHead(int val)
    {
        Node* new_node = new Node(val, nullptr);
        Node* tmp = head.next;
        head.next = new_node;
        new_node->next = tmp;
    }

    void addAtTail(int val)
    {
        Node* each = &head;
        while (each->next) {
            each = each->next;
        }

        Node* new_node = new Node(val, nullptr);
        each->next = new_node;
    }

    void addAtIndex(int index, int val)
    {
        --index;
        if (index < -1) {
            return;
        } else if (index == -1) {
            addAtHead(val);
        } else {
            Node* each = head.next;
            while (each && index) {
                each = each->next;
                --index;
            }
            if (!each) {
                return;
            }
            Node* new_node = new Node(val, nullptr);
            new_node->next = each->next;
            each->next = new_node;
        }
    }

    void deleteAtIndex(int index)
    {
        --index;
        if (index < -1) {
            return;
        } else if (index == -1) {
            if (!head.next)
                return;
            Node* tmp = head.next->next;
            delete head.next;
            head.next = tmp;
        } else {
            Node* each = head.next;
            while (each && index) {
                each = each->next;
                --index;
            }
            if (!each || !each->next) {
                return;
            }
            Node* del_node = each->next;
            each->next = each->next->next;
            delete del_node;
        }
    }

private:
    Node head { 0, nullptr };
};
