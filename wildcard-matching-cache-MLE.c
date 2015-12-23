// MLE
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

int **alloc(size_t row, size_t col) {
  int **m = (int **)malloc(row * sizeof(int *));
  if (m == NULL) {
    exit(1);
  }
  for (size_t i = 0; i < row; ++i) {
    m[i] = (int *)malloc(col * sizeof(int));
    if (NULL == m[i]) {
      exit(1); // previous allocation may leak
    }
    memset(m[i], 0xFF, col * sizeof(int)); // -1
  }

  return m;
}

void dealloc(int **m, size_t row) {
  for (size_t i = 0; i < row; ++i) {
    free(m[i]);
  }
  free(m);
}

const char *g_s;
const char *g_p;

bool isMatch_dfs(const char *s, const char *p, int **m) {
  int *pret = &m[s - g_s][p - g_p];
  if (*pret != -1) {
    assert(*pret == 0 || *pret == 1);
    return *pret;
  }

  if (*p == '\0') {
    return (*pret = (*s == '\0'));
  }
  if (*s == '\0') {
    if (strcmp(p, "*") == 0) {
      return (*pret = true);
    }
    if (*p != '*') {
      return (*pret = false);
    }
  }

  if (*p == '*') {
    while (*(p + 1) == '*') {
      ++p;
    }

    int s_len = strlen(s);
    for (int i = 0; i <= s_len; ++i) {
      if (isMatch_dfs(s + i, p + 1, m)) {
        return (*pret = true);
      }
    }
    return (*pret = false);
  } else {
    if (*p == '?' || *s == *p) {
      return (*pret = isMatch_dfs(s + 1, p + 1, m));
    } else {
      return (*pret = false);
    }
  }
}

bool isMatch(const char *s, const char *p) {
  g_s = s;
  g_p = p;

  size_t s_size = strlen(s);
  size_t p_size = strlen(p);
  int **dp = alloc(1 + s_size, 1 + p_size);

  bool ret = isMatch_dfs(s, p, dp);
  dealloc(dp, 1 + s_size);

  return ret;
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
  assert(!isMatch("aaabbbbaaaabbabbbbaabbabaaababaababaaaaaaabaaababbaababbaa"
                  "babbbaaaaabaabbabbaabaababbaabababbbbbbbbabbaabbaaabaababa"
                  "abaababababababbbbbbabbabbaabbaabaaaaaababaabbbaaabaaabbbb"
                  "bbbbbaabaabaaabaaabbabbabb",
                  "****a*b*b**b*bbb*b**bba***b**b*b*b**ba***b*b*a*b*b*****a**"
                  "aaa*baaa*ba*****a****ba*a****a**b*******a*a"));
  puts("finished");

  return 0;
}
