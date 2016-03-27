/*
   Write a function to find the longest common prefix string amongst an array of strings.
   */

#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
  //std::string longestCommonPrefix(std::vector<std::string> &strs) {
  std::string longestCommonPrefix(std::vector<std::string> strs) {
    if (strs.empty()) {
      return "";
    }

    std::size_t i;
    for (i = 0; is_valid(strs, i); ++i) {
    }

    return std::string(strs.front().begin(), strs.front().begin() + i);
  }

  bool is_valid(const std::vector<std::string> &strs, std::size_t pos) {
    if (pos >= strs.front().size()) {
      return false;
    }
    char c = strs.front().at(pos);
    return std::all_of(strs.begin(), strs.end(),
                       [pos, c](const std::string &s) {
                         return pos < s.size() && s[pos] == c;
                       });
  }
};

int main() {
  assert("a" == Solution().longestCommonPrefix({"a", "ab"}));
  std::cout << Solution().longestCommonPrefix({""});
  std::cout << Solution().longestCommonPrefix({"abb", "ab", "abc"});
  std::cout << Solution().longestCommonPrefix({""});

  return 0;
}
