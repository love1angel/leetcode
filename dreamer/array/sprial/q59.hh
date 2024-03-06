class Solution {
public:
    vector<vector<int>> generateMatrix(int n)
    {
        std::vector<std::vector<int>> ret(n, std::vector<int>(n, 0));

        int top { n - 1 }, below { 0 }, left { 0 }, right { n - 1 }, cnt { 0 }, total { n * n };
        int x { 0 }, y { 0 };

        while (true) {
            while (y <= right) {
                if (cnt == total)
                    return ret;
                ret[x][y] = ++cnt;
                ++y;
            }
            ++x, --y, ++below;

            while (x <= top) {
                if (cnt == total)
                    return ret;
                ret[x][y] = ++cnt;
                ++x;
            }
            --x, --y, --right;

            while (y >= left) {
                if (cnt == total)
                    return ret;
                ret[x][y] = ++cnt;
                --y;
            }
            --x, ++y, --top;

            while (x >= below) {
                if (cnt == total)
                    return ret;
                ret[x][y] = ++cnt;
                --x;
            }
            ++x, ++y, ++left;
            if (cnt == total)
                return ret;
        }

        return ret;
    }
};
