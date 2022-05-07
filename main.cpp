#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <deque>
#include <queue>
#include <unordered_set>

using std::vector;
using std::string;

using std::queue;
using std::deque;

using std::unordered_set;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minMutation(string start, string end, vector<string> &bank)
    {

    }

private:
    std::unordered_set<std::string> m_bank;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

int main()
{
    Solution solution;
    TreeNode t1(3);
    TreeNode t2(9);
    TreeNode t3(20);
    TreeNode t4(15);
    TreeNode t5(7);

    t1.left = &t2;
    t1.right = &t3;
    t2.left = nullptr;
    t2.right = nullptr;

    t3.left = &t4;
    t3.right = &t5;

    t4.left = nullptr;
    t4.right = nullptr;

    t5.left = nullptr;
    t5.right = nullptr;

    auto vec = solution.levelOrder(&t1);

    for (auto item: vec) {
        for (auto m: item) {
            std::cout << m << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}
