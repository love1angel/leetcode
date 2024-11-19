import std;

// TODO https://leetcode.cn/problems/search-insert-position/description/

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target)
    {
        auto left { 0 }, right { static_cast<int>(nums.size()) - 1 };
        while (left <= right) {
            const auto mid = std::midpoint(left, right);
            const auto ordering { target <=> nums[mid] };
            if (std::is_gt(ordering)) {
                left = mid + 1;
            } else if (std::is_lt(ordering)) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
        return left;
    }
};