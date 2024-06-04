class Solution {
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        std::array<int, 26> s_cnt {}, t_cnt {};
        for (int i { 0 }; i < s.size(); ++i) {
            ++s_cnt[s[i] - 'a'];
            ++t_cnt[t[i] - 'a'];
        }

        for (int i { 0 }; i < s_cnt.size(); ++i) {
            if (s_cnt[i] != t_cnt[i])
                return false;
        }
        return true;
    }
};
