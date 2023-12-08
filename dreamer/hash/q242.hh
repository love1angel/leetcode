#pragma once

class Solution {
public:
    bool isAnagram(string s, string t)
    {
        int S[26] {}, T[26] {};
        for (auto ch : s) {
            S[ch - 'a'] = S[ch - 'a'] + 1;
        }

        for (auto ch : t) {
            T[ch - 'a'] = T[ch - 'a'] + 1;
        }

        for (int i = 0; i < 26; ++i) {
            if (S[i] != T[i]) {
                return false;
            }
        }
        return true;
    }
};
