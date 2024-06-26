class Solution {
public:
    int mySqrt(int x)
    {
        if (x == 0)
            return 0;
        double xi {}, xi_1 { static_cast<double>(x) }, c { static_cast<double>(x) };
        do {
            xi = 0.5 * (xi_1 + c / xi_1);
        } while (std::abs(xi - xi_1) > 1e-7 && (xi_1 = xi));
        return xi;
    }
};

class Solution {
public:
    int mySqrt(int x)
    {
        int left { 0 }, right { x / 2 + 1 };
        while (left <= right) {
            int mid { left + ((right - left) >> 1) };
            std::strong_ordering ret { static_cast<long long>(mid) * mid <=> x };
            if (std::is_lt(ret))
                left = mid + 1;
            else if (std::is_gt(ret))
                right = mid - 1;
            else
                return mid;
        }
        return right;
    }
};
