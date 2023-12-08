#pragma once

class Solution {
public:
    string reverseWords(string s)
    {
        trim(s);

        int start = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                reverse(s, start, i);
                start = i + 1;
            }
        }
        reverse(s, start, s.size());

        reverse(s, 0, s.size());
        return s;
    }

    void reverse(std::string& s, int start, int end)
    {
        for (int i = 0; i < (end - start) / 2; ++i) {
            std::swap(s[start + i], s[end - 1 - i]);
        }
    }

    void trim(std::string& s)
    {
        int i = 0;
        for (; i < s.size() && s[i] == ' '; ++i)
            ;

        if (i == s.size()) {
            s.resize(0);
            return;
        }

        int cnt = 0;
        while (i < s.size() && s[i] != ' ') {
            s[cnt++] = s[i++];
        }

        while (i < s.size()) {
            for (; i < s.size() && s[i] == ' '; ++i)
                ;
            if (i == s.size()) {
                s.resize(cnt);
                return;
            }
            s[cnt++] = ' ';
            while (i < s.size() && s[i] != ' ') {
                s[cnt++] = s[i++];
            }
        }
        s.resize(cnt);
    }
};
