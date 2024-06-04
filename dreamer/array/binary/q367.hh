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

class Solution {
public:
    bool isPerfectSquare(int num)
    {
        if (num == 0)
            return true;
        double xi, x0 { static_cast<double>(num) }, C { static_cast<double>(num) };

        do {
            xi = 0.5 * (x0 + C / x0);
        } while (std::abs(xi - x0) > 1e-7 && (x0 = xi));

        return static_cast<int>(xi) * static_cast<int>(xi) == num;
    }
};
