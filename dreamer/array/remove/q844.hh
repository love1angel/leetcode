#pragma once

class Solution {
public:
    bool backspaceCompare(string s, string t)
    {
        int left = replace(s), right = replace(t);
        if (left == right) {
            for (int i = 0; i < left; ++i) {
                if (s[i] != t[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    int replace(std::string& s)
    {
        int slow = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '#') {
                --slow;
                if (slow < 0) {
                    slow = 0;
                }
            } else {
                s[slow++] = s[i];
            }
        }
        return slow;
    }
};
