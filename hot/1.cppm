import std;

// TODO https://leetcode.cn/problems/two-sum/description/

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::unordered_map<int, int> map {};
        for (auto const [idx, num] : nums | std::views::enumerate) {
            if (map.contains(target - num)) [[unlikely]] {
                return { static_cast<int>(idx), map[target - num] };
            } else {
                map[num] = idx;
            }
        }
        std::unreachable();
    }
};
