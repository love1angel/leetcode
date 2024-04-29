class Solution {
public:
    int mySqrt(int x)
    {
        int left { 0 }, right { x / 2 + 1 };
        while (left <= right) {
            int mid { left + ((right - left) >> 1) };
            std::strong_ordering order = static_cast<long long>(mid) * mid <=> x;
            if (std::is_lt(order))
                left = mid + 1;
            else if (std::is_gt(order))
                right = mid - 1;
            else
                return mid;
        }
        return right;
    }
};
