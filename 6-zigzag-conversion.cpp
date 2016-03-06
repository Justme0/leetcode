/*
   The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

   P   A   H   N
   A P L S I I G
   Y   I   R
   And then read line by line: "PAHNAPLSIIGYIR"
   Write the code that will take a string and make this conversion given a number of rows:

   string convert(string text, int nRows);
   convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
   */

// other solution O(n): http://www.cnblogs.com/TenosDoIt/p/3738693.html

#include <string>
#include <cassert>
#include <vector>

class Solution {
public:
  std::string convert(std::string s, int numRows) {
    if (1 == numRows) {
      return s;
    }

    std::vector<std::string> m(numRows, std::string(s.size() / 2 + 1, '\0'));
    bool is_down = true;
    int row = 0;
    int col = 0;
    for (std::string::size_type i = 0; i < s.size(); ++i) {
      m[row][col] = s[i];
      int num = i % (2 * (numRows - 1));
      is_down = 0 <= num && num <= numRows - 2;
      if (is_down) {
        ++row;
      } else {
        --row;
        ++col;
      }
    }

    std::string ret;
    for (const std::string &s : m) {
      for (char c : s) {
        if (c != '\0') {
          ret.push_back(c);
        }
      }
    }
    return ret;
  }
};

int main() {
  assert("PAHNAPLSIIGYIR" == Solution().convert("PAYPALISHIRING", 3));
  assert("a" == Solution().convert("a", 1));

  return 0;
}
