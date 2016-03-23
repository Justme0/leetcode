/*
   Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.

Subscribe to see which companies asked this question

Hide Tags Array Two Pointers
Hide Similar Problems (H) Trapping Rain Water
*/

#include <cassert>
#include <vector>
#include <algorithm>

class Solution {
  struct Point {
    int x = 0;
    int y = 0;

    Point() {}

    Point(int x_, int y_) : x(x_), y(y_) {}
  };

public:
  // BF(O(n^2)) is TLE
  int maxArea(std::vector<int>& height) {
    if (height.empty() || height.size() == 1) {
      return 0;
    }

    int max_area = 0;
    int left = 0;
    int right = height.size() - 1;
    while (left < right) {
      max_area = std::max(max_area,
                          metric(Point(left, height[left]), Point(right, height[right])));
      // OPTIMIZE: slide far more and reduce area computation
      height[left] < height[right] ? ++left : --right;
    }

    return max_area;
  }

  static int metric(const Point &left, const Point &right) {
    return (right.x - left.x) * std::min(left.y, right.y);
  }
};

int main() {
  std::vector<int> v;
  v = {1, 0};
  assert(0 == Solution().maxArea(v));
  v = {1, 2, 8};
  assert(2 == Solution().maxArea(v));

  return 0;
}
