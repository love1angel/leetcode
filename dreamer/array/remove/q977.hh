// https://leetcode.cn/problems/squares-of-a-sorted-array/description/

class Solution {
public:
    std::vector<int> sortedSquares(const std::vector<int>& nums)
    {
        std::vector ret(nums.size(), 0);

        auto cur { static_cast<int>(nums.size()) - 1 };
        bool store_left { true };
        auto stored_value { nums[0] * nums[0] };
        auto left { 1 }, right { cur };

        while (left <= right) {
            if (store_left) {
                Solution::calc_cmp_store(nums, right, stored_value, store_left, ret, cur);
                --right;
            } else {
                Solution::calc_cmp_store(nums, left, stored_value, store_left, ret, cur);
                ++left;
            }
        }

        ret[cur] = stored_value;
        return ret;
    }

private:
    static void calc_cmp_store(const std::vector<int>& nums, int& cur, int& stored_value, bool& flag, std::vector<int>& ret, int& ret_cur)
    {
        auto new_value { nums[cur] * nums[cur] };
        if (new_value >= stored_value) {
            ret[ret_cur--] = new_value;
        } else {
            ret[ret_cur--] = stored_value;
            stored_value = new_value;
            flag = !flag;
        }
    }
};
