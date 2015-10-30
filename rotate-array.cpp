// TODO: three methods

class Solution {
public:
	void rotate(int nums[], int n, int k) {
		k %= n;
		vector<int> v(n);
		copy(nums, nums + n, v.begin());
		for (int i = 0; i < k; ++i) {
			assert(0 <= i + n - k && i + n - k <= n - 1);
			nums[i] = v[i + n - k];
		}
		for (int i = k; i < n; ++i) {
			nums[i] = v[i - k];
		}
	}
};
