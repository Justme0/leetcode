/*
   Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

   For example, given n = 3, a solution set is:

   "((()))", "(()())", "(())()", "()(())", "()()()"
   */

#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <cassert>

class Solution {
public:
  // take no account of validity, number of all permutation is (2n)!/(n!)^2;
  // Catalan number is (2n)!/(n+1)!n!
  std::vector<std::string> generateParenthesis(int n) {
  }
};

template <class C>
void print(C c) {
  for (auto e : c) {
    std::cout << e << ' ';
  }
  std::cout << std::endl;
}

int main() {
  auto v = Solution().generateParenthesis(3);
  print(v);

  return 0;
}
