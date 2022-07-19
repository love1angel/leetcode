#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &nums)
    {
        int beg = 0, end = nums.size() - 1;
        int mid = beg + (end - beg) / 2;
        while (beg <= end) {
            if (nums[mid] == mid)
                beg = mid + 1;
            else
                end = end - 1;
            mid = beg + (end - beg) / 2;
        }
        return beg;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    std::vector<int> r = {1};
    std::cout << solution.missingNumber(r) << std::endl;
    return 0;
}
