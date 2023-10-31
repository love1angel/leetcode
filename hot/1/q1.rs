impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut ret: Vec<i32> = Vec::new();
        for i in 0..nums.len() {
            for j in i + 1..nums.len() {
                if target == nums[i] + nums[j] {
                    ret.push(i as i32);
                    ret.push(j as i32);
                    break;
                }
            }
        }
        ret
    }
}
