//
// Created by Helianthus Xie on 2022/7/20.
//

#ifndef LEETCODE_Q50_HH
#define LEETCODE_Q50_HH

class Solution {
public:
    char firstUniqChar(string s)
    {
        int bitMap[26] = {0};

        for (char ch: s) {
            ++bitMap[ch - 'a'];
            m_list.push_back(ch);
        }

        for (auto ch: m_list) {
            if (bitMap[ch - 'a'] == 1)
                return ch;
        }

        return ' ';
    }

private:
    std::deque<char> m_list;
};

#endif //LEETCODE_Q50_HH
