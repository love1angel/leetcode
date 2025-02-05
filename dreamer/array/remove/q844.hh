// https://leetcode.cn/problems/backspace-string-compare/description/

class Solution {
public:
    bool backspaceCompare(const std::string& s, const std::string& t)
    {
        auto s_ptr { static_cast<int>(s.size()) - 1 }, t_ptr { static_cast<int>(t.size()) - 1 };
        auto s_stack { 0 }, t_stack { 0 };

        while (s_ptr >= 0 || t_ptr >= 0) {
            Solution::handle(s, s_ptr, s_stack);
            Solution::handle(t, t_ptr, t_stack);

            if (s_ptr >= 0 && t_ptr >= 0) {
                if (s[s_ptr] != t[t_ptr]) {
                    return false;
                }
                --s_ptr, --t_ptr;
            } else if (s_ptr < 0 && t_ptr < 0) {
                return true;
            } else {
                return false;
            }
        }
        return true;
    }

private:
    static void handle(const std::string& s, int& offset, int& stack)
    {
        while (offset >= 0) {
            if (s[offset] == '#') {
                ++stack;
            } else if (stack == 0) {
                return;
            } else {
                --stack;
            }
            --offset;
        }
    }
};
