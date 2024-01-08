class Solution {
public:
    int totalFruit(vector<int>& fruits)
    {
        int max = 0;
        std::set<int> have;

        for (int left {}, right {}; right < fruits.size(); ++right) {
            if (have.count(fruits[right])) {
                max = std::max(max, right - left + 1);
            } else {
                if (have.size() == 2) {
                    int target = fruits[left = right - 1];
                    do {
                        --left;
                    } while (fruits[left] == target);
                    have.erase(fruits[left++]);
                    have.insert(fruits[right]);
                } else {
                    have.insert(fruits[right]);
                    max = std::max(max, right - left + 1);
                }
            }
        }

        return max;
    }
};
