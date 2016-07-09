/*
https://leetcode.com/problems/longest-valid-parentheses/


Given a string containing just the characters '(' and ')', find the length of
the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length =
2.

Another example is ")()())", where the longest valid parentheses substring is
"()()", which has length = 4.
*/

#include <string>
#include <iostream>
#include <cassert>

class Solution {
public:
  int longestValidParentheses(std::string s) {}
};

int main() {
  assert(4 == Solution().longestValidParentheses(")()())"));
  assert(2 == Solution().longestValidParentheses("(()"));

  return 0;
}
