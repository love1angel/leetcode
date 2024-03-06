class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int left { 0 }, right = nums.size() - 1, mid { right / 2 };
        while (left <= right) {
            if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
            else
                break;
            mid = left + (right - left) / 2;
        }
        if (left > right)
            return { -1, -1 };
        return { findLeft(nums, left, mid - 1, target), findRight(nums, mid + 1, right, target) };
    }

private:
    int findLeft(const std::vector<int>& nums, int left, int right, int target)
    {
        int mid { left + (right - left) / 2 };
        while (left <= right) {
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
            mid = left + (right - left) / 2;
        }
        return left;
    }

    int findRight(const std::vector<int>& nums, int left, int right, int target)
    {
        int mid { left + (right - left) / 2 };
        while (left <= right) {
            if (nums[mid] == target)
                left = mid + 1;
            else
                right = mid - 1;
            mid = left + (right - left) / 2;
        }
        return right;
    }
};
