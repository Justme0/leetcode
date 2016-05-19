/*
   Given a string containing just the characters '(', ')', '{', '}', '[' and
   ']', determine if the input string is valid.

   The brackets must close in the correct order, "()" and "()[]{}" are all valid
   but "(]" and "([)]" are not.
   */

#define NDEBUG
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

char partner(char c) {
  switch (c) {
  case ')':
    return '(';
    break;

  case ']':
    return '[';
    break;

  case '}':
    return '{';
    break;

  default:
    assert(!"invalid character");
    break;
  }
  return '\0';
}

bool isValid(char *s) {
  char stack[512]; // FIXME: maybe overflow
  char *sp = stack; // stack pointer (points to the above of top element)
  for (char *p = s; *p != '\0'; ++p) {
    switch (*p) {
    case '(':
    case '[':
    case '{':
      *sp++ = *p;
      break;

    case ')':
    case ']':
    case '}':
      if (sp <= stack) {
        return false;
      }
      if (*(sp - 1) == partner(*p)) {
        --sp;
      } else {
        return false;
      }
      break;

    default:
      assert(!"invalid character");
      break;
    }
  }

  return sp == stack;
}

int main() {
  assert(isValid("()"));
  assert(isValid("()[]"));
  assert(isValid("([])"));
  assert(!isValid("(]"));
  assert(!isValid("([)]"));
  assert(!isValid("{"));

  return 0;
}
