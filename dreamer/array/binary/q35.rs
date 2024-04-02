impl Solution {
    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        let (mut beg, mut end) = (0, nums.len());
        while beg < end {
            let mid = beg + (end - beg) / 2;
            match nums[mid].cmp(&target) {
                std::cmp::Ordering::Less => beg = mid + 1,
                std::cmp::Ordering::Greater => end = mid,
                std::cmp::Ordering::Equal => return mid as i32,
            }
        }
        beg as i32
    }
}
