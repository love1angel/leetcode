class Solution {
public:
    bool backspaceCompare(string s, string t)
    {
        int i { static_cast<int>(s.size()) - 1 }, i_skip { 0 };
        int j { static_cast<int>(t.size()) - 1 }, j_skip { 0 };

        while (i >= 0 || j >= 0) {
            handle(s, i, i_skip);
            handle(t, j, j_skip);

            if (i < 0 && j < 0) {
                return true;
            } else if (i < 0 || j < 0) {
                return false;
            } else {
                if (s[i] != t[j]) {
                    return false;
                }
                --i, --j;
            }
        }

        return true;
    }

private:
    void handle(const std::string& str, int& iterator, int& stack)
    {
        while (iterator >= 0) {
            if (str[iterator] == '#') {
                ++stack;
                --iterator;
            } else if (stack) {
                --stack;
                --iterator;
            } else {
                break;
            }
        }
    }
};
