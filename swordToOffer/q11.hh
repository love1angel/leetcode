//
// Created by Helianthus Xie on 2022/7/20.
//

#ifndef LEETCODE_Q11_HH
#define LEETCODE_Q11_HH

class Solution {
public:
    int minArray(vector<int> &numbers)
    {
        int beg = 0, end = numbers.size() - 1;
        while (beg < end) {
            int mid = beg + (end - beg) / 2;
            if (numbers[mid] > numbers[end]) {
                beg = mid + 1;
            } else if (numbers[mid] < numbers[end]) {
                end = mid;
            } else {
                --end;
            }
        }
        return numbers[beg];
    }
};

#endif //LEETCODE_Q11_HH
