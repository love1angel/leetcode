class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int cur {};
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val)
                nums[cur++] = nums[i];
        }
        return cur;
    }
};

/**
 * since ret can random order
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int left {}, right = nums.size() - 1;

        while (left <= right) {
            while (left <= right && nums[left] != val)
                ++left;
            while (left <= right && nums[right] == val)
                --right;
            if (left <= right)
                std::swap(nums[left], nums[right]);
        }

        return left;
    }
};
