#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>

class Solution {
public:
  int minDistance(std::string word1, std::string word2) {
    int dp[1001][1001];
    int len1 = word1.size();
    int len2 = word2.size();

    for (int i = 0; i <= std::max(len1,len2); i++) {
      dp[i][0] = i;
      dp[0][i] = i;
    }

    for (int i=1; i<=len1; i++) {
      for (int j=1; j<=len2; j++) {
        if (word1[i-1]==word2[j-1]) {
          dp[i][j]=dp[i-1][j-1];//不需操作
        } else {
          dp[i][j]=std::min(dp[i][j-1]+1,
                            std::min(dp[i-1][j]+1,dp[i-1][j-1]+1));
        }
      }
    }

    return dp[len1][len2];
  }
};

int main()
{
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

  std::cout << "OK" << std::endl;

  return 0;
}
