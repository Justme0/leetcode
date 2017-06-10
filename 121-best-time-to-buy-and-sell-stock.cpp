/*
Say you have an array for which the ith element is the price of a given stock on
day i.

If you were only permitted to complete at most one transaction (ie, buy one and
sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than
buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.
*/

#include <iostream>
#include <cassert>
#include <vector>
#include <climits>

/// If the current price is sold, find the minimum price before current time.
class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    int min_price = INT_MAX;
    int max_diff = 0;
    for (int price : prices) {
      if (price < min_price) {
        min_price = price;
      }

      int diff = price - min_price;
      if (diff > max_diff) {
        max_diff = diff;
      }
    }

    return max_diff;
  }
};

int main() {
  std::vector<int> v{7, 1, 5, 3, 6, 4};
  assert(5 == Solution().maxProfit(v));
  assert(0 == Solution().maxProfit(v = {7, 6, 4, 3, 1}));

  return 0;
}
