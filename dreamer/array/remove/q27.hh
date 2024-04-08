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
        int i { 0 }, j = nums.size() - 1;
        while (i <= j) {
            while (i <= j && nums[i] != val)
                ++i;
            while (i <= j && nums[j] == val)
                --j;
            if (i < j)
                std::swap(nums[i++], nums[j--]);
        }
        return i;
    }
};
