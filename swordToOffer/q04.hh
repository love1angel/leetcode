//
// Created by Helianthus Xie on 2022/7/20.
//

#ifndef LEETCODE_Q04_HH
#define LEETCODE_Q04_HH

#include <vector>

class Solution {
    template <typename T>
    using Matrix = std::vector<std::vector<T>>;

public:
    bool findNumberIn2DArray(Matrix<int> const& matrix, int target)
    {
        if (matrix.empty())
            return false;
        int i = 0, j = matrix[0].size() - 1;
        while (i < matrix.size() && j >= 0) {
            if (matrix[i][j] == target)
                return true;

            if (matrix[i][j] < target)
                ++i;
            else
                --j;
        }
        return false;
    }
};

#endif // LEETCODE_Q04_HH
