// https://leetcode.cn/problems/binary-search/description

class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        auto left { 0 }, right { static_cast<int>(nums.size()) - 1 };
        while (left <= right) {
            const auto mid { left + ((right - left) >> 1) };
            const auto ordering { target <=> nums[mid] };
            if (std::is_gt(ordering)) {
                left = mid + 1;
            } else if (std::is_lt(ordering)) {
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
    int search(vector<int>& nums, int target)
    {
        auto beg { 0 }, end { static_cast<int>(nums.size()) };
        while (beg < end) {
            const auto mid { beg + ((end - beg) >> 1) };
            const auto ordering { target <=> nums[mid] };
            if (std::is_gt(ordering)) {
                beg = mid + 1;
            } else if (std::is_lt(ordering)) {
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
    int search(vector<int>& nums, int target)
    {
        auto beg { 0 }, end { static_cast<int>(nums.size()) };
        auto mid { beg + ((end - beg) >> 1) };
        while (mid != end && nums[mid] != target) {
            if (nums[mid] < target) {
                beg = mid + 1;
            } else {
                end = mid;
            }
            mid = beg + ((end - beg) >> 1);
        }
        return mid == end ? -1 : mid;
    }
};
