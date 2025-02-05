// https://leetcode.cn/problems/valid-perfect-square/description/

class Solution {
public:
    bool isPerfectSquare(int num)
    {
        const auto c { static_cast<double>(num) };
        auto x_e { static_cast<double>(num) };
        double x_n;
        do {
            x_n = .5 * (x_e + c / x_e);
        } while (std::abs(x_n - x_e) > 1e-7 && (x_e = x_n));
        return static_cast<int>(x_e) * static_cast<int>(x_e) == num;
    }
};
