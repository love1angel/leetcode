class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int ths {}, sum { std::numeric_limits<int>::min() };
        for (auto num : nums) {
            ths = std::max(num, ths + num);
            sum = std::max(ths, sum);
        }
        return sum;
    }
};

class Solution {
    struct Status {
        int LSum, RSum, iSum, MSum;
    };

public:
    int maxSubArray(vector<int>& nums)
    {
        return this->get(nums, 0, nums.size() - 1).MSum;
    }

private:
    Status get(const std::vector<int>& nums, int left, int right)
    {
        if (left == right)
            return { nums[left], nums[left], nums[left], nums[left] };
        int mid = left + ((right - left) >> 1);
        auto l = this->get(nums, left, mid);
        auto r = this->get(nums, mid + 1, right);

        return this->pushUp(l, r);
    }

    Status pushUp(const Status& l, const Status& r)
    {
        auto lsum = std::max(l.LSum, l.iSum + r.LSum);
        auto rsum = std::max(r.RSum, r.iSum + l.RSum);
        auto isum = l.iSum + r.iSum;
        return { lsum, rsum, isum, std::max(std::max(l.MSum, r.MSum), l.RSum + r.LSum) };
    }
};
