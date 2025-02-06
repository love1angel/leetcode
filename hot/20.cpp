// https://leetcode.cn/problems/valid-parentheses/description/

class Solution {
public:
    bool isValid(const std::string& s)
    {
        std::stack<char> st;

        std::unordered_set<char> lhs_set { '(', '[', '{' };

        constexpr auto is_match = [](const char lhs, const char rhs) {
            if (lhs == '(' && rhs == ')') {
                return true;
            } else if (lhs == '[' && rhs == ']') {
                return true;
            } else if (lhs == '{' && rhs == '}') {
                return true;
            }
            return false;
        };

        for (auto c : s) {
            if (lhs_set.contains(c)) {
                st.push(c);
            } else if (st.empty() || !is_match(st.top(), c)) {
                return false;
            } else {
                st.pop();
            }
        }
        return st.empty();
    }
};
