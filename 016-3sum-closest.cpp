/*
   Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
   Return the sum of the three integers. You may assume that each input would have exactly one solution.

   For example, given array S = {-1 2 1 -4}, and target = 1.

   The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
   */

#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>

class Solution {
public:
  // Assume that each input would have exactly one solution.
  int threeSumClosest(std::vector<int> nums, int target) { // for test
    std::sort(nums.begin(), nums.end());
    int ret = nums[0] + nums[1] + nums[2];
    for (auto i = nums.begin(); i != nums.end() - 2; ++i) {
      auto low = 1 + i;
      auto high = nums.end() - 1;
      while (low < high) {
        int s = *low + *high + *i;
        if (s == target) {
          return target;
        }
        if (std::abs(target - s) < std::abs(target - ret)) {
          ret = s;
        }
        s > target ? --high : ++low;
      }
    }

    return ret;
  }

  //int threeSumClosest(std::vector<int>& nums, int target) {
  int threeSumClosestTrivial(std::vector<int> nums, int target) { // for test
    bool first = true;
    int ret = 0;
    for (auto i = nums.begin(); i != nums.end(); ++i) {
      for (auto j = i + 1; j != nums.end(); ++j) {
        for (auto k = j + 1; k != nums.end(); ++k) {
          int sum = *i + *j + *k;
          if (first) {
            ret = sum;
            first = false;
          } else {
            if (std::abs(sum - target) < std::abs(ret - target)) {
              //std::cout << *i << ' ' << *j << ' ' << *k << std::endl;
              ret = sum;
            }
          }
        }
      }
    }

    return ret;
  }
};

int main() {
  assert(2 == Solution().threeSumClosest({-1, 2, 1, -4}, 1));
  assert(0 == Solution().threeSumClosest({-1, 2, -1, -4}, 0));
  assert(-192 == Solution().threeSumClosest({-28,-74,55,1,-10,28,78,-39,-73,-89,-81,-73,77,-14,86,80,43,-60,56,-5,33,30,34,-11,-38,87,27,66,31,-58,14,30,56,21,-84,-9,58,-94,-75,-64,71,64,-43,67,42,-90,95,81,43,-61,61,9,-43,-77,6,29,-23,40,-56,-39,65,-20,82,-8,35,-16,-39,46,-27,98,-96,-43,87,85,57,5,18,79,-59,90,-56,-88,-64,42,89,58,66,2,-84,60,76,-60,-91,26,-59,-76,21,75,29,42,21,1,0,72,22,-57,97,92,88,1,-32,-26,73,-38,-83,86,-46,-58,-23,-28,-94,-77,-34,-42,-51,34,87,-36,27,27,-53,80,-66,-77,100,68,56,-15,-11,77,67,11,-37,79,20,5,51,-37,-55,38,85,-46,15,96,-50,55,49,-3,46,-48,-20,5,4,19,-22,12,96,-79,-51,70,-79,-51,-23,-45,-1,68,-11,-91,-49,75,0,10,45,39,96,-63,-100,-33,33,24,2,-89,-31,62,56,-84,-90,-84,-48,62,-65,83,4,-19,-25,39,67}, -192));

  assert(2 == Solution().threeSumClosestTrivial({-1, 2, 1, -4}, 1));
  assert(0 == Solution().threeSumClosestTrivial({-1, 2, -1, -4}, 0));
  assert(-192 == Solution().threeSumClosestTrivial({-28,-74,55,1,-10,28,78,-39,-73,-89,-81,-73,77,-14,86,80,43,-60,56,-5,33,30,34,-11,-38,87,27,66,31,-58,14,30,56,21,-84,-9,58,-94,-75,-64,71,64,-43,67,42,-90,95,81,43,-61,61,9,-43,-77,6,29,-23,40,-56,-39,65,-20,82,-8,35,-16,-39,46,-27,98,-96,-43,87,85,57,5,18,79,-59,90,-56,-88,-64,42,89,58,66,2,-84,60,76,-60,-91,26,-59,-76,21,75,29,42,21,1,0,72,22,-57,97,92,88,1,-32,-26,73,-38,-83,86,-46,-58,-23,-28,-94,-77,-34,-42,-51,34,87,-36,27,27,-53,80,-66,-77,100,68,56,-15,-11,77,67,11,-37,79,20,5,51,-37,-55,38,85,-46,15,96,-50,55,49,-3,46,-48,-20,5,4,19,-22,12,96,-79,-51,70,-79,-51,-23,-45,-1,68,-11,-91,-49,75,0,10,45,39,96,-63,-100,-33,33,24,2,-89,-31,62,56,-84,-90,-84,-48,62,-65,83,4,-19,-25,39,67}, -192));

  std::cout << "ok" << std::endl;

  return 0;
}
