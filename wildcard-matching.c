#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

bool **alloc(size_t row, size_t col) {
  bool **m = (bool **)calloc(row, sizeof(bool *));
  if (m == NULL) {
    exit(1);
  }
  for (size_t i = 0; i < row; ++i) {
    m[i] = (bool *)calloc(col, sizeof(bool));
    if (NULL == m[i]) {
      exit(1);
    }
  }
  return m;
}

void dealloc(bool **m, size_t row) {
  for (size_t i = 0; i < row; ++i) {
    free(m[i]);
  }
  free(m);
}

// bool isMatch(const char *s, const char *p) {
//   size_t s_size = strlen(s);
//   size_t p_size = strlen(p);
//   bool **dp = alloc(1 + s_size, 1 + p_size);
// }

bool isMatch(const char* s, const char* p) {
  if (*p == '\0') {
    return *s == '\0';
  }
  if (*s == '\0') {
    if (strcmp(p, "*") == 0) {
      return true;
    }
    if (*p != '*') {
      return false;
    }
  }

  if (*p == '*') {
    while (*(p + 1) == '*') {
      ++p;
    }

    int s_len = strlen(s);
    for (int i = 0; i <= s_len; ++i) {
      if (isMatch(s + i, p + 1)) {
        return true;
      }
    }
    return false;
  } else {
    if (*p == '?' || *s == *p) {
      return isMatch(s + 1, p + 1);
    } else {
      return false;
    }
  }
}

int main() {
  assert(isMatch("a", "*"));
  assert(!isMatch("b", "*a*"));
  assert(isMatch("aab", "a*a*b"));
  assert(isMatch("aa","a**a"));
  assert(!isMatch("aa","a*a**a"));
  assert(!isMatch("aa","a**a**a"));
  assert(!isMatch("", "a"));
  assert(!isMatch("a","aa"));
  assert(!isMatch("aa","a"));
  assert(isMatch("aa","aa"));
  assert(!isMatch("aaa","aa"));
  assert(isMatch("aa", "*"));
  assert(isMatch("aa", "a*"));
  assert(isMatch("ab", "?*"));
  assert(!isMatch("aab", "c*a*b"));
  assert(!isMatch("aab", "c*a*b"));
  assert(isMatch("ab", "?*"));
  assert(!isMatch("aaabbbaabaabaaabbabbbbbbbbaabababbabbbaaaaba", "a*******b"));
  //assert(!isMatch("aaabbbbaaaabbabbbbaabbabaaababaababaaaaaaabaaababbaababbaa"\
                  "babbbaaaaabaabbabbaabaababbaabababbbbbbbbabbaabbaaabaababa"\
                  "abaababababababbbbbbabbabbaabbaabaaaaaababaabbbaaabaaabbbb"\
                  "bbbbbaabaabaaabaaabbabbabb",
                  "****a*b*b**b*bbb*b**bba***b**b*b*b**ba***b*b*a*b*b*****a**"\
                  "aaa*baaa*ba*****a****ba*a****a**b*******a*a"));

  puts("finished");

  return 0;
}
