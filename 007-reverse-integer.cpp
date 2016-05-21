/*
   Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

Update (2014-11-10):
Test cases had been added to test the overflow behavior.
*/

#include <cassert>
#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>

class Solution {
public:
  int reverse(int x) {
    std::string s = std::to_string(x >= 0 ? x : std::abs(x));
    std::reverse(s.begin(), s.end());
    int ret = 0;
    try {
      ret = std::stoi(s);
    } catch (const std::out_of_range &oor) {
      return 0;
    }
    if (x < 0) {
      ret = -ret;
    }
    return ret;
  }
};

template <class T, class U>
void assert_equal(const T &expected, const U &result) {
  if (expected == result) {
    std::cout << "Good!" << std::endl;
  } else {
    std::cout << "Expected is " << expected << ", but result is " << result << "." << std::endl;
    exit(3);
  }
}

int main() {
  assert_equal(1, Solution().reverse(1));
  assert_equal(-1, Solution().reverse(-1));
  assert_equal(-12, Solution().reverse(-21));
  assert_equal(12, Solution().reverse(21));
  assert_equal(0, Solution().reverse(1534236469));

  return 0;
}
