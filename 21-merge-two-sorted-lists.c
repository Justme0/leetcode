/* Merge two sorted linked lists and return it as a new list. The new list should
   be made by splicing together the nodes of the first two lists.
   */

#include <stdio.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
  struct ListNode dummy = {0, NULL};
  struct ListNode *p = l1;
  struct ListNode *q = l2;
  struct ListNode *r = &dummy;

  for (; p != NULL && q != NULL; r = r->next) {
    if (p->val < q->val) {
      r->next = p;
      p = p->next;
    } else {
      r->next = q;
      q = q->next;
    }
  }
  if (NULL == p) {
    r->next = q;
  } else {
    r->next = p;
  }

  return dummy.next;
}

int main() {

  return 0;
}
