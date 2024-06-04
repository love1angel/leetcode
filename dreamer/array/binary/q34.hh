class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int left { 0 }, right { static_cast<int>(nums.size()) - 1 }, mid { right >> 1 };

        while (left <= right) {
            if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
            else
                break;
            mid = left + ((right - left) >> 1);
        }

        left = search_left(nums, left, mid - 1, target);
        right = search_right(nums, mid + 1, right, target);

        if (left > right)
            return { -1, -1 };
        return { left, right };
    }

private:
    int search_left(const std::vector<int>& nums, int left, int right, int target)
    {
        while (left <= right) {
            int mid { left + ((right - left) >> 1) };
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }

    int search_right(const std::vector<int>& nums, int left, int right, int target)
    {
        while (left <= right) {
            int mid { left + ((right - left) >> 1) };
            if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return right;
    }
};
