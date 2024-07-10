class Solution {
public:
    int totalFruit(vector<int>& fruits)
    {
        std::unordered_map<int, int> map;
        int max { 0 }, left { 0 };
        for (int i { 0 }; i < fruits.size(); ++i) {
            if (map.contains(fruits[i])) {
                map[fruits[i]] = i;
            } else {
                if (map.size() < 2) {
                    map[fruits[i]] = i;
                } else {
                    max = std::max(max, i - left);
                    std::erase_if(map, [&](const auto& itr) {
                        if (itr.first == fruits[i - 1]) {
                            return false;
                        }
                        left = itr.second + 1;
                        return true;
                    });
                    map[fruits[i]] = i;
                }
            }
        }
        max = std::max<int>(max, fruits.size() - left);
        return max == 0 ? fruits.size() : max;
    }
};
