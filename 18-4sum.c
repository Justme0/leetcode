/*
   Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

A solution set is:
(-1,  0, 0, 1)
(-2, -1, 1, 2)
(-2,  0, 0, 2)
*/

#include <stdlib.h>
#include <stdio.h>

static int cmp(const void *pa, const void *pb) {
  return *(const int *)pa - *(const int *)pb;
}

static void print(int *nums, size_t numsSize) {
  for (int *p = nums; p != nums + numsSize; ++p) {
    printf("%d ", *p);
  }
  printf("\n");
}

int *advance(int *p, const int *last) {
  do {
    ++p;
  } while (p < last && *(p - 1) == *p);

  return p;
}

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* preturnSize) {
  qsort(nums, numsSize, sizeof(int), cmp); // O(n*log(n))
  print(nums, numsSize);
  int **ret = malloc(512 * sizeof(int *)); // FIXME: maybe need realloc()
  if (NULL == ret) {
    exit(-1);
  }
  int **pp = ret; // data is in [nums, pp)
  const int *const last = nums + numsSize;

  // O(n^3)
  for (int *a = nums; a < last; a = advance(a, last)) {
    for (int *b = a + 1; b < nums + numsSize; b = advance(b, last)) {
      int *c = b + 1;
      int *d = nums + numsSize - 1;
      while (c < d) {
        int sum = *a + *b + *c + *d;
        if (sum > target) {
          --d;
        } else if (sum < target) {
          ++c;
        } else {
          *pp = malloc(4 * sizeof(int));
          if (NULL == *pp) {
            exit(-1); // TODO: free allocated memory
          }
          (*pp)[0] = *a;
          (*pp)[1] = *b;
          (*pp)[2] = *c;
          (*pp)[3] = *d;
          ++pp; // FIXME: check bound
          c = advance(c, last);
        }
      }
    }
  }
  *preturnSize = pp - ret;
  return ret;
}

void dealloc(int **m, int returnSize) {
  for (int **pp = m; pp < m + returnSize; ++pp) {
    free(*pp);
  }
  free(m);
}

int main() {
  //  int arr[] = {1, 0, -1, 0, -2, 2};
  int arr[] = {
    -3,-2,-1,0,0,1,2,3
  };
  int n = sizeof arr / sizeof *arr;
  int target = 0;
  int returnSize = 0;

  int **m = fourSum(arr, n, target, &returnSize);
  for (int **pp = m; pp != m + returnSize; ++pp) {
    print(*pp, 4);
  }
  printf("return size is %d\n", returnSize);
  dealloc(m, returnSize);

  return 0;
}
