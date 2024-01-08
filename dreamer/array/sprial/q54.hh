class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        std::vector<int> ret {};
        ret.reserve(std::max(matrix.size() * matrix.size(), matrix[0].size() * matrix[0].size()));

        int left { 0 }, right = matrix[0].size() - 1, bottom { 0 }, top = matrix.size() - 1;
        int cur[2] { 0, 0 };

        for (int i = 0; i <= std::min(matrix.size(), matrix[0].size()) / 2; ++i) {
            for (int& m_0 = cur[1]; m_0 <= right; ++m_0) {
                ret.push_back(matrix[cur[0]][m_0]);
            }
            ++cur[0], --cur[1];

            for (int& m_0 = cur[0]; m_0 <= top; ++m_0) {
                ret.push_back(matrix[m_0][cur[1]]);
            }
            --cur[0], --cur[1];

            for (int& m_0 = cur[1]; m_0 >= left; --m_0) {
                ret.push_back(matrix[cur[0]][m_0]);
            }
            --cur[0], ++cur[1];

            for (int& m_0 = cur[0]; m_0 > bottom; --m_0) {
                ret.push_back(matrix[m_0][cur[1]]);
            }
            ++cur[0], ++cur[1];
            ++left, ++bottom, --right, --top;
        }

        ret.resize(matrix.size() * matrix[0].size());
        return ret;
    }
};
