impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        let (mut left, mut right) = (0, nums.len() - 1);
        while left <= right {
            let mid = left + ((right - left) >> 1);
            match target.cmp(&nums[mid]) {
                std::cmp::Ordering::Less => {
                    if mid == 0 {
                        return -1;
                    }
                    right = mid - 1;
                }
                std::cmp::Ordering::Greater => left = mid + 1,
                std::cmp::Ordering::Equal => return mid as i32,
            }
        }
        -1
    }
}
