class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int left {}, sum {}, min = std::numeric_limits<int>::max();

        for (int right = 0; right < nums.size(); ++right) {
            sum += nums[right];
            if (sum >= target) {
                min = std::min(min, right - left + 1);
                do {
                    sum -= nums[left++];
                } while (sum >= target && (min = std::min(min, right - left + 1), 1));
            }
        }

        if (min == std::numeric_limits<int>::max())
            return 0;
        return min;
    }
};