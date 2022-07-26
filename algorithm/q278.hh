//
// Created by Helianthus Xie on 2022/7/26.
//

#ifndef LEETCODE_Q278_HH
#define LEETCODE_Q278_HH

class Solution {
public:
    int firstBadVersion(int n)
    {
        int l = 1, r = n;
        bool flag_l = isBadVersion(l);
        if (flag_l)
            return l;
        bool flag_r = isBadVersion(r);
        if (!flag_r)
            return r;
        while (l < r) {
            auto m = l + (r - l) / 2;
            bool flag_m = isBadVersion(m);
            if (!flag_m) {
                l = m + 1;
                if (isBadVersion(l))
                    return l;
            } else {
                r = m;
            }
        }
        return r;
    }
};

#endif //LEETCODE_Q278_HH
