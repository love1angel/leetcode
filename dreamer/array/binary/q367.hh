class Solution {
public:
    bool isPerfectSquare(int num)
    {
        int left = 1, right = num / 2 + 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            long long ret = (long long)mid * mid;
            if (ret < num)
                left = mid + 1;
            else if (ret > num)
                right = mid - 1;
            else
                return true;
        }
        return false;
    }
};
