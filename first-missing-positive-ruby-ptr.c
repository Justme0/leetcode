#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void place(int **nums, size_t size) {
	for (size_t i = 0; i < size; ++i) {
		int *x = nums[i];
		while (1 <= *x && *x <= (int)size && *x != (int)(i + 1) && *(nums[i]) != *(nums[(size_t)(*x - 1)])) {
			// printf("%zu\n", i);
			int *temp = nums[i];
			nums[i] = nums[(size_t)(*x - 1)];
			nums[(size_t)(*x - 1)] = temp;

			x = nums[i];
		}
	}
}

int * first_missing_positive_aux(int **arr, size_t size) {
	static int result = 0;
	for (size_t i = 0; i < size; ++i) {
		int *x = arr[i];
		if (*x != (int)(i + 1)) {
			result = i + 1;
			return &result;
		}
	}
	result = 1 + size;
	return &result;
}

int * ruby_first_missing_positive(int **nums, size_t size) {
	place(nums, size);
	return first_missing_positive_aux(nums, size);
}

int firstMissingPositive(int* nums, int numsSize) {
	int **pnums = (int **)malloc(numsSize * sizeof(int *));	// TODO: NULL and free
	for (size_t i = 0; i < (size_t)numsSize; ++i) {
		pnums[i] = &nums[i];
	}

	return *ruby_first_missing_positive(pnums, numsSize);
}

void test(int *a, size_t size, int result) {
	assert(firstMissingPositive(a, size) == result);
	//assert(*ruby_first_missing_positive(a, size) == result);
	puts("ok");
}

int main() {
	int nums[] = {};
	size_t size = sizeof nums / sizeof *nums;
	test(nums, size, 1);

	return 0;
}
