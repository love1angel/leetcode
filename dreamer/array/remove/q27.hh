// https://leetcode.cn/problems/remove-element/description/

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val)
    {
        auto left { 0 }, right { static_cast<int>(nums.size()) - 1 };
        while (left <= right) {
            if (nums[left] == val) {
                nums[left] = nums[right--];
            } else {
                ++left;
            }
        }
        return left;
    }
};
