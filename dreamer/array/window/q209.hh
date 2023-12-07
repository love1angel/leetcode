#pragma once

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int min = std::numeric_limits<int>::max();
        int start = 0, sum = 0;
        for (int end = 0; end < nums.size(); ++end) {
            sum += nums[end];
            if (sum >= target) {
                min = std::min(min, end - start + 1);
                do {
                    sum -= nums[start++];
                } while (sum >= target && (min = std::min(min, end - start + 1), 1));
            }
        }
        if (min == std::numeric_limits<int>::max()) {
            return 0;
        }
        return min;
    }
};
