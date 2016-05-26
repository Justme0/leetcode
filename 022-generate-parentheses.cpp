/*
   Given n pairs of parentheses, write a function to generate all combinations
   of well-formed parentheses.

   For example, given n = 3, a solution set is:

   "((()))", "(()())", "(())()", "()(())", "()()()"
   */

#include <iostream>
#include <string>
#include <vector>

class Solution {
private:
  std::vector<std::string> strs_;
  size_t s_size_;

public:
  // take no account of validity, number of all permutation is (2n)!/(n!)^2;
  // Catalan number is (2n)!/(n+1)!n!
  std::vector<std::string> generateParenthesis(int n) {
    s_size_ = n * 2;
    aux_gen_prs_("", 0);
    return strs_;
  }

private:
  void aux_gen_prs_(std::string s, size_t left_num) {
    if (left_num * 2 > s_size_) {
      return;
    }
    size_t right_num = s.size() - left_num;
    if (left_num < right_num) {
      return;
    }
    if (s.size() == s_size_) {
      strs_.push_back(s);
      return;
    }

    aux_gen_prs_(s + '(', left_num + 1);
    aux_gen_prs_(s + ')', left_num);
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
