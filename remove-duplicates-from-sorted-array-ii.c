#include <stdio.h>
#include <assert.h>

int removeDuplicates(int A[], int n) {
	if (n <= 2) {
		return n;
	}

	int len = 2;
	for (int i = 2; i < n; ++i) {
		if (A[i] != A[len - 2]) {
			A[len] = A[i];
			++len;
		}
	}
	assert(len <= n);

	return len;
}

void test(int *a, int n, int expect) {
	assert(expect == removeDuplicates(a, n));
	printf("ok\n");
}

int main() {
	{
		int arr[] = {};
		int len = sizeof arr / sizeof *arr;
		test(arr, len, 0);
	}
	{
		int arr[] = {1};
		int len = sizeof arr / sizeof *arr;
		test(arr, len, 1);
	}
	{
		int arr[] = {1, 1};
		int len = sizeof arr / sizeof *arr;
		test(arr, len, 2);
	}
	{
		int arr[] = {1, 1, 1, 2};
		int len = sizeof arr / sizeof *arr;
		test(arr, len, 3);
	}
	{
		int arr[] = {1, 1, 1, 2, 2, 3};
		int len = sizeof arr / sizeof *arr;
		test(arr, len, 5);
	}

	return 0;
}
