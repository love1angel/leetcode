impl Solution {
    pub fn move_zeroes(nums: &mut Vec<i32>) {
        let mut len = 0;
        for i in 0..nums.len() {
            if nums[i] != 0 {
                (nums[i], nums[len]) = (nums[len], nums[i]);
                len = len + 1;
            }
        }
    }
}
