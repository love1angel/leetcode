// https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        auto left { 0 }, right { static_cast<int>(nums.size()) - 1 };
        auto mid { right >> 1 };
        while (left <= right) {
            const auto ordering { target <=> nums[mid] };
            if (std::is_gt(ordering)) {
                left = mid + 1;
            } else if (std::is_lt(ordering)) {
                right = mid - 1;
            } else {
                break;
            }
            mid = left + ((right - left) >> 1);
        }
        if (left > right) {
            return { -1, -1 };
        }
        return {
            searchLeft(nums, left, mid - 1, target),
            searchRight(nums, mid + 1, right, target)
        };
    }

private:
    int searchLeft(const std::vector<int>& nums, int left, int right, int target)
    {
        while (left <= right) {
            const auto mid { left + ((right - left) >> 1) };
            const auto ordering { target <=> nums[mid] };
            if (std::is_gt(ordering)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    int searchRight(const std::vector<int>& nums, int left, int right, int target)
    {
        while (left <= right) {
            const auto mid { left + ((right - left) >> 1) };
            const auto ordering { target <=> nums[mid] };
            if (std::is_lt(ordering)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
};
