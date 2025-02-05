// https://leetcode.cn/problems/move-zeroes/description/

class Solution {
public:
    void moveZeroes(std::vector<int>& nums)
    {
        auto cur { 0 };
        for (auto& num : nums) {
            if (num != 0) {
                std::swap(num, nums[cur++]);
            }
        }
    }
};
