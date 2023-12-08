#pragma once

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        std::vector<std::vector<std::string>> ret { { strs[0] } };
        std::vector<std::vector<int>> map {};

        for (int i = 0; i < strs.size(); ++i) {
            std::vector<int> current(26, 0);
            for (auto ch : strs[i]) {
                ++current[ch - 'a'];
            }

            bool all_flag = true;
            for (int j = 0; j < map.size(); ++j) {
                bool this_flag = true;
                for (int k = 0; k < 26; ++k) {
                    if (map[j][k] != current[k]) {
                        this_flag = false;
                        break;
                    }
                }
                if (this_flag) {
                    ret[j].push_back(strs[i]);
                    all_flag = false;
                    break;
                }
            }
            if (all_flag) {
                ret.push_back({ strs[i] });
                map.push_back(current);
            }
        }

        return ret;
    }
};
