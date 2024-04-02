class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int left { 0 }, right = nums.size() - 1;
        while (left <= right) {
            int mid { left + (right - left) / 2 };
            if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
            else
                return mid;
        }
        return -1;
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int beg { 0 }, end = nums.size();
        while (beg < end) {
            int mid { beg + (end - beg) / 2 };
            if (nums[mid] < target)
                beg = mid + 1;
            else if (nums[mid] > target)
                end = mid;
            else
                return mid;
        }
        return -1;
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int beg { 0 }, end = nums.size(), mid { end / 2 };
        while (mid != end && nums[mid] != target) {
            if (nums[mid] < target)
                beg = mid + 1;
            else
                end = mid;
            mid = beg + (end - beg) / 2;
        }
        if (mid == end)
            return -1;
        return mid;
    }
};
