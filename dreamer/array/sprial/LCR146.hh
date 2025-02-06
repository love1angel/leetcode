// https://leetcode.cn/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/description/

class Solution {
public:
    std::vector<int> spiralArray(const std::vector<std::vector<int>>& array)
    {
        if (!array.size() || !array[0].size())
            return {};
        std::vector<int> result;
        auto x { 0 }, y { 0 }, loop { static_cast<int>(array.size() * array[0].size()) };
        result.reserve(loop);

        auto left { 0 }, right { static_cast<int>(array[0].size()) - 1 }, top { static_cast<int>(array.size()) - 1 }, bottom { 0 };
        while (loop > 0) {
            while (x <= right) {
                result.push_back(array[y][x]);
                ++x, --loop;
            }
            --x, ++y, ++bottom;
            while (y <= top) {
                result.push_back(array[y][x]);
                ++y, --loop;
            }
            --x, --y, --right;
            if (loop == 0) {
                break;
            }
            while (x >= left) {
                result.push_back(array[y][x]);
                --x, --loop;
            }
            ++x, --y, --top;
            while (y >= bottom) {
                result.push_back(array[y][x]);
                --y, --loop;
            }
            ++x, ++y, ++left;
        }
        return result;
    }
};
