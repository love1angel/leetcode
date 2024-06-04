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

class Solution {
public:
    int mySqrt(int x)
    {
        if (x == 0)
            return 0;
        double xi {}, x0 { static_cast<double>(x) }, c { static_cast<double>(x) };

        do {
            xi = 0.5 * (x0 + c / x0);
        } while (std::abs(xi - x0) > 1e-7 && (x0 = xi));

        return xi;
    }
};
