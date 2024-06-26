class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        std::vector<int> ret {};
        ret.resize(nums.size());

        int tmp { nums[0] * nums[0] };
        int left { 0 }, right { static_cast<int>(nums.size()) - 1 }, cur { right };
        bool stored_left { true };

        while (left <= right) {
            if (stored_left) {
                int ths { nums[right] * nums[right] };
                if (ths >= tmp) {
                    ret[cur--] = ths;
                    --right;
                } else {
                    ret[cur--] = tmp;
                    ++left;
                    tmp = ths;
                    stored_left = false;
                }
            } else {
                int ths { nums[left] * nums[left] };
                if (ths >= tmp) {
                    ret[cur--] = ths;
                    ++left;
                } else {
                    ret[cur--] = tmp;
                    --right;
                    tmp = ths;
                    stored_left = true;
                }
            }
        }

        return ret;
    }
};
