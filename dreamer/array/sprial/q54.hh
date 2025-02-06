// https://leetcode.cn/problems/spiral-matrix/

class Solution {
public:
    std::vector<int> spiralOrder(const std::vector<std::vector<int>>& matrix)
    {
        std::vector<int> result;
        auto x { 0 }, y { 0 }, loop { static_cast<int>(matrix.size() * matrix[0].size()) };
        result.reserve(loop);

        auto left { 0 }, right { static_cast<int>(matrix[0].size()) - 1 }, top { static_cast<int>(matrix.size()) - 1 }, bottom { 0 };
        while (loop > 0) {
            while (x <= right) {
                result.push_back(matrix[y][x]);
                ++x, --loop;
            }
            --x, ++y, ++bottom;
            while (y <= top) {
                result.push_back(matrix[y][x]);
                ++y, --loop;
            }
            --x, --y, --right;
            if (loop == 0) {
                break;
            }
            while (x >= left) {
                result.push_back(matrix[y][x]);
                --x, --loop;
            }
            ++x, --y, --top;
            while (y >= bottom) {
                result.push_back(matrix[y][x]);
                --y, --loop;
            }
            ++x, ++y, ++left;
        }
        return result;
    }
};
