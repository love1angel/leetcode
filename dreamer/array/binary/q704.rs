impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        let (mut beg, mut end) = (0, nums.len());
        while beg < end {
            let mid = beg + (end - beg) / 2;
            match target.cmp(&nums[mid]) {
                std::cmp::Ordering::Less => end = mid,
                std::cmp::Ordering::Greater => beg = mid + 1,
                std::cmp::Ordering::Equal => return mid as i32,
            }
        }
        -1
    }
}
