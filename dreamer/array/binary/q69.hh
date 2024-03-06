class Solution {
public:
    int mySqrt(int x)
    {
        int left { 0 }, right { x / 2 + 1 }, mid { right / 2 };
        while (left <= right) {
            long long squared { (long long)mid * mid };
            if (squared < x)
                left = mid + 1;
            else if (squared > x)
                right = mid - 1;
            else
                return mid;
            mid = left + (right - left) / 2;
        }
        return right;
    }
};
