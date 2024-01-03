class Solution {
public:
    bool backspaceCompare(string s, string t)
    {
        int left = replace(s), right = replace(t);
        if (left != right)
            return false;
        for (int i = 0; i < left; ++i) {
            if (s[i] != t[i])
                return false;
        }
        return true;
    }

private:
    int replace(std::string& s)
    {
        int cur = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != '#')
                s[cur++] = s[i];
            else
                cur = std::max(0, cur - 1);
        }
        return cur;
    }
};
