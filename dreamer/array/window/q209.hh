// https://leetcode.cn/problems/minimum-size-subarray-sum/description/

class Solution {
public:
    int minSubArrayLen(const int target, const std::vector<int>& nums)
    {
        auto ths_sum { 0 }, left { 0 }, min_len { std::numeric_limits<int>::max() };
        for (auto right { 0 }; right < nums.size(); ++right) {
            ths_sum += nums[right];
            while (ths_sum >= target) {
                min_len = std::min(min_len, right - left + 1);
                ths_sum -= nums[left++];
            }
        }
        return min_len == std::numeric_limits<int>::max() ? 0 : min_len;
    }
};
