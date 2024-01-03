class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        std::vector<int> ret {};
        ret.resize(nums.size());

        int last = nums.size() - 1;
        int left = 1, right = nums.size() - 1;

        int now = nums[0] * nums[0];
        bool compare_right = true;

        while (left <= right) {
            if (compare_right) {
                int ths = nums[right] * nums[right];
                --right;
                if (now <= ths) {
                    ret[last--] = ths;
                } else {
                    ret[last--] = now;
                    now = ths;
                    compare_right = false;
                }
            } else {
                int ths = nums[left] * nums[left];
                ++left;
                if (now <= ths) {
                    ret[last--] = ths;
                } else {
                    ret[last--] = now;
                    now = ths;
                    compare_right = true;
                }
            }
        }

        ret[0] = now;
        return ret;
    }
};
