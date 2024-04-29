class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int left { 0 }, sum { 0 }, min_len { std::numeric_limits<int>::max() };

        for (int right { 0 }; right < nums.size(); ++right) {
            sum += nums[right];
            while (sum >= target) {
                min_len = std::min(min_len, right - left + 1);
                sum -= nums[left++];
            }
        }

        if (min_len == std::numeric_limits<int>::max())
            return 0;

        return min_len;
    }
};
