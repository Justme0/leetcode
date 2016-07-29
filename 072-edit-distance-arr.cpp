#include <algorithm>
#include <cassert>
#include <iostream>
#include <memory>
#include <string>

class Solution {
private:
  int minimum(int a, int b, int c) {
    return std::min(a, std::min(b, c));
  }

public:
  int minDistance(std::string word1, std::string word2) {
    int dp[1001][1001];
    int len1 = word1.size();
    int len2 = word2.size();

    for (int i = 0; i <= std::max(len1, len2); i++) {
      dp[i][0] = i;
      dp[0][i] = i;
    }

    for (int i = 1; i <= len1; i++) {
      for (int j = 1; j <= len2; j++) {
        if (word1[i - 1] == word2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = 1 + minimum(dp[i][j - 1],
                                 dp[i - 1][j],
                                 dp[i - 1][j - 1]);
        }
      }
    }

    return dp[len1][len2];
  }

  unsigned ComputeEditDistance(std::string FromArray, std::string ToArray,
                               bool AllowReplacements = true,
                               unsigned MaxEditDistance = 0) {
    // The algorithm implemented below is the "classic"
    // dynamic-programming algorithm for computing the Levenshtein
    // distance, which is described here:
    //
    //   http://en.wikipedia.org/wiki/Levenshtein_distance
    //
    // Although the algorithm is typically described using an m x n
    // array, only one row plus one element are used at a time, so this
    // implementation just keeps one vector for the row.  To update one entry,
    // only the entries to the left, top, and top-left are needed.  The left
    // entry is in Row[x-1], the top entry is what's in Row[x] from the last
    // iteration, and the top-left entry is stored in Previous.
    std::string::size_type m = FromArray.size();
    std::string::size_type n = ToArray.size();

    const unsigned SmallBufferSize = 64;
    // 2016.7.29 jiangg
    // Buffer should be initialized explictly, otherwise if the given two
    // strings are both empty, result will be random.
    unsigned SmallBuffer[SmallBufferSize] = {0};
    std::unique_ptr<unsigned[]> Allocated;
    unsigned *Row = SmallBuffer;
    if (n + 1 > SmallBufferSize) {
      Row = new unsigned[n + 1];
      Allocated.reset(Row);
    }

    for (unsigned i = 1; i <= n; ++i)
      Row[i] = i;

    for (std::string::size_type y = 1; y <= m; ++y) {
      Row[0] = y;
      unsigned BestThisRow = Row[0];

      unsigned Previous = y - 1;
      for (std::string::size_type x = 1; x <= n; ++x) {
        int OldRow = Row[x];
        if (AllowReplacements) {
          Row[x] = std::min(Previous +
                                (FromArray[y - 1] == ToArray[x - 1] ? 0u : 1u),
                            std::min(Row[x - 1], Row[x]) + 1);
        } else {
          if (FromArray[y - 1] == ToArray[x - 1])
            Row[x] = Previous;
          else
            Row[x] = std::min(Row[x - 1], Row[x]) + 1;
        }
        Previous = OldRow;
        BestThisRow = std::min(BestThisRow, Row[x]);
      }

      if (MaxEditDistance && BestThisRow > MaxEditDistance)
        return MaxEditDistance + 1;
    }

    unsigned Result = Row[n];
    return Result;
  }
};

int main() {
  assert(0 == Solution().minDistance("", ""));
  assert(1 == Solution().minDistance("a", "ac"));
  assert(0 == Solution().minDistance("a", "a"));
  assert(1 == Solution().minDistance("", "a"));
  assert(1 == Solution().minDistance("a", ""));
  assert(1 == Solution().minDistance("c", ""));
  assert(1 == Solution().minDistance("a", "b"));
  assert(1 == Solution().minDistance("aa", "a"));
  assert(1 == Solution().minDistance("aba", "aaa"));
  assert(1 == Solution().minDistance("aba", "acba"));
  assert(2 == Solution().minDistance("abbba", "acba"));
  assert(2 == Solution().minDistance("", "ac"));
  assert(2 == Solution().minDistance("ac", ""));
  assert(3 == Solution().minDistance("teacher", "poached"));

  assert(0 == Solution().ComputeEditDistance("", ""));
  assert(1 == Solution().ComputeEditDistance("a", "ac"));
  assert(0 == Solution().ComputeEditDistance("a", "a"));
  assert(1 == Solution().ComputeEditDistance("", "a"));
  assert(1 == Solution().ComputeEditDistance("a", ""));
  assert(1 == Solution().ComputeEditDistance("c", ""));
  assert(1 == Solution().ComputeEditDistance("a", "b"));
  assert(1 == Solution().ComputeEditDistance("aa", "a"));
  assert(1 == Solution().ComputeEditDistance("aba", "aaa"));
  assert(1 == Solution().ComputeEditDistance("aba", "acba"));
  assert(2 == Solution().ComputeEditDistance("abbba", "acba"));
  assert(2 == Solution().ComputeEditDistance("", "ac"));
  assert(2 == Solution().ComputeEditDistance("ac", ""));
  assert(3 == Solution().ComputeEditDistance("teacher", "poached"));

  std::cout << "OK" << std::endl;

  return 0;
}
