class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int left { 0 }, sum { 0 }, min_len { std::numeric_limits<int>::max() };
        for (int i { 0 }; i < nums.size(); ++i) {
            sum += nums[i];
            while (sum >= target) {
                min_len = std::min(i - left + 1, min_len);
                sum -= nums[left++];
            }
        }
        return min_len == std::numeric_limits<int>::max() ? 0 : min_len;
    }
};
