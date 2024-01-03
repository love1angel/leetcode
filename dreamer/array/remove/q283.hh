class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        int cnt {}, cur {};
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0)
                nums[cur++] = nums[i];
            else
                ++cnt;
        }
        for (int i = nums.size() - cnt; i < nums.size(); ++i) {
            nums[i] = 0;
        }
    }
};
