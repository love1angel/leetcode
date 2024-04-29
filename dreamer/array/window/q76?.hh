class Solution {
public:
    string minWindow(string s, string t)
    {
        std::unordered_map<char, int> cnt;
        for (auto ch : t)
            ++cnt[ch];

        int left { 0 }, min_left { 0 }, min_len { std::numeric_limits<int>::max() };
        std::unordered_map<char, int> cur;
        for (int i { 0 }; i < s.size(); ++i) {
            ++cur[s[i]];
            while (larger(cur, cnt)) {
                if (int len { i - left + 1 }; len < min_len) {
                    min_left = left;
                    min_len = len;
                }

                if (int tmp { cur[s[left]] }; tmp == 1)
                    cur.erase(s[left]);
                else
                    --cur[s[left]];
                ++left;
            }
        }

        if (min_len == std::numeric_limits<int>::max())
            return {};
        return s.substr(min_left, min_len);
    }

private:
    bool larger(const std::unordered_map<char, int>& cur, const std::unordered_map<char, int>& cnt)
    {
        for (auto [ch, cnt] : cnt) {
            if (!cur.contains(ch) || cur.at(ch) < cnt) {
                return false;
            }
        }
        return true;
    }
};
