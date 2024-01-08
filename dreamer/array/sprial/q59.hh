class Solution {
public:
    vector<vector<int>> generateMatrix(int n)
    {
        std::vector<std::vector<int>> vec(n, std::vector<int>(n, 0));

        int cnt { 1 };
        int left { 0 }, right { n - 1 }, top { n - 1 }, bottom { 0 };
        int cur[2] { 0, 0 };

        for (int i = 0; i <= n / 2; ++i) {
            for (int& m_0 = cur[1]; m_0 <= right; ++m_0) {
                vec[cur[0]][m_0] = cnt;
                ++cnt;
            }
            ++cur[0], --cur[1];

            for (int& m_2 = cur[0]; m_2 <= top; ++m_2) {
                vec[m_2][cur[1]] = cnt;
                ++cnt;
            }
            --cur[0], --cur[1];

            for (int& m_3 = cur[1]; m_3 >= left; --m_3) {
                vec[cur[0]][m_3] = cnt;
                ++cnt;
            }
            --cur[0], ++cur[1];

            for (int& m_4 = cur[0]; m_4 > bottom; --m_4) {
                vec[m_4][cur[1]] = cnt;
                ++cnt;
            }
            ++cur[0], ++cur[1];

            ++left, --right, --top, ++bottom;
        }

        return vec;
    }
};
