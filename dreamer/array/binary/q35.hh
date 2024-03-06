class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int left { 0 }, right = nums.size() - 1, mid { right / 2 };
        while (left <= right) {
            if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
            else
                return mid;
            mid = left + (right - left) / 2;
        }
        // return right + 1;
        return left;
    }
};

class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int beg { 0 }, end = nums.size(), mid { beg + (end - beg) / 2 };
        while (beg < end) {
            if (nums[mid] < target)
                beg = mid + 1;
            else if (nums[mid] > target)
                end = mid;
            else
                return mid;
            mid = beg + (end - beg) / 2;
        }
        // return end;
        return beg;
    }
};
