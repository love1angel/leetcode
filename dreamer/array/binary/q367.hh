class Solution {
public:
    bool isPerfectSquare(int num)
    {
        if (num == 0)
            return 0;
        double xi {}, xi_1 { static_cast<double>(num) }, c { static_cast<double>(num) };
        do {
            xi = 0.5 * (xi_1 + c / xi_1);
        } while (std::abs(xi - xi_1) > 1e-7 && (xi_1 = xi));
        return static_cast<int>(xi) * static_cast<int>(xi) == num;
    }
};

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
