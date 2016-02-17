/*

   Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

   If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

   You may not alter the values in the nodes, only nodes itself may be changed.

   Only constant memory is allowed.

   For example,
   Given this linked list: 1->2->3->4->5

   For k = 2, you should return: 2->1->4->3->5

   For k = 3, you should return: 3->2->1->4->5
   */

#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode * advance(struct ListNode *p, int k) {
  for (int i = 0; i < k; ++i) {
    assert(p != NULL);
    p = p->next;
  }

  return p;
}

bool has_enough(struct ListNode *p, int k) {
  for (int i = 0; i < k; ++i) {
    if (p == NULL) {
      return false;
    }
    p = p->next;
  }

  return true;
}

struct ListNode * catenate(struct ListNode * const dst, struct ListNode * const other) {
  assert(NULL != dst);
  if (other == NULL) {
    return dst;
  }

  struct ListNode *p;
  for (p = dst; p->next != NULL; p = p->next) {
  }
  p->next = other;
  return dst;
}

struct ListNode * reverseKGroup(struct ListNode *head, int k) {
  if (head == NULL) {
    return NULL;
  }

  struct ListNode head_tmp = {0, NULL};
  struct ListNode *ret_first = &head_tmp;
  struct ListNode *begin = head;
  while (has_enough(begin, k)) {
    struct ListNode *end = advance(begin, k);
    struct ListNode *tmp = NULL;
    for (struct ListNode *p = begin; p != end; p = tmp) {
      tmp = p->next;
      p->next = ret_first->next;
      ret_first->next = p;
    }
    ret_first = begin;
    begin = end;
  }
  catenate(&head_tmp, begin);

  return head_tmp.next;
}

struct ListNode * create_list(int *arr, int size) {
  struct ListNode *head = NULL;
  for (int i = size - 1; i != -1; --i) {
    struct ListNode *tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (tmp == NULL) {
      // FIXME: rollback
      exit(-1);
    }
    tmp->val = arr[i];
    tmp->next = head;
    head = tmp;
  }

  return head;
}

void destruct_list(struct ListNode *lst) {
  struct ListNode *tmp = NULL;
  for (struct ListNode *p = lst; p != NULL; p = tmp) {
    tmp = p->next;
    free(p);
  }
}

void print(struct ListNode *lst) {
  for (struct ListNode *p = lst; p != NULL; p = p->next) {
    printf("%d ", p->val);
  }
  printf("\n");
}

int main() {
  int arr[] = {1, 2, 3, 4};
  int k = 3;
  int size = sizeof arr / sizeof *arr;
  struct ListNode *lst = create_list(arr, size);
  print(lst);
  struct ListNode *rev_lst = reverseKGroup(lst, k);
  print(rev_lst);
  destruct_list(rev_lst);

  printf("OK\n");

  return 0;
}
