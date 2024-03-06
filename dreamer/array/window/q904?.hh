class Solution {
public:
    int totalFruit(vector<int>& fruits)
    {
        int left { 0 }, max { 0 };
        std::unordered_map<int, int> m_val_last_idx;
        int i { 0 };
        for (; i < fruits.size(); ++i) {
            if (m_val_last_idx.size() == 2) {
                if (!m_val_last_idx.contains(fruits[i])) {
                    max = std::max(max, i - left);

                    std::erase_if(m_val_last_idx, [&](auto& val) {
                        if (std::get<0>(val) != fruits[i - 1]) {
                            left = std::get<1>(val) + 1;
                            return true;
                        }
                        return false;
                    });
                }
            }
            m_val_last_idx[fruits[i]] = i;
        }
        max = std::max(max, i - left);
        return max;
    }
};
