#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    int minArray(vector<int> &numbers)
    {
        if (numbers[0] <= numbers[numbers.size() - 1])
            return numbers[0];
        int beg = 0, end = numbers.size() - 1;
        while (beg < end) {
            int mid = beg + (end - beg) / 2;
            if (numbers[mid] > numbers[end]) {
                beg = mid + 1;
            } else if (numbers[mid] < numbers[end]) {
                end = mid;
            } else {
                --end;
            }
        }
        return numbers[beg];
    }
};


int main(int argc, char *argv[])
{
    Solution solution;
    std::vector<vector<int>> a = {{1,  4,  7,  11, 15},
                                  {2,  5,  8,  12, 19},
                                  {3,  6,  9,  16, 22},
                                  {10, 13, 14, 17, 24},
                                  {18, 21, 23, 26, 30}};
    std::vector<int> b = {3, 4, 5, 1, 2};
    std::cout << solution.minArray(b) << std::endl;
    return 0;
}
