/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index,
otherwise return -1.

You may assume no duplicate exists in the array.

Hide Tags Binary Search Array
*/

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <iostream>
#include <vector>

class Solution {
public:
  int search(std::vector<int> &nums, int target) {
    auto ret = search(nums.begin(), nums.end(), target);
    return ret == nums.end() ? -1 : ret - nums.begin();
  }

  template <class Iter>
  Iter search(Iter l, Iter h, int target) {
    if (h - l <= 4) {
      return std::find(l, h, target);
    }

    auto m = l + (h - l) / 2;
    if (*m < *l) {
      if (*m <= target && target <= *(h - 1)) {
        return search(m, h, target);
      } else {
        auto ret = search(l, m, target);
        return ret == m ? h : ret;
      }
    } else {
      if (*l <= target && target <= *m) {
        auto ret = search(l, m + 1, target);
        return ret == m + 1 ? h : ret;
      } else {
        return search(m + 1, h, target);
      }
    }
  }
};

int main() {
  std::vector<int> v{4, 5, 6, 7, 0, 1, 2};
  for (size_t i = 0; i < v.size(); ++i) {
    std::cout << "test " << v[i] << std::endl;
    assert(static_cast<int>(i) == Solution().search(v, v[i]));
  }
  assert(-1 == Solution().search(v, 22));
  std::cout << "Good.\n";

  return 0;
}
