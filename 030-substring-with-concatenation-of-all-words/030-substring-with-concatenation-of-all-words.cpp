#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> findSubstring(std::string s,
                                 std::vector<std::string> words) {
    std::vector<int> ret;
    if (words.empty()) {
      return ret;
    }

    std::unordered_map<std::string, int> hash;
    for (const std::string &str : words) {
      ++hash[str];
    }
    size_t len = words.front().length();
    size_t last =
        s.size() - words.size() * len + 1; // maybe benefit a lot for you!
    for (size_t i = 0; i < last; ++i) {
      size_t cnt = words.size();
      auto word_cnt = hash;
      size_t j = i;
      while (cnt != 0) {
        std::string word = s.substr(j, len);
        if (word_cnt[word] == 0) {
          break;
        } else {
          --word_cnt[word];
          --cnt;
          j += len;
        }
      }
      if (cnt == 0) {
        ret.push_back(i);
      }
    }

    return ret;
  }
};

int main() {}
