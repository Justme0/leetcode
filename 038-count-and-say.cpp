/*
   The count-and-say sequence is the sequence of integers beginning as follows:
   1, 11, 21, 1211, 111221, ...

   1 is read off as "one 1" or 11.
   11 is read off as "two 1s" or 21.
   21 is read off as "one 2, then one 1" or 1211.
   Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/

#include <string>
#include <iostream>

class Solution {
public:
  std::string countAndSay(int n) {
    std::string ret = "1";
    for (int i = 1; i < n; ++i) {
      ret = next(ret);
    }

    return ret;
  }

private:
  std::string next(const std::string &s) {
    std::string ret;

    for (size_t i = 0; i < s.size(); ) {
      size_t j = i + 1;
      for (; j < s.size() && s[j] == s[j-1]; ++j) {
      }
      unsigned cnt = j - i;
      char c = s[i];
      ret += std::to_string(cnt) + c;
      std::clog << "ret is " << ret << std::endl;
      i = j;
    }

    std::clog << "current iteration ends, ret is " << ret << std::endl;
    return ret;
  }
};

int main() {
  std::cout << Solution().countAndSay(5) << std::endl;

  return 0;
}
