class Solution {
public:
    int mySqrt(int x)
    {
        int left { 0 }, right { x / 2 + 1 };
        while (left <= right) {
            int mid { left + ((right - left) >> 1) };
            long long squared { static_cast<long long>(mid) * mid };
            if (squared < x)
                left = mid + 1;
            else if (squared > x)
                right = mid - 1;
            else
                return mid;
        }
        return right;
    }
};
