//
// Created by Helianthus Xie on 2022/5/12.
//

#ifndef LEETCODE_Q944_HH
#define LEETCODE_Q944_HH

class Solution {
public:
    int minDeletionSize(vector <string> &strs)
    {
        int row = strs.size(), col = strs[0].length(), ret = 0;
        for (int j = 0; j < col; ++j) {
            for (int i = 0; i < row - 1; ++i) {
                if (strs[i][j] > strs[i + 1][j]) {
                    ++ret;
                    break;
                }
            }
        }
        return ret;
    }
};

#endif //LEETCODE_Q944_HH
