// https://leetcode.cn/problems/backspace-string-compare/description/

class Solution {
public:
    bool backspaceCompare(string s, string t)
    {
        auto l_cnt { 0 }, r_cnt { 0 };
        auto l_ptr { static_cast<int>(s.size()) - 1 }, r_ptr { static_cast<int>(t.size()) - 1 };

        while (l_ptr >= 0 || r_ptr >= 0) {
            this->handle(s, l_ptr, l_cnt);
            this->handle(t, r_ptr, r_cnt);

            if (l_ptr >= 0 && r_ptr >= 0) {
                if (s[l_ptr] != t[r_ptr]) {
                    return false;
                }
                --l_ptr, --r_ptr;
            } else if (l_ptr < 0 && r_ptr < 0) {
                return true;
            } else {
                return false;
            }
        }

        if (l_ptr >= 0 || r_ptr >= 0) {
            return false;
        }
        return true;
    }

private:
    void handle(const std::string& str, int& ptr, int& cnt)
    {
        while (ptr >= 0) {
            if (str[ptr] == '#') {
                ++cnt;
            } else if (cnt) {
                --cnt;
            } else {
                return;
            }
            --ptr;
        }
    }
};
