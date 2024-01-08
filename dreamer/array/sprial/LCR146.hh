class Solution {
public:
    vector<int> spiralArray(vector<vector<int>>& array)
    {
        if (!array.size()) {
            return {};
        }
        std::vector<int> ret {};
        ret.reserve(std::max(array.size() * array.size(), array[0].size() * array[0].size()));

        int left { 0 }, right = array[0].size() - 1, bottom { 0 }, top = array.size() - 1;
        int cur[2] { 0, 0 };

        for (int i = 0; i <= std::min(array.size(), array[0].size()) / 2; ++i) {
            for (int& m_0 = cur[1]; m_0 <= right; ++m_0) {
                ret.push_back(array[cur[0]][m_0]);
            }
            ++cur[0], --cur[1];

            for (int& m_0 = cur[0]; m_0 <= top; ++m_0) {
                ret.push_back(array[m_0][cur[1]]);
            }
            --cur[0], --cur[1];

            for (int& m_0 = cur[1]; m_0 >= left; --m_0) {
                ret.push_back(array[cur[0]][m_0]);
            }
            --cur[0], ++cur[1];

            for (int& m_0 = cur[0]; m_0 > bottom; --m_0) {
                ret.push_back(array[m_0][cur[1]]);
            }
            ++cur[0], ++cur[1];
            ++left, ++bottom, --right, --top;
        }

        ret.resize(array.size() * array[0].size());
        return ret;
    }
};
