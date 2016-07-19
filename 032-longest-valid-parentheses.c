#include <stdlib.h>

int longestValidParentheses(char* s) {
  char *stack[512]; // '(' index stack
  char **top = stack;
  for (char *p = s; *p != '\0'; ++p) {
    if (*p == '(') {
      *top++ = p;
    }
  }

  return 0;
}
