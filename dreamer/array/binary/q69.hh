// https://leetcode.cn/problems/sqrtx

class Solution {
public:
    int mySqrt(int x)
    {
        if (x == 0) {
            return 0;
        }
        const auto c { static_cast<double>(x) };
        auto xi { .0 }, x0 { static_cast<double>(x) };
        do {
            xi = 0.5 * (c / x0 + x0);
        } while (std::abs(xi - x0) > 1e-7 && (x0 = xi));
        return xi;
    }
};
