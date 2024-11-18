// https://leetcode.cn/problems/sqrtx/description/

class Solution {
public:
    int mySqrt(int x)
    {
        if (x == 0) {
            return 0;
        }
        const auto c { static_cast<double>(x) };
        auto x_e { static_cast<double>(x) };
        double x_n;
        do {
            x_n = 0.5 * (x_e + c / x_e);
        } while (std::abs(x_n - x_e) > 1e-7 && (x_e = x_n));
        return x_e;
    }
};
