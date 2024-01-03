class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int before {};
        for (int cur = 1; cur < nums.size(); ++cur) {
            if (nums[cur] != nums[before]) {
                nums[++before] = nums[cur];
            }
        }
        return before + 1;
    }
};
