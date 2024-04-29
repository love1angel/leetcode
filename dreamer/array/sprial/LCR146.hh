class Solution {
public:
    vector<int> spiralArray(vector<vector<int>>& array)
    {
        if (!array.size() || !array[0].size())
            return {};

        std::vector<int> ret {};
        int m { static_cast<int>(array.size()) }, n { static_cast<int>(array[0].size()) };
        ret.reserve(n * m);

        int left { 0 }, right { n - 1 }, top { m - 1 }, bottom { 0 };
        int x { 0 }, y { 0 };
        while (left <= right && bottom <= top) {
            while (x <= right) {
                ret.push_back(array[y][x]);
                ++x;
            }
            --x, ++y, ++bottom;
            if (bottom > top)
                break;

            while (y <= top) {
                ret.push_back(array[y][x]);
                ++y;
            }
            --x, --y, --right;
            if (left > right)
                break;

            while (x >= left) {
                ret.push_back(array[y][x]);
                --x;
            }
            ++x, --y, --top;

            while (y >= bottom) {
                ret.push_back(array[y][x]);
                --y;
            }
            ++x, ++y, ++left;
        }

        return ret;
    }
};
