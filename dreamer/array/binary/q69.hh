class Solution {
public:
    int mySqrt(int x)
    {
        int left = 0, right = x / 2 + 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long ret = (long long)mid * mid;
            if (ret < x)
                left = mid + 1;
            else if (ret > x)
                right = mid - 1;
            else
                return mid;
        }
        return left - 1;
    }
};
