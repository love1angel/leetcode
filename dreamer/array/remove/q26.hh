class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int len { 1 };
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[len - 1]) {
                nums[len++] = nums[i];
            }
        }
        return len;
    }
};
