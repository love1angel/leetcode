class Solution {
public:
    bool backspaceCompare(string s, string t)
    {
        return build(s) == build(t);
    }

private:
    std::string build(const std::string& s)
    {
        std::string ret;
        for (auto ch : s) {
            if (ch != '#')
                ret.push_back(ch);
            else if (!ret.empty())
                ret.pop_back();
        }
        return ret;
    }
};

class Solution {
public:
    bool backspaceCompare(string s, string t)
    {
        int i = s.size() - 1, j = t.size() - 1;
        int i_skip { 0 }, j_skip { 0 };

        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                if (s[i] == '#')
                    ++i_skip, --i;
                else if (i_skip > 0)
                    --i_skip, --i;
                else
                    break;
            }

            while (j >= 0) {
                if (t[j] == '#')
                    ++j_skip, --j;
                else if (j_skip > 0)
                    --j_skip, --j;
                else
                    break;
            }

            if (i < 0 && j < 0)
                return true;
            else if (i < 0 || j < 0)
                return false;
            else {
                if (s[i] != t[j])
                    return false;
                else
                    --i, --j;
            }
        }
        return true;
    }
};
