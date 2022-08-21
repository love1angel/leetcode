//
// Created by Helianthus Xie on 2022/8/21.
//

#ifndef LEETCODE_Q1455_HH
#define LEETCODE_Q1455_HH

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord)
    {
        int off_set = 0, off_max = searchWord.size(), word_cnt = 1;
        if (off_max == 1 && sentence[0] == ' ') return -1;

        bool flag = true;
        for (int i = 0; i < sentence.size(); ++i) {
            if (sentence[i] == ' ') {
                ++word_cnt;
                off_set = 0;
                flag = true;
                continue;
            } else if (flag) {
                if (sentence[i] == searchWord[off_set])
                    ++off_set;
                else
                    flag = false;
                if (off_set == off_max)
                    return word_cnt;
            }
        }
        return -1;
    }
};

#endif //LEETCODE_Q1455_HH
