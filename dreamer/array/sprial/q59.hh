class Solution {
public:
    vector<vector<int>> generateMatrix(int n)
    {
        std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
        int left { 0 }, right { n - 1 }, top { n - 1 }, bottom { 0 };
        int x { 0 }, y { 0 }, cnt { 1 }, loop { n / 2 };
        while (loop) {
            while (x <= right) {
                matrix[y][x] = cnt;
                ++x, ++cnt;
            }
            --x, ++y, ++bottom;

            while (y <= top) {
                matrix[y][x] = cnt;
                ++y, ++cnt;
            }
            --x, --y, --right;

            while (x >= left) {
                matrix[y][x] = cnt;
                --x, ++cnt;
            }
            ++x, --y, --top;

            while (y >= bottom) {
                matrix[y][x] = cnt;
                --y, ++cnt;
            }
            ++x, ++y, ++left;

            --loop;
        }

        if (n % 2)
            matrix[n / 2][n / 2] = cnt;

        return matrix;
    }
};
