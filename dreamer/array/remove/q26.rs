impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let mut current = 0;

        for i in 1..nums.len() {
            if nums[i] != nums[current as usize] {
                current = current + 1;
                nums[current as usize] = nums[i];
            }
        }

        current + 1
    }
}
