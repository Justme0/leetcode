/*
   Determine whether an integer is a palindrome. Do this without extra space.

   click to show spoilers.

   Some hints:
   Could negative integers be palindromes? (ie, -1)

   If you are thinking of converting the integer to string, note the restriction of using extra space.

   You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

   There is a more generic way of solving this problem.
   */

#include <cassert>
#include <string>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#include <iterator>

class Solution {
public:
  bool isPalindrome(int x) {
    std::string s = std::to_string(x);
    std::string rev_s;
    std::reverse_copy(s.begin(), s.end(), std::back_inserter(rev_s));

    return s == rev_s;
  }
};

int main() {
  assert(Solution().isPalindrome(2));
  assert(!Solution().isPalindrome(-2));
  assert(Solution().isPalindrome(22));
  assert(Solution().isPalindrome(232));
  assert(!Solution().isPalindrome(INT_MAX));
  assert(!Solution().isPalindrome(INT_MIN));

  return 0;
}
