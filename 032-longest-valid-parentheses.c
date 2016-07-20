#include <stdlib.h>
#include <stdio.h>

int longestValidParentheses(const char* s) {
  const char *stack[512]; // store index of left parenthese
  const char **top = stack;
  const char *begin = s;
  int len = 0;
  for (const char *p = s; *p != '\0'; ++p) {
    if (*p == '(') {
      *top++ = p;
    } else {
      int tmp_len;
      if (top == stack) {
        tmp_len = p - begin;
      } else {
        tmp_len = p - *(top - 1) + 1;
      }
      if (tmp_len > len) {
        len = tmp_len;
      }
      --top;
    }
  }

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
