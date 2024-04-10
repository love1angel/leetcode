impl Solution {
    pub fn my_sqrt(x: i32) -> i32 {
        let (mut left, mut right) = (0, x / 2 + 1);
        while left <= right {
            let mid = left + ((right - left) >> 1);
            let squared: i64 = mid as i64 * mid as i64;
            match squared.cmp(&(x as i64)) {
                std::cmp::Ordering::Less => left = mid + 1,
                std::cmp::Ordering::Greater => right = mid - 1,
                std::cmp::Ordering::Equal => return mid,
            }
        }
        right
    }
}
