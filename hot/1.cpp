// https://leetcode.cn/problems/two-sum/description/

class Solution {
public:
    std::vector<int> twoSum(const std::vector<int>& nums, const int target)
    {
        std::unordered_map<int, int> map;
        for (auto i { 0 }; i < nums.size(); ++i) {
            if (map.contains(target - nums[i])) {
                return { i, map[target - nums[i]] };
            } else {
                map[nums[i]] = i;
            }
        }
        std::unreachable();
    }
};
