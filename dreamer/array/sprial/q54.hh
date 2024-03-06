class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        std::vector<int> ret {};
        int m = matrix.size(), n = matrix[0].size(), total { m * n };
        ret.reserve(total);

        int x { 0 }, y { 0 }, cnt { 0 };
        int top { m - 1 }, below { 0 }, left { 0 }, right { n - 1 };

        while (true) {
            while (y <= right) {
                ret.push_back(matrix[x][y]);
                ++y, ++cnt;
                if (cnt == total)
                    return ret;
            }
            ++x, --y, ++below;

            while (x <= top) {
                ret.push_back(matrix[x][y]);
                ++x, ++cnt;
                if (cnt == total)
                    return ret;
            }
            --x, --y, --right;

            while (y >= left) {
                ret.push_back(matrix[x][y]);
                --y, ++cnt;
                if (cnt == total)
                    return ret;
            }
            --x, ++y, --top;

            while (x >= below) {
                ret.push_back(matrix[x][y]);
                --x, ++cnt;
                if (cnt == total)
                    return ret;
            }
            ++x, ++y, ++left;
        }
        return ret;
    }
};
