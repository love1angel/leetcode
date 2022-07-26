#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
    {}
};


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL)
    {}
};

class Solution {
public:
    ListNode *getKthFromEnd(ListNode *head, int k)
    {
        auto fast = head, slow = head;

        int i = 0;
        while (i < k && fast) {
            fast = fast->next;
            ++i;
        }
        if (i != k)
            return head;

        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};


int main(int argc, char *argv[])
{

    TreeNode n6(9, nullptr, nullptr);
    TreeNode n5(6, nullptr, nullptr);
    TreeNode n4(3, nullptr, nullptr);
    TreeNode n3(1, nullptr, nullptr);
    TreeNode n2(7, &n5, &n6);
    TreeNode n1(2, &n3, &n4);
    TreeNode n0(4, &n1, &n2);

    Solution solution;

    std::string s;
    std::cout << (s == "23") << std::endl;

    return 0;
}
