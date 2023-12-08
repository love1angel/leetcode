#pragma once

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int CH[26] {};

        for (auto ch : magazine) {
            CH[ch - 'a'] = ++CH[ch - 'a'];
        }

        for (auto ch : ransomNote) {
            CH[ch - 'a'] = --CH[ch - 'a'];
        }

        for (auto cnt : CH) {
            if (cnt < 0) {
                return false;
            }
        }

        return true;
    }
};
