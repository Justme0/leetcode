/*
   You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  int carry = 0;
  struct ListNode *ret = (struct ListNode *)malloc(sizeof(struct ListNode)); // dummy node; TODO: test malloc failed
  ret->val = 0;
  ret->next = NULL;
  struct ListNode *pret = ret;
  struct ListNode *p = l1, *q = l2;
  do {
    int sum = (p == NULL ? 0 : p->val) + (q == NULL ? 0 : q->val) + carry;
    if (sum >= 10) {
      carry = 1;
      sum -= 10;
    } else {
      carry = 0;
    }

    pret->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    pret->next->val = sum;
    pret->next->next = NULL;
    pret = pret->next;
    if (p != NULL) {
      p = p->next;
    }
    if (q != NULL) {
      q = q->next;
    }
  } while (p != NULL || q != NULL);
  if (carry == 1) {
    pret->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    pret->next->val = 1;
    pret->next->next = NULL;
  }

  return ret->next;
}

int main() {

  return 0;
}
