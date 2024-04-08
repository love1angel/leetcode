impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        let mut len = 0;

        for i in 0..nums.len() {
            if nums[i] != val {
                nums[len] = nums[i];
                len = len + 1;
            }
        }

        len as i32
    }
}

impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        let (mut i, mut j) = (0, nums.len() as i32 - 1);

        while i <= j {
            while i <= j && nums[i as usize] != val {
                i = i + 1;
            }
            while i <= j && nums[j as usize] == val {
                j = j - 1;
            }

            if i < j {
                (nums[i as usize], nums[j as usize]) = (nums[j as usize], nums[i as usize]);
                i = i + 1;
                j = j - 1;
            }
        }

        i
    }
}
