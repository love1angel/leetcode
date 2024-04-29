class Solution {
public:
    bool isPerfectSquare(int num)
    {
        int left { 1 }, right { num / 2 + 1 };
        while (left <= right) {
            int mid { left + ((right - left) >> 1) };
            std::strong_ordering order = static_cast<long long>(mid) * mid <=> num;
            if (std::is_lt(order))
                left = mid + 1;
            else if (std::is_gt(order))
                right = mid - 1;
            else
                return true;
        }
        return false;
    }
};
