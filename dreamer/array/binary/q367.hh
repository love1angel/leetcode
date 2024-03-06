class Solution {
public:
    bool isPerfectSquare(int num)
    {
        int left { 1 }, right { num / 2 + 1 }, mid = left + (right - left) / 2;

        while (left <= right) {
            long long squared { (long long)mid * mid };
            if (squared < num)
                left = mid + 1;
            else if (squared > num)
                right = mid - 1;
            else
                return true;
            mid = left + (right - left) / 2;
        }
        return false;
    }
};
