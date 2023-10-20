//
// Created by Helianthus Xie on 2022/7/20.
//

#ifndef LEETCODE_Q04_HH
#define LEETCODE_Q04_HH

#include <vector>

class Solution {
public:
    bool findNumberIn2DArray(std::vector<std::vector<int>>& matrix, int target)
    {
        if (!matrix.size())
            return false;
        int i = 0, j = matrix[0].size() - 1;
        while (i < matrix.size() && j >= 0) {
            if (matrix[i][j] == target) [[unlikely]]
                return true;
            else if (matrix[i][j] < target)
                ++i;
            else
                --j;
        }
        return false;
    }
};

#endif // LEETCODE_Q04_HH
