class Solution {
public:
    bool backspaceCompare(string s, string t)
    {
        int s_i { static_cast<int>(s.size()) - 1 }, t_i { static_cast<int>(t.size()) - 1 };
        int s_stack { 0 }, t_stack { 0 };

        while (s_i >= 0 || t_i >= 0) {
            handle(s, s_i, s_stack);
            handle(t, t_i, t_stack);

            if (s_i >= 0 && t_i >= 0) {
                if (s[s_i] != t[t_i]) {
                    return false;
                }
                --s_i, --t_i;
            } else if (s_i < 0 && t_i < 0) {
                return true;
            } else {
                return false;
            }
        }

        return true;
    }

private:
    void handle(const std::string& s, int& i, int& stack)
    {
        while (i >= 0) {
            if (s[i] == '#')
                ++stack;
            else if (stack)
                --stack;
            else
                return;
            --i;
        }
    }
};
