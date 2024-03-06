class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        std::vector<int> ret {};
        ret.resize(nums.size());

        int last = nums.size() - 1;
        int left { 1 }, right = nums.size() - 1;

        int now { nums[0] * nums[0] };
        bool compare_right { true };

        while (left <= right) {
            if (compare_right) {
                int ths { nums[right] * nums[right] };
                --right;
                if (now <= ths) {
                    ret[last--] = ths;
                } else {
                    ret[last--] = now;
                    now = ths;
                    compare_right = false;
                }
            } else {
                int ths { nums[left] * nums[left] };
                ++left;
                if (now <= ths) {
                    ret[last--] = ths;
                } else {
                    ret[last--] = now;
                    now = ths;
                    compare_right = true;
                }
            }
        }

        ret[0] = now;
        return ret;
    }
};

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        std::vector<int> ret {};
        ret.reserve(nums.size());

        int left { 0 }, right = nums.size() - 1;
        if (nums[left] >= 0) {
            for (auto num : nums) {
                ret.push_back(num * num);
            }
            return ret;
        } else if (nums[right] <= 0) {
            for (int i { right }; i >= 0; --i) {
                ret.push_back(nums[i] * nums[i]);
            }
            return ret;
        }

        int mid { right / 2 };
        while (right - left != 1) {
            if (nums[mid] < 0)
                left = mid;
            else if (nums[mid] > 0)
                right = mid;
            else {
                left = mid;
                right = mid + 1;
                break;
            }
            mid = left + (right - left) / 2;
        }

        bool left_leave = true;
        int tmp = nums[left] * nums[left];

        while (left >= 0 && right < nums.size()) {
            if (left_leave) {
                int right_ret { nums[right] * nums[right] };
                if (right_ret <= tmp) {
                    ret.push_back(right_ret);
                    ++right;
                } else {
                    ret.push_back(tmp);
                    --left;
                    left_leave = false;
                    tmp = right_ret;
                }
            } else {
                int left_ret { nums[left] * nums[left] };
                if (left_ret <= tmp) {
                    ret.push_back(left_ret);
                    --left;
                } else {
                    ret.push_back(tmp);
                    ++right;
                    left_leave = true;
                    tmp = left_ret;
                }
            }
        }

        while (left >= 0) {
            ret.push_back(nums[left] * nums[left]);
            --left;
        }

        while (right < nums.size()) {
            ret.push_back(nums[right] * nums[right]);
            ++right;
        }

        return ret;
    }
};
