class Solution {
public:
    vector<int> spiralArray(vector<vector<int>>& array)
    {
        if (array.size() == 0)
            return {};

        std::vector<int> ret {};
        int left { 0 }, right = array[0].size() - 1, below { 0 }, top = array.size() - 1;
        int x { 0 }, y { 0 }, cnt { 0 }, total { (right + 1) * (top + 1) };

        ret.reserve(total);

        while (true) {
            while (y <= right) {
                ret.push_back(array[x][y]);
                ++y, ++cnt;
                if (cnt == total)
                    return ret;
            }
            ++x, --y, ++below;

            while (x <= top) {
                ret.push_back(array[x][y]);
                ++x, ++cnt;
                if (cnt == total)
                    return ret;
            }
            --x, --y, --right;

            while (y >= left) {
                ret.push_back(array[x][y]);
                --y, ++cnt;
                if (cnt == total)
                    return ret;
            }
            --x, ++y, --top;

            while (x >= below) {
                ret.push_back(array[x][y]);
                --x, ++cnt;
                if (cnt == total)
                    return ret;
            }
            ++x, ++y, ++left;
        }
        return ret;
    }
};
