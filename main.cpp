#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <thread>
#include <unordered_set>
#include <random>

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
    int sumNums(int n)
    {
        return 1 +
    }
};

int test()
{
    for (int i = 0; i < 10; ++i) {
        std::cout << i << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    return 0;
}

std::string s =
        int

main(int argc, char *argv[])
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
    std::default_random_engine random(std::chrono::system_clock::now().time_since_epoch().count());

    std::uniform_int_distribution<int> dist(0, 9);

    for (int i = 0; i < 10; ++i) {
        std::cout << dist(random) << std::endl;
    }
    return 0;
}
