#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/// the length of (before_first, tail]
/// http://www.geeksforgeeks.org/length-of-the-longest-valid-substring/
int longestValidParentheses(const char *s) {
  const char **stack = malloc((strlen(s) + 1) * sizeof(const char *));
  if (NULL == stack) {
    exit(1);
  }
  *stack = s - 1;
  const char **top = stack + 1;
  int len = 0;
  for (const char *p = s; *p != '\0'; ++p) {
    if (*p == '(') {
      *top++ = p;
    } else {
      assert(stack != top); // The stack always contains "before first" index.
      if (top - stack != 1) {
        --top; // Match the top, that is the matched left parenthese.
        int new_len = p - *(top - 1); // top-1 is the "before first" index. NOTE
                                      // that `top` points to the position after
                                      // the top element.
        if (new_len > len) {
          len = new_len;
        }
      } else {
        *stack = p; // Not match. Just update "before first" index.
      }
    }
  }
  free(stack);

  return len;
}

void test(int expected, const char *str) {
  printf("Test \"%s\"...\n", str);
  int res = longestValidParentheses(str);
  if (expected != res) {
    printf("Test result of \"%s\" is %d, but expect %d.\n", str, res, expected);
    exit(1);
  }
  printf("OK\n");
}

int main() {
  test(2, "(()");
  test(2, "()(()");
  test(4, "(())(()");
  test(4, "(())");
  test(4, "()()");
  test(8, "(())(())");
  test(0, "");
  test(0, "(");
  test(0, "((");
  test(2, "(()");
  test(4, ")()())");
  test(6, ")(()())");
  test(4, ")()())()()(");

  return 0;
}
