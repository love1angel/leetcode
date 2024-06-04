class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int left { 0 }, right { static_cast<int>(nums.size()) - 1 };
        while (left <= right) {
            int mid { left + ((right - left) >> 1) };
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
        int beg { 0 }, end { static_cast<int>(nums.size()) };
        while (beg < end) {
            int mid { beg + ((end - beg) >> 1) };
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
        int beg { 0 }, end { static_cast<int>(nums.size()) }, mid { end >> 1 };
        while (mid != end && nums[mid] != target) {
            if (nums[mid] < target)
                beg = mid + 1;
            else
                end = mid;
            mid = beg + ((end - beg) >> 1);
        }
        if (mid == end)
            return -1;
        return mid;
    }
};
