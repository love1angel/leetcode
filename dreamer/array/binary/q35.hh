// https://leetcode.cn/problems/search-insert-position/description/

class Solution {
public:
    int searchInsert(const std::vector<int>& nums, const int target)
    {
        auto left { 0 }, right { static_cast<int>(nums.size()) - 1 };
        while (left <= right) {
            const auto mid { std::midpoint(left, right) };
            if (const auto cmp { nums[mid] <=> target }; std::is_lt(cmp)) {
                left = mid + 1;
            } else if (std::is_gt(cmp)) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
        // return right + 1;
        return left;
    }
};

class Solution {
public:
    int searchInsert(const std::vector<int>& nums, const int target)
    {
        auto beg { 0 }, end { static_cast<int>(nums.size()) };
        while (beg < end) {
            const auto mid { std::midpoint(beg, end) };
            if (const auto cmp { nums[mid] <=> target }; std::is_lt(cmp)) {
                beg = mid + 1;
            } else if (std::is_gt(cmp)) {
                end = mid;
            } else {
                return mid;
            }
        }
        // return end;
        return beg;
    }
};
