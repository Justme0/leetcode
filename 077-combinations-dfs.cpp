class Solution {
	public:
		std::vector<std::vector<int>> combine(int n, int k) {
			std::vector<std::vector<int>> result;
			dfs_(n, k, std::vector<int>(), 1, result);
			return result;
		}

	private:
		void dfs_(size_t n, size_t k, std::vector<int> array, size_t index, std::vector<std::vector<int>> &result) {
			if (k == array.size()) {
				result.push_back(array);

				return;
			}

			for (size_t i = index; i != n + 1; ++i) {
				array.push_back(i);
				dfs_(n, k, array, 1 + i, result);
				array.pop_back();
			}

		}
};
