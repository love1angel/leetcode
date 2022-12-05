#ifndef LEETCODE_Q09_HH
#define LEETCODE_Q09_HH

#include <climits>
#include <string>

class Solution {
public:
    int secondHighest(std::string s)
    {
        char first = CHAR_MIN, second = CHAR_MIN;
        for (auto ch: s) {
            if (std::isdigit(ch)) {
                if (first < ch) {
                    second = first;
                    first = ch;
                } else if (first > ch) {
                    second = std::max(second, ch);
                }
            }
        }

        if (first != CHAR_MIN && second != CHAR_MIN) {
            return second - '0';
        }
        return -1;
    }
};

#endif
