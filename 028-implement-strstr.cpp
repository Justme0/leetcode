/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

#include <string>
#include <iostream>

class Solution {
public:
  int strStr(std::string haystack, std::string needle) {
    auto pos = haystack.find(needle);
    if (pos == std::string::npos) {
      return -1;
    }
    return pos;
  }
};

int main() {
  std::cout << Solution().strStr("Hello, world!", "world") << std::endl;
  std::cout << Solution().strStr("Hello, world!", "waorld") << std::endl;

  return 0;
}
