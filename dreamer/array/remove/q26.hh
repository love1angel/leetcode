class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int current { 0 };

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[current]) {
                nums[++current] = nums[i];
            }
        }

        return current + 1;
    }
};
