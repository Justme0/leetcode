/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct Node {
  int val;
  struct Node *next;
};

int g_sum;

void sumNumbersAux(struct TreeNode *root, struct Node * const stack) {
  if (root == NULL) {
    return ;
  }

  if (root->left == NULL && root->right == NULL) {
    // When root is a leaf.
    int sum = root->val;
    int weight = 10;
    for (struct Node *p = stack->next; p != NULL; p = p->next, weight *= 10) {
      sum += p->val * weight;
    }
    printf("leaf sum is %d\n", sum);
    g_sum += sum;
    return ;
  }

  struct Node *p = malloc(sizeof(struct Node));
  p->next = stack->next;
  p->val = root->val;
  stack->next = p;

  sumNumbersAux(root->left, stack);
  sumNumbersAux(root->right, stack);

  assert(p == stack->next);
  stack->next = stack->next->next; // Important!
  free(p);
}

int sumNumbers(struct TreeNode *root) {
  g_sum = 0;
  struct Node *stack = calloc(1, sizeof(struct Node));
  sumNumbersAux(root, stack);

  assert(stack->next == NULL);
  free(stack);

  return g_sum;
}

int main() {



  return 0;
}
