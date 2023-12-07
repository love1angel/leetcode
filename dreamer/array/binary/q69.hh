#pragma once

class Solution {
public:
    int mySqrt(int x)
    {
        if (x <= 1)
            return x;

        int left = 1, right = x / 2 + 1;
        while (right - left > 1) {
            int mid = left + ((right - left) >> 1);
            auto ret = (long long)mid * mid;
            if (ret == x) {
                return mid;
            } else if (ret > x) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return left;
    }
};
