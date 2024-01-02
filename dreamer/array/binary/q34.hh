class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        int mid = right / 2;
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
        return { searchLeft(nums, left, mid - 1, target), searchRight(nums, mid + 1, right, target) };
    }

private:
    int searchLeft(vector<int>& nums, int left, int right, int target)
    {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }

    int searchRight(vector<int>& nums, int left, int right, int target)
    {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return right;
    }
};
