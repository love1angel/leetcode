// https://leetcode.cn/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums)
    {
        auto cur { 0 };
        for (auto i { 1 }; i < nums.size(); ++i) {
            if (nums[i] != nums[cur]) {
                nums[++cur] = nums[i];
            }
        }
        return cur + 1;
    }
};
