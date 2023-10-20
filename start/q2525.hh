#pragma once

#include <string>

using std::string;

class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass)
    {
        bool isBulky = length >= 10000 || width >= 10000 || height >= 10000 || (long)length * width * height >= 1000000000,
             isHeavy = mass >= 100;
        return (isBulky && isHeavy) ? "Both" : (isBulky ? "Bulky" : (isHeavy ? "Heavy" : "Neither"));
    }
};
