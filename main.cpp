#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <thread>
#include <unordered_set>
#include <random>
#include <set>

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

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    string reverseLeftWords(string s, int n)
    {
        exchange(s, 0, n);
        exchange(s, n, s.size());
        exchange(s, 0, s.size());
        return s;
    }

private:
    void exchange(std::string &s, int beg, size_t end)
    {
        for (int i = 0; i < (end - beg) / 2; ++i) {
            char temp = s[beg + i];
            s[beg + i] = s[end - 1 - i];
            s[end - 1 - i] = temp;
        }
    }
};


constexpr int new_sz()
{
    return 42;
}

constexpr size_t scale(size_t cnt)
{
    return new_sz() * cnt;
}


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

//    Solution solution;
    std::default_random_engine random(std::chrono::system_clock::now().time_since_epoch().count());

    std::uniform_int_distribution<int> dist(0, 9);

    for (int i = 0; i < 10; ++i) {
//        std::cout << dist(random) << std::endl;
    }


    int i = 10;

    auto lam = [m_ref(i)]() {
        std::cout << m_ref << std::endl;
    };
    lam();

    int iii = 1;
    auto f = [](const int i) {
        std::cout << i << std::endl;
    };

    Solution solution;

    std::cout << solution.reverseLeftWords("lrloseumgh", 6) << std::endl;

    return 0;
}
