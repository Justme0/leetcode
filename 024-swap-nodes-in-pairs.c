/*
   Given a linked list, swap every two adjacent nodes and return its head.

   For example,
   Given 1->2->3->4, you should return the list as 2->1->4->3.

   Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
   */

#include <stdio.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head) {
  struct ListNode dummy = {0, head};

  struct ListNode *pre = &dummy;
  struct ListNode *p;
  while (p = pre->next, p != NULL && p->next != NULL) {
    pre->next = p->next;
    p->next = pre->next->next;
    pre->next->next = p;
    pre = p;
  }

  return dummy.next;
}

int main() {
  struct ListNode arr[5] = {
    {0, arr + 1},
    {1, arr + 2},
    {2, arr + 3},
    {3, arr + 4},
    {4, NULL},
  };

  struct ListNode *l = swapPairs(arr);

  for (struct ListNode *p = l; p != NULL; p = p->next) {
    printf("%d ", p->val);
  }
  printf("\n");

  return 0;
}
