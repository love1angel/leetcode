#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <deque>
#include <queue>
#include <unordered_set>
#include <algorithm>

using std::vector;
using std::string;

using std::queue;
using std::deque;

using std::unordered_set;


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int findRepeatNumber(vector<int> &nums)
    {
        for (int i = 0; i < nums.size();) {
            if (nums[i] == i) {
                ++i;
                continue;
            }
            if (nums[nums[i]] == nums[i])
                return nums[i];

            std::swap(nums[i], nums[nums[i]]);
        }
        return 0;
    }
};

int main()
{
//    Solution solution;
//    TreeNode t1(3);
//    TreeNode t2(9);
//    TreeNode t3(20);
//    TreeNode t4(15);
//    TreeNode t5(7);
//
//    t1.left = &t2;
//    t1.right = &t3;
//    t2.left = nullptr;
//    t2.right = nullptr;
//
//    t3.left = &t4;
//    t3.right = &t5;
//
//    t4.left = nullptr;
//    t4.right = nullptr;
//
//    t5.left = nullptr;
//    t5.right = nullptr;
//
////    auto vec = solution.levelOrder(&t1);
//
//    Solution solution1;
//    std::vector<int> temp{5, 4, 6, 7, 9, 3, 10, 9, 5, 6};
//    auto vec = solution1.findDuplicates(temp);
//
//
//    for (auto item: vec) {
//        std::cout << item << std::endl;
//    }

    Solution solution;
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(4);
    ListNode l5(5);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    l5.next = nullptr;
    std::vector<int> vec = {2, 3, 1, 0, 2, 5, 3};
    auto x = solution.findRepeatNumber(vec);
    std::cout << x << std::endl;
    return 0;
}
