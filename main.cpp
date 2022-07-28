#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <unordered_set>

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
    string reverseWords(string s)
    {
        int n = s.size();
        string ans = "";
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                int right = i;
                while (i >= 0 && s[i] != ' ') {
                    i--;
                }
                ans += s.substr(i + 1, right - i) + " ";
            }
        }
        return ans.substr(0, ans.size() - 1);
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

    ListNode l0(1);
    ListNode l1(2);
    ListNode l2(4);
    l0.next = &l1;
    l1.next = &l2;


    ListNode l3(1);
    ListNode l4(3);
    ListNode l5(4);
    l3.next = &l4;
    l4.next = &l5;

    Solution solution;

    std::string s;
    std::vector<int> vec{1, 2, 3, 1};
    std::cout << solution.mergeTwoLists(&l0, &l3) << std::endl;

    return 0;
}
