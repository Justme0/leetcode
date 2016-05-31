/*
   Given a sorted array, remove the duplicates in place such that each element
   appear only once and return the new length.

   Do not allocate extra space for another array, you must do this in place with
   constant memory.

   For example,
   Given input array nums = [1,1,2],

   Your function should return length = 2, with the first two elements of nums
   being 1 and 2 respectively. It doesn't matter what you leave beyond the new
   length.
   */

#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int *nums, int numsSize) {
  if (numsSize == 0) {
    return 0;
  }

  // 1. find first non adjacent equal position
  int *first = nums + 1;
  for (; first != nums + numsSize && *(first - 1) != *first; ++first) {
  }
  if (first == nums + numsSize) {
    return numsSize;
  }

  // 2. unique
  int *tail = first; // tail points to next position
  int *p = first;
  for (; p != nums + numsSize; ++p) {
    if (*(tail - 1) != *p) {
      *tail++ = *p;
    }
  }
  return tail - nums;
}

int removeDuplicatesOld(int *nums, int numsSize) {
  if (numsSize == 0) {
    return 0;
  }
  int *tail = nums + 1;
  int *p = nums + 1;
  for (; p < nums + numsSize; ++p) {
    if (*(tail - 1) != *p) {
      *tail++ = *p;
    }
  }
  return tail - nums;
}

int main() {
  int arr[] = {2, 2, 3, 3};
  size_t size = sizeof arr / sizeof *arr;
  size_t new_size = removeDuplicates(arr, size);
  for (int *p = arr; p < arr + new_size; ++p) {
    printf("%d ", *p);
  }
  printf("\n");

  return 0;
}
