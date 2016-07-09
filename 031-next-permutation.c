/*
https://leetcode.com/problems/next-permutation/

Implement next permutation, which rearranges numbers into the lexicographically
next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible
order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding
outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

#include <assert.h>
#include <stdio.h>

void swap(int *p, int *q) {
  int tmp = *p;
  *p = *q;
  *q = tmp;
}

void reverse(int *first, int *last) {
  for (; first < last - 1; ++first, --last) {
    swap(first, last - 1);
  }
}

void nextPermutation(int *nums, int numsSize) {
  if (numsSize == 0) {
    return;
  }

  // 1.1 find first less pattern
  int *p;
  for (p = nums + numsSize - 1; p >= nums + 1; --p) {
    if (*(p - 1) < *p) {
      break;
    }
  }
  if (p == nums) {
    reverse(nums, nums + numsSize);
    return;
  }

  // 1.2 find first greater pattern
  int *q;
  for (q = nums + numsSize - 1; q > p; --q) {
    if (*q > *(p - 1)) {
      break;
    }
  }
  assert(p <= q && q < nums + numsSize && *(p - 1) < *p && *(p - 1) < *q &&
         *p >= *q);

  // 1.3 swap to set highest position
  swap(p - 1, q);

  // 2. reverse to reset right segment
  reverse(p, nums + numsSize);
}

int main() {
  int arr[] = {3, 2};
  const int size = sizeof arr / sizeof *arr;
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < size; ++j) {
      printf("%d ", arr[j]);
    }
    printf("\n");
    nextPermutation(arr, size);
  }

  return 0;
}
