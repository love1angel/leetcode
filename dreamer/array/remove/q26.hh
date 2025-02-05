// https://leetcode.cn/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums)
    {
        auto cur { 0 };
        for (auto num : nums) {
            if (num != nums[cur]) {
                nums[++cur] = num;
            }
        }
        return cur + 1;
    }
};
