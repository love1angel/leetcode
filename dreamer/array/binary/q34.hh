// https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/

class Solution {
public:
    std::vector<int> searchRange(const std::vector<int>& nums, const int target)
    {
        const auto left { Solution::search<true>(nums, target, 0, nums.size() - 1) }, right { Solution::search<false>(nums, target, left, nums.size() - 1) - 1 };
        return left <= right ? std::vector { left, right } : std::vector(2, -1);
    }

private:
    template <bool ContainsEq>
    static int search(const std::vector<int>& nums, const int target, int left, int right)
    {
        auto result { static_cast<int>(nums.size()) };
        while (left <= right) {
            if (const auto mid { std::midpoint(left, right) }; isLarger<ContainsEq>(nums[mid], target)) {
                right = mid - 1;
                result = mid;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }

    template <bool ContainsEq>
    static constexpr bool isLarger(const auto& lhs, const auto& rhs)
    {
        if constexpr (ContainsEq) {
            return lhs >= rhs;
        } else {
            return lhs > rhs;
        }
    }
};

class Solution {
public:
    std::vector<int> searchRange(const std::vector<int>& nums, const int target)
    {
        auto is_found { false };
        auto left { 0 }, right { static_cast<int>(nums.size()) - 1 }, mid { std::midpoint(left, right) };
        while (left <= right) {
            if (const auto cmp { nums[mid] <=> target }; std::is_lt(cmp)) {
                left = mid + 1;
            } else if (std::is_gt(cmp)) {
                right = mid - 1;
            } else {
                is_found = true;
                break;
            }
            mid = std::midpoint(left, right);
        }
        return is_found
            ? std::vector {
                  Solution::searchLeft(nums, target, left, mid - 1),
                  Solution::searchRight(nums, target, mid + 1, right)
              }
            : std::vector(2, -1);
    }

private:
    static int searchLeft(const std::vector<int>& nums, const int target, int left, int right)
    {
        while (left <= right) {
            if (const auto mid { std::midpoint(left, right) }; nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    static int searchRight(const std::vector<int>& nums, const int target, int left, int right)
    {
        while (left <= right) {
            if (const auto mid { std::midpoint(left, right) }; nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
};
