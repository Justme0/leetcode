/*
   Given an integer, convert it to a roman numeral.

   Input is guaranteed to be within the range from 1 to 3999.
   */

#include <string>
#include <iostream>
#include <cassert>

class Solution {
public:
  std::string intToRoman(int num) {
    std::string ret;
    const char *chars = "IVXLCDM";
    int pos = 0; // position of weight
    do {
      int d = num % 10;
      num /= 10;
      if (d != 0) {
        ret = single(d, chars[pos], chars[pos + 1], chars[pos + 2]) + ret;
      }
      pos += 2;
    } while (num != 0);

    return ret;
  }

  std::string single(int n, char I, char V, char X) {
    switch (n) {
    case 1: return {I};
    case 2: return {I, I};
    case 3: return {I, I, I};
    case 4: return {I, V};
    case 5: return {V};
    case 6: return {V, I};
    case 7: return {V, I, I};
    case 8: return {V, I, I, I};
    case 9: return {I, X};

    default:
            assert(!"shit");
            break;
    }
  }
};

int main() {
  assert("M" == Solution().intToRoman(1000));
  assert("I" == Solution().intToRoman(1));
  assert("MCD" == Solution().intToRoman(1400));
  assert("MCDXXXVII" == Solution().intToRoman(1437));
  assert("MD" == Solution ().intToRoman(1500));
  assert("MDCCC" == Solution().intToRoman(1800));
  assert("MDCCCLXXX" == Solution().intToRoman(1880));
  assert("MCM" == Solution().intToRoman(1900));
  assert("MM" == Solution().intToRoman(2000));
  assert("MMM" == Solution().intToRoman(3000));
  assert("MMMCCCXXXIII" == Solution().intToRoman(3333));

  return 0;
}
