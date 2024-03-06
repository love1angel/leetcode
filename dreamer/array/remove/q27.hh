class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int len { 0 };
        for (auto num : nums) {
            if (num != val)
                nums[len++] = num;
        }
        return len;
    }
};

/**
 * since ret can random order
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int left { 0 }, right = nums.size() - 1;
        while (left <= right) {
            while (left <= right && nums[left] != val)
                ++left;
            while (right >= left && nums[right] == val)
                --right;
            if (left < right) // < ? <=
                std::swap(nums[left++], nums[right--]);
        }
        return left;
    }
};
