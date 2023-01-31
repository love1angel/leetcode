//
// Created by Helianthus Xie on 2022/7/20.
//

#ifndef LEETCODE_Q11_HH
#define LEETCODE_Q11_HH

#include <vector>

class Solution {
public:
    int minArray(std::vector<int>& numbers)
    {
        int first = 0, last = numbers.size() - 1;
        while (first < last) {
            auto mid = first + (last - first) / 2;
            if (numbers[mid] < numbers[last])
                last = mid;
            else if (numbers[mid] > numbers[last])
                first = mid + 1;
            else
                --last;
        }
        return numbers[first];
    }
};

#endif //LEETCODE_Q11_HH
