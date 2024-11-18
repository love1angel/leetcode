// https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        auto left { 0 }, right { static_cast<int>(nums.size()) - 1 }, mid { right >> 1 };
        bool flag { false };
        while (left <= right) {
            const auto ordering { target <=> nums[mid] };
            if (std::is_gt(ordering)) {
                left = mid + 1;
            } else if (std::is_lt(ordering)) {
                right = mid - 1;
            } else {
                flag = true;
                break;
            }
            mid = std::midpoint(left, right);
        }
        return flag ? std::vector<int> { this->searchLeft(nums, left, mid - 1, target), this->searchRight(nums, mid + 1, right, target) }
                    : std::vector<int>(2, -1);
    }

private:
    int searchLeft(const std::vector<int>& nums, int left, int right, int target)
    {
        while (left <= right) {
            const auto mid { std::midpoint(left, right) };
            if (nums[mid] < target) {
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
            const auto mid { std::midpoint(left, right) };
            if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
};

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        const auto left { this->search(nums, 0, nums.size() - 1, target, true) };
        const auto right { this->search(nums, left, nums.size() - 1, target) - 1 };
        return left <= right ? std::vector<int> { left, right } : std::vector<int>(2, -1);
    }

private:
    int search(const std::vector<int>& nums, int left, int right, int target, bool flag = false)
    {
        auto result { static_cast<int>(nums.size()) };
        while (left <= right) {
            const auto mid { std::midpoint(left, right) };
            if (nums[mid] > target || (flag && nums[mid] >= target)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
};
