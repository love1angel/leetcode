// https://leetcode.cn/problems/fruit-into-baskets/description/

class Solution {
public:
    int totalFruit(const std::vector<int>& fruits)
    {
        auto max { 0 }, left { 0 }, right { 0 };
        std::unordered_map<int, int> map;
        for (; right < fruits.size(); ++right) {
            if (!map.contains(fruits[right]) && map.size() == 2) {
                max = std::max(max, right - left);
                std::erase_if(map, [&](auto& pair) {
                    if (pair.first == fruits[right - 1]) {
                        return false;
                    }
                    left = pair.second + 1;
                    return true;
                });
            }
            map[fruits[right]] = right;
        }
        max = std::max(max, right - left);
        return max;
    }
};
