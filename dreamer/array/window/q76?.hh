class Solution {
public:
    string minWindow(string s, string t)
    {
        int min_len { std::numeric_limits<int>::max() }, min_l { 0 }, min_r { 0 };
        std::unordered_map<char, int> fixed;
        for (char ch : t) {
            addChar(fixed, ch);
        }

        std::unordered_map<char, int> ths;
        for (int left { 0 }, right { 0 }; right < s.size(); ++right) {
            addChar(ths, s[right]);
            while (larger(ths, fixed)) {
                if (min_len > right - left + 1) {
                    min_len = right - left + 1;
                    min_l = left;
                    min_r = right;
                }
                removeChar(ths, s[left]);
                ++left;
            }
        }

        if (min_len == std::numeric_limits<int>::max())
            return {};
        return s.substr(min_l, min_len);
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
