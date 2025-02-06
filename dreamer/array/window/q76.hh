// https://leetcode.cn/problems/minimum-window-substring/description/

class Solution {
public:
    std::string minWindow(const std::string& s, const std::string& t)
    {
        std::unordered_map<char, int> map;
        for (const auto& c : t) {
            Solution::push(map, c);
        }

        auto left { 0 }, min_len { std::numeric_limits<int>::max() }, min_left { 0 };
        std::unordered_map<char, int> ths;
        for (auto right { 0 }; right < s.size(); ++right) {
            ++ths[s[right]];
            while (Solution::cover(ths, map)) {
                if (const auto ths_len { right - left + 1 }; ths_len < min_len) {
                    min_left = left;
                    min_len = ths_len;
                }
                Solution::pop(ths, s[left]);
                ++left;
            }
        }
        return min_len == std::numeric_limits<int>::max() ? "" : s.substr(min_left, min_len);
    }

private:
    static void push(std::unordered_map<char, int>& map, char c)
    {
        ++map[c];
    }
    static void pop(std::unordered_map<char, int>& map, char c)
    {
        --map[c];
        if (map[c] == 0) {
            map.erase(c);
        }
    }
    static bool cover(const std::unordered_map<char, int>& lhs, const std::unordered_map<char, int>& rhs)
    {
        for (auto [ch, cnt] : rhs) {
            if (!lhs.contains(ch) || lhs.at(ch) < cnt) {
                return false;
            }
        }
        return true;
    }
};
