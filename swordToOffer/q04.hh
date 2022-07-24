//
// Created by Helianthus Xie on 2022/7/20.
//

#ifndef LEETCODE_Q04_HH
#define LEETCODE_Q04_HH

class Solution {
public:
    bool findNumberIn2DArray(vector <vector<int>> &matrix, int target)
    {
        if (matrix.empty()) return false;

        int i = 0, j = matrix[0].size() - 1;
        while (i < matrix.size() && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            }
            if (matrix[i][j] > target)
                --j;
            else
                ++i;
        }
        return false;
    }
};

#endif //LEETCODE_Q04_HH