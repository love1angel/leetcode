class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int left { 0 }, cnt { 0 }, len { std::numeric_limits<int>::max() };

        for (int i { 0 }; i < nums.size(); ++i) {
            cnt += nums[i];
            while (cnt >= target) {
                len = std::min(len, i - left + 1);
                cnt -= nums[left];
                ++left;
            }
        }

        if (len == std::numeric_limits<int>::max())
            return 0;

        return len;
    }
};
