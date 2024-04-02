impl Solution {
    pub fn is_perfect_square(num: i32) -> bool {
        let (mut left, mut right) = (1, num / 2 + 1);
        while left <= right {
            let mid = left + (right - left) / 2;
            let squared: i64 = mid as i64 * mid as i64;
            match squared.cmp(&(num as i64)) {
                std::cmp::Ordering::Less => left = mid + 1,
                std::cmp::Ordering::Greater => right = mid - 1,
                std::cmp::Ordering::Equal => return true,
            }
        }
        false
    }
}
