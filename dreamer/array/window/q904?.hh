// https://leetcode.cn/problems/fruit-into-baskets/description/

class Solution {
public:
    int totalFruit(const std::vector<int>& fruits)
    {
        std::unordered_map<int, int> map;
        auto i { 0 }, max_len { 0 }, j { 0 };
        for (; j < fruits.size(); ++j) {
            if (!map.contains(fruits[j]) && map.size() == 2) {
                max_len = std::max(max_len, j - i);
                std::erase_if(map, [&](auto& pair) {
                    if (pair.first == fruits[j - 1]) {
                        return false;
                    }
                    i = pair.second + 1;
                    return true;
                });
            }
            map[fruits[j]] = j;
        }
        max_len = std::max(max_len, j - i);
        return max_len;
    }
};
