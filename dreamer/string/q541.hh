#pragma once

class Solution {
public:
    string reverseStr(string s, int k)
    {
        string::size_type start = 0, end = 2 * k;
        do {
            if (end >= s.size()) {
                end = s.size();
            }

            if (end - start >= k) {
                reverse(s, start, start + k);
            } else {
                reverse(s, start, end);
            }

            start += 2 * k;
            end += 2 * k;
        } while (start < s.size());
        return s;
    }

private:
    void reverse(std::string& s, string::size_type start, string::size_type end)
    {
        for (int i = 0; i < (end - start) / 2; ++i) {
            std::swap(s[start + i], s[end - 1 - i]);
        }
    }
};
