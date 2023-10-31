#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    int countSeniors(vector<string>& details)
    {
        int cnt = 0;

        for (const auto& detail : details) {
            char first = detail[11], second = detail[12];
            int year = 10 * (first - 48) + second - 48;
            if (year > 60)
                ++cnt;
        }

        return cnt;
    }
};
