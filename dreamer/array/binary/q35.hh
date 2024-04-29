class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int left { 0 }, right { static_cast<int>(nums.size() - 1) };
        while (left <= right) {
            int mid { left + ((right - left) >> 1) };
            if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
            else
                return mid;
        }
        // return right + 1;
        return left;
    }
};

class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int beg { 0 }, end { static_cast<int>(nums.size()) };
        while (beg < end) {
            int mid { left + ((right - left) >> 1) };
            if (nums[mid] < target)
                beg = mid + 1;
            else if (nums[mid] > target)
                end = mid;
            else
                return mid;
        }
        // return end;
        return beg;
    }
};
