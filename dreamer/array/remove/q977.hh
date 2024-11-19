// https://leetcode.cn/problems/squares-of-a-sorted-array/description/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        std::vector<int> ret;
        ret.resize(nums.size());

        auto left { 1 }, right { static_cast<int>(nums.size()) - 1 };
        auto tmp = nums[0] * nums[0];
        auto cur { right };
        bool store_l { true };
        while (left <= right) {
            if (store_l) {
                calc_cmp(nums, right, tmp, store_l, ret, cur);
                --right;
            } else {
                calc_cmp(nums, left, tmp, store_l, ret, cur);
                ++left;
            }
        }
        ret[cur] = tmp;
        return ret;
    }

private:
    void calc_cmp(const std::vector<int>& nums, int& ptr, int& tmp, bool& flag, std::vector<int>& ret, int& cur)
    {
        auto value { nums[ptr] * nums[ptr] };
        if (value >= tmp) {
            ret[cur--] = value;
        } else {
            ret[cur--] = tmp;
            tmp = value;
            flag = !flag;
        }
    }
};
