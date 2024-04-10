impl Solution {
    pub fn search_range(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let (mut left, mut right) = (0, (nums.len() - 1) as i32);
        let mut mid = right >> 1;

        while left <= right {
            match nums[mid as usize].cmp(&target) {
                std::cmp::Ordering::Less => left = mid + 1,
                std::cmp::Ordering::Greater => right = mid - 1,
                std::cmp::Ordering::Equal => break,
            }
            mid = left + ((right - left) >> 1);
        }
        if left > right {
            return vec![-1, -1];
        } else {
            return vec![
                Solution::search_left(&nums, left, mid - 1, target),
                Solution::search_right(&nums, mid + 1, right, target),
            ];
        }
    }

    fn search_left(nums: &Vec<i32>, mut left: i32, mut right: i32, target: i32) -> i32 {
        while left <= right {
            let mid = left + ((right - left) >> 1);
            if nums[mid as usize] < target {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        left
    }

    fn search_right(nums: &Vec<i32>, mut left: i32, mut right: i32, target: i32) -> i32 {
        while left <= right {
            let mid = left + ((right - left) >> 1);
            if nums[mid as usize] > target {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        right
    }
}
