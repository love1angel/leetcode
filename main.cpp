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

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

// 1  2  3  4  5

// F  F  F  T  T

// l: 4, r: 5
//  m 3

//  F

bool isBadVersion(int version)
{
    if (version < 4)
        return false;
    return true;
}

class Solution {
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int beg = 0, end = nums.size() - 1;
        while (beg <= end) {
            auto mid = beg + (end - beg) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] < target)
                beg = mid + 1;
            else
                end = mid - 1;
        }
        return beg;
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
    std::vector<int> vec{1, 3, 5, 7};
    std::cout << solution.searchInsert(vec, 8) << std::endl;

    return 0;
}
