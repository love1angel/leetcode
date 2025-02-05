// https://leetcode.cn/problems/binary-search/description/

class Solution {
public:
    int search(const std::vector<int>& nums, const int target)
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
        return -1;
    }
};

class Solution {
public:
    int search(const std::vector<int>& nums, const int target)
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
        return -1;
    }
};

class Solution {
public:
    int search(const std::vector<int>& nums, const int target)
    {
        auto beg { 0 }, end { static_cast<int>(nums.size()) }, mid { std::midpoint(beg, end) };
        while (mid != end && nums[mid] != target) {
            if (nums[mid] < target) {
                beg = mid + 1;
            } else {
                end = mid;
            }
            mid = std::midpoint(beg, end);
        }
        return mid == end ? -1 : mid;
    }
};
