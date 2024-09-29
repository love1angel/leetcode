// https://leetcode.cn/problems/valid-perfect-square/description

class Solution {
public:
    bool isPerfectSquare(int num)
    {
        const auto c { static_cast<double>(num) };
        auto xi { .0 }, x0 { static_cast<double>(num) };
        do {
            xi = 0.5 * (c / x0 + x0);
        } while (std::abs(xi - x0) > 1e-7 && (x0 = xi));
        return num == static_cast<int>(xi) * static_cast<int>(xi);
    }
};
