#include <iostream>
#include <vector>
#include <set>
#include <cassert>
#include <string>

class Solution {
    public:
        std::vector<std::string> cellsInRange(std::string s) {
            char c1 = s[0];
            char r1 = s[1];
            char c2 = s[3];
            char r2 = s[4];

            std::vector<std::string> ret;

            for (char j = c1; j <= c2; ++j) {
                for (char i = r1; i <= r2; ++i) {
                    ret.push_back(std::string() + j + i);
                }
            }

            return ret;
        }
};
