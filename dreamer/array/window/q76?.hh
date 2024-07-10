class Solution {
public:
    string minWindow(string s, string t)
    {
        std::unordered_map<char, int> t_map;
        for (auto ch : t) {
            ++t_map[ch];
        }

        std::unordered_map<char, int> s_map;
        int left { 0 }, min_left { 0 }, min_len { std::numeric_limits<int>::max() };
        for (int i { 0 }; i < s.size(); ++i) {
            ++s_map[s[i]];
            while (cover(s_map, t_map)) {
                if (i - left + 1 < min_len) {
                    min_len = i - left + 1;
                    min_left = left;
                }
                if (s_map[s[left]] == 1)
                    s_map.erase(s[left]);
                else
                    --s_map[s[left]];
                ++left;
            }
        }
        return min_len == std::numeric_limits<int>::max() ? "" : s.substr(min_left, min_len);
    }

private:
    bool cover(const std::unordered_map<char, int>& lhs, const std::unordered_map<char, int>& rhs)
    {
        for (auto [ch, cnt] : rhs) {
            if (!lhs.contains(ch) || lhs.at(ch) < cnt) {
                return false;
            }
        }
        return true;
    }
};
