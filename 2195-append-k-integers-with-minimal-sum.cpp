
#include <iostream>
#include <vector>
#include <set>
#include <cassert>


class Solution {
    public:
        long long minimalKSum(std::vector<int>& nums, int k) {
            std::set<int> s(nums.begin(), nums.end());
            s.insert(0);
            assert(s.size() >= 2);
            int64_t ret = 0;
            int allInsertNum = 0;

            auto pre = s.begin();
            auto work = std::next(pre, 1);
            for (; work != s.end(); pre = work, ++work) {
                int subInsertNum = *work - *pre - 1; // opt: if 0
                int ifInsertNum = allInsertNum + subInsertNum;

                if (ifInsertNum >= k) {
                    subInsertNum -= (ifInsertNum - k);
                    allInsertNum = ifInsertNum;

                    int64_t subSum = ((*pre + 1) + (*pre + 1) + subInsertNum - 1) * subInsertNum / 2;
                    ret += subSum;
                    break;
                } else {
                    allInsertNum = ifInsertNum;

                    int64_t subSum = ((*pre + 1) + (*pre + 1) + subInsertNum - 1) * subInsertNum / 2;
                    ret += subSum;
                }
            }
            if (work == s.end()) {
                assert(allInsertNum < k);
                int subInsertNum = k - allInsertNum;

                int lastElem = *(--s.end());
                int64_t subSum = ((lastElem  + 1) + (lastElem + 1) + subInsertNum - 1) * subInsertNum / 2;
                ret += subSum;

            }

            return ret;
        }
};

int main() {


}
