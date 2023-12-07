#pragma once

class Solution {
public:
    string addStrings(string num1, string num2)
    {
        std::string max, min;
        if (num1.size() >= num2.size()) {
            max = std::move(num1);
            min = std::move(num2);
        } else {
            max = std::move(num2);
            min = std::move(num1);
        }

        int max_s = max.size() - 1, min_s = min.size() - 1;
        int flag = 0;
        while (max_s >= 0) {
            int each = max[max_s] - '0' + flag;
            if (min_s >= 0) {
                each += min[min_s--] - '0';
            }

            flag = each / 10;
            max[max_s--] = each % 10 + '0';
        }

        if (flag) {
            max.resize(max.size() + 1);
            for (int i = max.size() - 2; i >= 0; --i) {
                max[i + 1] = max[i];
            }
            max[0] = '0' + flag;
        }
        return max;
    }
};
