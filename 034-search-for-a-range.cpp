/*
Given a sorted array of integers, find the starting and ending position of a
given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<int> searchRange(std::vector<int> nums, int target) {
    auto ret_pair = std::equal_range(nums.begin(), nums.end(), target);
    int first = static_cast<int>(ret_pair.first - nums.begin());
    int last = static_cast<int>(ret_pair.second - nums.begin());

    if (last - first == 0) {
      return {-1, -1};
    }
    return {first, last - 1};
  }
};

int main() {
  assert((Solution().searchRange({1}, 0) == std::vector<int>{-1, -1}));
  assert((Solution().searchRange({1}, 1) == std::vector<int>{0, 0}));

  return 0;
}
