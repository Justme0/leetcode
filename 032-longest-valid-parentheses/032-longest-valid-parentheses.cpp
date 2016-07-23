/*
https://leetcode.com/problems/longest-valid-parentheses/

Given a string containing just the characters '(' and ')', find the length of
the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length =
2.

Another example is ")()())", where the longest valid parentheses substring is
"()()", which has length = 4.
*/

#include <cassert>
#include <cstdio>
#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
  int longestValidParentheses(std::string s) {
    std::stack<std::string::iterator> stk; // only store the index of '('
    std::string::iterator before_first = s.begin() - 1;
    int len = 0;

    for (auto i = s.begin(); i != s.end(); ++i) {
      if (*i == '(') {
        stk.push(i);
      } else {
        if (stk.empty()) {
          before_first = i;
        } else {
          // matched
          stk.pop();
          int new_len = i - (stk.empty() ? before_first : stk.top());
          len = std::max(len, new_len);
        }
      }
    }

    return len;
  }
};

void test(int expected, const char *str) {
  printf("Test \"%s\"...\n", str);
  int res = Solution().longestValidParentheses(str);
  if (expected != res) {
    printf("Test result of \"%s\" is %d, but expect %d.\n", str, res, expected);
    exit(1);
  }
  printf("OK\n");
}

int main() {
  test(2, "(()");
  test(2, "()(()");
  test(4, "(())(()");
  test(4, "(())");
  test(4, "()()");
  test(8, "(())(())");
  test(0, "");
  test(0, "(");
  test(0, "((");
  test(2, "(()");
  test(4, ")()())");
  test(6, ")(()())");
  test(4, ")()())()()(");

  return 0;
}
