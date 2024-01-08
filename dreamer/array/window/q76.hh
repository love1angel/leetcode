class Solution {
public:
    string minWindow(string s, string t)
    {
        int min = std::numeric_limits<int>::max(), min_l {}, min_r {};
        std::unordered_map<char, int> fixed;
        for (char ch : t) {
            addChar(fixed, ch);
        }

        std::unordered_map<char, int> ths;
        for (int left {}, right {}; right < s.size(); ++right) {
            addChar(ths, s[right]);
            while (larger(ths, fixed)) {
                if (min > right - left + 1) {
                    min = right - left + 1;
                    min_l = left;
                    min_r = right;
                }
                removeChar(ths, s[left]);
                ++left;
            }
        }

        if (min == std::numeric_limits<int>::max())
            return {};
        return s.substr(min_l, min);
    }

private:
    void addChar(std::unordered_map<char, int>& map, char ch)
    {
        if (map.count(ch))
            ++map[ch];
        else
            map.insert({ ch, 1 });
    }

    void removeChar(std::unordered_map<char, int>& map, char ch)
    {
        if (map.count(ch)) {
            --map[ch];
            if (map[ch] == 0) {
                map.erase(ch);
            }
        }
    }

    bool larger(const std::unordered_map<char, int>& cur, const std::unordered_map<char, int>& fixed)
    {
        if (cur.size() < fixed.size())
            return false;

        for (auto [ch, cnt] : fixed) {
            if (!cur.count(ch) || cur.at(ch) < cnt)
                return false;
        }
        return true;
    }
};
